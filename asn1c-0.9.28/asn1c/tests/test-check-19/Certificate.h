/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "ModuleTestParam"
 * 	found in "/home/intest/hozon/asnEDc/asn1c-0.9.28/tests/19-param-OK.asn1"
 * 	`asn1c -S /home/intest/hozon/asnEDc/asn1c-0.9.28/skeletons -Wdebug-compiler`
 */

#ifndef	_Certificate_H_
#define	_Certificate_H_


#include <asn_application.h>

/* Including external dependencies */
#include "SIGNED.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Certificate */
typedef SIGNED_15P0_t	 Certificate_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Certificate;
asn_struct_free_f Certificate_free;
asn_struct_print_f Certificate_print;
asn_constr_check_f Certificate_constraint;
ber_type_decoder_f Certificate_decode_ber;
der_type_encoder_f Certificate_encode_der;
xer_type_decoder_f Certificate_decode_xer;
xer_type_encoder_f Certificate_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _Certificate_H_ */
#include <asn_internal.h>
