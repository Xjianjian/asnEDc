/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "ModuleTestSequenceSimple"
 * 	found in "/home/intest/hozon/asnEDc/asn1c-0.9.28/tests/32-sequence-of-OK.asn1"
 * 	`asn1c -S /home/intest/hozon/asnEDc/asn1c-0.9.28/skeletons -Wdebug-compiler`
 */

#ifndef	_SeqWithOptional_H_
#define	_SeqWithOptional_H_


#include <asn_application.h>

/* Including external dependencies */
#include <UTF8String.h>
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct Error;

/* SeqWithOptional */
typedef struct SeqWithOptional {
	UTF8String_t	 someString;
	struct seqOfOpt {
		A_SEQUENCE_OF(struct Error) list;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *seqOfOpt;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} SeqWithOptional_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SeqWithOptional;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "Error.h"

#endif	/* _SeqWithOptional_H_ */
#include <asn_internal.h>
