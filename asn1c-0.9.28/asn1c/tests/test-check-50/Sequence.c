/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "ModuleNestedConstraintsCheck"
 * 	found in "/home/intest/hozon/asnEDc/asn1c-0.9.28/tests/50-constraint-OK.asn1"
 * 	`asn1c -S /home/intest/hozon/asnEDc/asn1c-0.9.28/skeletons -Wdebug-compiler`
 */

#include "Sequence.h"

static int
enum_c_6_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	/* Replace with underlying type checker */
	td->check_constraints = asn_DEF_NativeEnumerated.check_constraints;
	return td->check_constraints(td, sptr, ctfailcb, app_key);
}

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
static void
enum_c_6_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {
	td->free_struct    = asn_DEF_NativeEnumerated.free_struct;
	td->print_struct   = asn_DEF_NativeEnumerated.print_struct;
	td->check_constraints = asn_DEF_NativeEnumerated.check_constraints;
	td->ber_decoder    = asn_DEF_NativeEnumerated.ber_decoder;
	td->der_encoder    = asn_DEF_NativeEnumerated.der_encoder;
	td->xer_decoder    = asn_DEF_NativeEnumerated.xer_decoder;
	td->xer_encoder    = asn_DEF_NativeEnumerated.xer_encoder;
	td->uper_decoder   = asn_DEF_NativeEnumerated.uper_decoder;
	td->uper_encoder   = asn_DEF_NativeEnumerated.uper_encoder;
	if(!td->per_constraints)
		td->per_constraints = asn_DEF_NativeEnumerated.per_constraints;
	td->elements       = asn_DEF_NativeEnumerated.elements;
	td->elements_count = asn_DEF_NativeEnumerated.elements_count;
     /* td->specifics      = asn_DEF_NativeEnumerated.specifics;	// Defined explicitly */
}

static void
enum_c_6_free(asn_TYPE_descriptor_t *td,
		void *struct_ptr, int contents_only) {
	enum_c_6_inherit_TYPE_descriptor(td);
	td->free_struct(td, struct_ptr, contents_only);
}

static int
enum_c_6_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
		int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	enum_c_6_inherit_TYPE_descriptor(td);
	return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

