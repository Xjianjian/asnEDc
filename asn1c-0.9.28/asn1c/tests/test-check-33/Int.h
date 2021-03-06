/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "ModuleTestMiscComplex"
 * 	found in "/home/intest/hozon/asnEDc/asn1c-0.9.28/tests/33-misc-OK.asn1"
 * 	`asn1c -S /home/intest/hozon/asnEDc/asn1c-0.9.28/skeletons -Wdebug-compiler`
 */

#ifndef	_Int_H_
#define	_Int_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum Int {
	Int_a	= 1,
	Int_b	= 2
} e_Int;

/* Int */
typedef long	 Int_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Int;
asn_struct_free_f Int_free;
asn_struct_print_f Int_print;
asn_constr_check_f Int_constraint;
ber_type_decoder_f Int_decode_ber;
der_type_encoder_f Int_encode_der;
xer_type_decoder_f Int_decode_xer;
xer_type_encoder_f Int_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _Int_H_ */
#include <asn_internal.h>
