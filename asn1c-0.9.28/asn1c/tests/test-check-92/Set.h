/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "ModuleCircularReferences"
 * 	found in "/home/intest/hozon/asnEDc/asn1c-0.9.28/tests/92-circular-loops-OK.asn1"
 * 	`asn1c -S /home/intest/hozon/asnEDc/asn1c-0.9.28/skeletons -Wdebug-compiler`
 */

#ifndef	_Set_H_
#define	_Set_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SET_OF.h>
#include <NativeInteger.h>
#include <constr_SEQUENCE.h>
#include <constr_SET_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct Set;
struct Sequence;

/* Set */
typedef struct Set {
	A_SET_OF(struct Member {
		long	 Int;
		struct Set	*set;
		struct Sequence	*seq;
		struct Set	*set2	/* OPTIONAL */;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
		struct Set	*set3;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} ) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Set_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Set;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "Set.h"
#include "Sequence.h"

#endif	/* _Set_H_ */
#include <asn_internal.h>
