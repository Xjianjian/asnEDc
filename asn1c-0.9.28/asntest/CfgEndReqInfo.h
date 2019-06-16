/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "HOZON"
 * 	found in "HOZON_PRIV_v1.0.asn"
 * 	`asn1c -gen-PER`
 */

#ifndef	_CfgEndReqInfo_H_
#define	_CfgEndReqInfo_H_


#include <asn_application.h>

/* Including external dependencies */
#include <BOOLEAN.h>
#include <OCTET_STRING.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* CfgEndReqInfo */
typedef struct CfgEndReqInfo {
	BOOLEAN_t	 configSuccess;
	OCTET_STRING_t	 mcuSw;
	OCTET_STRING_t	 mpuSw;
	OCTET_STRING_t	 configSw;
	OCTET_STRING_t	 cfgVersion;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} CfgEndReqInfo_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_CfgEndReqInfo;

#ifdef __cplusplus
}
#endif

#endif	/* _CfgEndReqInfo_H_ */
#include <asn_internal.h>
