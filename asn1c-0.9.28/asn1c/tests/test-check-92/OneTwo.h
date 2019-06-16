/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "ModuleCircularReferences"
 * 	found in "/home/intest/hozon/asnEDc/asn1c-0.9.28/tests/92-circular-loops-OK.asn1"
 * 	`asn1c -S /home/intest/hozon/asnEDc/asn1c-0.9.28/skeletons -Wdebug-compiler`
 */

#ifndef	_OneTwo_H_
#define	_OneTwo_H_


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
typedef enum OneTwo_PR {
	OneTwo_PR_m12,	/* Member m12 is present */
} OneTwo_PR;

/* Forward declarations */
struct TwoThree;

/* OneTwo */
typedef struct OneTwo {
	struct TwoThree	*m12;
	
	/* Presence bitmask: ASN_SET_ISPRESENT(pOneTwo, OneTwo_PR_x) */
	unsigned int _presence_map
		[((1+(8*sizeof(unsigned int))-1)/(8*sizeof(unsigned int)))];
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} OneTwo_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_OneTwo;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "TwoThree.h"

#endif	/* _OneTwo_H_ */
#include <asn_internal.h>