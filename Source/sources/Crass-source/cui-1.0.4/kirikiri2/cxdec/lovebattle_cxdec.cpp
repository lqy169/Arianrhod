#include "cxdec.h"

static int xcode_building_stage0(struct cxdec_xcode_status *xcode, int stage);
static int xcode_building_stage1(struct cxdec_xcode_status *xcode, int stage);

static BYTE EncryptionControlBlock[4096] = {
		0x20, 0x45, 0x6e, 0x63, 0x72, 0x79, 0x70, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x63, 0x6f, 0x6e, 0x74, 
		0x72, 0x6f, 0x6c, 0x20, 0x62, 0x6c, 0x6f, 0x63, 0x6b, 0x20, 0x2d, 0x2d, 0x20, 0x53, 0x74, 0x61, 
		0x74, 0x69, 0x63, 0x61, 0x6c, 0x6c, 0x79, 0x20, 0x6f, 0x72, 0x20, 0x64, 0x79, 0x6e, 0x61, 0x6d, 
		0x69, 0x63, 0x61, 0x6c, 0x6c, 0x79, 0x2c, 0x20, 0x64, 0x69, 0x72, 0x65, 0x63, 0x74, 0x6c, 0x79, 
		0x20, 0x6f, 0x72, 0x20, 0x69, 0x6e, 0x64, 0x69, 0x72, 0x65, 0x63, 0x74, 0x6c, 0x79, 0x2c, 0x20, 
		0x75, 0x73, 0x69, 0x6e, 0x67, 0x20, 0x74, 0x68, 0x69, 0x73, 0x20, 0x70, 0x72, 0x6f, 0x67, 0x72, 
		0x61, 0x6d, 0x20, 0x61, 0x6e, 0x64, 0x2f, 0x6f, 0x72, 0x20, 0x62, 0x6c, 0x6f, 0x63, 0x6b, 0x20, 
		0x66, 0x72, 0x6f, 0x6d, 0x20, 0x6f, 0x74, 0x68, 0x65, 0x72, 0x20, 0x70, 0x72, 0x6f, 0x67, 0x72, 
		0x61, 0x6d, 0x73, 0x20, 0x77, 0x69, 0x6c, 0x6c, 0x20, 0x62, 0x65, 0x20, 0x69, 0x6c, 0x6c, 0x65, 
		0x67, 0x61, 0x6c, 0x20, 0x62, 0x79, 0x20, 0x74, 0x68, 0x65, 0x20, 0x6c, 0x69, 0x63, 0x65, 0x6e, 
		0x73, 0x65, 0x20, 0x61, 0x67, 0x72, 0x65, 0x65, 0x6d, 0x65, 0x6e, 0x74, 0x2e, 0x20, 0x82, 0xb1, 
		0x82, 0xcc, 0x83, 0x76, 0x83, 0x8d, 0x83, 0x4f, 0x83, 0x89, 0x83, 0x80, 0x82, 0xe2, 0x83, 0x75, 
		0x83, 0x8d, 0x83, 0x62, 0x83, 0x4e, 0x82, 0xf0, 0x81, 0x41, 0x90, 0xc3, 0x93, 0x49, 0x82, 0xc5, 
		0x82, 0xa0, 0x82, 0xea, 0x93, 0xae, 0x93, 0x49, 0x82, 0xc5, 0x82, 0xa0, 0x82, 0xea, 0x81, 0x41, 
		0x92, 0xbc, 0x90, 0xda, 0x93, 0x49, 0x82, 0xc5, 0x82, 0xa0, 0x82, 0xea, 0x8a, 0xd4, 0x90, 0xda, 
		0x93, 0x49, 0x82, 0xc5, 0x82, 0xa0, 0x82, 0xea, 0x81, 0x41, 0x91, 0xbc, 0x82, 0xcc, 0x83, 0x76, 
		0x83, 0x8d, 0x83, 0x4f, 0x83, 0x89, 0x83, 0x80, 0x82, 0xa9, 0x82, 0xe7, 0x97, 0x70, 0x82, 0xa2, 
		0x82, 0xe9, 0x82, 0xb1, 0x82, 0xc6, 0x82, 0xcd, 0x83, 0x89, 0x83, 0x43, 0x83, 0x5a, 0x83, 0x93, 
		0x83, 0x58, 0x82, 0xc9, 0x82, 0xe6, 0x82, 0xe8, 0x8b, 0xd6, 0x82, 0xb6, 0x82, 0xe7, 0x82, 0xea, 
		0x82, 0xc4, 0x82, 0xa2, 0x82, 0xdc, 0x82, 0xb7, 0x81, 0x42, 0x0a, 0x81, 0x40, 0x8c, 0x6b, 0x92, 
		0x4a, 0x89, 0x88, 0x82, 0xa2, 0x82, 0xcc, 0x8d, 0xd7, 0x82, 0xa2, 0x8f, 0xac, 0x8c, 0x61, 0x82, 
		0xf0, 0x92, 0x48, 0x82, 0xe9, 0x8e, 0x84, 0x82, 0xcc, 0x96, 0x6a, 0x82, 0xf0, 0x81, 0x41, 0x8f, 
		0x5f, 0x82, 0xe7, 0x82, 0xa9, 0x82, 0xc8, 0x96, 0x46, 0x8f, 0x74, 0x82, 0xcc, 0x95, 0x97, 0x82, 
		0xaa, 0x95, 0x8f, 0x82, 0xc5, 0x82, 0xc4, 0x82, 0xa2, 0x82, 0xad, 0x81, 0x42, 0x0a, 0x8d, 0xf7, 
		0x82, 0xcc, 0x95, 0x91, 0x82, 0xa2, 0x8e, 0x55, 0x82, 0xe9, 0x82, 0xbb, 0x82, 0xcc, 0x89, 0x9c, 
		0x82, 0xc9, 0x81, 0x41, 0x82, 0xd0, 0x82, 0xc1, 0x82, 0xbb, 0x82, 0xe8, 0x82, 0xc6, 0x98, 0xc8, 
		0x82, 0xdc, 0x82, 0xa4, 0x82, 0xb3, 0x82, 0xb3, 0x82, 0xe2, 0x82, 0xa9, 0x82, 0xc8, 0x89, 0xb7, 
		0x90, 0xf2, 0x8f, 0x68, 0x81, 0x42, 0x82, 0xbb, 0x82, 0xb1, 0x82, 0xc9, 0x81, 0x63, 0x81, 0x63, 
		0x94, 0xde, 0x82, 0xaa, 0x8b, 0x8f, 0x82, 0xe9, 0x81, 0x49, 0x0a, 0x0a, 0x81, 0x40, 0x8e, 0x84, 
		0x81, 0x41, 0x8c, 0x8e, 0x93, 0x87, 0x8f, 0x74, 0x8d, 0x81, 0x81, 0x42, 0x0a, 0x88, 0xe3, 0x8e, 
		0x74, 0x82, 0xf0, 0x96, 0xda, 0x8e, 0x77, 0x82, 0xb5, 0x82, 0xc4, 0x93, 0x73, 0x89, 0xef, 0x82, 
		0xcc, 0x8a, 0x77, 0x8d, 0x5a, 0x82, 0xc5, 0x96, 0xd2, 0x95, 0xd7, 0x8b, 0xad, 0x92, 0x86, 0x81, 
		0x42, 0x0a, 0x98, 0x65, 0x96, 0xda, 0x82, 0xe0, 0x82, 0xd3, 0x82, 0xe7, 0x82, 0xb8, 0x81, 0x63, 
		0x81, 0x63, 0x82, 0xc6, 0x8c, 0xbe, 0x82, 0xa2, 0x82, 0xbd, 0x82, 0xa2, 0x83, 0x67, 0x83, 0x52, 
		0x82, 0xc8, 0x82, 0xf1, 0x82, 0xbe, 0x82, 0xaf, 0x82, 0xc7, 0x81, 0x41, 0x82, 0xe2, 0x82, 0xc1, 
		0x82, 0xcf, 0x82, 0xe8, 0x8e, 0x84, 0x82, 0xbe, 0x82, 0xc1, 0x82, 0xc4, 0x94, 0x4e, 0x8d, 0xa0, 
		0x82, 0xcc, 0x8f, 0x97, 0x82, 0xcc, 0x8e, 0x71, 0x81, 0x41, 0x8b, 0x43, 0x82, 0xc9, 0x82, 0xc8, 
		0x82, 0xe9, 0x92, 0x6a, 0x82, 0xcc, 0x8e, 0x71, 0x82, 0xcc, 0x82, 0xd0, 0x82, 0xc6, 0x82, 0xe8, 
		0x82, 0xad, 0x82, 0xe7, 0x82, 0xa2, 0x82, 0xcd, 0x82, 0xa2, 0x82, 0xe9, 0x82, 0xed, 0x81, 0x42, 
		0x0a, 0x82, 0xc5, 0x82, 0xe0, 0x82, 0xbb, 0x82, 0xa2, 0x82, 0xc2, 0x82, 0xc1, 0x82, 0xbd, 0x82, 
		0xe7, 0x82, 0xe0, 0x82, 0xa4, 0x89, 0xbd, 0x8d, 0x6c, 0x82, 0xa6, 0x82, 0xc4, 0x82, 0xe9, 0x82, 
		0xcc, 0x82, 0xa9, 0x82, 0xed, 0x82, 0xa9, 0x82, 0xf1, 0x82, 0xc8, 0x82, 0xa2, 0x81, 0x49, 0x81, 
		0x40, 0x82, 0xa0, 0x82, 0xf1, 0x82, 0xc8, 0x82, 0xcc, 0x82, 0xaa, 0x8f, 0x97, 0x82, 0xcc, 0x8e, 
		0x71, 0x82, 0xc9, 0x90, 0x6c, 0x8b, 0x43, 0x82, 0xa0, 0x82, 0xe9, 0x82, 0xc8, 0x82, 0xf1, 0x82, 
		0xc4, 0x82, 0xcb, 0x81, 0x42, 0x0a, 0x83, 0x4e, 0x81, 0x5b, 0x83, 0x8b, 0x81, 0x48, 0x81, 0x40, 
		0x8e, 0x84, 0x82, 0xc9, 0x8c, 0xbe, 0x82, 0xed, 0x82, 0xb9, 0x82, 0xe8, 0x82, 0xe1, 0x96, 0xb3, 
		0x93, 0xda, 0x92, 0x85, 0x82, 0xc8, 0x82, 0xbe, 0x82, 0xaf, 0x82, 0xe6, 0x81, 0x42, 0x82, 0xa0, 
		0x82, 0xa2, 0x82, 0xc2, 0x82, 0xcc, 0x83, 0x7d, 0x83, 0x43, 0x83, 0x79, 0x81, 0x5b, 0x83, 0x58, 
		0x89, 0xc1, 0x8c, 0xb8, 0x82, 0xc9, 0x82, 0xcd, 0x93, 0xaa, 0x82, 0xc9, 0x97, 0x88, 0x82, 0xbf, 
		0x82, 0xe1, 0x82, 0xa4, 0x81, 0x42, 0x0a, 0x0a, 0x81, 0x40, 0x82, 0xbb, 0x82, 0xf1, 0x82, 0xc8, 
		0x94, 0xde, 0x82, 0xaa, 0x81, 0x41, 0x89, 0xc6, 0x82, 0xcc, 0x93, 0x73, 0x8d, 0x87, 0x82, 0xc5, 
		0x8a, 0x77, 0x8d, 0x5a, 0x82, 0xf0, 0x8b, 0x8e, 0x82, 0xe9, 0x82, 0xb1, 0x82, 0xc6, 0x82, 0xc9, 
		0x82, 0xc8, 0x82, 0xc1, 0x82, 0xbd, 0x81, 0x42, 0x0a, 0x82, 0xc6, 0x82, 0xe8, 0x82, 0xa0, 0x82, 
		0xa6, 0x82, 0xb8, 0x90, 0x65, 0x90, 0xca, 0x82, 0xbe, 0x82, 0xa9, 0x82, 0xc8, 0x82, 0xf1, 0x82, 
		0xbe, 0x82, 0xa9, 0x82, 0xaa, 0x82, 0xe2, 0x82, 0xc1, 0x82, 0xc4, 0x82, 0xe9, 0x93, 0x63, 0x8e, 
		0xc9, 0x82, 0xcc, 0x97, 0xb7, 0x8a, 0xd9, 0x82, 0xc9, 0x90, 0x67, 0x82, 0xf0, 0x8a, 0xf1, 0x82, 
		0xb9, 0x82, 0xe9, 0x82, 0xe7, 0x82, 0xb5, 0x82, 0xa2, 0x81, 0x42, 0x0a, 0x94, 0xde, 0x82, 0xc9, 
		0x90, 0x55, 0x82, 0xe8, 0x89, 0xf1, 0x82, 0xb3, 0x82, 0xea, 0x82, 0xe9, 0x93, 0xfa, 0x81, 0x58, 
		0x82, 0xcd, 0x93, 0xcb, 0x91, 0x52, 0x8f, 0x49, 0x82, 0xed, 0x82, 0xe8, 0x82, 0xf0, 0x8d, 0x90, 
		0x82, 0xb0, 0x82, 0xbd, 0x81, 0x42, 0x8e, 0x84, 0x82, 0xcd, 0x82, 0xd0, 0x82, 0xc7, 0x82, 0xad, 
		0x93, 0xae, 0x97, 0x68, 0x82, 0xb5, 0x82, 0xc4, 0x81, 0x63, 0x81, 0x63, 0x82, 0xd0, 0x82, 0xc7, 
		0x82, 0xa2, 0x8c, 0xbe, 0x97, 0x74, 0x82, 0xc5, 0x82, 0xa0, 0x82, 0xa2, 0x82, 0xc2, 0x82, 0xc6, 
		0x95, 0xca, 0x82, 0xea, 0x82, 0xc4, 0x82, 0xb5, 0x82, 0xdc, 0x82, 0xc1, 0x82, 0xbd, 0x81, 0x42, 
		0x0a, 0x8e, 0x84, 0x82, 0xaa, 0x94, 0xde, 0x82, 0xc9, 0x8c, 0xbe, 0x82, 0xa2, 0x82, 0xbd, 0x82, 
		0xa9, 0x82, 0xc1, 0x82, 0xbd, 0x82, 0xcc, 0x82, 0xcd, 0x82, 0xbb, 0x82, 0xf1, 0x82, 0xc8, 0x8c, 
		0xbe, 0x97, 0x74, 0x82, 0xb6, 0x82, 0xe1, 0x82, 0xc8, 0x82, 0xa9, 0x82, 0xc1, 0x82, 0xbd, 0x82, 
		0xcc, 0x82, 0xc9, 0x81, 0x63, 0x81, 0x63, 0x81, 0x42, 0x0a, 0x0a, 0x81, 0x40, 0x82, 0xbb, 0x82, 
		0xb5, 0x82, 0xc4, 0x8f, 0x74, 0x8b, 0x78, 0x82, 0xdd, 0x81, 0x41, 0x8e, 0x84, 0x82, 0xcd, 0x88, 
		0xd3, 0x82, 0xf0, 0x8c, 0x88, 0x82, 0xb5, 0x82, 0xc4, 0x97, 0xb7, 0x97, 0xa7, 0x82, 0xc1, 0x82, 
		0xbd, 0x81, 0x42, 0x0a, 0x94, 0xde, 0x82, 0xaa, 0x95, 0xe9, 0x82, 0xe7, 0x82, 0xb7, 0x8e, 0x52, 
		0x8a, 0xd4, 0x82, 0xcc, 0x89, 0xb7, 0x90, 0xf2, 0x8f, 0x68, 0x82, 0xd6, 0x81, 0x42, 0x0a, 0x0a, 
		0x82, 0xa0, 0x82, 0xa2, 0x82, 0xc2, 0x82, 0xc6, 0x82, 0xe0, 0x82, 0xa4, 0x88, 0xea, 0x93, 0x78, 
		0x8c, 0xbe, 0x97, 0x74, 0x82, 0xf0, 0x8c, 0xf0, 0x82, 0xed, 0x82, 0xb7, 0x82, 0xbd, 0x82, 0xdf, 
		0x82, 0xc9, 0x81, 0x42, 0x0a, 0x82, 0xbb, 0x82, 0xb5, 0x82, 0xc4, 0x81, 0x63, 0x81, 0x63, 0x8e, 
		0x84, 0x82, 0xcc, 0x8b, 0x43, 0x8e, 0x9d, 0x82, 0xbf, 0x82, 0xf0, 0x8a, 0x6d, 0x82, 0xa9, 0x82, 
		0xdf, 0x82, 0xe9, 0x82, 0xbd, 0x82, 0xdf, 0x82, 0xc9, 0x81, 0x49, 0x0a, 0x0a, 0x0a, 0x2d, 0x2d, 
		0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 
		0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 
		0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 
		0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 
		0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x0a, 0x81, 0x9b, 0x20, 0x8c, 0x8e, 0x93, 
		0x87, 0x81, 0x40, 0x8f, 0x74, 0x8d, 0x81, 0x81, 0x40, 0x81, 0x69, 0x82, 0xc2, 0x82, 0xab, 0x82, 
		0xb5, 0x82, 0xdc, 0x81, 0x40, 0x82, 0xcd, 0x82, 0xe9, 0x82, 0xa9, 0x2f, 0x54, 0x73, 0x75, 0x6b, 
		0x69, 0x73, 0x68, 0x69, 0x6d, 0x61, 0x20, 0x48, 0x61, 0x72, 0x75, 0x6b, 0x61, 0x81, 0x6a, 0x20, 
		0x0a, 0x20, 0x0a, 0x91, 0x4f, 0x8d, 0xec, 0x82, 0xcc, 0x83, 0x71, 0x83, 0x8d, 0x83, 0x43, 0x83, 
		0x93, 0x81, 0x41, 0x8c, 0x8e, 0x93, 0x87, 0x90, 0xe7, 0x89, 0xc4, 0x82, 0xcc, 0x96, 0x85, 0x81, 
		0x42, 0x0a, 0x0a, 0x8e, 0x6f, 0x82, 0xcc, 0x83, 0x8d, 0x83, 0x7d, 0x83, 0x93, 0x83, 0x58, 0x82, 
		0xc9, 0x93, 0xb2, 0x82, 0xea, 0x82, 0xc4, 0x82, 0xa2, 0x82, 0xe9, 0x82, 0xcc, 0x82, 0xbe, 0x82, 
		0xaa, 0x81, 0x41, 0x8e, 0x6f, 0x82, 0xc6, 0x90, 0xb3, 0x94, 0xbd, 0x91, 0xce, 0x82, 0xcc, 0x0a, 
		0x83, 0x4c, 0x83, 0x63, 0x82, 0xa2, 0x90, 0xab, 0x8a, 0x69, 0x82, 0xaa, 0x89, 0xd0, 0x82, 0xb5, 
		0x82, 0xc4, 0x81, 0x41, 0x83, 0x7d, 0x83, 0x43, 0x83, 0x79, 0x81, 0x5b, 0x83, 0x58, 0x82, 0xc8, 
		0x8e, 0xe5, 0x90, 0x6c, 0x8c, 0xf6, 0x82, 0xc9, 0x91, 0xce, 0x82, 0xb5, 0x82, 0xc4, 0x82, 0xcd, 
		0x82, 0xa2, 0x82, 0xdc, 0x82, 0xa2, 0x82, 0xbf, 0x91, 0x66, 0x92, 0xbc, 0x82, 0xc9, 0x82, 0xc8, 
		0x82, 0xe8, 0x82, 0xab, 0x82, 0xea, 0x82, 0xc8, 0x82, 0xa2, 0x81, 0x42, 0x0a, 0x0a, 0x83, 0x50, 
		0x83, 0x93, 0x83, 0x4a, 0x95, 0xca, 0x82, 0xea, 0x82, 0xb5, 0x82, 0xc4, 0x82, 0xb5, 0x82, 0xdc, 
		0x82, 0xc1, 0x82, 0xbd, 0x8e, 0xe5, 0x90, 0x6c, 0x8c, 0xf6, 0x82, 0xf0, 0x96, 0x4b, 0x82, 0xcb, 
		0x82, 0xc4, 0x0a, 0x97, 0xb7, 0x8a, 0xd9, 0x82, 0xc9, 0x82, 0xe2, 0x82, 0xc1, 0x82, 0xc4, 0x82, 
		0xad, 0x82, 0xe9, 0x81, 0x42, 0x20, 0x0a, 0x20, 0x0a, 0x0a, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 
		0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 
		0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 
		0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 
		0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 
		0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x0a, 0x81, 0x9b, 0x20, 0x89, 0xc1, 0x94, 0xfc, 0x8e, 0x52, 0x81, 
		0x40, 0x92, 0xd6, 0x81, 0x40, 0x81, 0x69, 0x82, 0xa9, 0x82, 0xdd, 0x82, 0xe2, 0x82, 0xdc, 0x81, 
		0x40, 0x82, 0xc2, 0x82, 0xce, 0x82, 0xab, 0x81, 0x5e, 0x4b, 0x61, 0x6d, 0x69, 0x79, 0x61, 0x6d, 
		0x61, 0x20, 0x54, 0x73, 0x75, 0x62, 0x61, 0x6b, 0x69, 0x81, 0x6a, 0x20, 0x0a, 0x20, 0x0a, 0x95, 
		0xea, 0x90, 0x65, 0x82, 0xcc, 0x82, 0xa0, 0x82, 0xe2, 0x82, 0xdf, 0x82, 0xc6, 0x8b, 0xa4, 0x82, 
		0xc9, 0x97, 0xb7, 0x8a, 0xd9, 0x82, 0xf0, 0x90, 0xd8, 0x82, 0xe8, 0x90, 0xb7, 0x82, 0xe8, 0x82, 
		0xb7, 0x82, 0xe9, 0x0a, 0x8e, 0xe5, 0x90, 0x6c, 0x8c, 0xf6, 0x82, 0xcc, 0x97, 0x63, 0x93, 0xe9, 
		0x90, 0xf5, 0x82, 0xdd, 0x81, 0x42, 0x0a, 0x0a, 0x82, 0xc7, 0x82, 0xb1, 0x82, 0xa9, 0x94, 0xb2, 
		0x82, 0xaf, 0x82, 0xc4, 0x82, 0xa2, 0x82, 0xe9, 0x82, 0xa0, 0x82, 0xe2, 0x82, 0xdf, 0x82, 0xf0, 
		0x83, 0x74, 0x83, 0x48, 0x83, 0x8d, 0x81, 0x5b, 0x82, 0xb5, 0x81, 0x41, 0x91, 0x53, 0x82, 0xc4, 
		0x82, 0xf0, 0x0a, 0x82, 0xbb, 0x82, 0xc2, 0x82, 0xc8, 0x82, 0xad, 0x8e, 0xe8, 0x8d, 0xdb, 0x82, 
		0xe6, 0x82, 0xad, 0x82, 0xb1, 0x82, 0xc8, 0x82, 0xb5, 0x82, 0xc4, 0x82, 0xa2, 0x82, 0xad, 0x81, 
		0x41, 0x97, 0xb7, 0x8a, 0xd9, 0x82, 0xcc, 0x91, 0xe5, 0x8d, 0x95, 0x92, 0x8c, 0x81, 0x42, 0x0a, 
		0x82, 0xbd, 0x82, 0xbe, 0x90, 0xda, 0x8b, 0x71, 0x91, 0xd4, 0x93, 0x78, 0x82, 0xbe, 0x82, 0xaf, 
		0x82, 0xcd, 0x96, 0xb3, 0x88, 0xa4, 0x91, 0x7a, 0x81, 0x42, 0x20, 0x0a, 0x20, 0x0a, 0x0a, 0x2d, 
		0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 
		0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 
		0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 
		0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 
		0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x0a, 0x81, 0x9b, 0x20, 0x89, 0xc1, 
		0x94, 0xfc, 0x8e, 0x52, 0x81, 0x40, 0x82, 0xa0, 0x82, 0xe2, 0x82, 0xdf, 0x81, 0x40, 0x81, 0x69, 
		0x82, 0xa9, 0x82, 0xdd, 0x82, 0xe2, 0x82, 0xdc, 0x81, 0x40, 0x82, 0xa0, 0x82, 0xe2, 0x82, 0xdf, 
		0x81, 0x5e, 0x4b, 0x61, 0x6d, 0x69, 0x79, 0x61, 0x6d, 0x61, 0x20, 0x41, 0x79, 0x61, 0x6d, 0x65, 
		0x81, 0x6a, 0x20, 0x0a, 0x0a, 0x0a, 0x96, 0xbe, 0x82, 0xe9, 0x82, 0xad, 0x82, 0xb3, 0x82, 0xce, 
		0x82, 0xaf, 0x82, 0xbd, 0x90, 0xab, 0x8a, 0x69, 0x82, 0xcc, 0x94, 0xfc, 0x90, 0x6c, 0x8f, 0x97, 
		0x8f, 0xab, 0x81, 0x42, 0x0a, 0x0a, 0x8e, 0xe5, 0x90, 0x6c, 0x8c, 0xf6, 0x82, 0xcc, 0x82, 0xb1, 
		0x82, 0xc6, 0x82, 0xf0, 0x81, 0x41, 0x82, 0xdc, 0x82, 0xe9, 0x82, 0xc5, 0x91, 0xa7, 0x8e, 0x71, 
		0x82, 0xcc, 0x82, 0xe6, 0x82, 0xa4, 0x82, 0xc9, 0x89, 0xc2, 0x88, 0xa4, 0x82, 0xaa, 0x82, 0xc1, 
		0x82, 0xc4, 0x82, 0xad, 0x82, 0xea, 0x82, 0xc4, 0x82, 0xa2, 0x82, 0xe9, 0x81, 0x42, 0x0a, 0x0a, 
		0x93, 0x56, 0x91, 0x52, 0x8c, 0x6e, 0x82, 0xc5, 0x81, 0x41, 0x96, 0xca, 0x93, 0x7c, 0x8c, 0xa9, 
		0x82, 0xcd, 0x97, 0xc7, 0x82, 0xa2, 0x82, 0xaa, 0x8e, 0x9e, 0x82, 0xc9, 0x89, 0xbd, 0x82, 0xf0, 
		0x8d, 0x6c, 0x82, 0xa6, 0x82, 0xc4, 0x82, 0xa2, 0x82, 0xe9, 0x82, 0xcc, 0x82, 0xa9, 0x94, 0xbb, 
		0x82, 0xe7, 0x82, 0xc8, 0x82, 0xa2, 0x90, 0x6c, 0x81, 0x42, 0x20, 0x0a, 0x20, 0x0a, 0x0a, 0x2d, 
		0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 
		0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 
		0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 
		0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 
		0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x0a, 0x81, 0x9b, 0x20, 0x89, 0x7e, 
		0x8d, 0x73, 0x8e, 0x9b, 0x81, 0x40, 0xfb, 0x59, 0x8e, 0x71, 0x81, 0x40, 0x81, 0x69, 0x82, 0xa6, 
		0x82, 0xf1, 0x82, 0xac, 0x82, 0xe5, 0x82, 0xa4, 0x82, 0xb6, 0x81, 0x40, 0x82, 0xe6, 0x82, 0xa4, 
		0x82, 0xb1, 0x81, 0x5e, 0x45, 0x6e, 0x67, 0x79, 0x6f, 0x75, 0x6a, 0x69, 0x20, 0x59, 0x6f, 0x75, 
		0x6b, 0x6f, 0x81, 0x6a, 0x20, 0x0a, 0x0a, 0x8e, 0x52, 0x8c, 0xfc, 0x82, 0xb1, 0x82, 0xa4, 0x82, 
		0xcc, 0x83, 0x81, 0x83, 0x57, 0x83, 0x83, 0x81, 0x5b, 0x82, 0xc8, 0x89, 0xb7, 0x90, 0xf2, 0x8a, 
		0x58, 0x82, 0xc5, 0x88, 0xea, 0x94, 0xd4, 0x82, 0xcc, 0x83, 0x8a, 0x83, 0x5d, 0x81, 0x5b, 0x83, 
		0x67, 0x83, 0x7a, 0x83, 0x65, 0x83, 0x8b, 0x82, 0xcc, 0x82, 0xa8, 0x8f, 0xec, 0x97, 0x6c, 0x81, 
		0x42, 0x8e, 0xe5, 0x90, 0x6c, 0x8c, 0xf6, 0x82, 0xcc, 0x97, 0x63, 0x93, 0xe9, 0x90, 0xf5, 0x82, 
		0xdd, 0x82, 0xc5, 0x82, 0xe0, 0x82, 0xa0, 0x82, 0xe9, 0x81, 0x42, 0x0a, 0x0a, 0x97, 0x44, 0x93, 
		0x99, 0x90, 0xb6, 0x82, 0xc5, 0x82, 0xa2, 0x82, 0xc2, 0x82, 0xe0, 0x83, 0x4e, 0x83, 0x89, 0x83, 
		0x58, 0x82, 0xf0, 0x8e, 0x64, 0x90, 0xd8, 0x82, 0xc1, 0x82, 0xc4, 0x82, 0xa2, 0x82, 0xbd, 0x82, 
		0xbd, 0x82, 0xdf, 0x81, 0x41, 0x91, 0xb2, 0x8b, 0xc6, 0x82, 0xb5, 0x82, 0xc4, 0x82, 0xe0, 0x81, 
		0x75, 0x88, 0xcf, 0x88, 0xf5, 0x92, 0xb7, 0x81, 0x76, 0x82, 0xc6, 0x8c, 0xc4, 0x82, 0xce, 0x82, 
		0xea, 0x82, 0xc4, 0x82, 0xa2, 0x82, 0xe9, 0x81, 0x42, 0x20, 0x0a, 0x20, 0x0a, 0x0a, 0x2d, 0x2d, 
		0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 
		0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 
		0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 
		0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 
		0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x0a, 0x81, 0x9b, 0x20, 0x93, 0xdd, 0x90, 
		0xec, 0x81, 0x40, 0xea, 0xa0, 0x94, 0x54, 0x81, 0x40, 0x81, 0x69, 0x82, 0xc9, 0x82, 0xd4, 0x82, 
		0xa9, 0x82, 0xed, 0x81, 0x40, 0x82, 0xdc, 0x82, 0xab, 0x82, 0xcc, 0x81, 0x5e, 0x4e, 0x69, 0x62, 
		0x75, 0x6b, 0x61, 0x77, 0x61, 0x20, 0x4d, 0x61, 0x6b, 0x69, 0x6e, 0x6f, 0x81, 0x6a, 0x20, 0x0a, 
		0x0a, 0x89, 0xb7, 0x90, 0xf2, 0x82, 0xc9, 0x97, 0x46, 0x92, 0x42, 0x82, 0xc6, 0x97, 0xb7, 0x8d, 
		0x73, 0x82, 0xc9, 0x97, 0x88, 0x82, 0xc4, 0x82, 0xa2, 0x82, 0xe9, 0x93, 0x8c, 0x8b, 0x9e, 0x82, 
		0xcc, 0x8f, 0x97, 0x8e, 0x71, 0x91, 0xe5, 0x90, 0xb6, 0x81, 0x42, 0x0a, 0x0a, 0x8e, 0xc0, 0x82, 
		0xcd, 0x91, 0xe5, 0x95, 0xcf, 0x82, 0xc8, 0x95, 0x85, 0x8f, 0x97, 0x8e, 0x71, 0x82, 0xcc, 0x90, 
		0x6c, 0x81, 0x42, 0x0a, 0x96, 0xcf, 0x91, 0x7a, 0x82, 0xbe, 0x82, 0xaf, 0x82, 0xc5, 0x90, 0xac, 
		0x91, 0x77, 0x8c, 0x97, 0x82, 0xdc, 0x82, 0xc5, 0x82, 0xbe, 0x82, 0xc1, 0x82, 0xc4, 0x94, 0xf2, 
		0x82, 0xf1, 0x82, 0xc5, 0x82, 0xa2, 0x82, 0xaf, 0x82, 0xe9, 0x81, 0x42, 0x0a, 0x0a, 0x82, 0x67, 
		0x82, 0xcc, 0x92, 0x6d, 0x8e, 0xaf, 0x82, 0xcd, 0x96, 0x4c, 0x95, 0x78, 0x82, 0xbe, 0x82, 0xaa, 
		0x81, 0x41, 0x95, 0xfb, 0x8c, 0xfc, 0x90, 0xab, 0x82, 0xcd, 0x96, 0xbe, 0x82, 0xe7, 0x82, 0xa9, 
		0x82, 0xc9, 0x8a, 0xd4, 0x88, 0xe1, 0x82, 0xc1, 0x82, 0xc4, 0x82, 0xa2, 0x82, 0xe9, 0x81, 0x42, 
		0x20, 0x0a, 0x20, 0x0a, 0xe5, 0x7f, 0x43, 0x27, 0xa1, 0x9e, 0xab, 0x8f, 0x20, 0x00, 0xd7, 0x3c, 
		0xa7, 0xa3, 0xed, 0x25, 0x51, 0x89, 0x60, 0x1d, 0x36, 0xa1, 0x67, 0xc1, 0x44, 0xbd, 0x76, 0x29, 
		0x26, 0xb8, 0x0b, 0x53, 0xe9, 0x13, 0x5f, 0xcb, 0x8a, 0x45, 0x8b, 0xe8, 0x17, 0x8c, 0x73, 0x93, 
		0xc3, 0x29, 0x09, 0x98, 0x2d, 0x61, 0x26, 0xf2, 0x41, 0x9b, 0xa9, 0xcd, 0x88, 0xd5, 0x4c, 0xf3, 
		0x7b, 0x61, 0x6b, 0x25, 0xc1, 0x71, 0xc1, 0x43, 0xe7, 0x07, 0x3f, 0xdd, 0xb1, 0x0e, 0xad, 0x2c, 
		0x2a, 0xbd, 0x1b, 0x7a, 0xb6, 0x79, 0x4f, 0x84, 0xad, 0x99, 0x82, 0xcd, 0x65, 0x53, 0x2d, 0xcb, 
		0xab, 0xa3, 0xad, 0x46, 0xc5, 0x8b, 0xb2, 0xa1, 0xeb, 0x0d, 0x9e, 0x9b, 0x20, 0xbb, 0x1f, 0x1a, 
		0xd8, 0x8d, 0x09, 0x28, 0xc7, 0x9f, 0x25, 0xa4, 0x6f, 0x9e, 0x99, 0x19, 0x4d, 0x86, 0xa5, 0x2d, 
		0xc7, 0x98, 0x78, 0x7c, 0xb5, 0x17, 0xa1, 0x10, 0xcd, 0x54, 0xd3, 0x94, 0xfc, 0x8f, 0x78, 0xc2, 
		0x2c, 0x19, 0xd1, 0xc1, 0x8f, 0xe1, 0xc7, 0xf4, 0x7e, 0xd3, 0x7d, 0x4f, 0x8b, 0xe5, 0x54, 0x96, 
		0x2d, 0x2a, 0x0a, 0xd1, 0x13, 0x50, 0xfd, 0x0b, 0x76, 0x5d, 0x58, 0x11, 0x6f, 0x19, 0x2a, 0x9e, 
		0x1a, 0xb8, 0xae, 0xb9, 0xe3, 0x64, 0x6b, 0x2a, 0x99, 0xe2, 0xab, 0xce, 0x0b, 0x7b, 0x7e, 0xeb, 
		0x85, 0x19, 0xe3, 0x93, 0xd4, 0x12, 0xbd, 0x23, 0x65, 0xec, 0x43, 0x6c, 0xa9, 0xcc, 0x6c, 0x2c, 
		0x9a, 0x14, 0xf4, 0x98, 0x6b, 0xaf, 0x54, 0x82, 0xcc, 0x38, 0x27, 0x9c, 0x8f, 0x52, 0xfc, 0x26, 
		0xc6, 0xf9, 0x98, 0xb2, 0xc2, 0x53, 0xd8, 0x3d, 0xfb, 0x2a, 0x67, 0x55, 0x9c, 0x40, 0x05, 0xed, 
		0x66, 0xdc, 0xca, 0x3a, 0x92, 0x71, 0xa1, 0x39, 0xcf, 0x29, 0x59, 0x95, 0x1a, 0xce, 0xea, 0xfd, 
		0x90, 0x63, 0x12, 0xc6, 0xcb, 0x86, 0x6c, 0x51, 0x31, 0x15, 0x2e, 0xbf, 0x0e, 0x41, 0x18, 0xc5, 
		0x0d, 0xff, 0xda, 0x0f, 0xc9, 0x0a, 0xee, 0xa2, 0xdb, 0x5d, 0xfd, 0x10, 0x06, 0xa1, 0xa8, 0x06, 
		0x04, 0x31, 0x8c, 0xaa, 0x80, 0x78, 0x3c, 0xab, 0x00, 0x6b, 0x57, 0xdf, 0xeb, 0xcc, 0xc3, 0x7f, 
		0x45, 0xd3, 0xa3, 0xdc, 0x44, 0x0c, 0xb0, 0xe2, 0xa9, 0xed, 0xd2, 0x04, 0x81, 0xd9, 0xa9, 0x8f, 
		0x76, 0xa3, 0xd9, 0xfa, 0x48, 0xf6, 0x3c, 0x5e, 0x77, 0x05, 0x70, 0x12, 0x73, 0x06, 0xfd, 0xea, 
		0xc4, 0x05, 0x39, 0xf8, 0x89, 0xb0, 0x6f, 0x37, 0x9c, 0xc8, 0x6b, 0xb2, 0xfb, 0x80, 0xb8, 0x02, 
		0xcf, 0xcf, 0x0c, 0x2a, 0x7e, 0x60, 0x23, 0x3b, 0x38, 0x78, 0xa4, 0x56, 0x28, 0xf5, 0x52, 0xd5, 
		0xf4, 0xff, 0x70, 0x8f, 0x45, 0x93, 0x74, 0xdd, 0x99, 0x42, 0x73, 0xf6, 0x38, 0xb6, 0x1e, 0xaa, 
		0xde, 0x09, 0xce, 0x3d, 0xbd, 0xc0, 0x51, 0xbd, 0xb7, 0xe3, 0xd9, 0xef, 0x10, 0x35, 0xdd, 0xa7, 
		0xd6, 0x15, 0xb4, 0x13, 0xf9, 0x97, 0x1e, 0x96, 0x05, 0xf1, 0x51, 0x2a, 0x21, 0x45, 0xfc, 0x58, 
		0x04, 0x40, 0x9c, 0x10, 0x0a, 0x9e, 0x36, 0xb0, 0xc4, 0x04, 0x8d, 0x63, 0x46, 0xa7, 0xe3, 0x49, 
		0x4d, 0x6c, 0x13, 0xb5, 0x67, 0x9c, 0xa3, 0x8a, 0x6f, 0x70, 0x08, 0x01, 0x74, 0x72, 0x08, 0x5e, 
		0xf5, 0xf2, 0xf6, 0x90, 0x78, 0xca, 0x88, 0xe4, 0x68, 0x03, 0x93, 0x8f, 0xca, 0xac, 0x6a, 0xa9, 
		0xa0, 0x1f, 0xb1, 0xff, 0xa8, 0xad, 0xb8, 0x43, 0x37, 0xfc, 0xea, 0x81, 0x32, 0x4c, 0x87, 0xa4, 
		0x3d, 0xb4, 0xb1, 0x7e, 0xa4, 0xa4, 0x8e, 0x3e, 0x09, 0x47, 0x40, 0x10, 0xe0, 0xfc, 0xab, 0x97, 
		0x2b, 0x19, 0xf3, 0x0c, 0x29, 0xe7, 0xe8, 0xd1, 0x02, 0xba, 0x9f, 0x2f, 0xe0, 0xf5, 0x99, 0x64, 
		0xa7, 0x5d, 0x37, 0x63, 0xea, 0x24, 0x68, 0xa7, 0x5b, 0x3d, 0x3c, 0x49, 0x8b, 0xa2, 0x83, 0x4a, 
		0x7e, 0x2f, 0x87, 0xcd, 0x18, 0x67, 0xa2, 0xc4, 0x77, 0x91, 0x64, 0xfc, 0xc6, 0x20, 0xdb, 0xf1, 
		0x57, 0xc9, 0x32, 0x85, 0xfb, 0x54, 0xb5, 0x0b, 0xdb, 0xa7, 0x17, 0xc2, 0x39, 0x7e, 0x78, 0x7c, 
		0xab, 0x75, 0x58, 0x45, 0xf9, 0x26, 0xab, 0xc4, 0xd3, 0xea, 0x36, 0x68, 0x80, 0x18, 0xc2, 0x6b, 
		0x3f, 0xf7, 0x65, 0x06, 0xae, 0xd2, 0x6b, 0xb9, 0x84, 0x18, 0xe4, 0xa5, 0x69, 0x73, 0x8c, 0xe9, 
		0xea, 0x85, 0x69, 0xcd, 0xa6, 0x19, 0xc9, 0xca, 0x36, 0x37, 0xab, 0x68, 0xd1, 0xec, 0xd7, 0x0b, 
		0x1c, 0x4c, 0xb2, 0x94, 0xae, 0x81, 0xe2, 0x68, 0xeb, 0x79, 0xa4, 0xe3, 0x9d, 0x76, 0x4d, 0x64, 
		0xc6, 0x4d, 0xe2, 0x01, 0xb8, 0x7d, 0x47, 0xe7, 0x56, 0x26, 0x2a, 0x34, 0xcd, 0xa9, 0xb5, 0x0d, 
		0xa9, 0xef, 0x96, 0xb9, 0xe7, 0xc6, 0xca, 0xd0, 0x05, 0x3a, 0x43, 0xad, 0x9b, 0x26, 0xc6, 0x11, 
		0x10, 0x0f, 0x7e, 0xc0, 0xa1, 0xf1, 0xf5, 0xad, 0x6a, 0xd1, 0x6e, 0x2a, 0xcc, 0x86, 0x4e, 0xb0, 
		0x38, 0x0c, 0x49, 0x8b, 0x9c, 0x2c, 0xd1, 0xac, 0xde, 0x07, 0x90, 0x0b, 0x7f, 0xa1, 0x5a, 0xaa, 
		0x1a, 0x60, 0xba, 0x8e, 0xf3, 0xbc, 0x43, 0x31, 0x3f, 0x71, 0xc8, 0x4a, 0x7c, 0x4f, 0x13, 0xc8, 
		0x7d, 0xa4, 0xcf, 0x7c, 0x63, 0x52, 0x30, 0xce, 0x83, 0xf6, 0x1b, 0x18, 0xb9, 0x49, 0xcf, 0x3d, 
		0x4b, 0xaa, 0xa9, 0x46, 0x18, 0x24, 0x4d, 0xee, 0xb5, 0x48, 0xca, 0xdb, 0x5f, 0x4d, 0xcf, 0x7c, 
		0x45, 0xb9, 0xeb, 0x3c, 0x15, 0xd8, 0x1b, 0x0c, 0x17, 0xf3, 0x8a, 0xc3, 0x49, 0x17, 0x41, 0x6c, 
		0xef, 0xab, 0xb3, 0xbf, 0x3b, 0xb7, 0x5c, 0x43, 0x30, 0x55, 0x1c, 0x65, 0x38, 0xa5, 0xde, 0x07, 
		0xda, 0x13, 0xc5, 0x41, 0xe0, 0xb7, 0x24, 0x3b, 0xd0, 0xa7, 0x57, 0x8e, 0xc9, 0x15, 0x4c, 0xdd, 
		0x67, 0xf5, 0xc2, 0xee, 0x0d, 0x94, 0x7d, 0x93, 0xa9, 0xb1, 0x3b, 0xc4, 0x20, 0xc9, 0xde, 0xfa, 
		0xd0, 0xdf, 0x6b, 0xa5, 0xc8, 0x37, 0x38, 0x18, 0x69, 0x55, 0x00, 0x51, 0xd1, 0xe3, 0xe3, 0xb7, 
		0x93, 0x1f, 0x94, 0x44, 0x00, 0x21, 0xe6, 0xc4, 0x2e, 0x85, 0x26, 0x6a, 0x06, 0x85, 0x05, 0xf7, 
		0x0a, 0xeb, 0xae, 0xa6, 0x91, 0xf9, 0x9f, 0xc6, 0x30, 0x01, 0x06, 0x28, 0x93, 0x34, 0x0c, 0x39, 
		0x6d, 0x80, 0x7d, 0x09, 0xdc, 0x44, 0xde, 0xd0, 0x4c, 0x92, 0x2f, 0x1d, 0x18, 0xa6, 0x5b, 0x27, 
		0x92, 0x8d, 0x22, 0x47, 0xd4, 0x1d, 0x21, 0x69, 0x87, 0x03, 0xbe, 0x70, 0x4f, 0x80, 0x92, 0xf5, 
		0x80, 0x87, 0x92, 0x2b, 0x8e, 0x89, 0x3e, 0x37, 0xaa, 0xda, 0x41, 0x33, 0xdc, 0x0a, 0x6c, 0x35, 
		0x78, 0x5a, 0x9f, 0xcd, 0x01, 0x8a, 0xdc, 0xa7, 0xd6, 0x9a, 0x13, 0x5e, 0x1d, 0xc0, 0xd1, 0x90, 
		0x5b, 0x36, 0xff, 0xd9, 0x56, 0xe3, 0xb8, 0xfa, 0xff, 0xe4, 0x05, 0x5d, 0x2c, 0xbb, 0x97, 0xae, 
		0xc9, 0x80, 0x13, 0x53, 0xc9, 0x88, 0x81, 0x40, 0x15, 0xc5, 0x32, 0x37, 0x69, 0x16, 0xfe, 0x03, 
		0x21, 0xa4, 0x10, 0x86, 0xb7, 0x85, 0x7c, 0x7f, 0x09, 0x58, 0xbb, 0x8a, 0xa4, 0x3f, 0xd2, 0x0a, 
		0xbe, 0x6f, 0x0d, 0xb7, 0xb2, 0x0a, 0x85, 0xc2, 0x23, 0x09, 0x5d, 0x18, 0x61, 0xb4, 0xcd, 0x5c, 
		0x0b, 0xf7, 0xac, 0x7b, 0x0a, 0xa6, 0x94, 0x92, 0x16, 0x48, 0xf8, 0xee, 0xb5, 0x65, 0x24, 0xbe, 
		0x0f, 0xe8, 0xb3, 0x99, 0xe5, 0x7f, 0x6f, 0xd2, 0x75, 0x3e, 0x78, 0xae, 0x88, 0x51, 0x49, 0x2e, 
		0x53, 0x71, 0xf7, 0x94, 0xfa, 0x55, 0x1a, 0x82, 0x5c, 0x07, 0x21, 0xe3, 0x73, 0x0d, 0x6a, 0x77, 
		0xf9, 0x97, 0xed, 0xc1, 0xe1, 0x1e, 0x20, 0x69, 0xfe, 0x13, 0xff, 0x7e, 0xb5, 0xfa, 0x10, 0x8c, 
		0xc8, 0x12, 0x5d, 0x82, 0xf7, 0xef, 0x6e, 0x21, 0xa4, 0x6a, 0xb5, 0x17, 0x48, 0x2d, 0x03, 0xb1, 
		0x5e, 0xe4, 0x39, 0x98, 0x68, 0x31, 0xf7, 0x14, 0xfc, 0x07, 0x2f, 0x4e, 0x82, 0x0c, 0xd3, 0xa2, 
		0x4f, 0x60, 0x8a, 0x87, 0xc5, 0x2b, 0xb2, 0xd4, 0xb9, 0x1c, 0xf1, 0x39, 0xe1, 0x4e, 0x23, 0x14, 
		0x74, 0xc1, 0x65, 0x4e, 0xc0, 0x48, 0xa9, 0x63, 0xaa, 0x6f, 0xd8, 0x29, 0x5f, 0x3b, 0x9c, 0x6b, 
		0xce, 0x35, 0x43, 0x3d, 0xfd, 0xc0, 0x1c, 0xd7, 0xad, 0x4d, 0x2a, 0x11, 0xf0, 0xbe, 0x94, 0x84, 
		0x34, 0xbf, 0xc9, 0x52, 0x73, 0xf3, 0x00, 0xeb, 0xdc, 0xf4, 0x22, 0xbe, 0x0f, 0x40, 0xf0, 0xfa, 
		0x41, 0x8c, 0xee, 0x7f, 0x79, 0xfa, 0x8a, 0xf9, 0x13, 0x6f, 0x08, 0xe6, 0x36, 0xcd, 0x30, 0xfe, 
		0x1a, 0xd9, 0xbb, 0xed, 0x5d, 0xe9, 0xd8, 0xd3, 0xc7, 0x93, 0xb6, 0x12, 0x18, 0x14, 0x31, 0x34, 
		0x06, 0x4b, 0x86, 0xec, 0x6a, 0x4a, 0xe9, 0x0c, 0x14, 0xd8, 0xb5, 0xd4, 0xe0, 0xf1, 0x2a, 0xe3, 
		0xb9, 0xca, 0x68, 0x28, 0x01, 0xf5, 0x64, 0x19, 0x38, 0x1d, 0x42, 0xa8, 0xd5, 0x47, 0x4f, 0x93, 
		0x94, 0x47, 0x49, 0xca, 0x54, 0x25, 0x6e, 0xe5, 0x3b, 0x03, 0xb2, 0x9e, 0x59, 0xb5, 0x33, 0x94, 
		0x86, 0x02, 0xe2, 0x9e, 0xb6, 0x64, 0xd7, 0xcd, 0x7b, 0x67, 0x45, 0x1f, 0xc5, 0x7d, 0x02, 0xe4, 
		0x5f, 0x47, 0x8a, 0xb1, 0x4d, 0xc2, 0x0f, 0x40, 0x2b, 0xf1, 0x62, 0xc9, 0x52, 0x22, 0x55, 0x7a, 
		0x0b, 0xb3, 0x0c, 0xd7, 0x15, 0x29, 0x3b, 0xd3, 0x73, 0x88, 0xa8, 0x13, 0xbd, 0xec, 0x12, 0x0a, 
		0x25, 0xfb, 0xf0, 0x3a, 0x85, 0xed, 0x56, 0xbc, 0x06, 0xe1, 0xae, 0x9c, 0x60, 0x9e, 0xac, 0x11, 
		0xd4, 0x76, 0xd0, 0x54, 0x0b, 0xcb, 0x2e, 0x25, 0x18, 0x2f, 0xa3, 0x79, 0xd0, 0xe1, 0x6e, 0xe9, 
		0x71, 0x34, 0xa6, 0x9a, 0x28, 0x87, 0xf4, 0x7b, 0x06, 0xae, 0x3f, 0x36, 0xdd, 0xdb, 0x97, 0xd7, 
		0x34, 0x07, 0x9b, 0xa1, 0xdc, 0x03, 0xe0, 0x40, 0x63, 0x1a, 0xf4, 0x67, 0x1d, 0x39, 0xcb, 0xea, 
		0xfc, 0x98, 0xa8, 0x01, 0x7c, 0x85, 0x5d, 0x23, 0x77, 0xbf, 0xe8, 0x48, 0x64, 0xe4, 0x8b, 0x9f, 
};

