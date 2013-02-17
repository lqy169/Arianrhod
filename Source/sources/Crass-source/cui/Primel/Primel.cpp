#include <windows.h>
#include <tchar.h>
#include <crass_types.h>
#include <acui.h>
#include <cui.h>
#include <package.h>
#include <resource.h>
#include <cui_error.h>
#include <stdio.h>
#include <utility.h>

/* 接口数据结构: 表示cui插件的一般信息 */
struct acui_information Primel_cui_information = {
	_T("Itsuki Myouhao"),		/* copyright */
	_T("Primel the Advanture System for x86"),	/* system */
	_T(".pcf"),	/* package */
	_T(""),			/* revision */
	_T("痴漢公賊"),			/* author */
	_T(""),	/* date */
	NULL,					/* notion */
	ACUI_ATTRIBUTE_LEVEL_DEVELOP
};

/* 所有的封包特定的数据结构都要放在这个#pragma段里 */
#pragma pack (1)
typedef struct {
	s8 magic[8];		// "PackCode"
	u32 index_entries;	// @08 ?
	u32 off_0x0c;		// @0c ?

	u64 data_size;		// @10
	u64 unknown_offset;	// @18 ?	用于和pcf文件的大小做比较（如果超出文件大小就有错误）

	u64 unknown_entry_size;	// @20 ?
	u64 index_offset;	// @28

	u32 off_0x30;		// @30 ?
	u32 off_0x34;		// @34 ?
	u32 flags;			// @38 ?
	u32 off_0x3c;		// @3c ?

	u32 off_0x40;		// @40 ?
	u32 off_0x44;		// @44 ?
	u32 off_0x48;		// @48 ?
	u32 off_0x4c;		// @4c ?

	u32 index_decrypt_key[4];	// @50

	u32 off_0x60;		// @60 ?
	u32 off_0x64;		// @64 ?
	u32 off_0x68;		// @68 ?
	u32 off_0x6c;		// @6c ?

	u32 off_0x70;		// @70 ?
	u32 off_0x74;		// @74 ?
	u32 off_0x78;		// @78 ?
	u32 off_0x7c;		// @7c ?

	u32 off_0x80;		// @80 ?
	u32 off_0x84;		// @84 ?
	u32 off_0x88;		// @88 ?
	u32 off_0x8c;		// @8c ?

	u32 off_0x90;		// @90 ?
	u32 off_0x94;		// @94 ?
	u32 off_0x98;		// @98 ?
	u32 off_0x9c;		// @9c ?
} pcf_header_t;

typedef struct {
	s8 name[116];
	u32 name_length;
	u32 offset;
	u32 length;
} pcf_entry_t;
#pragma pack ()

extern void sha256(unsigned char *md, unsigned int md_len,
	unsigned char *data, unsigned int len);

static inline unsigned int hweight32(unsigned int w)
{
    unsigned int res = (w & 0x55555555) + ((w >> 1) & 0x55555555);
    res = (res & 0x33333333) + ((res >> 2) & 0x33333333);
    res = (res & 0x0F0F0F0F) + ((res >> 4) & 0x0F0F0F0F);
    res = (res & 0x00FF00FF) + ((res >> 8) & 0x00FF00FF);
    return (res & 0x0000FFFF) + ((res >> 16) & 0x0000FFFF);
}

struct crypt_ctx {
	unsigned int buflen;
	unsigned int state[8];
	unsigned int buf[4];
};

static unsigned int key[8] = {
	0x243f6a89, 0xb7e15163, 0x9e3779b9, 0x6f2dec55, 
	0x6a09e668, 0xbb67ae86, 0xb504f334, 0x93cd3a2d, 
};

