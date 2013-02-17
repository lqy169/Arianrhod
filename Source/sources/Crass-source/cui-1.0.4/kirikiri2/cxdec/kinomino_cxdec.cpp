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
		0x82, 0xc4, 0x82, 0xa2, 0x82, 0xdc, 0x82, 0xb7, 0x81, 0x42, 0x0a, 0x88, 0xc4, 0x93, 0xe0, 0x82, 
		0xc9, 0x8f, 0x91, 0x82, 0xa2, 0x82, 0xc4, 0x82, 0xa0, 0x82, 0xc1, 0x82, 0xbd, 0x89, 0x77, 0x82, 
		0xc5, 0x89, 0xba, 0x8e, 0xd4, 0x82, 0xb5, 0x81, 0x41, 0x83, 0x76, 0x83, 0x89, 0x83, 0x62, 0x83, 
		0x67, 0x83, 0x74, 0x83, 0x48, 0x81, 0x5b, 0x83, 0x80, 0x82, 0xc9, 0x8d, 0x7e, 0x82, 0xe8, 0x97, 
		0xa7, 0x82, 0xc2, 0x81, 0x42, 0x8f, 0xac, 0x82, 0xb3, 0x82, 0xc8, 0x91, 0xd2, 0x8d, 0x87, 0x8e, 
		0xba, 0x82, 0xaa, 0x83, 0x7c, 0x83, 0x63, 0x83, 0x8a, 0x82, 0xc6, 0x82, 0xa0, 0x82, 0xe9, 0x82, 
		0xbe, 0x82, 0xaf, 0x82, 0xcc, 0x96, 0xb3, 0x90, 0x6c, 0x89, 0x77, 0x82, 0xc5, 0x81, 0x41, 0x82, 
		0xdc, 0x82, 0xed, 0x82, 0xe8, 0x82, 0xc9, 0x90, 0x6c, 0x89, 0xc6, 0x82, 0xcd, 0x8c, 0xa9, 0x82, 
		0xa0, 0x82, 0xbd, 0x82, 0xe7, 0x82, 0xc8, 0x82, 0xa2, 0x81, 0x42, 0x0a, 0x82, 0xb1, 0x82, 0xcc, 
		0x89, 0x77, 0x82, 0xc5, 0x8d, 0x7e, 0x82, 0xe8, 0x82, 0xe9, 0x8f, 0xe6, 0x8b, 0x71, 0x82, 0xcd, 
		0x96, 0x6c, 0x88, 0xea, 0x90, 0x6c, 0x82, 0xbe, 0x82, 0xaf, 0x82, 0xe7, 0x82, 0xb5, 0x82, 0xad, 
		0x81, 0x41, 0x97, 0xf1, 0x8e, 0xd4, 0x82, 0xcd, 0x8d, 0x8c, 0x89, 0xb9, 0x82, 0xf0, 0x96, 0xc2, 
		0x82, 0xe7, 0x82, 0xb5, 0x82, 0xc8, 0x82, 0xaa, 0x82, 0xe7, 0x96, 0xfb, 0x8f, 0x4c, 0x82, 0xa2, 
		0x89, 0x8c, 0x82, 0xc6, 0x82, 0xc6, 0x82, 0xe0, 0x82, 0xc9, 0x91, 0x96, 0x82, 0xe8, 0x8b, 0x8e, 
		0x82, 0xc1, 0x82, 0xc4, 0x82, 0xa2, 0x82, 0xc1, 0x82, 0xbd, 0x81, 0x42, 0x97, 0xf1, 0x8e, 0xd4, 
		0x82, 0xcc, 0x83, 0x47, 0x83, 0x93, 0x83, 0x57, 0x83, 0x93, 0x89, 0xb9, 0x82, 0xaa, 0x8f, 0xc1, 
		0x82, 0xa6, 0x82, 0xc4, 0x82, 0xa2, 0x82, 0xad, 0x82, 0xc6, 0x81, 0x41, 0x8d, 0xa1, 0x93, 0x78, 
		0x82, 0xcd, 0x90, 0xe4, 0x82, 0xcc, 0x96, 0xc2, 0x82, 0xab, 0x90, 0xba, 0x82, 0xaa, 0x83, 0x4b, 
		0x83, 0x93, 0x83, 0x4b, 0x83, 0x93, 0x82, 0xc6, 0x93, 0xaa, 0x82, 0xc9, 0x8b, 0xbf, 0x82, 0xa2, 
		0x82, 0xc4, 0x82, 0xad, 0x82, 0xe9, 0x81, 0x42, 0x0a, 0x83, 0x6f, 0x83, 0x62, 0x83, 0x4f, 0x82, 
		0xa9, 0x82, 0xe7, 0x8e, 0x96, 0x91, 0x4f, 0x82, 0xc9, 0x92, 0xb2, 0x82, 0xd7, 0x82, 0xc4, 0x88, 
		0xf3, 0x8d, 0xfc, 0x82, 0xb5, 0x82, 0xc4, 0x82, 0xab, 0x82, 0xbd, 0x92, 0x6e, 0x90, 0x7d, 0x82, 
		0xf0, 0x88, 0xf8, 0x82, 0xc1, 0x92, 0xa3, 0x82, 0xe8, 0x8f, 0x6f, 0x82, 0xb5, 0x81, 0x41, 0x82, 
		0xa0, 0x82, 0xbd, 0x82, 0xe8, 0x82, 0xf0, 0x8c, 0xa9, 0x89, 0xf1, 0x82, 0xb7, 0x81, 0x42, 0x91, 
		0x75, 0x82, 0xe2, 0x82, 0xa9, 0x82, 0xc8, 0x8e, 0x52, 0x82, 0xcc, 0x8d, 0x81, 0x82, 0xe8, 0x82, 
		0xaa, 0x97, 0xc1, 0x82, 0xb5, 0x82, 0xa2, 0x95, 0x97, 0x82, 0xc6, 0x82, 0xc8, 0x82, 0xc1, 0x82, 
		0xc4, 0x90, 0x81, 0x82, 0xab, 0x95, 0x74, 0x82, 0xaf, 0x82, 0xc4, 0x82, 0xab, 0x82, 0xbd, 0x81, 
		0x42, 0x82, 0xa8, 0x82, 0xa8, 0x82, 0xa9, 0x82, 0xbd, 0x82, 0xcc, 0x95, 0xfb, 0x8a, 0x70, 0x82, 
		0xcc, 0x8c, 0xa9, 0x93, 0x96, 0x82, 0xcd, 0x82, 0xc2, 0x82, 0xa2, 0x82, 0xbd, 0x82, 0xaa, 0x81, 
		0x41, 0x82, 0xb5, 0x82, 0xa9, 0x82, 0xb5, 0x82, 0xa2, 0x82, 0xdc, 0x82, 0xa2, 0x82, 0xbf, 0x92, 
		0x6e, 0x90, 0x7d, 0x82, 0xc6, 0x8e, 0xc0, 0x8d, 0xdb, 0x82, 0xcc, 0x92, 0x6e, 0x8c, 0x60, 0x82, 
		0xc6, 0x82, 0xaa, 0x82, 0xa9, 0x82, 0xdd, 0x8d, 0x87, 0x82, 0xed, 0x82, 0xc8, 0x82, 0xa2, 0x81, 
		0x42, 0x82, 0xb5, 0x82, 0xce, 0x82, 0xe7, 0x82, 0xad, 0x95, 0xe0, 0x82, 0xad, 0x82, 0xb1, 0x82, 
		0xc6, 0x82, 0xc9, 0x82, 0xc8, 0x82, 0xe8, 0x82, 0xbb, 0x82, 0xa4, 0x82, 0xbe, 0x81, 0x41, 0x82, 
		0xc6, 0x82, 0xbd, 0x82, 0xdf, 0x91, 0xa7, 0x82, 0xf0, 0x82, 0xc2, 0x82, 0xab, 0x82, 0xc2, 0x82, 
		0xc2, 0x81, 0x41, 0x91, 0xd2, 0x8d, 0x87, 0x8e, 0xba, 0x82, 0xc9, 0x93, 0xfc, 0x82, 0xc1, 0x82, 
		0xbd, 0x81, 0x42, 0x0a, 0x91, 0xd2, 0x8d, 0x87, 0x8e, 0xba, 0x82, 0xcc, 0x92, 0x86, 0x82, 0xcd, 
		0x82, 0xd0, 0x82, 0xf1, 0x82, 0xe2, 0x82, 0xe8, 0x82, 0xc6, 0x82, 0xb5, 0x82, 0xc4, 0x82, 0xa2, 
		0x82, 0xc4, 0x81, 0x41, 0x90, 0xe4, 0x82, 0xcc, 0x96, 0xc2, 0x82, 0xab, 0x90, 0xba, 0x82, 0xe0, 
		0x88, 0xea, 0x92, 0x69, 0x82, 0xc6, 0x90, 0xc3, 0x82, 0xa9, 0x82, 0xc9, 0x95, 0xb7, 0x82, 0xb1, 
		0x82, 0xa6, 0x82, 0xe9, 0x81, 0x42, 0x88, 0xc3, 0x82, 0xa2, 0x8e, 0xba, 0x93, 0xe0, 0x82, 0xc9, 
		0x96, 0xda, 0x82, 0xaa, 0x82, 0xc8, 0x82, 0xea, 0x82, 0xc4, 0x82, 0xad, 0x82, 0xe9, 0x82, 0xc6, 
		0x81, 0x41, 0x92, 0xb7, 0x88, 0xd6, 0x8e, 0x71, 0x82, 0xc9, 0x8e, 0xe1, 0x82, 0xa2, 0x8f, 0x97, 
		0x90, 0xab, 0x82, 0xaa, 0x8d, 0x98, 0x8a, 0x7c, 0x82, 0xaf, 0x82, 0xc4, 0x8b, 0x8f, 0x96, 0xb0, 
		0x82, 0xe8, 0x82, 0xf0, 0x82, 0xb5, 0x82, 0xc4, 0x82, 0xa2, 0x82, 0xe9, 0x82, 0xcc, 0x82, 0xaa, 
		0x96, 0xda, 0x82, 0xc9, 0x93, 0xfc, 0x82, 0xc1, 0x82, 0xbd, 0x81, 0x42, 0x97, 0xf1, 0x8e, 0xd4, 
		0x82, 0xf0, 0x91, 0xd2, 0x82, 0xc1, 0x82, 0xc4, 0x82, 0xa2, 0x82, 0xbd, 0x82, 0xcc, 0x82, 0xbe, 
		0x82, 0xeb, 0x82, 0xa4, 0x82, 0xa9, 0x81, 0x42, 0x97, 0xf1, 0x8e, 0xd4, 0x82, 0xcd, 0x82, 0xa2, 
		0x82, 0xdc, 0x92, 0xca, 0x82, 0xe8, 0x89, 0xdf, 0x82, 0xac, 0x82, 0xc4, 0x82, 0xa2, 0x82, 0xc1, 
		0x82, 0xbd, 0x82, 0xcc, 0x82, 0xbe, 0x82, 0xaa, 0x81, 0x63, 0x81, 0x42, 0x0a, 0x89, 0x77, 0x91, 
		0x4f, 0x82, 0xcc, 0x82, 0xbf, 0x82, 0xe5, 0x82, 0xc1, 0x82, 0xc6, 0x82, 0xb5, 0x82, 0xbd, 0x92, 
		0x93, 0x8e, 0xd4, 0x8f, 0xea, 0x82, 0xc9, 0x96, 0xda, 0x82, 0xf0, 0x8c, 0xfc, 0x82, 0xaf, 0x82, 
		0xe9, 0x82, 0xc6, 0x83, 0x6f, 0x83, 0x58, 0x82, 0xaa, 0x8e, 0x7e, 0x82, 0xdc, 0x82, 0xc1, 0x82, 
		0xc4, 0x82, 0xa2, 0x82, 0xbd, 0x81, 0x42, 0x82, 0xb1, 0x82, 0xcc, 0x89, 0x77, 0x82, 0xa9, 0x82, 
		0xe7, 0x83, 0x6f, 0x83, 0x58, 0x82, 0xaa, 0x8f, 0x6f, 0x82, 0xc4, 0x82, 0xa2, 0x82, 0xe9, 0x82, 
		0xc6, 0x82, 0xcd, 0x92, 0x6d, 0x82, 0xe7, 0x82, 0xc8, 0x82, 0xa9, 0x82, 0xc1, 0x82, 0xbd, 0x82, 
		0xaa, 0x81, 0x41, 0x82, 0xe0, 0x82, 0xb5, 0x82, 0xa9, 0x82, 0xb5, 0x82, 0xbd, 0x82, 0xe7, 0x98, 
		0x48, 0x82, 0xf0, 0x8f, 0xda, 0x82, 0xb5, 0x82, 0xad, 0x8b, 0xb3, 0x82, 0xa6, 0x82, 0xc4, 0x82, 
		0xad, 0x82, 0xea, 0x82, 0xe9, 0x82, 0xa9, 0x82, 0xe0, 0x82, 0xb5, 0x82, 0xea, 0x82, 0xc8, 0x82, 
		0xa2, 0x82, 0xb5, 0x81, 0x41, 0x89, 0x5e, 0x82, 0xaa, 0x97, 0xc7, 0x82, 0xaf, 0x82, 0xea, 0x82, 
		0xce, 0x96, 0xda, 0x93, 0x49, 0x92, 0x6e, 0x82, 0xdc, 0x82, 0xc5, 0x82, 0xcc, 0x83, 0x6f, 0x83, 
		0x58, 0x82, 0xa9, 0x82, 0xe0, 0x82, 0xb5, 0x82, 0xea, 0x82, 0xc8, 0x82, 0xa2, 0x81, 0x42, 0x0a, 
		0x82, 0xbb, 0x82, 0xea, 0x82, 0xc9, 0x82, 0xb5, 0x82, 0xc4, 0x82, 0xe0, 0x81, 0x41, 0x8c, 0xbe, 
		0x82, 0xc1, 0x82, 0xc4, 0x82, 0xcd, 0x88, 0xab, 0x82, 0xa2, 0x82, 0xaa, 0x83, 0x7b, 0x83, 0x8d, 
		0x82, 0xad, 0x82, 0xb3, 0x82, 0xa2, 0x83, 0x6f, 0x83, 0x58, 0x82, 0xbe, 0x81, 0x42, 0x89, 0x98, 
		0x82, 0xa2, 0x82, 0xc6, 0x82, 0xa2, 0x82, 0xa4, 0x82, 0xed, 0x82, 0xaf, 0x82, 0xc5, 0x82, 0xcd, 
		0x82, 0xc8, 0x82, 0xa2, 0x82, 0xaa, 0x81, 0x41, 0x92, 0xb7, 0x94, 0x4e, 0x8e, 0x67, 0x82, 0xed, 
		0x82, 0xea, 0x82, 0xc4, 0x82, 0xab, 0x82, 0xbd, 0x82, 0xf1, 0x82, 0xbe, 0x82, 0xeb, 0x82, 0xa4, 
		0x82, 0xc8, 0x81, 0x41, 0x82, 0xc6, 0x82, 0xa2, 0x82, 0xa4, 0x8a, 0xb4, 0x82, 0xb6, 0x82, 0xf0, 
		0x8e, 0xf3, 0x82, 0xaf, 0x82, 0xe9, 0x81, 0x42, 0x89, 0x5e, 0x93, 0x5d, 0x91, 0xe4, 0x82, 0xc9, 
		0x82, 0xcd, 0x90, 0x6c, 0x82, 0xcc, 0x97, 0xc7, 0x82, 0xb3, 0x82, 0xbb, 0x82, 0xa4, 0x82, 0xc8, 
		0x98, 0x56, 0x90, 0x6c, 0x82, 0xaa, 0x8d, 0xc0, 0x82, 0xc1, 0x82, 0xc4, 0x82, 0xa2, 0x82, 0xbd, 
		0x81, 0x42, 0x0a, 0x96, 0x6c, 0x82, 0xaa, 0x81, 0x75, 0x82, 0xa0, 0x82, 0xcc, 0x81, 0x5b, 0x81, 
		0x76, 0x82, 0xc6, 0x90, 0xba, 0x82, 0xf0, 0x82, 0xa9, 0x82, 0xaf, 0x82, 0xe9, 0x82, 0xc6, 0x81, 
		0x41, 0x94, 0xde, 0x82, 0xcd, 0x89, 0x5e, 0x93, 0x5d, 0x91, 0xe4, 0x82, 0xa9, 0x82, 0xe7, 0x90, 
		0x67, 0x82, 0xf0, 0x8f, 0xe6, 0x82, 0xe8, 0x8f, 0x6f, 0x82, 0xb5, 0x82, 0xc4, 0x81, 0x75, 0x92, 
		0x42, 0x95, 0x76, 0x82, 0xb3, 0x82, 0xf1, 0x82, 0xa9, 0x82, 0xa6, 0x81, 0x48, 0x81, 0x76, 0x82, 
		0xc6, 0x96, 0x6c, 0x82, 0xcc, 0x96, 0xbc, 0x91, 0x4f, 0x82, 0xf0, 0x82, 0xa2, 0x82, 0xa2, 0x81, 
		0x41, 0x83, 0x47, 0x83, 0x93, 0x83, 0x57, 0x83, 0x93, 0x82, 0xf0, 0x82, 0xa9, 0x82, 0xaf, 0x82, 
		0xbd, 0x81, 0x42, 0x0a, 0x96, 0x6c, 0x82, 0xcd, 0x8b, 0xc1, 0x82, 0xa2, 0x82, 0xc4, 0x81, 0x75, 
		0x82, 0xa6, 0x81, 0x48, 0x82, 0xc8, 0x82, 0xf1, 0x82, 0xc5, 0x96, 0x6c, 0x82, 0xcc, 0x96, 0xbc, 
		0x91, 0x4f, 0x82, 0xf0, 0x92, 0x6d, 0x82, 0xc1, 0x82, 0xc4, 0x82, 0xe9, 0x82, 0xf1, 0x82, 0xc5, 
		0x82, 0xb7, 0x82, 0xa9, 0x81, 0x48, 0x81, 0x76, 0x82, 0xc6, 0x90, 0x75, 0x82, 0xad, 0x82, 0xc6, 
		0x81, 0x41, 0x94, 0xde, 0x82, 0xcd, 0x81, 0x75, 0x94, 0xfc, 0x97, 0x44, 0x82, 0xbf, 0x82, 0xe1, 
		0x82, 0xf1, 0x82, 0xcd, 0x82, 0xc7, 0x82, 0xa4, 0x82, 0xb7, 0x82, 0xbd, 0x81, 0x48, 0x81, 0x76, 
		0x82, 0xc6, 0x96, 0x6c, 0x82, 0xc9, 0x90, 0x75, 0x82, 0xab, 0x95, 0xd4, 0x82, 0xb7, 0x81, 0x42, 
		0x0a, 0x81, 0x75, 0x82, 0xa0, 0x81, 0x41, 0x81, 0x76, 0x82, 0xc6, 0x96, 0x6c, 0x82, 0xcd, 0x91, 
		0xd2, 0x8d, 0x87, 0x8e, 0xba, 0x82, 0xc9, 0x88, 0xf8, 0x82, 0xab, 0x95, 0xd4, 0x82, 0xb7, 0x81, 
		0x42, 0x82, 0xdc, 0x82, 0xb3, 0x82, 0xa9, 0x82, 0xa0, 0x82, 0xcc, 0x8f, 0x97, 0x90, 0xab, 0x81, 
		0x63, 0x8b, 0x7b, 0x8e, 0xc0, 0x82, 0xb3, 0x82, 0xf1, 0x81, 0x48, 0x0a, 0x91, 0xd2, 0x8d, 0x87, 
		0x8e, 0xba, 0x82, 0xc5, 0x82, 0xa2, 0x82, 0xdc, 0x82, 0xbe, 0x83, 0x52, 0x83, 0x4e, 0x83, 0x8a, 
		0x83, 0x52, 0x83, 0x4e, 0x83, 0x8a, 0x82, 0xc6, 0x8b, 0x8f, 0x96, 0xb0, 0x82, 0xe8, 0x82, 0xf0, 
		0x82, 0xb5, 0x82, 0xc4, 0x82, 0xa2, 0x82, 0xe9, 0x94, 0xde, 0x8f, 0x97, 0x82, 0xcc, 0x91, 0x4f, 
		0x82, 0xc9, 0x97, 0xa7, 0x82, 0xbf, 0x81, 0x41, 0x8b, 0xfc, 0x82, 0xf1, 0x82, 0xc5, 0x81, 0x75, 
		0x8b, 0x7b, 0x8e, 0xc0, 0x82, 0xb3, 0x82, 0xf1, 0x81, 0x48, 0x81, 0x76, 0x82, 0xc6, 0x90, 0xba, 
		0x82, 0xf0, 0x82, 0xa9, 0x82, 0xaf, 0x82, 0xbd, 0x81, 0x42, 0x82, 0xb3, 0x82, 0xc1, 0x82, 0xab, 
		0x82, 0xcd, 0x8b, 0x43, 0x82, 0xc3, 0x82, 0xa9, 0x82, 0xc8, 0x82, 0xa9, 0x82, 0xc1, 0x82, 0xbd, 
		0x82, 0xaa, 0x81, 0x41, 0x82, 0xbd, 0x82, 0xb5, 0x82, 0xa9, 0x82, 0xc9, 0x8b, 0x7b, 0x8e, 0xc0, 
		0x82, 0xb3, 0x82, 0xf1, 0x82, 0xbe, 0x81, 0x42, 0x94, 0xde, 0x8f, 0x97, 0x82, 0xcd, 0x96, 0x6c, 
		0x82, 0xcc, 0x8c, 0xbe, 0x97, 0x74, 0x82, 0xc9, 0x8a, 0xe7, 0x82, 0xf0, 0x82, 0xa0, 0x82, 0xb0, 
		0x81, 0x41, 0x96, 0x6c, 0x82, 0xcc, 0x8a, 0xe7, 0x82, 0xf0, 0x82, 0xb5, 0x82, 0xce, 0x82, 0xe7, 
		0x82, 0xad, 0x8c, 0xa9, 0x82, 0xc4, 0x82, 0xa2, 0x82, 0xbd, 0x82, 0xaa, 0x81, 0x41, 0x82, 0xa2, 
		0x82, 0xab, 0x82, 0xc8, 0x82, 0xe8, 0x8b, 0x43, 0x82, 0xc3, 0x82, 0xa2, 0x82, 0xbd, 0x82, 0xe6, 
		0x82, 0xa4, 0x82, 0xc9, 0x81, 0x75, 0x82, 0xa0, 0x81, 0x41, 0x92, 0x42, 0x95, 0x76, 0x8c, 0x4e, 
		0x81, 0x48, 0x81, 0x76, 0x82, 0xc6, 0x8c, 0xbe, 0x97, 0x74, 0x82, 0xf0, 0x94, 0xad, 0x82, 0xb5, 
		0x81, 0x41, 0x82, 0xbb, 0x82, 0xb5, 0x82, 0xc4, 0x82, 0xc9, 0x82, 0xc1, 0x82, 0xb1, 0x82, 0xe8, 
		0x82, 0xc6, 0x8f, 0xce, 0x82, 0xc1, 0x82, 0xbd, 0x81, 0x42, 0x0a, 0xb8, 0x64, 0x06, 0xdc, 0x18, 
		0x8d, 0xcf, 0xe1, 0xb4, 0x58, 0xa4, 0xb8, 0xfb, 0x27, 0x49, 0x63, 0x79, 0x71, 0x78, 0x16, 0x22, 
		0x05, 0xc2, 0x0c, 0x4b, 0xd5, 0x6d, 0x97, 0x93, 0xa6, 0xc7, 0x3e, 0x20, 0x4c, 0x1d, 0xa9, 0x54, 
		0x22, 0xed, 0xca, 0x27, 0x19, 0x1e, 0x6b, 0x5f, 0xc9, 0x4c, 0x56, 0x19, 0xcb, 0x9a, 0x0c, 0x09, 
		0xd9, 0x09, 0x95, 0xf2, 0x91, 0xcc, 0x0f, 0x54, 0x6e, 0x4c, 0x66, 0xcc, 0xb2, 0xb7, 0x02, 0x7f, 
		0x8f, 0x54, 0xa5, 0xad, 0xce, 0x33, 0x2d, 0x92, 0x4a, 0x06, 0x24, 0x94, 0xa4, 0x29, 0x05, 0x5b, 
		0xf0, 0x33, 0xfb, 0x2f, 0x18, 0xcb, 0xf4, 0x13, 0xd0, 0x59, 0x47, 0x4d, 0x45, 0xfd, 0xd9, 0x64, 
		0x38, 0x13, 0x0a, 0x59, 0x13, 0x65, 0xa5, 0x1e, 0x7c, 0x31, 0x4d, 0x51, 0x28, 0x4f, 0xbc, 0x65, 
		0x58, 0xa6, 0x7f, 0xe7, 0x35, 0xae, 0xfc, 0x19, 0x17, 0x3c, 0x48, 0xcd, 0x4e, 0x1f, 0xa5, 0xce, 
		0x85, 0x63, 0x65, 0xda, 0xdd, 0x8a, 0x1d, 0x33, 0x45, 0x2f, 0x90, 0x0b, 0x48, 0xad, 0x12, 0x04, 
		0xb5, 0xda, 0x37, 0x98, 0xf2, 0x7c, 0xda, 0x09, 0x14, 0x44, 0x14, 0xca, 0x96, 0x8c, 0x1f, 0xe0, 
		0x73, 0x4e, 0x09, 0x18, 0xb2, 0xcf, 0xf7, 0x81, 0x5d, 0xe2, 0xc6, 0x02, 0xb7, 0xb5, 0x7d, 0xbc, 
		0x2c, 0x4c, 0x1f, 0x11, 0x02, 0x25, 0x07, 0xe3, 0x98, 0xe9, 0xec, 0x43, 0x3a, 0x8c, 0x16, 0x1d, 
		0xd2, 0x23, 0x8a, 0x99, 0x6e, 0xa0, 0x13, 0x90, 0x94, 0xb0, 0xd5, 0x77, 0xcd, 0xff, 0x71, 0x56, 
		0x68, 0x8b, 0x76, 0xa6, 0xb9, 0x28, 0x11, 0x84, 0x0d, 0x25, 0x54, 0x8c, 0x7e, 0x39, 0x6d, 0xe0, 
		0x07, 0x33, 0x80, 0xff, 0xff, 0xc2, 0xfa, 0xf9, 0x3a, 0x26, 0x3f, 0x7f, 0x38, 0xf9, 0xbf, 0x9a, 
		0x29, 0xbe, 0x7f, 0xae, 0xb2, 0x0c, 0x19, 0x45, 0x2d, 0x73, 0xa2, 0xdf, 0x67, 0xbf, 0x19, 0x86, 
		0xca, 0xe5, 0xd9, 0x07, 0xa9, 0x4c, 0xc9, 0x9b, 0x24, 0xa4, 0xc2, 0x98, 0x56, 0x51, 0x84, 0xb9, 
		0x7f, 0xd9, 0xcf, 0x54, 0x48, 0x66, 0xd5, 0x09, 0xc8, 0x75, 0x94, 0x49, 0x3f, 0x32, 0x25, 0x3f, 
		0x68, 0xb4, 0x54, 0xac, 0xf4, 0x17, 0xcc, 0x18, 0x3d, 0x4d, 0xa6, 0x8f, 0x5b, 0x0c, 0xb6, 0x67, 
		0x12, 0x7d, 0xd3, 0x5a, 0x2c, 0x67, 0x8d, 0xb0, 0x01, 0x21, 0xa9, 0x5a, 0x73, 0x67, 0x2e, 0x51, 
		0xb2, 0xec, 0x07, 0x01, 0xa8, 0x54, 0x68, 0xa4, 0xc0, 0x48, 0x84, 0x37, 0xa0, 0x02, 0x4d, 0x18, 
		0xdb, 0x49, 0x47, 0x42, 0x24, 0x3c, 0x1f, 0x44, 0x90, 0xb1, 0xe4, 0xa7, 0xc7, 0xa8, 0xe8, 0xc6, 
		0xfc, 0x82, 0x5a, 0x6c, 0x36, 0x05, 0x25, 0x9c, 0x82, 0x4f, 0xca, 0x67, 0x8f, 0x1c, 0xd4, 0x6a, 
		0xeb, 0x90, 0xf2, 0x72, 0xc9, 0x2e, 0xad, 0xf4, 0x31, 0x62, 0x1d, 0xc8, 0x7f, 0x93, 0xca, 0xea, 
		0xaf, 0xec, 0x0b, 0x57, 0x62, 0x71, 0x8d, 0x1f, 0x26, 0xb5, 0x3a, 0xc8, 0x1c, 0x5f, 0xfd, 0x0c, 
		0x23, 0xbb, 0x56, 0xb9, 0x79, 0x93, 0xdb, 0x9d, 0x23, 0x04, 0x00, 0x2a, 0x78, 0xe9, 0x4c, 0x1e, 
		0x06, 0xd5, 0x5b, 0x2e, 0xf0, 0x32, 0x6f, 0x4a, 0x67, 0x99, 0x69, 0x9c, 0xb7, 0x4b, 0xfc, 0xf0, 
		0x79, 0x97, 0xe1, 0x55, 0x52, 0x98, 0x72, 0xe3, 0xba, 0xcd, 0x0d, 0x1d, 0x8e, 0x41, 0x8c, 0xe7, 
		0x53, 0x79, 0xcd, 0x34, 0x3e, 0x88, 0x30, 0xa9, 0xd0, 0xc5, 0xc1, 0x62, 0x3b, 0xfa, 0x48, 0x4e, 
		0x6a, 0x05, 0x51, 0x89, 0x1b, 0xc0, 0xd1, 0x8f, 0x1c, 0x88, 0x98, 0x48, 0x72, 0xf5, 0xc0, 0x60, 
		0xba, 0x7c, 0x7b, 0x0d, 0x2a, 0x07, 0x45, 0xc3, 0x86, 0x86, 0x80, 0x32, 0x12, 0x16, 0xef, 0x70, 
		0x72, 0xe7, 0x28, 0x7e, 0xee, 0xcf, 0xd8, 0x7e, 0x87, 0x81, 0xf9, 0xd1, 0xfb, 0x32, 0x1a, 0xe4, 
		0xf4, 0x15, 0x91, 0xb4, 0xe6, 0x03, 0xbb, 0xe6, 0xad, 0x58, 0xb8, 0xc6, 0x9e, 0x51, 0x10, 0xf7, 
		0x25, 0x38, 0xfe, 0xb0, 0x66, 0xdc, 0xbd, 0xcf, 0x88, 0x19, 0xca, 0x66, 0x45, 0xfb, 0xa7, 0x96, 
		0xbe, 0xfd, 0x51, 0xa7, 0xca, 0xda, 0xb1, 0x86, 0x6e, 0x51, 0x7f, 0x70, 0xd0, 0x6c, 0xdf, 0x05, 
		0x68, 0x83, 0xfc, 0x9d, 0xb6, 0xd7, 0xb9, 0xb6, 0x44, 0x47, 0x0c, 0x07, 0xab, 0x95, 0x74, 0xa9, 
		0xd6, 0x83, 0x0e, 0x68, 0x72, 0x29, 0x59, 0x27, 0x08, 0x66, 0x2e, 0xbe, 0x03, 0x43, 0xa6, 0x91, 
		0x38, 0x59, 0x63, 0x99, 0xe0, 0xef, 0x98, 0x8c, 0x32, 0x03, 0x94, 0x18, 0x61, 0x9a, 0xa3, 0x28, 
		0x63, 0xd9, 0x33, 0x4a, 0x3b, 0xe3, 0x7c, 0x95, 0x8a, 0xa4, 0x82, 0xd9, 0x11, 0x2e, 0xf0, 0xf5, 
		0x60, 0x5e, 0xb5, 0x8d, 0x81, 0xa8, 0xce, 0xee, 0xde, 0x0c, 0x77, 0x85, 0xac, 0xf8, 0xfb, 0xa0, 
		0x1d, 0xc7, 0xec, 0x89, 0x5a, 0x9e, 0xa6, 0x2d, 0x9c, 0x9a, 0x90, 0xbc, 0xdc, 0x20, 0xce, 0x63, 
		0xc6, 0x4b, 0xc7, 0x23, 0xb3, 0x2d, 0x4e, 0x2a, 0x58, 0x70, 0xe3, 0x76, 0x27, 0x31, 0xc7, 0x71, 
		0x80, 0xc6, 0x37, 0xe3, 0x14, 0x48, 0x63, 0x22, 0x36, 0xec, 0xaa, 0x66, 0xd6, 0x1b, 0x73, 0x0c, 
		0xcf, 0x5c, 0xd7, 0x1c, 0x68, 0xfa, 0x52, 0xb4, 0xb2, 0xe8, 0x97, 0xbf, 0xaf, 0xdc, 0x15, 0x11, 
		0x5d, 0x54, 0xfd, 0xd7, 0x05, 0x0d, 0x9a, 0x2a, 0xe6, 0xd1, 0x3d, 0x58, 0x97, 0xf6, 0xa9, 0x79, 
		0xe6, 0xe1, 0xe1, 0x0a, 0x66, 0x50, 0xa8, 0x27, 0x95, 0xfc, 0xe7, 0x74, 0xe7, 0x10, 0x85, 0x08, 
		0x49, 0x15, 0xe5, 0x0e, 0xdc, 0xf1, 0xfe, 0x4e, 0xbf, 0x84, 0x75, 0xe9, 0x0f, 0xe0, 0x3a, 0x43, 
		0x09, 0x8e, 0x69, 0xd6, 0x74, 0xf5, 0x30, 0x1c, 0xfc, 0xfa, 0x6b, 0x2d, 0x93, 0xfe, 0xd0, 0x84, 
		0x6b, 0xfe, 0x1b, 0x70, 0x1d, 0x4b, 0x1f, 0xad, 0x54, 0x55, 0x84, 0x54, 0xd9, 0x47, 0x49, 0x4b, 
		0x09, 0xad, 0xc6, 0x7d, 0xc0, 0x70, 0xe0, 0xb6, 0x76, 0x33, 0x8d, 0xe6, 0xa0, 0xe6, 0xc0, 0x78, 
		0xd0, 0x4b, 0x21, 0xe9, 0x5d, 0xb6, 0xd8, 0x79, 0x1f, 0xf6, 0x3e, 0xa8, 0xeb, 0x6e, 0x79, 0x02, 
		0x50, 0x0a, 0x22, 0xbb, 0x0c, 0x1e, 0xc0, 0x97, 0x18, 0x8c, 0x20, 0xf1, 0x3a, 0x5e, 0xb1, 0x07, 
		0x8b, 0x87, 0x4b, 0xcd, 0x3a, 0x20, 0x60, 0x3a, 0x30, 0x30, 0xe0, 0xf7, 0xdd, 0x6f, 0x01, 0xb2, 
		0x96, 0xb5, 0x7c, 0x66, 0x8d, 0x00, 0x70, 0x08, 0x77, 0xff, 0xb5, 0x23, 0x53, 0xd2, 0x49, 0xf9, 
		0xad, 0x99, 0x73, 0xc2, 0xd0, 0x4e, 0xec, 0x77, 0x55, 0xcf, 0x67, 0xd9, 0xdb, 0xf3, 0xc0, 0xa4, 
		0xaa, 0x91, 0xd8, 0x26, 0x09, 0x6d, 0xd0, 0xf5, 0x90, 0x09, 0xe5, 0xa3, 0xb3, 0x6e, 0xab, 0x3e, 
		0x2f, 0x24, 0x34, 0xf0, 0xa3, 0x44, 0x47, 0x10, 0xb7, 0xe1, 0xd4, 0xb7, 0x17, 0x3f, 0x94, 0x78, 
		0x2f, 0x29, 0x7b, 0x75, 0xb1, 0x7c, 0xc4, 0xce, 0x43, 0x3c, 0x9c, 0xaf, 0xb2, 0x64, 0xa2, 0xc5, 
		0xa1, 0xa4, 0x0f, 0xd5, 0xcb, 0xdf, 0xe2, 0x77, 0xbd, 0xfa, 0x7c, 0x91, 0x41, 0x91, 0xa3, 0x61, 
		0x5c, 0x89, 0x10, 0xe5, 0x34, 0x1a, 0x56, 0x89, 0x74, 0x0b, 0x19, 0x47, 0x7e, 0x7a, 0x0e, 0x06, 
		0x80, 0xe7, 0xdb, 0x04, 0x53, 0x9c, 0xb0, 0x31, 0x65, 0x40, 0x8a, 0x29, 0xf4, 0x45, 0xa3, 0xa5, 
		0xeb, 0xf0, 0x18, 0xc8, 0xc7, 0x89, 0xa5, 0x1b, 0x09, 0x03, 0x21, 0x00, 0x0b, 0x5a, 0x4e, 0x77, 
		0x61, 0x4f, 0x2e, 0xd1, 0xd8, 0x51, 0xe7, 0x9a, 0x91, 0xc0, 0x2d, 0x55, 0x5b, 0xc5, 0xe3, 0xe2, 
		0x99, 0x33, 0x53, 0x85, 0xb4, 0x4d, 0x4f, 0xd2, 0x7e, 0xb0, 0x3a, 0x42, 0x8d, 0xf3, 0x9c, 0x35, 
		0x3e, 0xd3, 0x06, 0xa6, 0x5f, 0x92, 0xd3, 0x0f, 0xa8, 0x99, 0x54, 0x10, 0x17, 0x82, 0x41, 0xb4, 
		0xbb, 0x0a, 0x99, 0x5a, 0x17, 0x3e, 0x4d, 0xdd, 0x22, 0x32, 0xd0, 0x4a, 0x5f, 0xf4, 0x00, 0x84, 
		0x62, 0xed, 0xb5, 0x41, 0x6e, 0xfc, 0x53, 0xc2, 0x10, 0x6f, 0xd6, 0xea, 0xda, 0x2f, 0xb2, 0x10, 
		0xf6, 0xc3, 0xd4, 0x04, 0xa1, 0x0b, 0x95, 0x42, 0xda, 0xc1, 0x74, 0x6a, 0xaf, 0xf6, 0x59, 0xd8, 
		0x2e, 0xab, 0xfe, 0x33, 0x60, 0x3b, 0x0c, 0xfb, 0xca, 0x78, 0xde, 0xb4, 0x3f, 0x55, 0xbf, 0x7d, 
		0x06, 0xfb, 0x84, 0x98, 0xd8, 0x24, 0x36, 0x88, 0x8e, 0x14, 0x3a, 0xb4, 0x2e, 0xd3, 0x89, 0x69, 
		0x88, 0x31, 0x79, 0x24, 0xe7, 0x96, 0x23, 0xc2, 0x24, 0x81, 0x57, 0x86, 0x60, 0x9d, 0x34, 0xc7, 
		0x77, 0x2b, 0xbb, 0x3f, 0x54, 0xcd, 0x61, 0x8b, 0x27, 0x2b, 0x78, 0x53, 0xa4, 0xa5, 0xb7, 0x96, 
		0xd7, 0xa4, 0x25, 0xfb, 0xb1, 0x50, 0x63, 0x66, 0x07, 0x58, 0xc6, 0x89, 0xdd, 0x0b, 0x61, 0x4a, 
		0x6e, 0x88, 0xa0, 0x62, 0x03, 0x20, 0x4c, 0x3c, 0x75, 0x53, 0x1c, 0xc3, 0x5a, 0xf2, 0x6b, 0x4e, 
		0x98, 0xbe, 0x43, 0xb6, 0x89, 0x47, 0xaf, 0xc9, 0xab, 0xe1, 0x3e, 0x8d, 0xea, 0xe1, 0xba, 0x3d, 
		0x11, 0xa0, 0x1f, 0x82, 0x96, 0x7a, 0x6f, 0x4f, 0x5e, 0x06, 0xa3, 0x85, 0x6d, 0xce, 0x56, 0xc8, 
		0x1a, 0x1f, 0x16, 0xa8, 0x07, 0x68, 0x65, 0x71, 0x5d, 0x14, 0xeb, 0xa5, 0x5f, 0xb6, 0x48, 0x55, 
		0x09, 0xd2, 0x24, 0xf3, 0x81, 0x8b, 0x58, 0xbc, 0x86, 0x8b, 0xa4, 0xeb, 0xa0, 0xd4, 0xaa, 0x4c, 
		0x44, 0xf8, 0xb7, 0xa6, 0xdd, 0xf6, 0xc1, 0x78, 0x70, 0x6c, 0x88, 0x65, 0x6a, 0x77, 0x96, 0x1d, 
		0x17, 0xc5, 0x74, 0xdc, 0xdd, 0xa7, 0xa8, 0x0d, 0x6c, 0xf1, 0xf5, 0xb1, 0xfa, 0xb0, 0xdc, 0xf8, 
		0xfe, 0x01, 0x93, 0x59, 0xbc, 0x89, 0xca, 0x3d, 0xb8, 0x77, 0xea, 0x4b, 0xe9, 0x54, 0x86, 0x35, 
		0xcb, 0x1f, 0xa5, 0xf9, 0x99, 0x7a, 0x14, 0x75, 0x1d, 0x48, 0xf2, 0x13, 0xc3, 0x27, 0x77, 0xed, 
		0x33, 0x33, 0x6c, 0x80, 0xab, 0xfb, 0xe3, 0x62, 0x6f, 0xdb, 0x26, 0x55, 0x90, 0x50, 0xcb, 0x4f, 
		0xcd, 0x9c, 0xa2, 0x49, 0x23, 0xef, 0x66, 0x38, 0xfe, 0x36, 0x19, 0x8f, 0xea, 0xfb, 0xc9, 0x1f, 
		0x34, 0x8d, 0xd5, 0x9b, 0x57, 0xfb, 0x3d, 0x1c, 0xb3, 0x3d, 0xd4, 0xc3, 0xb8, 0xc4, 0xee, 0xc3, 
		0x17, 0xde, 0x2a, 0xe1, 0x03, 0x78, 0xfa, 0x5d, 0xb6, 0x74, 0xd1, 0xce, 0xb2, 0x09, 0x24, 0xe8, 
		0xb6, 0x21, 0x37, 0x41, 0xad, 0xdb, 0xe1, 0x47, 0xa6, 0x5a, 0x63, 0xff, 0xcc, 0x4c, 0x7c, 0xae, 
		0x38, 0x99, 0x4f, 0xa7, 0xc1, 0x17, 0x74, 0x31, 0x00, 0x8f, 0xc0, 0xb6, 0x5f, 0x3e, 0xff, 0xf6, 
		0x73, 0xe5, 0xd0, 0x5b, 0x61, 0xc4, 0x59, 0xcf, 0x1d, 0x50, 0x15, 0x01, 0x3e, 0xd6, 0xc3, 0xdc, 
		0x43, 0x86, 0xa9, 0x89, 0x39, 0x38, 0x77, 0x93, 0xad, 0x6a, 0x12, 0x33, 0xcd, 0x5b, 0x65, 0xf9, 
		0x25, 0x65, 0x61, 0x26, 0x7a, 0x51, 0x75, 0xe8, 0xbf, 0xd4, 0x80, 0x0a, 0x00, 0xf7, 0x2a, 0xc1, 
		0x4d, 0xa1, 0x91, 0xc3, 0xed, 0x87, 0xcc, 0xb9, 0x4e, 0x29, 0xf8, 0x17, 0xd9, 0x77, 0xe1, 0x28, 
		0x1e, 0xae, 0xed, 0xf6, 0x12, 0xde, 0x97, 0x08, 0x5e, 0x1d, 0x8c, 0x9b, 0xea, 0x98, 0x27, 0xf5, 
		0x51, 0x38, 0x47, 0x7b, 0x22, 0x74, 0x52, 0xd9, 0x9d, 0xc6, 0x64, 0x86, 0x35, 0x6c, 0x29, 0x39, 
		0xb3, 0x62, 0xde, 0xde, 0x9a, 0x31, 0x38, 0xb8, 0x89, 0x26, 0xf8, 0xcc, 0xea, 0xe4, 0xc7, 0xc4, 
		0xae, 0x43, 0xde, 0x5b, 0xe1, 0x55, 0x68, 0x81, 0xa5, 0x0e, 0xad, 0x2a, 0x37, 0xe7, 0x82, 0xbc, 
		0x89, 0xba, 0xf1, 0x89, 0xc4, 0x9e, 0xe2, 0x57, 0x96, 0xef, 0x08, 0x55, 0x5e, 0x0c, 0xaa, 0xbb, 
		0xc8, 0x3a, 0x2c, 0x49, 0x86, 0xc3, 0x46, 0x9f, 0xa6, 0x63, 0x51, 0x2f, 0xfb, 0x6b, 0x66, 0x9f, 
		0x71, 0xee, 0x25, 0xf5, 0x86, 0x52, 0x35, 0x47, 0x2e, 0x8a, 0xbd, 0x88, 0x3a, 0x82, 0x05, 0x0d, 
		0x02, 0x17, 0x1d, 0xd9, 0x84, 0x19, 0xa4, 0x79, 0xe2, 0x3a, 0x50, 0x94, 0x5b, 0x3d, 0xe2, 0xab, 
		0x7a, 0x4c, 0x11, 0x72, 0xfb, 0xcd, 0xe4, 0x3e, 0xdf, 0xef, 0x84, 0x75, 0xd9, 0x8e, 0x20, 0x84, 
		0x5a, 0x7c, 0x5e, 0xdf, 0x1e, 0x1b, 0xcd, 0xd7, 0x80, 0x0d, 0x6c, 0x3f, 0x8d, 0xf7, 0xab, 0x27, 
		0xf8, 0x39, 0x0d, 0xe8, 0xe4, 0x4f, 0xb6, 0xd5, 0x4b, 0x2a, 0x1b, 0xf6, 0x93, 0x1d, 0x57, 0xf8, 
		0x4d, 0x5d, 0x73, 0x2f, 0x2f, 0x4c, 0xb7, 0x55, 0x8e, 0xe8, 0xcd, 0x9a, 0x55, 0x07, 0x75, 0xb0, 
		0x94, 0x99, 0xf5, 0x7e, 0xc4, 0x21, 0x38, 0xfd, 0xd6, 0xca, 0x02, 0x70, 0xcb, 0x6f, 0x4c, 0x9b, 
		0x5d, 0x73, 0x42, 0x87, 0xe2, 0xf5, 0xd4, 0x22, 0x1b, 0x6e, 0x70, 0x4f, 0xcd, 0xa0, 0x3c, 0xf8, 
		0x8a, 0x67, 0x4a, 0x74, 0xe0, 0x1b, 0xf7, 0xa6, 0xbc, 0x72, 0xd1, 0x78, 0xf4, 0x07, 0x20, 0x1d, 
		0xf0, 0xfa, 0x77, 0x77, 0xaa, 0xc3, 0xde, 0xb4, 0xb8, 0x43, 0x44, 0x30, 0xa3, 0x45, 0x8d, 0xf4, 
		0xea, 0xb3, 0xf2, 0x5b, 0xd4, 0x80, 0xd7, 0x47, 0xf8, 0xdb, 0x2f, 0x5d, 0xa4, 0xbd, 0x9e, 0x88, 
		0xd3, 0xc2, 0x40, 0x92, 0x3b, 0x76, 0x22, 0xc3, 0x90, 0xa1, 0x0c, 0x53, 0x5a, 0xa3, 0x8b, 0x2c, 
		0x5b, 0x5c, 0x15, 0xc8, 0x4f, 0xd1, 0x8f, 0xda, 0x9d, 0x8e, 0xdc, 0xf6, 0xcb, 0xbe, 0x22, 0x76, 
		0x53, 0x30, 0x20, 0xf0, 0x1e, 0xd6, 0x02, 0x99, 0x1c, 0xd7, 0x72, 0x4e, 0xb8, 0x37, 0xec, 0x80, 
		0x52, 0x9d, 0x5f, 0x25, 0x55, 0x54, 0x2c, 0x7c, 0x20, 0x6e, 0x59, 0x7e, 0x87, 0x79, 0xbb, 0x46, 
		0x42, 0xfc, 0x6e, 0xfb, 0x70, 0x37, 0xf2, 0x28, 0xed, 0xb4, 0xe0, 0x9e, 0xc7, 0xc2, 0xfa, 0x4e, 
		0xdf, 0x6c, 0x52, 0xbf, 0xac, 0xb5, 0x0b, 0xf1, 0x7b, 0x9a, 0xac, 0xb5, 0xcb, 0x32, 0x0e, 0x1c, 
		0x88, 0x33, 0x53, 0x85, 0x22, 0x5a, 0x7d, 0x74, 0xe5, 0x1e, 0xc7, 0x16, 0x64, 0x8c, 0x14, 0x4c, 
		0x91, 0x1b, 0x42, 0x6a, 0x5f, 0xe3, 0x61, 0x7e, 0x2b, 0x0c, 0xaf, 0x9a, 0xb1, 0x02, 0x63, 0x2e, 
		0xde, 0x25, 0x50, 0xb1, 0xb9, 0xc0, 0x3f, 0xc5, 0xfd, 0x10, 0x69, 0x09, 0x01, 0xeb, 0x2c, 0xc5, 
		0xfc, 0xc9, 0xd8, 0xe9, 0x4e, 0x10, 0xe4, 0x6e, 0x42, 0x8f, 0x8f, 0x58, 0xe3, 0xc3, 0x88, 0xd7, 
		0x14, 0x76, 0xb7, 0xa6, 0x0f, 0xdc, 0x9b, 0x28, 0x30, 0x54, 0xdf, 0x9f, 0x65, 0xa1, 0x47, 0x93, 
		0xc9, 0x2f, 0x43, 0x66, 0xea, 0x53, 0x11, 0x8f, 0x25, 0x34, 0x4e, 0xa7, 0x93, 0x25, 0x0a, 0x88, 
		0xfc, 0x9f, 0xdf, 0x90, 0x90, 0x76, 0xf3, 0xba, 0xfe, 0x10, 0x15, 0x17, 0x69, 0x2e, 0x32, 0x6a, 
		0x74, 0x96, 0xef, 0xf1, 0xfc, 0xd8, 0xc4, 0x82, 0x4e, 0x0b, 0x42, 0x87, 0xf4, 0x7d, 0x5f, 0x72, 
		0xec, 0x2c, 0x62, 0xee, 0x7d, 0xfd, 0x04, 0xf4, 0xfa, 0x25, 0xc9, 0x70, 0x3c, 0x89, 0xb9, 0x7e, 
		0x8f, 0x4e, 0xb4, 0xd8, 0x5e, 0x4e, 0x84, 0xcd, 0xbc, 0xbe, 0x14, 0xb9, 0x1e, 0xf4, 0xa0, 0x0e, 
		0x1e, 0xbe, 0xbf, 0x56, 0xdc, 0xb2, 0x59, 0xca, 0x0b, 0xd0, 0x11, 0x3e, 0xd1, 0xfa, 0x00, 0x58, 
		0xfd, 0x68, 0xbb, 0x04, 0x3f, 0xa7, 0x56, 0x4d, 0xed, 0x56, 0x43, 0x16, 0xbd, 0xf3, 0x69, 0x65, 
		0x32, 0xf9, 0xcb, 0x9d, 0x75, 0x18, 0x54, 0x0a, 0xae, 0x1c, 0x54, 0x6b, 0xdc, 0xf0, 0x7b, 0x96, 
		0xb8, 0xca, 0xef, 0xde, 0xe2, 0xa9, 0x06, 0x5d, 0x48, 0x76, 0xa1, 0x15, 0xf3, 0x6d, 0x1a, 0x28, 
		0xca, 0x96, 0x18, 0x2f, 0x65, 0x89, 0xa9, 0xe3, 0x31, 0x2a, 0xcd, 0xb2, 0x37, 0xfc, 0x76, 0xe7, 
};

