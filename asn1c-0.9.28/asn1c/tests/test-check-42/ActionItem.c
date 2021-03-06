/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "ModuleLAPStorage"
 * 	found in "/home/intest/hozon/asnEDc/asn1c-0.9.28/tests/42-real-life-OK.asn1"
 * 	`asn1c -S /home/intest/hozon/asnEDc/asn1c-0.9.28/skeletons -Wdebug-compiler`
 */

#include "ActionItem.h"

static int
accept_as_2_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
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
accept_as_2_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {
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
accept_as_2_free(asn_TYPE_descriptor_t *td,
		void *struct_ptr, int contents_only) {
	accept_as_2_inherit_TYPE_descriptor(td);
	td->free_struct(td, struct_ptr, contents_only);
}

static int
accept_as_2_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
		int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	accept_as_2_inherit_TYPE_descriptor(td);
	return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

static asn_dec_rval_t
accept_as_2_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const void *bufptr, size_t size, int tag_mode) {
	accept_as_2_inherit_TYPE_descriptor(td);
	return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

static asn_enc_rval_t
accept_as_2_encode_der(asn_TYPE_descriptor_t *td,
		void *structure, int tag_mode, ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *cb, void *app_key) {
	accept_as_2_inherit_TYPE_descriptor(td);
	return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

static asn_dec_rval_t
accept_as_2_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const char *opt_mname, const void *bufptr, size_t size) {
	accept_as_2_inherit_TYPE_descriptor(td);
	return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

static asn_enc_rval_t
accept_as_2_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
		int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	accept_as_2_inherit_TYPE_descriptor(td);
	return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static const asn_INTEGER_enum_map_t asn_MAP_accept_as_value2enum_2[] = {
	{ 0,	7,	"unknown" },
	{ 1,	4,	"safe" },
	{ 2,	6,	"unsafe" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_accept_as_enum2value_2[] = {
	1,	/* safe(1) */
	0,	/* unknown(0) */
	2	/* unsafe(2) */
	/* This list is extensible */
};
static const asn_INTEGER_specifics_t asn_SPC_accept_as_specs_2 = {
	asn_MAP_accept_as_value2enum_2,	/* "tag" => N; sorted by tag */
	asn_MAP_accept_as_enum2value_2,	/* N => "tag"; sorted by N */
	3,	/* Number of elements in the maps */
	4,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_accept_as_tags_2[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_accept_as_2 = {
	"accept-as",
	"accept-as",
	accept_as_2_free,
	accept_as_2_print,
	accept_as_2_constraint,
	accept_as_2_decode_ber,
	accept_as_2_encode_der,
	accept_as_2_decode_xer,
	accept_as_2_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_accept_as_tags_2,
	sizeof(asn_DEF_accept_as_tags_2)
		/sizeof(asn_DEF_accept_as_tags_2[0]), /* 1 */
	asn_DEF_accept_as_tags_2,	/* Same as above */
	sizeof(asn_DEF_accept_as_tags_2)
		/sizeof(asn_DEF_accept_as_tags_2[0]), /* 1 */
	0,	/* No PER visible constraints */
	0, 0,	/* Defined elsewhere */
	&asn_SPC_accept_as_specs_2	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_email_9[] = {
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
static const ber_tlv_tag_t asn_DEF_email_tags_9[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (17 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_email_specs_9 = {
	sizeof(struct email),
	offsetof(struct email, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_email_9 = {
	"email",
	"email",
	SET_OF_free,
	SET_OF_print,
	SET_OF_constraint,
	SET_OF_decode_ber,
	SET_OF_encode_der,
	SET_OF_decode_xer,
	SET_OF_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_email_tags_9,
	sizeof(asn_DEF_email_tags_9)
		/sizeof(asn_DEF_email_tags_9[0]), /* 1 */
	asn_DEF_email_tags_9,	/* Same as above */
	sizeof(asn_DEF_email_tags_9)
		/sizeof(asn_DEF_email_tags_9[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_email_9,
	1,	/* Single element */
	&asn_SPC_email_specs_9	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_notify_7[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct notify, critical),
		(ASN_TAG_CLASS_UNIVERSAL | (1 << 2)),
		0,
		&asn_DEF_BOOLEAN,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"critical"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct notify, email),
		(ASN_TAG_CLASS_UNIVERSAL | (17 << 2)),
		0,
		&asn_DEF_email_9,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"email"
		},
};
static const ber_tlv_tag_t asn_DEF_notify_tags_7[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_notify_tag2el_7[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (1 << 2)), 0, 0, 0 }, /* critical */
    { (ASN_TAG_CLASS_UNIVERSAL | (17 << 2)), 1, 0, 0 } /* email */
};
static asn_SEQUENCE_specifics_t asn_SPC_notify_specs_7 = {
	sizeof(struct notify),
	offsetof(struct notify, _asn_ctx),
	asn_MAP_notify_tag2el_7,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	1,	/* Start extensions */
	3	/* Stop extensions */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_notify_7 = {
	"notify",
	"notify",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_notify_tags_7,
	sizeof(asn_DEF_notify_tags_7)
		/sizeof(asn_DEF_notify_tags_7[0]), /* 1 */
	asn_DEF_notify_tags_7,	/* Same as above */
	sizeof(asn_DEF_notify_tags_7)
		/sizeof(asn_DEF_notify_tags_7[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_notify_7,
	2,	/* Elements count */
	&asn_SPC_notify_specs_7	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_ActionItem_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct ActionItem, accept_as),
		(ASN_TAG_CLASS_UNIVERSAL | (10 << 2)),
		0,
		&asn_DEF_accept_as_2,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"accept-as"
		},
	{ ATF_POINTER, 1, offsetof(struct ActionItem, notify),
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_notify_7,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"notify"
		},
};
static const ber_tlv_tag_t asn_DEF_ActionItem_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_ActionItem_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (10 << 2)), 0, 0, 0 }, /* accept-as */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 1, 0, 0 } /* notify */
};
static asn_SEQUENCE_specifics_t asn_SPC_ActionItem_specs_1 = {
	sizeof(struct ActionItem),
	offsetof(struct ActionItem, _asn_ctx),
	asn_MAP_ActionItem_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	1,	/* Start extensions */
	3	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_ActionItem = {
	"ActionItem",
	"ActionItem",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_ActionItem_tags_1,
	sizeof(asn_DEF_ActionItem_tags_1)
		/sizeof(asn_DEF_ActionItem_tags_1[0]), /* 1 */
	asn_DEF_ActionItem_tags_1,	/* Same as above */
	sizeof(asn_DEF_ActionItem_tags_1)
		/sizeof(asn_DEF_ActionItem_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_ActionItem_1,
	2,	/* Elements count */
	&asn_SPC_ActionItem_specs_1	/* Additional specs */
};

