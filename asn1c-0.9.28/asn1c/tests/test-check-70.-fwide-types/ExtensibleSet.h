/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "ModuleTestXERDecoding"
 * 	found in "/home/intest/hozon/asnEDc/asn1c-0.9.28/tests/70-xer-test-OK.asn1"
 * 	`asn1c -S /home/intest/hozon/asnEDc/asn1c-0.9.28/skeletons -Wdebug-compiler -fwide-types`
 */

#ifndef	_ExtensibleSet_H_
#define	_ExtensibleSet_H_


#include <asn_application.h>

/* Including external dependencies */
#include <UTF8String.h>
#include <ENUMERATED.h>
#include <constr_SET.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */

/*
 * Method of determining the components presence
 */
typedef enum ExtensibleSet_PR {
	ExtensibleSet_PR_string,	/* Member string is present */
	ExtensibleSet_PR_enum,	/* Member enum is present */
} ExtensibleSet_PR;
typedef enum Enum {
	enum_b	= 0,
	enum_a	= 1
} e_enum;

/* ExtensibleSet */
typedef struct ExtensibleSet {
	UTF8String_t	*string	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	ENUMERATED_t	*Enum;
	
	/* Presence bitmask: ASN_SET_ISPRESENT(pExtensibleSet, ExtensibleSet_PR_x) */
	unsigned int _presence_map
		[((2+(8*sizeof(unsigned int))-1)/(8*sizeof(unsigned int)))];
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ExtensibleSet_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_enum_4;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_ExtensibleSet;

#ifdef __cplusplus
}
#endif

#endif	/* _ExtensibleSet_H_ */
#include <asn_internal.h>
