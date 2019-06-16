/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "ModuleCircularReferences"
 * 	found in "/home/intest/hozon/asnEDc/asn1c-0.9.28/tests/92-circular-loops-OK.asn1"
 * 	`asn1c -S /home/intest/hozon/asnEDc/asn1c-0.9.28/skeletons -Wdebug-compiler -findirect-choice`
 */

#ifndef	_Gamma_H_
#define	_Gamma_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct TwoThree;
struct Alpha;
struct Beta;

/* Gamma */
typedef struct Gamma {
	struct TwoThree	*o;
	struct Alpha	*a;
	struct Beta	*b;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Gamma_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Gamma;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "TwoThree.h"
#include "Alpha.h"
#include "Beta.h"

#endif	/* _Gamma_H_ */
#include <asn_internal.h>
