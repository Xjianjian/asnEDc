/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "ModuleNestedConstraintsCheck"
 * 	found in "/home/intest/hozon/asnEDc/asn1c-0.9.28/tests/50-constraint-OK.asn1"
 * 	`asn1c -S /home/intest/hozon/asnEDc/asn1c-0.9.28/skeletons -Wdebug-compiler`
 */

#ifndef	_Str1_H_
#define	_Str1_H_


#include <asn_application.h>

/* Including external dependencies */
#include <IA5String.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Str1 */
typedef IA5String_t	 Str1_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Str1;
asn_struct_free_f Str1_free;
asn_struct_print_f Str1_print;
asn_constr_check_f Str1_constraint;
ber_type_decoder_f Str1_decode_ber;
der_type_encoder_f Str1_encode_der;
xer_type_decoder_f Str1_decode_xer;
xer_type_encoder_f Str1_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _Str1_H_ */
#include <asn_internal.h>
