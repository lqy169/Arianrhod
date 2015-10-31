"""Test help output of various IPython entry points"""

# Copyright (c) IPython Development Team.
# Distributed under the terms of the Modified BSD License.

import IPython.testing.tools as tt
from IPython.testing.decorators import skip_without


def test_ipython_help():
    tt.help_all_output_test()

def test_profile_help():
    tt.help_all_output_test("profile")

def test_profile_list_help():
    tt.help_all_output_test("profile list")

def test_profile_create_help():
    tt.help_all_output_test("profile create")

def test_locate_help():
    tt.help_all_output_test("locate")

def test_locate_profile_help():
    tt.help_all_output_test("locate profile")

@skip_without('nbformat')  # Requires jsonschema to be installed
def test_trust_help():
    tt.help_all_output_test("trust")
