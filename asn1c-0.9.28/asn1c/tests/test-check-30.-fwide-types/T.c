/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "ModuleTestSetSimple"
 * 	found in "/home/intest/hozon/asnEDc/asn1c-0.9.28/tests/30-set-OK.asn1"
 * 	`asn1c -S /home/intest/hozon/asnEDc/asn1c-0.9.28/skeletons -Wdebug-compiler -fwide-types`
 */

#include "T.h"

static asn_TYPE_member_t asn_MBR_T_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct T, i),
		(ASN_TAG_CLASS_APPLICATION | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_INTEGER,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"i"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct T, s),
		(ASN_TAG_CLASS_UNIVERSAL | (22 << 2)),
		0,
		&asn_DEF_IA5String,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"s"
		},
	{ ATF_POINTER, 1, offsetof(struct T, b),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BOOLEAN,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"b"
		},
};
static const ber_tlv_tag_t asn_DEF_T_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (17 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_T_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (22 << 2)), 1, 0, 0 }, /* s */
    { (ASN_TAG_CLASS_APPLICATION | (3 << 2)), 0, 0, 0 }, /* i */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* b */
};
static const uint8_t asn_MAP_T_mmap_1[(3 + (8 * sizeof(unsigned int)) - 1) / 8] = {
	(1 << 7) | (1 << 6) | (0 << 5)
};
static asn_SET_specifics_t asn_SPC_T_specs_1 = {
	sizeof(struct T),
	offsetof(struct T, _asn_ctx),
	offsetof(struct T, _presence_map),
	asn_MAP_T_tag2el_1,
	3,	/* Count of tags in the map */
	asn_MAP_T_tag2el_1,	/* Same as above */
	3,	/* Count of tags in the CXER map */
	1,	/* Whether extensible */
	(unsigned int *)asn_MAP_T_mmap_1	/* Mandatory elements map */
};
asn_TYPE_descriptor_t asn_DEF_T = {
	"T",
	"T",
	SET_free,
	SET_print,
	SET_constraint,
	SET_decode_ber,
	SET_encode_der,
	SET_decode_xer,
	SET_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_T_tags_1,
	sizeof(asn_DEF_T_tags_1)
		/sizeof(asn_DEF_T_tags_1[0]), /* 1 */
	asn_DEF_T_tags_1,	/* Same as above */
	sizeof(asn_DEF_T_tags_1)
		/sizeof(asn_DEF_T_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_T_1,
	3,	/* Elements count */
	&asn_SPC_T_specs_1	/* Additional specs */
};