static unsigned char decrypt_code[4][256] = {
	{
		0x29, 0x4e, 0xf8, 0x6c, 0x4d, 0xd1, 0x52, 0x5b, 0x2f, 0x4b, 0xe5, 0x0a, 0xa4, 0xbb, 0xf7, 0xdf, 
		0x9f, 0x8c, 0x27, 0xb9, 0x25, 0xfd, 0x07, 0x4a, 0x7c, 0x81, 0x10, 0x26, 0x46, 0x11, 0xa3, 0xdb, 
		0x39, 0x08, 0x55, 0x36, 0x96, 0xc4, 0x5c, 0xfe, 0x2e, 0x66, 0xa6, 0x74, 0x45, 0x60, 0xf3, 0x83, 
		0x72, 0x3f, 0xc5, 0x99, 0x0d, 0x16, 0x3d, 0x6d, 0x5d, 0x57, 0xae, 0x35, 0xde, 0x8e, 0xa0, 0x41, 
		0x8b, 0x34, 0xd7, 0xe3, 0xbe, 0x33, 0xb0, 0x44, 0xeb, 0xec, 0xff, 0x91, 0x6e, 0x85, 0x9d, 0x12, 
		0xaf, 0x8d, 0xe9, 0xba, 0x1c, 0x05, 0xee, 0x3a, 0x03, 0xfa, 0x7b, 0x23, 0xd4, 0x8a, 0xd9, 0x67, 
		0xca, 0x97, 0x02, 0x70, 0xd8, 0xfc, 0xe4, 0x78, 0x73, 0x19, 0x5e, 0x77, 0x59, 0x69, 0xe0, 0xd6, 
		0x14, 0x37, 0x00, 0x6b, 0x13, 0x17, 0x0f, 0x49, 0xaa, 0x22, 0x89, 0xe1, 0x7a, 0xad, 0x6a, 0x30, 
		0x2b, 0xb4, 0xfb, 0xb6, 0x88, 0xf0, 0x7e, 0xa1, 0x18, 0xe7, 0xd2, 0x3c, 0x9a, 0x84, 0xa7, 0x54, 
		0x40, 0x64, 0x90, 0x9b, 0x3e, 0x6f, 0xcf, 0x80, 0xf4, 0x93, 0x75, 0x1b, 0x51, 0xd3, 0x79, 0xe2, 
		0x42, 0x15, 0xe8, 0xb3, 0x0b, 0x9e, 0x31, 0xda, 0xac, 0x50, 0x7d, 0x87, 0xea, 0xdd, 0x04, 0x56, 
		0xc9, 0x28, 0x1e, 0x94, 0x63, 0x47, 0x8f, 0xc6, 0x1a, 0xc7, 0xf1, 0xf2, 0x71, 0xce, 0x1d, 0x53, 
		0x06, 0x0c, 0xdc, 0x82, 0x48, 0xbc, 0xcb, 0xa2, 0xab, 0x4f, 0x98, 0xb2, 0xcd, 0x1f, 0xa8, 0x3b, 
		0xef, 0xf5, 0x58, 0x20, 0xb8, 0xc0, 0xc1, 0x21, 0x2c, 0x86, 0x32, 0xa9, 0x2d, 0xc3, 0xbd, 0x62, 
		0xb7, 0x76, 0x95, 0xd5, 0x9c, 0x68, 0xe6, 0x92, 0x2a, 0xc8, 0x43, 0x4c, 0x0e, 0x7f, 0x01, 0x5f, 
		0xd0, 0x38, 0x65, 0x61, 0x24, 0xb1, 0xf6, 0xcc, 0xbf, 0xc2, 0x5a, 0x09, 0xb5, 0xed, 0xa5, 0xf9, 
	},
	{
		0xc5, 0xe6, 0xf6, 0x06, 0x9b, 0x77, 0xb8, 0x61, 0x95, 0x14, 0x6c, 0x01, 0xe5, 0xc8, 0xd3, 0x20, 
		0xfe, 0x73, 0xec, 0x3b, 0xcb, 0x07, 0xa3, 0x28, 0xde, 0x99, 0x2a, 0xc0, 0x90, 0x42, 0x10, 0x0a, 
		0x19, 0x16, 0xcc, 0xc3, 0x92, 0x86, 0x4b, 0x80, 0xc1, 0xae, 0xd1, 0x9f, 0x2f, 0x41, 0xe9, 0x63, 
		0x6e, 0x22, 0x55, 0x9c, 0x5d, 0x81, 0xa2, 0xb4, 0x0d, 0xa0, 0x4a, 0xdd, 0xd8, 0x54, 0x39, 0xfd, 
		0x8f, 0x49, 0xdc, 0x6d, 0x1e, 0x36, 0x02, 0xb3, 0x52, 0x85, 0x21, 0xe1, 0xdb, 0xe3, 0x23, 0x33, 
		0x00, 0x12, 0x04, 0x7f, 0x98, 0x79, 0xc6, 0x60, 0x8e, 0x03, 0x3c, 0x1c, 0xfb, 0x09, 0x6f, 0xad, 
		0x6b, 0xbb, 0x18, 0x3a, 0xbc, 0xf8, 0x3d, 0x9e, 0x9d, 0x26, 0xda, 0xff, 0xaf, 0xa5, 0xaa, 0x3f, 
		0x5b, 0x71, 0xa1, 0x70, 0xee, 0x4f, 0x68, 0xb0, 0x13, 0xd5, 0x87, 0x4d, 0x35, 0xf5, 0xa8, 0x17, 
		0xd4, 0xf1, 0x40, 0x57, 0x59, 0x1a, 0x93, 0x47, 0xbf, 0x05, 0x67, 0x8c, 0x1b, 0x69, 0x25, 0xc9, 
		0xbe, 0x5c, 0xea, 0x74, 0xc4, 0x2d, 0x38, 0xce, 0x5a, 0xe4, 0x94, 0x30, 0xc7, 0x65, 0x5f, 0x64, 
		0x7e, 0xe7, 0xd7, 0x8a, 0x0c, 0x2e, 0x9a, 0x82, 0xcf, 0x2b, 0x62, 0xf3, 0xb7, 0xcd, 0x3e, 0xf4, 
		0xbd, 0x83, 0xac, 0x0b, 0x7b, 0x45, 0xf9, 0x75, 0x32, 0xa4, 0x50, 0x58, 0xca, 0x78, 0xf7, 0xb6, 
		0x84, 0x51, 0x31, 0xab, 0x56, 0x11, 0x72, 0x76, 0xd9, 0x29, 0x43, 0x15, 0x4c, 0xe2, 0xe0, 0x4e, 
		0x89, 0x7a, 0xfa, 0x44, 0x6a, 0x91, 0xba, 0xb9, 0x7d, 0x2c, 0x46, 0x8b, 0xb1, 0x66, 0xdf, 0x08, 
		0x8d, 0xd6, 0xef, 0xd0, 0xb5, 0xa9, 0xeb, 0xfc, 0xed, 0x88, 0x7c, 0xf0, 0x27, 0x53, 0xe8, 0x96, 
		0x24, 0x5e, 0xd2, 0x1d, 0x0e, 0x48, 0x34, 0xa7, 0x1f, 0xc2, 0x0f, 0x37, 0xf2, 0xa6, 0xb2, 0x97, 
	},
	{
		0xe7, 0xf2, 0x6f, 0xcd, 0x4b, 0x52, 0xbc, 0x8b, 0xd1, 0x14, 0x68, 0xac, 0xd2, 0x92, 0x9f, 0x78, 
		0x4f, 0x59, 0x47, 0x15, 0x02, 0x79, 0x53, 0x93, 0x8d, 0x94, 0x03, 0x9e, 0x3e, 0x72, 0x19, 0x48, 
		0x89, 0x0f, 0x27, 0xd7, 0xe6, 0xaf, 0x91, 0x39, 0x9b, 0x44, 0xa8, 0xfe, 0x18, 0xa5, 0x8c, 0x42, 
		0x7c, 0x74, 0xea, 0x9c, 0x97, 0xe9, 0xdf, 0x65, 0x2e, 0xfb, 0xd6, 0xda, 0x5d, 0x49, 0x9d, 0x04, 
		0x81, 0xb2, 0xe4, 0x6c, 0x8f, 0xf7, 0x4d, 0x85, 0xa9, 0xb5, 0xce, 0xbf, 0xbe, 0xe3, 0x50, 0x21, 
		0x54, 0x46, 0xb6, 0x16, 0xef, 0x1e, 0x08, 0xcc, 0x6b, 0x35, 0xab, 0x7b, 0xc7, 0xa1, 0xc5, 0x90, 
		0x20, 0x63, 0x55, 0x1c, 0xc3, 0xb8, 0x3c, 0x3a, 0x29, 0xd5, 0x0b, 0x41, 0x5c, 0xc0, 0x57, 0x05, 
		0x0c, 0x0a, 0x4e, 0xa2, 0xfd, 0x28, 0x9a, 0x70, 0xdc, 0x51, 0x2a, 0xb4, 0x8e, 0x7e, 0x34, 0x10, 
		0xc1, 0x25, 0x4c, 0xe2, 0x6e, 0x84, 0x1d, 0x61, 0x17, 0xb3, 0x6d, 0xc2, 0x43, 0xeb, 0x24, 0x83, 
		0xff, 0x1b, 0x76, 0xae, 0x67, 0x87, 0x5a, 0x69, 0x58, 0xcb, 0x32, 0xdd, 0x26, 0x3f, 0x96, 0x5f, 
		0x82, 0x5e, 0x01, 0x7a, 0x2d, 0xf9, 0xf5, 0xf0, 0xad, 0x37, 0x45, 0xf8, 0x31, 0x38, 0x88, 0x75, 
		0x36, 0x7f, 0x64, 0x5b, 0x1a, 0xbd, 0xe0, 0xfa, 0x11, 0xb9, 0x33, 0xa3, 0x6a, 0x23, 0xf6, 0xdb, 
		0x66, 0x71, 0xf3, 0x77, 0x1f, 0xcf, 0x22, 0x3b, 0xe8, 0xec, 0x95, 0x98, 0x99, 0xd3, 0xca, 0x40, 
		0xb1, 0x30, 0x12, 0x3d, 0xa7, 0x06, 0x0d, 0xbb, 0xed, 0x07, 0xd4, 0xc4, 0x7d, 0xf1, 0xe1, 0xa4, 
		0x13, 0xa0, 0xde, 0x80, 0xc6, 0x2c, 0xba, 0x0e, 0xc8, 0xd9, 0xd0, 0x00, 0xee, 0xb0, 0x86, 0xaa, 
		0xfc, 0x73, 0xd8, 0xa6, 0x56, 0x2f, 0x2b, 0xb7, 0x09, 0x4a, 0xf4, 0xe5, 0x62, 0x8a, 0x60, 0xc9, 
	},
	{
		0x7a, 0x26, 0x6e, 0x12, 0x08, 0x7e, 0xe6, 0x15, 0xe8, 0x0e, 0x3d, 0x6a, 0x29, 0x5a, 0x45, 0xe4, 
		0x2f, 0x86, 0x5f, 0x76, 0xdf, 0xea, 0x09, 0xc5, 0x83, 0x16, 0xeb, 0xa0, 0x23, 0x9f, 0xd7, 0x30, 
		0x02, 0x79, 0x81, 0xaf, 0x97, 0x58, 0xd4, 0xba, 0xd5, 0xb1, 0x73, 0x6c, 0x2a, 0xab, 0x2e, 0x7b, 
		0x34, 0xd9, 0xf8, 0xb2, 0x67, 0xb6, 0x7d, 0xf3, 0x1e, 0xc1, 0x5c, 0xb7, 0x88, 0xf2, 0x0d, 0x1a, 
		0x8a, 0x5b, 0x55, 0xa8, 0xee, 0x78, 0x70, 0xed, 0x7c, 0xf9, 0xf6, 0xd3, 0x50, 0xbd, 0x56, 0xdc, 
		0x38, 0x21, 0xbc, 0x9b, 0x03, 0xf0, 0xe1, 0x04, 0x8f, 0x6d, 0x31, 0xc9, 0x8d, 0xfb, 0xbe, 0x14, 
		0x54, 0x3f, 0x91, 0x35, 0x72, 0xa7, 0xe9, 0x19, 0xfa, 0x17, 0xb8, 0x9d, 0xde, 0x24, 0x25, 0xa1, 
		0xdb, 0xcb, 0xcc, 0x39, 0xa5, 0xe0, 0xef, 0x57, 0x85, 0xbf, 0x49, 0x1b, 0x7f, 0x3b, 0x65, 0xc3, 
		0x77, 0x00, 0x10, 0x59, 0xb3, 0xc6, 0x95, 0x1c, 0x60, 0x5d, 0x41, 0xaa, 0x51, 0x71, 0xd6, 0x99, 
		0x1f, 0x52, 0x82, 0xcd, 0x2b, 0xd1, 0x61, 0xb9, 0x43, 0x63, 0x69, 0x46, 0xa2, 0x47, 0x8e, 0x36, 
		0x42, 0x87, 0xd8, 0xb4, 0xd2, 0x53, 0xec, 0x06, 0x6b, 0xc8, 0xe5, 0x33, 0x6f, 0x4b, 0x8b, 0x66, 
		0xe3, 0x74, 0xfe, 0x4d, 0xad, 0x28, 0x48, 0xe2, 0x90, 0xf5, 0x84, 0xb0, 0xda, 0xd0, 0x20, 0xac, 
		0xdd, 0x75, 0x92, 0xca, 0xf7, 0x2d, 0x3a, 0x9c, 0x0a, 0xb5, 0xc4, 0x07, 0x5e, 0x13, 0x05, 0xbb, 
		0x0c, 0xff, 0xa4, 0xf1, 0x27, 0x4e, 0xa3, 0x98, 0x11, 0xa9, 0x96, 0x93, 0x68, 0x4f, 0xfc, 0x37, 
		0x80, 0x4a, 0xcf, 0x01, 0x9a, 0xc0, 0x1d, 0x3c, 0x8c, 0x4c, 0x3e, 0x0b, 0xc7, 0xa6, 0xae, 0x0f, 
		0x2c, 0x62, 0xf4, 0x94, 0xce, 0x89, 0x40, 0x22, 0xfd, 0x18, 0x32, 0xc2, 0x9e, 0x64, 0x44, 0xe7, 
	}
};

