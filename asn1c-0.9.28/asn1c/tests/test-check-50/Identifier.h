/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "IdentifierModule"
 * 	found in "/home/intest/hozon/asnEDc/asn1c-0.9.28/tests/50-constraint-OK.asn1"
 * 	`asn1c -S /home/intest/hozon/asnEDc/asn1c-0.9.28/skeletons -Wdebug-compiler`
 */

#ifndef	_Identifier_H_
#define	_Identifier_H_


#include <asn_application.h>

/* Including external dependencies */
#include <VisibleString.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Identifier */
typedef VisibleString_t	 Identifier_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Identifier;
asn_struct_free_f Identifier_free;
asn_struct_print_f Identifier_print;
asn_constr_check_f Identifier_constraint;
ber_type_decoder_f Identifier_decode_ber;
der_type_encoder_f Identifier_encode_der;
xer_type_decoder_f Identifier_decode_xer;
xer_type_encoder_f Identifier_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _Identifier_H_ */
#include <asn_internal.h>
