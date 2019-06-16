/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "ModuleTestANYSyntax"
 * 	found in "/home/intest/hozon/asnEDc/asn1c-0.9.28/tests/62-any-OK.asn1"
 * 	`asn1c -S /home/intest/hozon/asnEDc/asn1c-0.9.28/skeletons -Wdebug-compiler`
 */

#ifndef	_T3_H_
#define	_T3_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NumericString.h>
#include <BOOLEAN.h>
#include <constr_SET.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */

/*
 * Method of determining the components presence
 */
typedef enum T3_PR {
	T3_PR_m1,	/* Member m1 is present */
	T3_PR_m2,	/* Member m2 is present */
} T3_PR;

/* T3 */
typedef struct T3 {
	NumericString_t	 m1;
	BOOLEAN_t	 m2;
	
	/* Presence bitmask: ASN_SET_ISPRESENT(pT3, T3_PR_x) */
	unsigned int _presence_map
		[((2+(8*sizeof(unsigned int))-1)/(8*sizeof(unsigned int)))];
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} T3_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_T3;

#ifdef __cplusplus
}
#endif

#endif	/* _T3_H_ */
#include <asn_internal.h>