// @1E017420
static int xcode_building_first_stage(struct cxdec_xcode_status *xcode)
{
  	switch (xcode_rand(xcode) % 3) {
  	case 2:
		// MOV ESI, EncryptionControlBlock
		// MOV EAX, DWORD PTR DS:[ESI+((xcode_rand(xcode) & 0x3ff) << 2)]
		if (!push_bytexcode(xcode, 0xbe)
				|| !push_dwordxcode(xcode, (DWORD)EncryptionControlBlock)
				|| !push_2bytesxcode(xcode, 0x8b, 0x86)
				|| !push_dwordxcode(xcode, (xcode_rand(xcode) & 0x3ff) << 2))
			return 0;
		break;
	case 1:
		// MOV EAX, xcode_rand(xcode)
		if (!push_bytexcode(xcode, 0xb8)
				|| !push_dwordxcode(xcode, xcode_rand(xcode)))
			return 0;
		break;
  	case 0:
  		// MOV EAX, EDI
  		if (!push_2bytesxcode(xcode, 0x8b, 0xc7))
  			return 0;
  		break;
  	}
  	return 1;
}

// @1E017530
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
	case 3:
		// NOT EAX
		if (!push_2bytesxcode(xcode, 0xf7, 0xd0))
			return 0;
        break;
	case 2:
		// DEC EAX
		if (!push_bytexcode(xcode, 0x48))
			return 0;
        break;
	case 5:
		// XOR EAX, xcode_rand(xcode)
		if (!push_bytexcode(xcode, 0x35) 
				|| !push_dwordxcode(xcode, xcode_rand(xcode)))
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
	case 7:
		// INC EAX
		if (!push_bytexcode(xcode, 0x40))
			return 0;
        break;
	case 6:
		// NEG EAX
        if (!push_2bytesxcode(xcode, 0xf7, 0xd8))
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
	case 1:
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
	}
	return 1;
}

