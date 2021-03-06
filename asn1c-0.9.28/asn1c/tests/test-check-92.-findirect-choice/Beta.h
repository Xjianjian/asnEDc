/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "ModuleCircularReferences"
 * 	found in "/home/intest/hozon/asnEDc/asn1c-0.9.28/tests/92-circular-loops-OK.asn1"
 * 	`asn1c -S /home/intest/hozon/asnEDc/asn1c-0.9.28/skeletons -Wdebug-compiler -findirect-choice`
 */

#ifndef	_Beta_H_
#define	_Beta_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct Alpha;
struct Gamma;

/* Beta */
typedef struct Beta {
	struct Alpha	*b	/* OPTIONAL */;
	struct Gamma	*g	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Beta_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Beta;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "Alpha.h"
#include "Gamma.h"

#endif	/* _Beta_H_ */
#include <asn_internal.h>
