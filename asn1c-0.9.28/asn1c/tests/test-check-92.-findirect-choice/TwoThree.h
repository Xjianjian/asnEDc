/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "ModuleCircularReferences"
 * 	found in "/home/intest/hozon/asnEDc/asn1c-0.9.28/tests/92-circular-loops-OK.asn1"
 * 	`asn1c -S /home/intest/hozon/asnEDc/asn1c-0.9.28/skeletons -Wdebug-compiler -findirect-choice`
 */

#ifndef	_TwoThree_H_
#define	_TwoThree_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_SET.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */

/*
 * Method of determining the components presence
 */
typedef enum TwoThree_PR {
	TwoThree_PR_m23,	/* Member m23 is present */
} TwoThree_PR;

/* Forward declarations */
struct ThreeOne;

/* TwoThree */
typedef struct TwoThree {
	struct ThreeOne	*m23;
	
	/* Presence bitmask: ASN_SET_ISPRESENT(pTwoThree, TwoThree_PR_x) */
	unsigned int _presence_map
		[((1+(8*sizeof(unsigned int))-1)/(8*sizeof(unsigned int)))];
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} TwoThree_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_TwoThree;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "ThreeOne.h"

#endif	/* _TwoThree_H_ */
#include <asn_internal.h>