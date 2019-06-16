/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "ModulePERChoice"
 * 	found in "/home/intest/hozon/asnEDc/asn1c-0.9.28/tests/132-per-choice-OK.asn1"
 * 	`asn1c -S /home/intest/hozon/asnEDc/asn1c-0.9.28/skeletons -Wdebug-compiler -gen-PER`
 */

#ifndef	_T_H_
#define	_T_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum T_PR {
	T_PR_NOTHING,	/* No components present */
	T_PR_first,
	T_PR_second
} T_PR;
typedef enum first_PR {
	first_PR_NOTHING,	/* No components present */
	first_PR_nothing
} first_PR;

/* T */
typedef struct T {
	T_PR present;
	union T_u {
		struct first {
			first_PR present;
			union T__first_u {
				long	 nothing;
			} choice;
			
			/* Context for parsing across buffer boundaries */
			asn_struct_ctx_t _asn_ctx;
		} first;
		long	 second;
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
