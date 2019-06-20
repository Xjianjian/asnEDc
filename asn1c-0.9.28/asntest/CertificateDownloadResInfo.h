/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "HOZON"
 * 	found in "HOZON_PRIV_v1.0.asn"
 * 	`asn1c -gen-PER`
 */

#ifndef	_CertificateDownloadResInfo_H_
#define	_CertificateDownloadResInfo_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include <BOOLEAN.h>
#include <INTEGER.h>
#include <OCTET_STRING.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* CertificateDownloadResInfo */
typedef struct CertificateDownloadResInfo {
	long	 mid;
	long	 eventId;
	BOOLEAN_t	 result;
	long	*failureType	/* OPTIONAL */;
	long	*certType	/* OPTIONAL */;
	INTEGER_t	*certLength	/* OPTIONAL */;
	OCTET_STRING_t	*certContent	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} CertificateDownloadResInfo_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_CertificateDownloadResInfo;

#ifdef __cplusplus
}
#endif

#endif	/* _CertificateDownloadResInfo_H_ */
#include <asn_internal.h>