static void decrypt(struct crypt_ctx *ctx, unsigned char *data, 
			   unsigned int len)
{
	if (len > 16)
		len = 16;

	memcpy(ctx->buf, data, len);

	unsigned int k = 0;
	for (int i = 0; i < 16; ++i) {
		k = ctx->buf[i & 3] ^ (k + key[(i + 3) & 7]);
		ctx->buf[i & 3] = (decrypt_code[3][k >> 24] << 24) | (decrypt_code[2][(k >> 16) & 0xff] << 16)
			| (decrypt_code[1][(k >> 8) & 0xff] << 8) | decrypt_code[0][k & 0xff];
	}

	unsigned int c;
	
	c = hweight32(ctx->buf[0]);
	ctx->state[0] = c & 0x1f;
	ctx->state[4] = ((c >> 1) ^ c) & 0x0f;
	
	c = hweight32(ctx->buf[1]);
	ctx->state[1] = (c + 1) & 0x1f;
	ctx->state[5] = (((c + 1) >> 1) ^ c) & 0x0f;

	c = hweight32(ctx->buf[2]);
	ctx->state[2] = (c + 2) & 0x1f;
	ctx->state[6] = (((c + 2) >> 1) ^ c) & 0x0f;

	c = hweight32(ctx->buf[3]);
	ctx->state[3] = (c + 3) & 0x1f;
	ctx->state[7] = (((c + 3) >> 1) ^ c) & 0x0f;
}

