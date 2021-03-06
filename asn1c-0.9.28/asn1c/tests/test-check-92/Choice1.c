/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "ModuleCircularReferences"
 * 	found in "/home/intest/hozon/asnEDc/asn1c-0.9.28/tests/92-circular-loops-OK.asn1"
 * 	`asn1c -S /home/intest/hozon/asnEDc/asn1c-0.9.28/skeletons -Wdebug-compiler`
 */

#include "Choice1.h"

static asn_TYPE_member_t asn_MBR_Choice1_1[] = {
	{ ATF_POINTER, 0, offsetof(struct Choice1, choice.something),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Everything,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"something"
		},
	{ ATF_POINTER, 0, offsetof(struct Choice1, choice.some2),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Everything,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"some2"
		},
};
static const asn_TYPE_tag2member_t asn_MAP_Choice1_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* something */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* some2 */
};
static asn_CHOICE_specifics_t asn_SPC_Choice1_specs_1 = {
	sizeof(struct Choice1),
	offsetof(struct Choice1, _asn_ctx),
	offsetof(struct Choice1, present),
	sizeof(((struct Choice1 *)0)->present),
	asn_MAP_Choice1_tag2el_1,
	2,	/* Count of tags in the map */
	0,
	1	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_Choice1 = {
	"Choice1",
	"Choice1",
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
	asn_MBR_Choice1_1,
	2,	/* Elements count */
	&asn_SPC_Choice1_specs_1	/* Additional specs */
};

