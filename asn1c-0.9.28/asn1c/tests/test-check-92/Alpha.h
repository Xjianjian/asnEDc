/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "ModuleCircularReferences"
 * 	found in "/home/intest/hozon/asnEDc/asn1c-0.9.28/tests/92-circular-loops-OK.asn1"
 * 	`asn1c -S /home/intest/hozon/asnEDc/asn1c-0.9.28/skeletons -Wdebug-compiler`
 */

#ifndef	_Alpha_H_
#define	_Alpha_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct Beta;

/* Alpha */
typedef struct Alpha {
	struct Beta	*a;
	struct b {
		struct Beta	*b	/* OPTIONAL */;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} b;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Alpha_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Alpha;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "Beta.h"

#endif	/* _Alpha_H_ */
#include <asn_internal.h>