/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "HOZON"
 * 	found in "HOZON_PRIV_v1.0.asn"
 * 	`asn1c -gen-PER`
 */

#include "CommonConfigSet.h"

static asn_TYPE_member_t asn_MBR_CommonConfigSet_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct CommonConfigSet, actived),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BOOLEAN,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"actived"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct CommonConfigSet, rcEnabled),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BOOLEAN,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"rcEnabled"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct CommonConfigSet, svtEnabled),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BOOLEAN,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"svtEnabled"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct CommonConfigSet, vsEnabled),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BOOLEAN,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"vsEnabled"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct CommonConfigSet, iCallEnabled),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BOOLEAN,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"iCallEnabled"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct CommonConfigSet, bCallEnabled),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BOOLEAN,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"bCallEnabled"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct CommonConfigSet, eCallEnabled),
		(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BOOLEAN,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"eCallEnabled"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct CommonConfigSet, dcEnabled),
		(ASN_TAG_CLASS_CONTEXT | (7 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BOOLEAN,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"dcEnabled"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct CommonConfigSet, dtcEnabled),
		(ASN_TAG_CLASS_CONTEXT | (8 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BOOLEAN,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"dtcEnabled"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct CommonConfigSet, journeysEnabled),
		(ASN_TAG_CLASS_CONTEXT | (9 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BOOLEAN,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"journeysEnabled"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct CommonConfigSet, onlineInfEnabled),
		(ASN_TAG_CLASS_CONTEXT | (10 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BOOLEAN,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"onlineInfEnabled"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct CommonConfigSet, rChargeEnabled),
		(ASN_TAG_CLASS_CONTEXT | (11 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BOOLEAN,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"rChargeEnabled"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct CommonConfigSet, btKeyEntryEnabled),
		(ASN_TAG_CLASS_CONTEXT | (12 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BOOLEAN,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"btKeyEntryEnabled"
		},
};
static const ber_tlv_tag_t asn_DEF_CommonConfigSet_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_CommonConfigSet_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* actived */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* rcEnabled */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* svtEnabled */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* vsEnabled */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* iCallEnabled */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 }, /* bCallEnabled */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 6, 0, 0 }, /* eCallEnabled */
    { (ASN_TAG_CLASS_CONTEXT | (7 << 2)), 7, 0, 0 }, /* dcEnabled */
    { (ASN_TAG_CLASS_CONTEXT | (8 << 2)), 8, 0, 0 }, /* dtcEnabled */
    { (ASN_TAG_CLASS_CONTEXT | (9 << 2)), 9, 0, 0 }, /* journeysEnabled */
    { (ASN_TAG_CLASS_CONTEXT | (10 << 2)), 10, 0, 0 }, /* onlineInfEnabled */
    { (ASN_TAG_CLASS_CONTEXT | (11 << 2)), 11, 0, 0 }, /* rChargeEnabled */
    { (ASN_TAG_CLASS_CONTEXT | (12 << 2)), 12, 0, 0 } /* btKeyEntryEnabled */
};
static asn_SEQUENCE_specifics_t asn_SPC_CommonConfigSet_specs_1 = {
	sizeof(struct CommonConfigSet),
	offsetof(struct CommonConfigSet, _asn_ctx),
	asn_MAP_CommonConfigSet_tag2el_1,
	13,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_CommonConfigSet = {
	"CommonConfigSet",
	"CommonConfigSet",
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
	asn_DEF_CommonConfigSet_tags_1,
	sizeof(asn_DEF_CommonConfigSet_tags_1)
		/sizeof(asn_DEF_CommonConfigSet_tags_1[0]), /* 1 */
	asn_DEF_CommonConfigSet_tags_1,	/* Same as above */
	sizeof(asn_DEF_CommonConfigSet_tags_1)
		/sizeof(asn_DEF_CommonConfigSet_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_CommonConfigSet_1,
	13,	/* Elements count */
	&asn_SPC_CommonConfigSet_specs_1	/* Additional specs */
};

