/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "ModuleTestMultipleTags"
 * 	found in "/home/intest/hozon/asnEDc/asn1c-0.9.28/tests/65-multi-tag-OK.asn1"
 * 	`asn1c -S /home/intest/hozon/asnEDc/asn1c-0.9.28/skeletons -Wdebug-compiler`
 */

#ifndef	_T1_H_
#define	_T1_H_


#include <asn_application.h>

/* Including external dependencies */
#include "T2.h"

#ifdef __cplusplus
extern "C" {
#endif

/* T1 */
typedef T2_t	 T1_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_T1;
asn_struct_free_f T1_free;
asn_struct_print_f T1_print;
asn_constr_check_f T1_constraint;
ber_type_decoder_f T1_decode_ber;
der_type_encoder_f T1_encode_der;
xer_type_decoder_f T1_decode_xer;
xer_type_encoder_f T1_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _T1_H_ */
#include <asn_internal.h>
