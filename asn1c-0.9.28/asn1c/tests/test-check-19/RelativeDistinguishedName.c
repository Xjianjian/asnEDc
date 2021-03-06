/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "ModuleTestParam"
 * 	found in "/home/intest/hozon/asnEDc/asn1c-0.9.28/tests/19-param-OK.asn1"
 * 	`asn1c -S /home/intest/hozon/asnEDc/asn1c-0.9.28/skeletons -Wdebug-compiler`
 */

#include "RelativeDistinguishedName.h"

static const int permitted_alphabet_table_2[256] = {
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	/*                  */
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	/*                  */
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 0,	/*             ,-.  */
 4, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0,	/* 0        9       */
 0, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19,20,	/*  ABCDEFGHIJKLMNO */
21,22,23,24,25,26,27,28,29,30,31, 0, 0, 0, 0, 0,	/* PQRSTUVWXYZ      */
 0,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,	/*  abcdefghijklmno */
47,48,49,50,51,52,53,54,55,56,57, 0, 0, 0, 0, 0,	/* pqrstuvwxyz      */
};

static int check_permitted_alphabet_2(const void *sptr) {
	const int *table = permitted_alphabet_table_2;
	/* The underlying type is IA5String */
	const IA5String_t *st = (const IA5String_t *)sptr;
	const uint8_t *ch = st->buf;
	const uint8_t *end = ch + st->size;
	
	for(; ch < end; ch++) {
		uint8_t cv = *ch;
		if(!table[cv]) return -1;
	}
	return 0;
}

static int
memb_IA5String_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const IA5String_t *st = (const IA5String_t *)sptr;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	
	if(!check_permitted_alphabet_2(st)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_TYPE_member_t asn_MBR_RelativeDistinguishedName_1[] = {
	{ ATF_POINTER, 0, 0,
		(ASN_TAG_CLASS_UNIVERSAL | (22 << 2)),
		0,
		&asn_DEF_IA5String,
		memb_IA5String_constraint_1,
		0,	/* PER is not compiled, use -gen-PER */
		0,
		""
		},
};
static const ber_tlv_tag_t asn_DEF_RelativeDistinguishedName_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (17 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_RelativeDistinguishedName_specs_1 = {
	sizeof(struct RelativeDistinguishedName),
	offsetof(struct RelativeDistinguishedName, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
asn_TYPE_descriptor_t asn_DEF_RelativeDistinguishedName = {
	"RelativeDistinguishedName",
	"RelativeDistinguishedName",
	SET_OF_free,
	SET_OF_print,
	SET_OF_constraint,
	SET_OF_decode_ber,
	SET_OF_encode_der,
	SET_OF_decode_xer,
	SET_OF_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_RelativeDistinguishedName_tags_1,
	sizeof(asn_DEF_RelativeDistinguishedName_tags_1)
		/sizeof(asn_DEF_RelativeDistinguishedName_tags_1[0]), /* 1 */
	asn_DEF_RelativeDistinguishedName_tags_1,	/* Same as above */
	sizeof(asn_DEF_RelativeDistinguishedName_tags_1)
		/sizeof(asn_DEF_RelativeDistinguishedName_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_RelativeDistinguishedName_1,
	1,	/* Single element */
	&asn_SPC_RelativeDistinguishedName_specs_1	/* Additional specs */
};

