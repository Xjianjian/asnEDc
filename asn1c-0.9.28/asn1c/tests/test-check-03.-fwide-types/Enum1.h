/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "ModuleTestEnum1"
 * 	found in "/home/intest/hozon/asnEDc/asn1c-0.9.28/tests/03-enum-OK.asn1"
 * 	`asn1c -S /home/intest/hozon/asnEDc/asn1c-0.9.28/skeletons -Wdebug-compiler -fwide-types`
 */

#ifndef	_Enum1_H_
#define	_Enum1_H_


#include <asn_application.h>

/* Including external dependencies */
#include <ENUMERATED.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum Enum1 {
	Enum1_red	= 0,
	Enum1_green	= 1,
	Enum1_blue	= 4,
	Enum1_alpha	= 5
	/*
	 * Enumeration is extensible
	 */
} e_Enum1;

/* Enum1 */
typedef ENUMERATED_t	 Enum1_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Enum1;
asn_struct_free_f Enum1_free;
asn_struct_print_f Enum1_print;
asn_constr_check_f Enum1_constraint;
ber_type_decoder_f Enum1_decode_ber;
der_type_encoder_f Enum1_encode_der;
xer_type_decoder_f Enum1_decode_xer;
xer_type_encoder_f Enum1_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _Enum1_H_ */
#include <asn_internal.h>