/********************* pcf *********************/

/* 封包匹配回调函数 */
static int Primel_pcf_match(struct package *pkg)
{
	pcf_header_t header;

	if (pkg->pio->open(pkg, IO_READONLY))
		return -CUI_EOPEN;

	if (pkg->pio->read(pkg, &header, sizeof(header))) {
		pkg->pio->close(pkg);
		return -CUI_EREAD;
	}

	if (strncmp(header.magic, "PackCode", 8)) {
		pkg->pio->close(pkg);
		return -CUI_EMATCH;	
	}

	u32 fsize_lo, fsize_hi;
	pkg->pio->length_of64(pkg, &fsize_lo, &fsize_hi);
	u64 fsize = fsize_lo | (u64)fsize_hi << 32;

	if (header.unknown_offset > fsize) {
		pkg->pio->close(pkg);
		return -CUI_EMATCH;	
	}

	if (header.flags & 0x20000000) {
		printf("not support PackDivF\n");
		pkg->pio->close(pkg);
		return -CUI_EMATCH;
	}

	return 0;	
}

/* 封包索引目录提取函数 */
static int Primel_pcf_extract_directory(struct package *pkg,
										struct package_directory *pkg_dir)
{
	pcf_header_t header;

	if (pkg->pio->readvec(pkg, &header, sizeof(header), 0, IO_SEEK_SET))
		return -CUI_EREADVEC;

