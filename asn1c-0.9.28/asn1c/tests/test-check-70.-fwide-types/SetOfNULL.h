/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "ModuleTestXERDecoding"
 * 	found in "/home/intest/hozon/asnEDc/asn1c-0.9.28/tests/70-xer-test-OK.asn1"
 * 	`asn1c -S /home/intest/hozon/asnEDc/asn1c-0.9.28/skeletons -Wdebug-compiler -fwide-types`
 */

#ifndef	_SetOfNULL_H_
#define	_SetOfNULL_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NULL.h>
#include <asn_SET_OF.h>
#include <constr_SET_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* SetOfNULL */
typedef struct SetOfNULL {
	A_SET_OF(NULL_t) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} SetOfNULL_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SetOfNULL;

#ifdef __cplusplus
}
#endif

#endif	/* _SetOfNULL_H_ */
#include <asn_internal.h>