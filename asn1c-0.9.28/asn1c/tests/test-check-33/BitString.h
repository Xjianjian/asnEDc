/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "ModuleTestMiscComplex"
 * 	found in "/home/intest/hozon/asnEDc/asn1c-0.9.28/tests/33-misc-OK.asn1"
 * 	`asn1c -S /home/intest/hozon/asnEDc/asn1c-0.9.28/skeletons -Wdebug-compiler`
 */

#ifndef	_BitString_H_
#define	_BitString_H_


#include <asn_application.h>

/* Including external dependencies */
#include <BIT_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* BitString */
typedef BIT_STRING_t	 BitString_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_BitString;
asn_struct_free_f BitString_free;
asn_struct_print_f BitString_print;
asn_constr_check_f BitString_constraint;
ber_type_decoder_f BitString_decode_ber;
der_type_encoder_f BitString_encode_der;
xer_type_decoder_f BitString_decode_xer;
xer_type_encoder_f BitString_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _BitString_H_ */
#include <asn_internal.h>