// @1E017790
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
	case 4:
		// ADD EAX, EBX
		if (!push_2bytesxcode(xcode, 0x01, 0xd8))
			return 0;
		break;
    case 5:
    	// SUB EAX, EBX
		if (!push_2bytesxcode(xcode, 0x29, 0xd8))
			return 0;
		break;
    case 2:
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
    case 1:
    	// IMUL EAX, EBX
		if (!push_3bytesxcode(xcode, 0x0f,  0xaf, 0xc3))
			return 0;
		break;
    case 3:
    	// NEG EAX, ADD EAX, EBX
		if (!push_2bytesxcode(xcode, 0xf7, 0xd8) 
				|| !push_2bytesxcode(xcode, 0x01, 0xd8))
			return 0;
		break;
    case 0:
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
	}
	// POP EBX
	return push_bytexcode(xcode, 0x5b);
}

struct cxdec_callback seiin_cxdec_callback = {
	"seiin",
	{ 0x213, 0x473 },
	xcode_building_stage1
};

struct cxdec_callback yu_gu_cxdec_callback = {
	"yu-gu",
	{ 0x213, 0x473 },
	xcode_building_stage1
};

struct cxdec_callback kinomino_cxdec_callback = {
	"kinomino",
	{ 0x213, 0x473 },
	xcode_building_stage1
};

struct cxdec_callback hitozuma_cxdec_callback = {
	"hitozuma",
	{ 0x213, 0x473 },
	xcode_building_stage1
};
