/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "HOZON"
 * 	found in "HOZON_PRIV_v1.0.asn"
 * 	`asn1c -gen-PER`
 */

#include "DiagnosticLogReqInfo.h"

static int
memb_diagTypeList_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
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
	
	if((size >= 1 && size <= 255)) {
		/* Perform validation of the inner elements */
		return td->check_constraints(td, sptr, ctfailcb, app_key);
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_type_diagTypeList_constr_2 GCC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 8,  8,  1,  255 }	/* (SIZE(1..255)) */,
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_diagTypeList_constr_2 GCC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 8,  8,  1,  255 }	/* (SIZE(1..255)) */,
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_diagTypeList_2[] = {
	{ ATF_POINTER, 0, 0,
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_DiagnosticLogType,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		""
		},
};
static const ber_tlv_tag_t asn_DEF_diagTypeList_tags_2[] = {
	(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_diagTypeList_specs_2 = {
	sizeof(struct diagTypeList),
	offsetof(struct diagTypeList, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_diagTypeList_2 = {
	"diagTypeList",
	"diagTypeList",
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
	asn_DEF_diagTypeList_tags_2,
	sizeof(asn_DEF_diagTypeList_tags_2)
		/sizeof(asn_DEF_diagTypeList_tags_2[0]) - 1, /* 1 */
	asn_DEF_diagTypeList_tags_2,	/* Same as above */
	sizeof(asn_DEF_diagTypeList_tags_2)
		/sizeof(asn_DEF_diagTypeList_tags_2[0]), /* 2 */
	&asn_PER_type_diagTypeList_constr_2,
	asn_MBR_diagTypeList_2,
	1,	/* Single element */
	&asn_SPC_diagTypeList_specs_2	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_DiagnosticLogReqInfo_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct DiagnosticLogReqInfo, diagTypeList),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		0,
		&asn_DEF_diagTypeList_2,
		memb_diagTypeList_constraint_1,
		&asn_PER_memb_diagTypeList_constr_2,
		0,
		"diagTypeList"
		},
};
static const ber_tlv_tag_t asn_DEF_DiagnosticLogReqInfo_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_DiagnosticLogReqInfo_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 } /* diagTypeList */
};
static asn_SEQUENCE_specifics_t asn_SPC_DiagnosticLogReqInfo_specs_1 = {
	sizeof(struct DiagnosticLogReqInfo),
	offsetof(struct DiagnosticLogReqInfo, _asn_ctx),
	asn_MAP_DiagnosticLogReqInfo_tag2el_1,
	1,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_DiagnosticLogReqInfo = {
	"DiagnosticLogReqInfo",
	"DiagnosticLogReqInfo",
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
	asn_DEF_DiagnosticLogReqInfo_tags_1,
	sizeof(asn_DEF_DiagnosticLogReqInfo_tags_1)
		/sizeof(asn_DEF_DiagnosticLogReqInfo_tags_1[0]), /* 1 */
	asn_DEF_DiagnosticLogReqInfo_tags_1,	/* Same as above */
	sizeof(asn_DEF_DiagnosticLogReqInfo_tags_1)
		/sizeof(asn_DEF_DiagnosticLogReqInfo_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_DiagnosticLogReqInfo_1,
	1,	/* Elements count */
	&asn_SPC_DiagnosticLogReqInfo_specs_1	/* Additional specs */
};

