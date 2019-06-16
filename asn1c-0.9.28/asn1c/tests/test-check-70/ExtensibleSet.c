/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "ModuleTestXERDecoding"
 * 	found in "/home/intest/hozon/asnEDc/asn1c-0.9.28/tests/70-xer-test-OK.asn1"
 * 	`asn1c -S /home/intest/hozon/asnEDc/asn1c-0.9.28/skeletons -Wdebug-compiler`
 */

#include "ExtensibleSet.h"

static int
enum_4_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
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
enum_4_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {
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
enum_4_free(asn_TYPE_descriptor_t *td,
		void *struct_ptr, int contents_only) {
	enum_4_inherit_TYPE_descriptor(td);
	td->free_struct(td, struct_ptr, contents_only);
}

static int
enum_4_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
		int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	enum_4_inherit_TYPE_descriptor(td);
	return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

static asn_dec_rval_t
enum_4_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const void *bufptr, size_t size, int tag_mode) {
	enum_4_inherit_TYPE_descriptor(td);
	return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

static asn_enc_rval_t
enum_4_encode_der(asn_TYPE_descriptor_t *td,
		void *structure, int tag_mode, ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *cb, void *app_key) {
	enum_4_inherit_TYPE_descriptor(td);
	return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

static asn_dec_rval_t
enum_4_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const char *opt_mname, const void *bufptr, size_t size) {
	enum_4_inherit_TYPE_descriptor(td);
	return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

static asn_enc_rval_t
enum_4_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
		int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	enum_4_inherit_TYPE_descriptor(td);
	return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static const asn_INTEGER_enum_map_t asn_MAP_enum_value2enum_4[] = {
	{ 0,	1,	"b" },
	{ 1,	1,	"a" }
};
static const unsigned int asn_MAP_enum_enum2value_4[] = {
	1,	/* a(1) */
	0	/* b(0) */
};
static const asn_INTEGER_specifics_t asn_SPC_enum_specs_4 = {
	asn_MAP_enum_value2enum_4,	/* "tag" => N; sorted by tag */
	asn_MAP_enum_enum2value_4,	/* N => "tag"; sorted by N */
	2,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_enum_tags_4[] = {
	(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_enum_4 = {
	"enum",
	"enum",
	enum_4_free,
	enum_4_print,
	enum_4_constraint,
	enum_4_decode_ber,
	enum_4_encode_der,
	enum_4_decode_xer,
	enum_4_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_enum_tags_4,
	sizeof(asn_DEF_enum_tags_4)
		/sizeof(asn_DEF_enum_tags_4[0]) - 1, /* 1 */
	asn_DEF_enum_tags_4,	/* Same as above */
	sizeof(asn_DEF_enum_tags_4)
		/sizeof(asn_DEF_enum_tags_4[0]), /* 2 */
	0,	/* No PER visible constraints */
	0, 0,	/* Defined elsewhere */
	&asn_SPC_enum_specs_4	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_ExtensibleSet_1[] = {
	{ ATF_POINTER, 2, offsetof(struct ExtensibleSet, string),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_UTF8String,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"string"
		},
	{ ATF_POINTER, 1, offsetof(struct ExtensibleSet, Enum),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_enum_4,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"enum"
		},
};
static const ber_tlv_tag_t asn_DEF_ExtensibleSet_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (17 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_ExtensibleSet_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* string */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* enum */
};
static const uint8_t asn_MAP_ExtensibleSet_mmap_1[(2 + (8 * sizeof(unsigned int)) - 1) / 8] = {
	(0 << 7) | (0 << 6)
};
static asn_SET_specifics_t asn_SPC_ExtensibleSet_specs_1 = {
	sizeof(struct ExtensibleSet),
	offsetof(struct ExtensibleSet, _asn_ctx),
	offsetof(struct ExtensibleSet, _presence_map),
	asn_MAP_ExtensibleSet_tag2el_1,
	2,	/* Count of tags in the map */
	asn_MAP_ExtensibleSet_tag2el_1,	/* Same as above */
	2,	/* Count of tags in the CXER map */
	1,	/* Whether extensible */
	(unsigned int *)asn_MAP_ExtensibleSet_mmap_1	/* Mandatory elements map */
};
asn_TYPE_descriptor_t asn_DEF_ExtensibleSet = {
	"ExtensibleSet",
	"ExtensibleSet",
	SET_free,
	SET_print,
	SET_constraint,
	SET_decode_ber,
	SET_encode_der,
	SET_decode_xer,
	SET_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_ExtensibleSet_tags_1,
	sizeof(asn_DEF_ExtensibleSet_tags_1)
		/sizeof(asn_DEF_ExtensibleSet_tags_1[0]), /* 1 */
	asn_DEF_ExtensibleSet_tags_1,	/* Same as above */
	sizeof(asn_DEF_ExtensibleSet_tags_1)
		/sizeof(asn_DEF_ExtensibleSet_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_ExtensibleSet_1,
	2,	/* Elements count */
	&asn_SPC_ExtensibleSet_specs_1	/* Additional specs */
};
