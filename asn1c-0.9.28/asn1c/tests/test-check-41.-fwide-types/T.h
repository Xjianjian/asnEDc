/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "ModuleTestIntOptional"
 * 	found in "/home/intest/hozon/asnEDc/asn1c-0.9.28/tests/41-int-optional-OK.asn1"
 * 	`asn1c -S /home/intest/hozon/asnEDc/asn1c-0.9.28/skeletons -Wdebug-compiler -fwide-types`
 */

#ifndef	_T_H_
#define	_T_H_


#include <asn_application.h>

/* Including external dependencies */
#include <UTF8String.h>
#include <INTEGER.h>
#include <constr_SEQUENCE.h>
#include <constr_SET.h>
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum T_PR {
	T_PR_NOTHING,	/* No components present */
	T_PR_seq,
	T_PR_set
} T_PR;

/*
 * Method of determining the components presence
 */
typedef enum set_PR {
	set_PR_string,	/* Member string is present */
	set_PR_alpha,	/* Member alpha is present */
	set_PR_beta,	/* Member beta is present */
} set_PR;

/* T */
typedef struct T {
	T_PR present;
	union T_u {
		struct seq {
			UTF8String_t	 string;
			INTEGER_t	*alpha	/* OPTIONAL */;
			INTEGER_t	*beta	/* OPTIONAL */;
			
			/* Context for parsing across buffer boundaries */
			asn_struct_ctx_t _asn_ctx;
		} seq;
		struct set {
			UTF8String_t	 string;
			INTEGER_t	*alpha	/* OPTIONAL */;
			INTEGER_t	*beta	/* OPTIONAL */;
			
			/* Presence bitmask: ASN_SET_ISPRESENT(pset, set_PR_x) */
			unsigned int _presence_map
				[((3+(8*sizeof(unsigned int))-1)/(8*sizeof(unsigned int)))];
			
			/* Context for parsing across buffer boundaries */
			asn_struct_ctx_t _asn_ctx;
		} set;
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
