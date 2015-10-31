import asyncio
from pymysql import NotSupportedError
from aiomysql.cursors import SSCursor
from tests import base
from tests._testutils import run_until_complete

from aiomysql import ProgrammingError


class TestSSCursor(base.AIOPyMySQLTestCase):
    data = [
        ('America', '', 'America/Jamaica'),
        ('America', '', 'America/Los_Angeles'),
        ('America', '', 'America/Lima'),
        ('America', '', 'America/New_York'),
        ('America', '', 'America/Menominee'),
        ('America', '', 'America/Havana'),
        ('America', '', 'America/El_Salvador'),
        ('America', '', 'America/Costa_Rica'),
        ('America', '', 'America/Denver'),
        ('America', '', 'America/Detroit'), ]

    @asyncio.coroutine
    def _prepare(self, conn):
        cursor = yield from conn.cursor()
        # Create table
        yield from cursor.execute('DROP TABLE IF EXISTS tz_data;')
        yield from cursor.execute('CREATE TABLE tz_data ('
                                  'region VARCHAR(64),'
                                  'zone VARCHAR(64),'
                                  'name VARCHAR(64))')

        yield from cursor.executemany(
            'INSERT INTO tz_data VALUES (%s, %s, %s)', self.data)
        yield from conn.commit()
        yield from cursor.close()

    @run_until_complete
    def test_ssursor(self):
        # affected_rows = 18446744073709551615
        conn = self.connections[0]
        cursor = yield from conn.cursor(SSCursor)
        # Create table
        yield from cursor.execute('DROP TABLE IF EXISTS tz_data;')
        yield from cursor.execute(('CREATE TABLE tz_data ('
                                   'region VARCHAR(64),'
                                   'zone VARCHAR(64),'
                                   'name VARCHAR(64))'))

        # Test INSERT
        for i in self.data:
            yield from cursor.execute(
                'INSERT INTO tz_data VALUES (%s, %s, %s)', i)
            self.assertEqual(conn.affected_rows(), 1,
                             'affected_rows does not match')
        yield from conn.commit()

        # Test update, affected_rows()
        yield from cursor.execute('UPDATE tz_data SET zone = %s', ['Foo'])
        yield from conn.commit()

        self.assertEqual(cursor.rowcount, len(self.data),
                         'Update failed. affected_rows != %s' % (
                         str(len(self.data))))

        yield from cursor.close()
        yield from cursor.close()

    @run_until_complete
    def test_sscursor_fetchall(self):
        conn = self.connections[0]
        cursor = yield from conn.cursor(SSCursor)

        yield from self._prepare(conn)
        yield from cursor.execute('SELECT * FROM tz_data')
        fetched_data = yield from cursor.fetchall()
        self.assertEqual(len(fetched_data), len(self.data),
                         'fetchall failed. Number of rows does not match')

    @run_until_complete
    def test_sscursor_fetchmany(self):
        conn = self.connections[0]
        cursor = yield from conn.cursor(SSCursor)
        yield from self._prepare(conn)
        yield from cursor.execute('SELECT * FROM tz_data')
        fetched_data = yield from cursor.fetchmany(2)
        self.assertEqual(len(fetched_data), 2,
                         'fetchmany failed. Number of rows does not match')

        # test default fetchmany size
        yield from cursor.execute('SELECT * FROM tz_data;')
        fetched_data = yield from cursor.fetchmany()
        self.assertEqual(len(fetched_data), 1)

    @run_until_complete
    def test_sscursor_executemany(self):
        conn = self.connections[0]
        yield from self._prepare(conn)
        cursor = yield from conn.cursor(SSCursor)
        # Test executemany
        yield from cursor.executemany(
            'INSERT INTO tz_data VALUES (%s, %s, %s)', self.data)
        msg = 'executemany failed. cursor.rowcount != %s'
        self.assertEqual(cursor.rowcount, len(self.data),
                         msg % (str(len(self.data))))

    @run_until_complete
    def test_sscursor_scroll_relative(self):
        conn = self.connections[0]
        yield from self._prepare(conn)
        cursor = yield from conn.cursor(SSCursor)
        yield from cursor.execute('SELECT * FROM tz_data;')
        yield from cursor.scroll(1)
        ret = yield from cursor.fetchone()
        self.assertEqual(('America', '', 'America/Los_Angeles'), ret)

    @run_until_complete
    def test_sscursor_scroll_absolute(self):
        conn = self.connections[0]
        yield from self._prepare(conn)
        cursor = yield from conn.cursor(SSCursor)
        yield from cursor.execute('SELECT * FROM tz_data;')
        yield from cursor.scroll(2, mode='absolute')
        ret = yield from cursor.fetchone()
        self.assertEqual(('America', '', 'America/Lima'), ret)

    @run_until_complete
    def test_sscursor_scroll_errors(self):
        conn = self.connections[0]
        cursor = yield from conn.cursor(SSCursor)

        yield from cursor.execute('SELECT * FROM tz_data;')

        with self.assertRaises(NotSupportedError):
            yield from cursor.scroll(-2, mode='relative')

        yield from cursor.scroll(2, mode='absolute')

        with self.assertRaises(NotSupportedError):
            yield from cursor.scroll(1, mode='absolute')
        with self.assertRaises(ProgrammingError):
            yield from cursor.scroll(2, mode='not_valid_mode')
