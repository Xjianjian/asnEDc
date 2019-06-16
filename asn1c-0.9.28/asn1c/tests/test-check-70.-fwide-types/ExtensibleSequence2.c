/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "ModuleTestXERDecoding"
 * 	found in "/home/intest/hozon/asnEDc/asn1c-0.9.28/tests/70-xer-test-OK.asn1"
 * 	`asn1c -S /home/intest/hozon/asnEDc/asn1c-0.9.28/skeletons -Wdebug-compiler -fwide-types`
 */

#include "ExtensibleSequence2.h"

static asn_TYPE_member_t asn_MBR_ExtensibleSequence2_1[] = {
	{ ATF_POINTER, 2, offsetof(struct ExtensibleSequence2, string),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_UTF8String,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"string"
		},
	{ ATF_POINTER, 1, offsetof(struct ExtensibleSequence2, integer),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_INTEGER,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"integer"
		},
};
static const ber_tlv_tag_t asn_DEF_ExtensibleSequence2_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_ExtensibleSequence2_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* string */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* integer */
};
static asn_SEQUENCE_specifics_t asn_SPC_ExtensibleSequence2_specs_1 = {
	sizeof(struct ExtensibleSequence2),
	offsetof(struct ExtensibleSequence2, _asn_ctx),
	asn_MAP_ExtensibleSequence2_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	0,	/* Start extensions */
	3	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_ExtensibleSequence2 = {
	"ExtensibleSequence2",
	"ExtensibleSequence2",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_ExtensibleSequence2_tags_1,
	sizeof(asn_DEF_ExtensibleSequence2_tags_1)
		/sizeof(asn_DEF_ExtensibleSequence2_tags_1[0]), /* 1 */
	asn_DEF_ExtensibleSequence2_tags_1,	/* Same as above */
	sizeof(asn_DEF_ExtensibleSequence2_tags_1)
		/sizeof(asn_DEF_ExtensibleSequence2_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_ExtensibleSequence2_1,
	2,	/* Elements count */
	&asn_SPC_ExtensibleSequence2_specs_1	/* Additional specs */
};
