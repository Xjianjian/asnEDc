/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "ModuleTestSequenceSimple"
 * 	found in "/home/intest/hozon/asnEDc/asn1c-0.9.28/tests/32-sequence-of-OK.asn1"
 * 	`asn1c -S /home/intest/hozon/asnEDc/asn1c-0.9.28/skeletons -Wdebug-compiler`
 */

#ifndef	_Fault_H_
#define	_Fault_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SET_OF.h>
#include <constr_SET_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct Error;

/* Fault */
typedef struct Fault {
	A_SET_OF(struct Error) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Fault_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Fault;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "Error.h"

#endif	/* _Fault_H_ */
#include <asn_internal.h>
