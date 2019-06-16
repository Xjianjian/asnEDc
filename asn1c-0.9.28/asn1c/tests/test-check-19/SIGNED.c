/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "ModuleTestParam"
 * 	found in "/home/intest/hozon/asnEDc/asn1c-0.9.28/tests/19-param-OK.asn1"
 * 	`asn1c -S /home/intest/hozon/asnEDc/asn1c-0.9.28/skeletons -Wdebug-compiler`
 */

#include "SIGNED.h"

static int
memb_signature_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const BIT_STRING_t *st = (const BIT_STRING_t *)sptr;
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	if(st->size > 0) {
		/* Size in bits */
		size = 8 * st->size - (st->bits_unused & 0x07);
	} else {
		size = 0;
	}
	
	if((size <= 256)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_TYPE_member_t asn_MBR_toBeSigned_2[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct toBeSigned, version),
		(ASN_TAG_CLASS_UNIVERSAL | (2 << 2)),
		0,
		&asn_DEF_NativeInteger,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"version"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct toBeSigned, signature),
		(ASN_TAG_CLASS_UNIVERSAL | (6 << 2)),
		0,
		&asn_DEF_OBJECT_IDENTIFIER,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"signature"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct toBeSigned, issuer),
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_Name,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"issuer"
		},
};
static const ber_tlv_tag_t asn_DEF_toBeSigned_tags_2[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_toBeSigned_tag2el_2[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)), 0, 0, 0 }, /* version */
    { (ASN_TAG_CLASS_UNIVERSAL | (6 << 2)), 1, 0, 0 }, /* signature */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 2, 0, 0 } /* issuer */
};
static asn_SEQUENCE_specifics_t asn_SPC_toBeSigned_specs_2 = {
	sizeof(struct toBeSigned),
	offsetof(struct toBeSigned, _asn_ctx),
	asn_MAP_toBeSigned_tag2el_2,
	3,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_toBeSigned_2 = {
	"toBeSigned",
	"toBeSigned",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_toBeSigned_tags_2,
	sizeof(asn_DEF_toBeSigned_tags_2)
		/sizeof(asn_DEF_toBeSigned_tags_2[0]), /* 1 */
	asn_DEF_toBeSigned_tags_2,	/* Same as above */
	sizeof(asn_DEF_toBeSigned_tags_2)
		/sizeof(asn_DEF_toBeSigned_tags_2[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_toBeSigned_2,
	3,	/* Elements count */
	&asn_SPC_toBeSigned_specs_2	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_SIGNED_15P0_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct SIGNED_15P0, toBeSigned),
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_toBeSigned_2,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"toBeSigned"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct SIGNED_15P0, algorithm),
		(ASN_TAG_CLASS_UNIVERSAL | (6 << 2)),
		0,
		&asn_DEF_OBJECT_IDENTIFIER,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"algorithm"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct SIGNED_15P0, signature),
		(ASN_TAG_CLASS_UNIVERSAL | (3 << 2)),
		0,
		&asn_DEF_BIT_STRING,
		memb_signature_constraint_1,
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"signature"
		},
};
static const ber_tlv_tag_t asn_DEF_SIGNED_15P0_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_SIGNED_15P0_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (3 << 2)), 2, 0, 0 }, /* signature */
    { (ASN_TAG_CLASS_UNIVERSAL | (6 << 2)), 1, 0, 0 }, /* algorithm */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 0, 0, 0 } /* toBeSigned */
};
static asn_SEQUENCE_specifics_t asn_SPC_SIGNED_15P0_specs_1 = {
	sizeof(struct SIGNED_15P0),
	offsetof(struct SIGNED_15P0, _asn_ctx),
	asn_MAP_SIGNED_15P0_tag2el_1,
	3,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_SIGNED_15P0 = {
	"SIGNED",
	"SIGNED",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_SIGNED_15P0_tags_1,
	sizeof(asn_DEF_SIGNED_15P0_tags_1)
		/sizeof(asn_DEF_SIGNED_15P0_tags_1[0]), /* 1 */
	asn_DEF_SIGNED_15P0_tags_1,	/* Same as above */
	sizeof(asn_DEF_SIGNED_15P0_tags_1)
		/sizeof(asn_DEF_SIGNED_15P0_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_SIGNED_15P0_1,
	3,	/* Elements count */
	&asn_SPC_SIGNED_15P0_specs_1	/* Additional specs */
};