	DWORD index_len = header.index_entries * sizeof(pcf_entry_t);
	pcf_entry_t *index = new pcf_entry_t[header.index_entries];
	if (!index)
		return -CUI_EMEM;

	u64 index_offset = sizeof(header) + header.index_offset;
	if (pkg->pio->readvec64(pkg, index, index_len, 0, 
			(u32)index_offset, (u32)(index_offset >> 32), IO_SEEK_SET)) {
		delete [] index;
		return -CUI_EREADVEC;
	}

	if (header.flags & 0x3FF0000) {
		unsigned int *d;		
		unsigned int d_size;

		if (header.flags & 0x3000000) {
			 printf("not supported\n");
		} else {
			d = &header.index_decrypt_key[2];
			d_size = 8;
		}

		unsigned char hash[16];

		sha256(hash, sizeof(hash), (unsigned char *)d, d_size);

		unsigned char hash2[16];

		sha256(hash2, sizeof(hash2), hash, sizeof(hash));

		u32 type = header.flags & 0xF0000;
		switch (type) {
		case 0x10000:
			//v20 = operator new(0x18u);
			//flags = v20;
			//v9 = sub_48EE70();
			printf("not support type 0x10000\n");
			return -CUI_EMATCH;
			break;
		case 0x20000:	// here
			//buffer_flags = new ???(0x38);	// 3d6bd8
			// op: 4ABCC4
			// member value: hash_len (init value: 4), hash_len <= 16 && 4字节对齐 
			break;
		case 0x30000:		
			//v8 = operator new(0x5Cu);
			//flags = v8;
			//v9 = sub_48E890(v8);
			printf("not support type 0x30000\n");
			return -CUI_EMATCH;
			break;
		case 0x70000:
			//v21 = operator new(0x814u);
			//v9 = sub_48C880();
			printf("not support type 0x70000\n");
			return -CUI_EMATCH;
			break;
		case 0x80000:
			//v23 = operator new(0xB4u);
			//flags = v23;
			//v10 = sub_48C400();
			printf("not support type 0x80000\n");
			return -CUI_EMATCH;
			break;
		case 0xA0000:
			//v22 = operator new(0x418u);
			//flags = v22;
			//v9 = sub_48DBB0();
			printf("not support type 0xA0000\n");
			return -CUI_EMATCH;
			break;
		default:
			delete [] index;
			return -CUI_EMATCH;
		}

	//	v26 = -1;


		// case 0x20000;
		struct crypt_ctx ctx;

		decrypt(&ctx, hash, sizeof(hash));

		u32 mode = header.flags & 0x3F00000;
		switch (mode) {
		case 0x0100000:
			printf("not support mode 0x0100000\n");
			return -CUI_EMATCH;		
			break;
		case 0x0200000:

		case 0x0300000:
			printf("not support mode 0x0300000\n");
			return -CUI_EMATCH;		
			break;
		case 0x0400000:
			printf("not support mode 0x0400000\n");
			return -CUI_EMATCH;		
			break;
		case 0x1000000:
			printf("not support mode 0x1000000\n");
			return -CUI_EMATCH;		
			break;
		case 0x2000000:
			printf("not support mode 0x2000000\n");
			return -CUI_EMATCH;		
			break;		



		}


		MySaveFile(_T("hash2"), hash2, sizeof(hash2));

		exit(0);
	}


#if 0

