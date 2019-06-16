/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "ModuleTestXERDecoding"
 * 	found in "/home/intest/hozon/asnEDc/asn1c-0.9.28/tests/70-xer-test-OK.asn1"
 * 	`asn1c -S /home/intest/hozon/asnEDc/asn1c-0.9.28/skeletons -Wdebug-compiler`
 */

#ifndef	_SimpleChoice_H_
#define	_SimpleChoice_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NULL.h>
#include <NativeInteger.h>
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum SimpleChoice_PR {
	SimpleChoice_PR_NOTHING,	/* No components present */
	SimpleChoice_PR_a,
	SimpleChoice_PR_b
} SimpleChoice_PR;

/* SimpleChoice */
typedef struct SimpleChoice {
	SimpleChoice_PR present;
	union SimpleChoice_u {
		NULL_t	 a;
		long	 b;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} SimpleChoice_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SimpleChoice;

#ifdef __cplusplus
}
#endif

#endif	/* _SimpleChoice_H_ */
#include <asn_internal.h>