static int xcode_building_first_stage(struct cxdec_xcode_status *xcode)
{
  	switch (xcode_rand(xcode) % 3) {
  	case 1:
		// MOV ESI, EncryptionControlBlock
		// MOV EAX, DWORD PTR DS:[ESI+((xcode_rand(xcode) & 0x3ff) << 2)]
		if (!push_bytexcode(xcode, 0xbe)
				|| !push_dwordxcode(xcode, (DWORD)EncryptionControlBlock)
				|| !push_2bytesxcode(xcode, 0x8b, 0x86)
				|| !push_dwordxcode(xcode, (xcode_rand(xcode) & 0x3ff) << 2))
			return 0;
		break;
	case 2:
  		// MOV EAX, EDI
  		if (!push_2bytesxcode(xcode, 0x8b, 0xc7))
  			return 0;
		break;
  	case 0:
		// MOV EAX, xcode_rand(xcode)
		if (!push_bytexcode(xcode, 0xb8)
				|| !push_dwordxcode(xcode, xcode_rand(xcode)))
			return 0;
  		break;
  	}
  	return 1;
}

static int xcode_building_stage0(struct cxdec_xcode_status *xcode, int stage)
{
	if (stage == 1)
		return xcode_building_first_stage(xcode);

    if (xcode_rand(xcode) & 1) {
		if (!xcode_building_stage1(xcode, stage - 1))
			return 0;
    } else {
		if (!xcode_building_stage0(xcode, stage - 1))
			return 0;
    }

    switch (xcode_rand(xcode) & 7) {
	case 1:
		// NOT EAX
		if (!push_2bytesxcode(xcode, 0xf7, 0xd0))
			return 0;
        break;
	case 7:
		// MOV ESI, EncryptionControlBlock
		// AND EAX, 3FFh
		// MOV EAX, DWORD PTR DS:[ESI+EAX*4]
        if (!push_bytexcode(xcode, 0xbe)
  				|| !push_dwordxcode(xcode, (DWORD)EncryptionControlBlock)
				|| !push_bytexcode(xcode, 0x25)
				|| !push_dwordxcode(xcode, 0x3ff)
				|| !push_3bytesxcode(xcode, 0x8b, 0x04, 0x86))
			return 0;
        break;
	case 3:
		// DEC EAX
		if (!push_bytexcode(xcode, 0x48))
			return 0;
        break;
	case 2:
		// NEG EAX
        if (!push_2bytesxcode(xcode, 0xf7, 0xd8))
			return 0;
		break;
	case 4:
        if (xcode_rand(xcode) & 1) {
        	// ADD EAX, xcode_rand(xcode)
			if (!push_bytexcode(xcode, 0x05))
            	return 0;
        } else {
        	// SUB EAX, xcode_rand(xcode)
			if (!push_bytexcode(xcode, 0x2d))
            	return 0;
        }
        if (!push_dwordxcode(xcode, xcode_rand(xcode)))
        	return 0;
        break;
	case 0:
		// PUSH EBX
		// MOV EBX, EAX
		// AND EBX, AAAAAAAA
		// AND EAX, 55555555
		// SHR EBX, 1
		// SHL EAX, 1
		// OR EAX, EBX
		// POP EBX
		if (!push_bytexcode(xcode, 0x53)
				|| !push_2bytesxcode(xcode, 0x89, 0xc3)
				|| !push_6bytesxcode(xcode, 0x81, 0xe3, 0xaa, 0xaa, 0xaa, 0xaa)
				|| !push_5bytesxcode(xcode, 0x25, 0x55, 0x55, 0x55, 0x55)
				|| !push_2bytesxcode(xcode, 0xd1, 0xeb)
				|| !push_2bytesxcode(xcode, 0xd1, 0xe0)
				|| !push_2bytesxcode(xcode, 0x09, 0xd8)
				|| !push_bytexcode(xcode, 0x5b))
			return 0;
		break;
	case 5:
		// INC EAX
		if (!push_bytexcode(xcode, 0x40))
			return 0;
		break;
	case 6:
		// XOR EAX, xcode_rand(xcode)
		if (!push_bytexcode(xcode, 0x35) 
				|| !push_dwordxcode(xcode, xcode_rand(xcode)))
			return 0;
        break;
	}
	return 1;
}

