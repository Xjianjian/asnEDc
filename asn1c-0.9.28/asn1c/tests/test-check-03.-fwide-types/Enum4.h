/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "ModuleTestEnum1"
 * 	found in "/home/intest/hozon/asnEDc/asn1c-0.9.28/tests/03-enum-OK.asn1"
 * 	`asn1c -S /home/intest/hozon/asnEDc/asn1c-0.9.28/skeletons -Wdebug-compiler -fwide-types`
 */

#ifndef	_Enum4_H_
#define	_Enum4_H_


#include <asn_application.h>

/* Including external dependencies */
#include <ENUMERATED.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum Enum4 {
	Enum4_a	= 0,
	Enum4_b	= 1,
	/*
	 * Enumeration is extensible
	 */
	Enum4_c	= 3,
	Enum4_d	= 4
} e_Enum4;

/* Enum4 */
typedef ENUMERATED_t	 Enum4_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Enum4;
asn_struct_free_f Enum4_free;
asn_struct_print_f Enum4_print;
asn_constr_check_f Enum4_constraint;
ber_type_decoder_f Enum4_decode_ber;
der_type_encoder_f Enum4_encode_der;
xer_type_decoder_f Enum4_decode_xer;
xer_type_encoder_f Enum4_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _Enum4_H_ */
#include <asn_internal.h>
