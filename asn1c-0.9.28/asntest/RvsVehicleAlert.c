/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "HOZON"
 * 	found in "HOZON_PRIV_v1.0.asn"
 * 	`asn1c -gen-PER`
 */

#include "RvsVehicleAlert.h"

static int
memb_alertTime_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
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

static int
memb_vagpsPos_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	/* Determine the number of elements */
	size = _A_CSEQUENCE_FROM_VOID(sptr)->count;
	
	if((size == 1)) {
		/* Perform validation of the inner elements */
		return td->check_constraints(td, sptr, ctfailcb, app_key);
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_alertSize_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 255)) {
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
memb_alertIds_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const OCTET_STRING_t *st = (const OCTET_STRING_t *)sptr;
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	size = st->size;
	
	if((size <= 255)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_type_vagpsPos_constr_3 GCC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 0,  0,  1,  1 }	/* (SIZE(1..1)) */,
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_alertTime_constr_2 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 31, -1,  0,  2147483647 }	/* (0..2147483647) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_vagpsPos_constr_3 GCC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 0,  0,  1,  1 }	/* (SIZE(1..1)) */,
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_alertSize_constr_5 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 8,  8,  0,  255 }	/* (0..255) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_alertIds_constr_6 GCC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 8,  8,  0,  255 }	/* (SIZE(0..255)) */,
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_vagpsPos_3[] = {
	{ ATF_POINTER, 0, 0,
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_VSgpspos,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		""
		},
};
static const ber_tlv_tag_t asn_DEF_vagpsPos_tags_3[] = {
	(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_vagpsPos_specs_3 = {
	sizeof(struct vagpsPos),
	offsetof(struct vagpsPos, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_vagpsPos_3 = {
	"vagpsPos",
	"vagpsPos",
	SEQUENCE_OF_free,
	SEQUENCE_OF_print,
	SEQUENCE_OF_constraint,
	SEQUENCE_OF_decode_ber,
	SEQUENCE_OF_encode_der,
	SEQUENCE_OF_decode_xer,
	SEQUENCE_OF_encode_xer,
	SEQUENCE_OF_decode_uper,
	SEQUENCE_OF_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_vagpsPos_tags_3,
	sizeof(asn_DEF_vagpsPos_tags_3)
		/sizeof(asn_DEF_vagpsPos_tags_3[0]) - 1, /* 1 */
	asn_DEF_vagpsPos_tags_3,	/* Same as above */
	sizeof(asn_DEF_vagpsPos_tags_3)
		/sizeof(asn_DEF_vagpsPos_tags_3[0]), /* 2 */
	&asn_PER_type_vagpsPos_constr_3,
	asn_MBR_vagpsPos_3,
	1,	/* Single element */
	&asn_SPC_vagpsPos_specs_3	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_RvsVehicleAlert_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct RvsVehicleAlert, alertTime),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		memb_alertTime_constraint_1,
		&asn_PER_memb_alertTime_constr_2,
		0,
		"alertTime"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct RvsVehicleAlert, vagpsPos),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		0,
		&asn_DEF_vagpsPos_3,
		memb_vagpsPos_constraint_1,
		&asn_PER_memb_vagpsPos_constr_3,
		0,
		"vagpsPos"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct RvsVehicleAlert, alertSize),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		memb_alertSize_constraint_1,
		&asn_PER_memb_alertSize_constr_5,
		0,
		"alertSize"
		},
	{ ATF_POINTER, 1, offsetof(struct RvsVehicleAlert, alertIds),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_OCTET_STRING,
		memb_alertIds_constraint_1,
		&asn_PER_memb_alertIds_constr_6,
		0,
		"alertIds"
		},
};
static const int asn_MAP_RvsVehicleAlert_oms_1[] = { 3 };
static const ber_tlv_tag_t asn_DEF_RvsVehicleAlert_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_RvsVehicleAlert_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* alertTime */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* vagpsPos */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* alertSize */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 } /* alertIds */
};
static asn_SEQUENCE_specifics_t asn_SPC_RvsVehicleAlert_specs_1 = {
	sizeof(struct RvsVehicleAlert),
	offsetof(struct RvsVehicleAlert, _asn_ctx),
	asn_MAP_RvsVehicleAlert_tag2el_1,
	4,	/* Count of tags in the map */
	asn_MAP_RvsVehicleAlert_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_RvsVehicleAlert = {
	"RvsVehicleAlert",
	"RvsVehicleAlert",
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
	asn_DEF_RvsVehicleAlert_tags_1,
	sizeof(asn_DEF_RvsVehicleAlert_tags_1)
		/sizeof(asn_DEF_RvsVehicleAlert_tags_1[0]), /* 1 */
	asn_DEF_RvsVehicleAlert_tags_1,	/* Same as above */
	sizeof(asn_DEF_RvsVehicleAlert_tags_1)
		/sizeof(asn_DEF_RvsVehicleAlert_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_RvsVehicleAlert_1,
	4,	/* Elements count */
	&asn_SPC_RvsVehicleAlert_specs_1	/* Additional specs */
};