static int xcode_building_stage1(struct cxdec_xcode_status *xcode, int stage)
{
	if (stage == 1)
		return xcode_building_first_stage(xcode);

	// PUSH EBX
	if (!push_bytexcode(xcode, 0x53))
		return 0;

	if (xcode_rand(xcode) & 1) {
		if (!xcode_building_stage1(xcode, stage - 1))
			return 0;
	} else {
		if (!xcode_building_stage0(xcode, stage - 1))
			return 0;
	}

	// MOV EBX, EAX
	if (!push_2bytesxcode(xcode, 0x89, 0xc3))
		return 0;

	if (xcode_rand(xcode) & 1) {
		if (!xcode_building_stage1(xcode, stage - 1))
			return 0;
	} else {
		if (!xcode_building_stage0(xcode, stage - 1))
			return 0;
	}

	switch (xcode_rand(xcode) % 6) {
	case 1:
		// ADD EAX, EBX
		if (!push_2bytesxcode(xcode, 0x01, 0xd8))
			return 0;
		break;
    case 3:
		// PUSH ECX
		// MOV ECX, EBX
		// AND ECX, 0F
		// SHR EAX, CL
		// POP ECX
		if (!push_bytexcode(xcode, 0x51)
				|| !push_2bytesxcode(xcode, 0x89, 0xd9)
				|| !push_3bytesxcode(xcode, 0x83, 0xe1, 0x0f)
				|| !push_2bytesxcode(xcode, 0xd3, 0xe8)
				|| !push_bytexcode(xcode, 0x59))
			return 0;
		break;
    case 4:
    	// PUSH ECX
    	// MOV ECX, EBX
    	// AND ECX, 0F
    	// SHL EAX, CL
    	// POP ECX
		if (!push_bytexcode(xcode, 0x51) 
				|| !push_2bytesxcode(xcode, 0x89, 0xd9)
				|| !push_3bytesxcode(xcode, 0x83, 0xe1, 0x0f)
				|| !push_2bytesxcode(xcode, 0xd3, 0xe0)
				|| !push_bytexcode(xcode, 0x59))
			return 0;
		break;
    case 2:
    	// NEG EAX, ADD EAX, EBX
		if (!push_2bytesxcode(xcode, 0xf7, 0xd8) 
				|| !push_2bytesxcode(xcode, 0x01, 0xd8))
			return 0;
		break;
    case 5:
    	// IMUL EAX, EBX
		if (!push_3bytesxcode(xcode, 0x0f,  0xaf, 0xc3))
			return 0;
		break;
    case 0:
    	// SUB EAX, EBX
		if (!push_2bytesxcode(xcode, 0x29, 0xd8))
			return 0;
		break;
	}
	// POP EBX
	return push_bytexcode(xcode, 0x5b);
}

struct cxdec_callback lovebattle_cxdec_callback = {
	"lovebattle",
	{ 0x101, 0x31d },
	xcode_building_stage1
};
