/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "ModuleRedefineType"
 * 	found in "/home/intest/hozon/asnEDc/asn1c-0.9.28/tests/46-redefine-OK.asn1"
 * 	`asn1c -S /home/intest/hozon/asnEDc/asn1c-0.9.28/skeletons -Wdebug-compiler`
 */

#include "ConstructedType.h"

static asn_TYPE_member_t asn_MBR_ConstructedType_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct ConstructedType, field),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_PrimitiveType,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"field"
		},
};
static const ber_tlv_tag_t asn_DEF_ConstructedType_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_ConstructedType_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 0, 0, 0 } /* field */
};
static asn_SEQUENCE_specifics_t asn_SPC_ConstructedType_specs_1 = {
	sizeof(struct ConstructedType),
	offsetof(struct ConstructedType, _asn_ctx),
	asn_MAP_ConstructedType_tag2el_1,
	1,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_ConstructedType = {
	"ConstructedType",
	"ConstructedType",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_ConstructedType_tags_1,
	sizeof(asn_DEF_ConstructedType_tags_1)
		/sizeof(asn_DEF_ConstructedType_tags_1[0]), /* 1 */
	asn_DEF_ConstructedType_tags_1,	/* Same as above */
	sizeof(asn_DEF_ConstructedType_tags_1)
		/sizeof(asn_DEF_ConstructedType_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_ConstructedType_1,
	1,	/* Elements count */
	&asn_SPC_ConstructedType_specs_1	/* Additional specs */
};