	dat_entry_t *index_buffer;
	unsigned int index_buffer_length;	
	unsigned int i;

	if (pkg->pio->read(pkg, &pkg_dir->index_entries, 4))
		return -CUI_EREAD;

	index_buffer_length = pkg_dir->index_entries * sizeof(dat_entry_t);
	index_buffer = new dat_entry_t[pkg_dir->index_entries];
	if (!index_buffer)
		return -CUI_EMEM;

	dat_entry_t *index = index_buffer;
	for (i = 0; i < pkg_dir->index_entries; i++) {
		if (pkg->pio->read(pkg, &index->name_length, 4))
			break;

		if (pkg->pio->read(pkg, index->name, index->name_length))
			break;
		index->name[index->name_length] = 0;

		if (pkg->pio->read(pkg, &index->offset, 4))
			break;

		if (pkg->pio->read(pkg, &index->length, 4))
			break;

		index++;
	}
	if (i != pkg_dir->index_entries) {
		delete [] index_buffer;
		return -CUI_EREAD;
	}

	pkg_dir->directory = index_buffer;
	pkg_dir->directory_length = index_buffer_length;
	pkg_dir->index_entry_length = sizeof(dat_entry_t);
	pkg_dir->flags = PKG_DIR_FLAG_SKIP0;
#endif
	return 0;
}