static asn_dec_rval_t
enum_c_6_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const void *bufptr, size_t size, int tag_mode) {
	enum_c_6_inherit_TYPE_descriptor(td);
	return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

static asn_enc_rval_t
enum_c_6_encode_der(asn_TYPE_descriptor_t *td,
		void *structure, int tag_mode, ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *cb, void *app_key) {
	enum_c_6_inherit_TYPE_descriptor(td);
	return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

static asn_dec_rval_t
enum_c_6_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const char *opt_mname, const void *bufptr, size_t size) {
	enum_c_6_inherit_TYPE_descriptor(td);
	return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

static asn_enc_rval_t
enum_c_6_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
		int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	enum_c_6_inherit_TYPE_descriptor(td);
	return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static int
memb_int1_c_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= -2)) {
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
memb_int4_c_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 5 && value <= 7)) {
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
memb_int5_c_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value == 5)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int asn_DFL_2_set_3(int set_value, void **sptr) {
	Int1_t *st = *sptr;
	
	if(!st) {
		if(!set_value) return -1;	/* Not a default value */
		st = (*sptr = CALLOC(1, sizeof(*st)));
		if(!st) return -1;
	}
	
	if(set_value) {
		/* Install default value 3 */
		*st = 3;
		return 0;
	} else {
		/* Test default value 3 */
		return (*st == 3);
	}
}
static int asn_DFL_5_set_1(int set_value, void **sptr) {
	BOOLEAN_t *st = *sptr;
	
	if(!st) {
		if(!set_value) return -1;	/* Not a default value */
		st = (*sptr = CALLOC(1, sizeof(*st)));
		if(!st) return -1;
	}
	
	if(set_value) {
		/* Install default value 1 */
		*st = 1;
		return 0;
	} else {
		/* Test default value 1 */
		return (*st == 1);
	}
}
static const asn_INTEGER_enum_map_t asn_MAP_enum_c_value2enum_6[] = {
	{ 1,	3,	"one" },
	{ 2,	3,	"two" },
	{ 3,	5,	"three" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_enum_c_enum2value_6[] = {
	0,	/* one(1) */
	2,	/* three(3) */
	1	/* two(2) */
	/* This list is extensible */
};
static const asn_INTEGER_specifics_t asn_SPC_enum_c_specs_6 = {
	asn_MAP_enum_c_value2enum_6,	/* "tag" => N; sorted by tag */
	asn_MAP_enum_c_enum2value_6,	/* N => "tag"; sorted by N */
	3,	/* Number of elements in the maps */
	3,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_enum_c_tags_6[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_enum_c_6 = {
	"enum-c",
	"enum-c",
	enum_c_6_free,
	enum_c_6_print,
	enum_c_6_constraint,
	enum_c_6_decode_ber,
	enum_c_6_encode_der,
	enum_c_6_decode_xer,
	enum_c_6_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_enum_c_tags_6,
	sizeof(asn_DEF_enum_c_tags_6)
		/sizeof(asn_DEF_enum_c_tags_6[0]), /* 1 */
	asn_DEF_enum_c_tags_6,	/* Same as above */
	sizeof(asn_DEF_enum_c_tags_6)
		/sizeof(asn_DEF_enum_c_tags_6[0]), /* 1 */
	0,	/* No PER visible constraints */
	0, 0,	/* Defined elsewhere */
	&asn_SPC_enum_c_specs_6	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_Sequence_1[] = {
	{ ATF_POINTER, 1, offsetof(struct Sequence, int1_c),
		(ASN_TAG_CLASS_UNIVERSAL | (2 << 2)),
		0,
		&asn_DEF_Int1,
		memb_int1_c_constraint_1,
		0,	/* PER is not compiled, use -gen-PER */
		asn_DFL_2_set_3,	/* DEFAULT 3 */
		"int1-c"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct Sequence, int4),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_Int4,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"int4"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct Sequence, int4_c),
		(ASN_TAG_CLASS_UNIVERSAL | (2 << 2)),
		0,
		&asn_DEF_Int4,
		memb_int4_c_constraint_1,
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"int4-c"
		},
	{ ATF_POINTER, 1, offsetof(struct Sequence, Bool),
		(ASN_TAG_CLASS_UNIVERSAL | (1 << 2)),
		0,
		&asn_DEF_BOOLEAN,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		asn_DFL_5_set_1,	/* DEFAULT 1 */
		"bool"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct Sequence, enum_c),
		(ASN_TAG_CLASS_UNIVERSAL | (10 << 2)),
		0,
		&asn_DEF_enum_c_6,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"enum-c"
		},
	{ ATF_POINTER, 2, offsetof(struct Sequence, null),
		(ASN_TAG_CLASS_UNIVERSAL | (5 << 2)),
		0,
		&asn_DEF_NULL,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"null"
		},
	{ ATF_POINTER, 1, offsetof(struct Sequence, int5_c),
		(ASN_TAG_CLASS_UNIVERSAL | (2 << 2)),
		0,
		&asn_DEF_Int5,
		memb_int5_c_constraint_1,
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"int5-c"
		},
};
static const ber_tlv_tag_t asn_DEF_Sequence_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_Sequence_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (1 << 2)), 3, 0, 0 }, /* bool */
    { (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)), 0, 0, 2 }, /* int1-c */
    { (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)), 2, -1, 1 }, /* int4-c */
    { (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)), 6, -2, 0 }, /* int5-c */
    { (ASN_TAG_CLASS_UNIVERSAL | (5 << 2)), 5, 0, 0 }, /* null */
    { (ASN_TAG_CLASS_UNIVERSAL | (10 << 2)), 4, 0, 0 }, /* enum-c */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 1, 0, 0 } /* int4 */
};
static asn_SEQUENCE_specifics_t asn_SPC_Sequence_specs_1 = {
	sizeof(struct Sequence),
	offsetof(struct Sequence, _asn_ctx),
	asn_MAP_Sequence_tag2el_1,
	7,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	5,	/* Start extensions */
	8	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_Sequence = {
	"Sequence",
	"Sequence",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_Sequence_tags_1,
	sizeof(asn_DEF_Sequence_tags_1)
		/sizeof(asn_DEF_Sequence_tags_1[0]), /* 1 */
	asn_DEF_Sequence_tags_1,	/* Same as above */
	sizeof(asn_DEF_Sequence_tags_1)
		/sizeof(asn_DEF_Sequence_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_Sequence_1,
	7,	/* Elements count */
	&asn_SPC_Sequence_specs_1	/* Additional specs */
};
