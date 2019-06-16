/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "ModuleCircularReferences"
 * 	found in "/home/intest/hozon/asnEDc/asn1c-0.9.28/tests/92-circular-loops-OK.asn1"
 * 	`asn1c -S /home/intest/hozon/asnEDc/asn1c-0.9.28/skeletons -Wdebug-compiler -findirect-choice`
 */

#include "ThreeOne.h"

static asn_TYPE_member_t asn_MBR_ThreeOne_1[] = {
	{ ATF_POINTER, 0, offsetof(struct ThreeOne, m31),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_OneTwo,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"m31"
		},
	{ ATF_POINTER, 0, offsetof(struct ThreeOne, g),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Gamma,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"g"
		},
};
static const ber_tlv_tag_t asn_DEF_ThreeOne_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (17 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_ThreeOne_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* m31 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* g */
};
static const uint8_t asn_MAP_ThreeOne_mmap_1[(2 + (8 * sizeof(unsigned int)) - 1) / 8] = {
	(1 << 7) | (1 << 6)
};
static asn_SET_specifics_t asn_SPC_ThreeOne_specs_1 = {
	sizeof(struct ThreeOne),
	offsetof(struct ThreeOne, _asn_ctx),
	offsetof(struct ThreeOne, _presence_map),
	asn_MAP_ThreeOne_tag2el_1,
	2,	/* Count of tags in the map */
	asn_MAP_ThreeOne_tag2el_1,	/* Same as above */
	2,	/* Count of tags in the CXER map */
	0,	/* Whether extensible */
	(unsigned int *)asn_MAP_ThreeOne_mmap_1	/* Mandatory elements map */
};
asn_TYPE_descriptor_t asn_DEF_ThreeOne = {
	"ThreeOne",
	"ThreeOne",
	SET_free,
	SET_print,
	SET_constraint,
	SET_decode_ber,
	SET_encode_der,
	SET_decode_xer,
	SET_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_ThreeOne_tags_1,
	sizeof(asn_DEF_ThreeOne_tags_1)
		/sizeof(asn_DEF_ThreeOne_tags_1[0]), /* 1 */
	asn_DEF_ThreeOne_tags_1,	/* Same as above */
	sizeof(asn_DEF_ThreeOne_tags_1)
		/sizeof(asn_DEF_ThreeOne_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_ThreeOne_1,
	2,	/* Elements count */
	&asn_SPC_ThreeOne_specs_1	/* Additional specs */
};
