/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "ModuleTestSameNames"
 * 	found in "/home/intest/hozon/asnEDc/asn1c-0.9.28/tests/72-same-names-OK.asn1"
 * 	`asn1c -S /home/intest/hozon/asnEDc/asn1c-0.9.28/skeletons -Wdebug-compiler -fcompound-names`
 */

#ifndef	_Type_H_
#define	_Type_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SET_OF.h>
#include "Type1.h"
#include "Type2.h"
#include <constr_SEQUENCE.h>
#include <constr_SET_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Type */
typedef struct Type {
	A_SET_OF(struct Type__Member {
		Type1_t	 t1;
		Type2_t	 t2;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} ) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Type_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Type;

#ifdef __cplusplus
}
#endif

#endif	/* _Type_H_ */
#include <asn_internal.h>
