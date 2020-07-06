/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "HOZON"
 * 	found in "HOZON_PRIV_v1.0.asn"
 * 	`asn1c -gen-PER`
 */

#ifndef	_XcallRespinfo_H_
#define	_XcallRespinfo_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct RvsposInfo;

/* XcallRespinfo */
typedef struct XcallRespinfo {
	long	 xcallType;
	long	 engineSt;
	long	 ttOdoMeter;
	struct gpsPos {
		A_SEQUENCE_OF(struct RvsposInfo) list;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} gpsPos;
	long	 srsSt;
	long	 updataTime;
	long	 battSOCEx;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} XcallRespinfo_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_XcallRespinfo;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "RvsposInfo.h"

#endif	/* _XcallRespinfo_H_ */
#include <asn_internal.h>