/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "ModuleTestIntOptional"
 * 	found in "/home/intest/hozon/asnEDc/asn1c-0.9.28/tests/41-int-optional-OK.asn1"
 * 	`asn1c -S /home/intest/hozon/asnEDc/asn1c-0.9.28/skeletons -Wdebug-compiler`
 */

#include "T.h"

static asn_TYPE_member_t asn_MBR_seq_2[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct seq, string),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_UTF8String,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"string"
		},
	{ ATF_POINTER, 2, offsetof(struct seq, alpha),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"alpha"
		},
	{ ATF_POINTER, 1, offsetof(struct seq, beta),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"beta"
		},
};
static const ber_tlv_tag_t asn_DEF_seq_tags_2[] = {
	(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_seq_tag2el_2[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* string */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* alpha */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* beta */
};
static asn_SEQUENCE_specifics_t asn_SPC_seq_specs_2 = {
	sizeof(struct seq),
	offsetof(struct seq, _asn_ctx),
	asn_MAP_seq_tag2el_2,
	3,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_seq_2 = {
	"seq",
	"seq",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_seq_tags_2,
	sizeof(asn_DEF_seq_tags_2)
		/sizeof(asn_DEF_seq_tags_2[0]) - 1, /* 1 */
	asn_DEF_seq_tags_2,	/* Same as above */
	sizeof(asn_DEF_seq_tags_2)
		/sizeof(asn_DEF_seq_tags_2[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_seq_2,
	3,	/* Elements count */
	&asn_SPC_seq_specs_2	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_set_6[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct set, string),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_UTF8String,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"string"
		},
	{ ATF_POINTER, 2, offsetof(struct set, alpha),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"alpha"
		},
	{ ATF_POINTER, 1, offsetof(struct set, beta),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"beta"
		},
};
static const ber_tlv_tag_t asn_DEF_set_tags_6[] = {
	(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (17 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_set_tag2el_6[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* string */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* alpha */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* beta */
};
static const uint8_t asn_MAP_set_mmap_6[(3 + (8 * sizeof(unsigned int)) - 1) / 8] = {
	(1 << 7) | (0 << 6) | (0 << 5)
};
static asn_SET_specifics_t asn_SPC_set_specs_6 = {
	sizeof(struct set),
	offsetof(struct set, _asn_ctx),
	offsetof(struct set, _presence_map),
	asn_MAP_set_tag2el_6,
	3,	/* Count of tags in the map */
	asn_MAP_set_tag2el_6,	/* Same as above */
	3,	/* Count of tags in the CXER map */
	0,	/* Whether extensible */
	(unsigned int *)asn_MAP_set_mmap_6	/* Mandatory elements map */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_set_6 = {
	"set",
	"set",
	SET_free,
	SET_print,
	SET_constraint,
	SET_decode_ber,
	SET_encode_der,
	SET_decode_xer,
	SET_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_set_tags_6,
	sizeof(asn_DEF_set_tags_6)
		/sizeof(asn_DEF_set_tags_6[0]) - 1, /* 1 */
	asn_DEF_set_tags_6,	/* Same as above */
	sizeof(asn_DEF_set_tags_6)
		/sizeof(asn_DEF_set_tags_6[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_set_6,
	3,	/* Elements count */
	&asn_SPC_set_specs_6	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_T_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct T, choice.seq),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		0,
		&asn_DEF_seq_2,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"seq"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct T, choice.set),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		0,
		&asn_DEF_set_6,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"set"
		},
};
static const asn_TYPE_tag2member_t asn_MAP_T_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* seq */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* set */
};
static asn_CHOICE_specifics_t asn_SPC_T_specs_1 = {
	sizeof(struct T),
	offsetof(struct T, _asn_ctx),
	offsetof(struct T, present),
	sizeof(((struct T *)0)->present),
	asn_MAP_T_tag2el_1,
	2,	/* Count of tags in the map */
	0,
	-1	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_T = {
	"T",
	"T",
	CHOICE_free,
	CHOICE_print,
	CHOICE_constraint,
	CHOICE_decode_ber,
	CHOICE_encode_der,
	CHOICE_decode_xer,
	CHOICE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	CHOICE_outmost_tag,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	0,	/* No PER visible constraints */
	asn_MBR_T_1,
	2,	/* Elements count */
	&asn_SPC_T_specs_1	/* Additional specs */
};

