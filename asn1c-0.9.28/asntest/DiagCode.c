/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "HOZON"
 * 	found in "HOZON_PRIV_v1.0.asn"
 * 	`asn1c -gen-PER`
 */

#include "DiagCode.h"

static int check_permitted_alphabet_2(const void *sptr) {
	/* The underlying type is IA5String */
	const IA5String_t *st = (const IA5String_t *)sptr;
	const uint8_t *ch = st->buf;
	const uint8_t *end = ch + st->size;
	
	for(; ch < end; ch++) {
		uint8_t cv = *ch;
		if(!(cv <= 127)) return -1;
	}
	return 0;
}

static int
memb_diagCode_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const IA5String_t *st = (const IA5String_t *)sptr;
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	size = st->size;
	
	if((size == 5)
		 && !check_permitted_alphabet_2(st)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_diagTime_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 2147483647)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_memb_diagCode_constr_2 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 7,  7,  0,  127 }	/* (0..127) */,
	{ APC_CONSTRAINED,	 0,  0,  5,  5 }	/* (SIZE(5..5)) */,
	0, 0	/* No PER character map necessary */
};
static asn_per_constraints_t asn_PER_memb_diagTime_constr_3 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 31, -1,  0,  2147483647 }	/* (0..2147483647) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_DiagCode_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct DiagCode, diagCode),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_IA5String,
		memb_diagCode_constraint_1,
		&asn_PER_memb_diagCode_constr_2,
		0,
		"diagCode"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct DiagCode, diagTime),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		memb_diagTime_constraint_1,
		&asn_PER_memb_diagTime_constr_3,
		0,
		"diagTime"
		},
};
static const ber_tlv_tag_t asn_DEF_DiagCode_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_DiagCode_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* diagCode */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* diagTime */
};
static asn_SEQUENCE_specifics_t asn_SPC_DiagCode_specs_1 = {
	sizeof(struct DiagCode),
	offsetof(struct DiagCode, _asn_ctx),
	asn_MAP_DiagCode_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_DiagCode = {
	"DiagCode",
	"DiagCode",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	SEQUENCE_decode_uper,
	SEQUENCE_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_DiagCode_tags_1,
	sizeof(asn_DEF_DiagCode_tags_1)
		/sizeof(asn_DEF_DiagCode_tags_1[0]), /* 1 */
	asn_DEF_DiagCode_tags_1,	/* Same as above */
	sizeof(asn_DEF_DiagCode_tags_1)
		/sizeof(asn_DEF_DiagCode_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_DiagCode_1,
	2,	/* Elements count */
	&asn_SPC_DiagCode_specs_1	/* Additional specs */
};

