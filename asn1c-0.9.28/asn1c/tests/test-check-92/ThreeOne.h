/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "ModuleCircularReferences"
 * 	found in "/home/intest/hozon/asnEDc/asn1c-0.9.28/tests/92-circular-loops-OK.asn1"
 * 	`asn1c -S /home/intest/hozon/asnEDc/asn1c-0.9.28/skeletons -Wdebug-compiler`
 */

#ifndef	_ThreeOne_H_
#define	_ThreeOne_H_


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
typedef enum ThreeOne_PR {
	ThreeOne_PR_m31,	/* Member m31 is present */
	ThreeOne_PR_g,	/* Member g is present */
} ThreeOne_PR;

/* Forward declarations */
struct OneTwo;
struct Gamma;

/* ThreeOne */
typedef struct ThreeOne {
	struct OneTwo	*m31;
	struct Gamma	*g;
	
	/* Presence bitmask: ASN_SET_ISPRESENT(pThreeOne, ThreeOne_PR_x) */
	unsigned int _presence_map
		[((2+(8*sizeof(unsigned int))-1)/(8*sizeof(unsigned int)))];
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ThreeOne_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ThreeOne;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "OneTwo.h"
#include "Gamma.h"

#endif	/* _ThreeOne_H_ */
#include <asn_internal.h>