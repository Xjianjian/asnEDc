/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "ModuleRecursion"
 * 	found in "/home/intest/hozon/asnEDc/asn1c-0.9.28/tests/43-recursion-OK.asn1"
 * 	`asn1c -S /home/intest/hozon/asnEDc/asn1c-0.9.28/skeletons -Wdebug-compiler`
 */

#ifndef	_Choice_1_H_
#define	_Choice_1_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include <asn_SET_OF.h>
#include <constr_SET_OF.h>
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum Choice_1_PR {
	Choice_1_PR_NOTHING,	/* No components present */
	Choice_1_PR_and,
	Choice_1_PR_or,
	Choice_1_PR_not,
	Choice_1_PR_other
} Choice_1_PR;

/* Forward declarations */
struct Choice_1;

/* Choice-1 */
typedef struct Choice_1 {
	Choice_1_PR present;
	union Choice_1_u {
		struct Choice_1	*And;
		struct Or {
			A_SET_OF(struct Choice_1) list;
			
			/* Context for parsing across buffer boundaries */
			asn_struct_ctx_t _asn_ctx;
		} Or;
		struct Choice_1	*Not;
		long	 other;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Choice_1_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Choice_1;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "Choice-1.h"

#endif	/* _Choice_1_H_ */
#include <asn_internal.h>
