/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "ModuleTestANYSyntax"
 * 	found in "/home/intest/hozon/asnEDc/asn1c-0.9.28/tests/62-any-OK.asn1"
 * 	`asn1c -S /home/intest/hozon/asnEDc/asn1c-0.9.28/skeletons -Wdebug-compiler`
 */

#ifndef	_T_H_
#define	_T_H_


#include <asn_application.h>

/* Including external dependencies */
#include "T1-ext.h"
#include "T2.h"
#include "T3.h"
#include "T4.h"
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum T_PR {
	T_PR_NOTHING,	/* No components present */
	T_PR_s1,
	T_PR_s2,
	T_PR_s3,
	T_PR_s4
} T_PR;

/* T */
typedef struct T {
	T_PR present;
	union T_u {
		T1_ext_t	 s1;
		T2_t	 s2;
		T3_t	 s3;
		T4_t	 s4;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} T_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_T;

#ifdef __cplusplus
}
#endif

#endif	/* _T_H_ */
#include <asn_internal.h>