/* 封包索引项解析函数 */
static int Primel_pcf_parse_resource_info(struct package *pkg,
										  struct package_resource *pkg_res)
{
	pcf_entry_t *pcf_entry;

	pcf_entry = (pcf_entry_t *)pkg_res->actual_index_entry;
	strcpy(pkg_res->name, pcf_entry->name);
	pkg_res->name_length = -1;			/* -1表示名称以NULL结尾 */
	pkg_res->raw_data_length = pcf_entry->length;
	pkg_res->actual_data_length = 0;	/* 数据都是明文 */
	pkg_res->offset = pcf_entry->offset;

	return 0;
}

/* 封包资源提取函数 */
static int Primel_pcf_extract_resource(struct package *pkg,
									   struct package_resource *pkg_res)
{
	BYTE *raw = new BYTE[pkg_res->raw_data_length];
	if (!raw)
		return -CUI_EMEM;

	if (pkg->pio->readvec(pkg, raw, pkg_res->raw_data_length,
		pkg_res->offset, IO_SEEK_SET)) {
			delete [] raw;
			return -CUI_EREADVEC;
	}

	pkg_res->raw_data = raw;

	return 0;
}

/* 资源保存函数 */
static int Primel_pcf_save_resource(struct resource *res, 
									struct package_resource *pkg_res)
{
	if (res->rio->create(res))
		return -CUI_ECREATE;

	if (pkg_res->actual_data && pkg_res->actual_data_length) {
		if (res->rio->write(res, pkg_res->actual_data, pkg_res->actual_data_length)) {
			res->rio->close(res);
			return -CUI_EWRITE;
		}
	} else if (pkg_res->raw_data && pkg_res->raw_data_length) {
		if (res->rio->write(res, pkg_res->raw_data, pkg_res->raw_data_length)) {
			res->rio->close(res);
			return -CUI_EWRITE;
		}
	}

	res->rio->close(res);
	
	return 0;
}

/* 封包资源释放函数 */
static void Primel_pcf_release_resource(struct package *pkg, 
										struct package_resource *pkg_res)
{
	if (pkg_res->actual_data) {
		delete [] pkg_res->actual_data;
		pkg_res->actual_data = NULL;
	}
	if (pkg_res->raw_data) {
		delete [] pkg_res->raw_data;
		pkg_res->raw_data = NULL;
	}
}

/* 封包卸载函数 */
static void Primel_pcf_release(struct package *pkg, 
							   struct package_directory *pkg_dir)
{
	if (pkg_dir->directory) {
		delete [] pkg_dir->directory;
		pkg_dir->directory = NULL;
	}

	pkg->pio->close(pkg);
}

/* 封包处理回调函数集合 */
static cui_ext_operation Primel_pcf_operation = {
	Primel_pcf_match,					/* match */
	Primel_pcf_extract_directory,		/* extract_directory */
	Primel_pcf_parse_resource_info,		/* parse_resource_info */
	Primel_pcf_extract_resource,		/* extract_resource */
	Primel_pcf_save_resource,			/* save_resource */
	Primel_pcf_release_resource,		/* release_resource */
	Primel_pcf_release					/* release */
};

/* 接口函数: 向cui_core注册支持的封包类型 */
int CALLBACK Primel_register_cui(struct cui_register_callback *callback)
{
	if (callback->add_extension(callback->cui, _T(".pcf"), NULL, 
		NULL, &Primel_pcf_operation, CUI_EXT_FLAG_PKG | CUI_EXT_FLAG_DIR))
			return -1;

	return 0;
}
