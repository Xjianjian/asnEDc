/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "ModulePERExtensions"
 * 	found in "/home/intest/hozon/asnEDc/asn1c-0.9.28/tests/126-per-extensions-OK.asn1"
 * 	`asn1c -S /home/intest/hozon/asnEDc/asn1c-0.9.28/skeletons -Wdebug-compiler -gen-PER`
 */

#include "Singleton.h"

static int asn_DFL_2_set(int set_value, void **sptr) {
	static uint8_t defv[] = "z";
	IA5String_t *st = *sptr;
	
	if(!st) {
		if(!set_value) return -1;	/* Not a default value */
		st = (*sptr = CALLOC(1, sizeof(*st)));
		if(!st) return -1;
	}
	
	if(set_value) {
		uint8_t *ptr = MALLOC(sizeof(defv));
		if(!ptr) return -1;
		memcpy(ptr, &defv, sizeof(defv));
		FREEMEM(st->buf);
		st->buf = ptr;
		st->size = sizeof(defv) - 1;
		return 0;
	} else {
		if(st->size != (sizeof(defv) - 1)
		|| memcmp(st->buf, &defv, sizeof(defv) - 1))
			return 0;
		return 1;
	}
	
}
static asn_TYPE_member_t asn_MBR_Singleton_1[] = {
	{ ATF_POINTER, 1, offsetof(struct Singleton, opt_z),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_IA5String,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		asn_DFL_2_set,	/* DEFAULT "z" */
		"opt-z"
		},
};
static const int asn_MAP_Singleton_oms_1[] = { 0 };
static const ber_tlv_tag_t asn_DEF_Singleton_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_Singleton_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 } /* opt-z */
};
static asn_SEQUENCE_specifics_t asn_SPC_Singleton_specs_1 = {
	sizeof(struct Singleton),
	offsetof(struct Singleton, _asn_ctx),
	asn_MAP_Singleton_tag2el_1,
	1,	/* Count of tags in the map */
	asn_MAP_Singleton_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_Singleton = {
	"Singleton",
	"Singleton",
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
	asn_DEF_Singleton_tags_1,
	sizeof(asn_DEF_Singleton_tags_1)
		/sizeof(asn_DEF_Singleton_tags_1[0]), /* 1 */
	asn_DEF_Singleton_tags_1,	/* Same as above */
	sizeof(asn_DEF_Singleton_tags_1)
		/sizeof(asn_DEF_Singleton_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_Singleton_1,
	1,	/* Elements count */
	&asn_SPC_Singleton_specs_1	/* Additional specs */
};

