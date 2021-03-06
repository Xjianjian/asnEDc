/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "ModuleLAPStorage"
 * 	found in "/home/intest/hozon/asnEDc/asn1c-0.9.28/tests/42-real-life-OK.asn1"
 * 	`asn1c -S /home/intest/hozon/asnEDc/asn1c-0.9.28/skeletons -Wdebug-compiler`
 */

#include "VariablePart.h"

static int
memb_vset_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	/* Determine the number of elements */
	size = _A_CSET_FROM_VOID(sptr)->count;
	
	if((size >= 1)) {
		/* Perform validation of the inner elements */
		return td->check_constraints(td, sptr, ctfailcb, app_key);
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_TYPE_member_t asn_MBR_vset_2[] = {
	{ ATF_POINTER, 0, 0,
		(ASN_TAG_CLASS_UNIVERSAL | (26 << 2)),
		0,
		&asn_DEF_VisibleString,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		""
		},
};
static const ber_tlv_tag_t asn_DEF_vset_tags_2[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (17 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_vset_specs_2 = {
	sizeof(struct vset),
	offsetof(struct vset, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_vset_2 = {
	"vset",
	"vset",
	SET_OF_free,
	SET_OF_print,
	SET_OF_constraint,
	SET_OF_decode_ber,
	SET_OF_encode_der,
	SET_OF_decode_xer,
	SET_OF_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_vset_tags_2,
	sizeof(asn_DEF_vset_tags_2)
		/sizeof(asn_DEF_vset_tags_2[0]), /* 1 */
	asn_DEF_vset_tags_2,	/* Same as above */
	sizeof(asn_DEF_vset_tags_2)
		/sizeof(asn_DEF_vset_tags_2[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_vset_2,
	1,	/* Single element */
	&asn_SPC_vset_specs_2	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_vrange_4[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct vrange, from),
		(ASN_TAG_CLASS_UNIVERSAL | (26 << 2)),
		0,
		&asn_DEF_VisibleString,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"from"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct vrange, to),
		(ASN_TAG_CLASS_UNIVERSAL | (26 << 2)),
		0,
		&asn_DEF_VisibleString,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"to"
		},
};
static const ber_tlv_tag_t asn_DEF_vrange_tags_4[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_vrange_tag2el_4[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (26 << 2)), 0, 0, 1 }, /* from */
    { (ASN_TAG_CLASS_UNIVERSAL | (26 << 2)), 1, -1, 0 } /* to */
};
static asn_SEQUENCE_specifics_t asn_SPC_vrange_specs_4 = {
	sizeof(struct vrange),
	offsetof(struct vrange, _asn_ctx),
	asn_MAP_vrange_tag2el_4,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	1,	/* Start extensions */
	3	/* Stop extensions */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_vrange_4 = {
	"vrange",
	"vrange",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_vrange_tags_4,
	sizeof(asn_DEF_vrange_tags_4)
		/sizeof(asn_DEF_vrange_tags_4[0]), /* 1 */
	asn_DEF_vrange_tags_4,	/* Same as above */
	sizeof(asn_DEF_vrange_tags_4)
		/sizeof(asn_DEF_vrange_tags_4[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_vrange_4,
	2,	/* Elements count */
	&asn_SPC_vrange_specs_4	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_VariablePart_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct VariablePart, choice.vset),
		(ASN_TAG_CLASS_UNIVERSAL | (17 << 2)),
		0,
		&asn_DEF_vset_2,
		memb_vset_constraint_1,
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"vset"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct VariablePart, choice.vrange),
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_vrange_4,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"vrange"
		},
};
static const asn_TYPE_tag2member_t asn_MAP_VariablePart_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 1, 0, 0 }, /* vrange */
    { (ASN_TAG_CLASS_UNIVERSAL | (17 << 2)), 0, 0, 0 } /* vset */
};
static asn_CHOICE_specifics_t asn_SPC_VariablePart_specs_1 = {
	sizeof(struct VariablePart),
	offsetof(struct VariablePart, _asn_ctx),
	offsetof(struct VariablePart, present),
	sizeof(((struct VariablePart *)0)->present),
	asn_MAP_VariablePart_tag2el_1,
	2,	/* Count of tags in the map */
	0,
	2	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_VariablePart = {
	"VariablePart",
	"VariablePart",
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
	asn_MBR_VariablePart_1,
	2,	/* Elements count */
	&asn_SPC_VariablePart_specs_1	/* Additional specs */
};

