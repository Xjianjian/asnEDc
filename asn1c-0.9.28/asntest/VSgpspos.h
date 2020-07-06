/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "HOZON"
 * 	found in "HOZON_PRIV_v1.0.asn"
 * 	`asn1c -gen-PER`
 */

#ifndef	_VSgpspos_H_
#define	_VSgpspos_H_


#include <asn_application.h>

/* Including external dependencies */
#include <BOOLEAN.h>
#include <NativeInteger.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* VSgpspos */
typedef struct VSgpspos {
	BOOLEAN_t	 gpsSt;
	long	 gpsTimestamp;
	long	 latitude;
	long	 longitude;
	long	 altitude;
	long	 heading;
	long	 gpsSpeed;
	long	 hdop;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} VSgpspos_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_VSgpspos;

#ifdef __cplusplus
}
#endif

#endif	/* _VSgpspos_H_ */
#include <asn_internal.h>