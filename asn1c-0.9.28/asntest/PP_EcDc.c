/******************************************************
文件名：	PrvtProt_EcDc.c

描述：	企业私有协议（浙江合众）,编解码	
Data			Vasion			author
2019/4/29		V1.0			liujian
*******************************************************/

/*******************************************************
description： include the header file
*******************************************************/
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/times.h>

#include <sys/types.h>
#include <sysexits.h>	/* for EX_* exit codes */
#include <assert.h>	/* for assert(3) */

#include <stdlib.h>
#include <time.h>
#include <wait.h>
#include <errno.h>
#include <netdb.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/time.h>


#include "constr_TYPE.h"
#include "asn_codecs.h"
#include "asn_application.h"
#include "asn_internal.h"	/* for _ASN_DEFAULT_STACK_MAX */
#include "XcallReqinfo.h"
#include "XcallRespinfo.h"
#include "Bodyinfo.h"
#include "RvsposInfo.h"
#include "CfgCheckReqInfo.h"
#include "CfgGetReqInfo.h"
#include "CfgGetRespInfo.h"
#include "CfgCheckRespInfo.h"
#include "CfgEndReqInfo.h"
#include "CfgConnRespInfo.h"
#include "CfgReadReqInfo.h"
#include "CfgReadRespInfo.h"
#include "RmtCtrlReqInfo.h"
#include "RmtCtrlStRespInfo.h"
#include "BookingResp.h"
#include "VehicleStReqInfo.h"
#include "VehicleStRespInfo.h"
#include "VSgpspos.h"
#include "VSExtStatus.h"

#include "DiagnosticReqInfo.h"
#include "DiagnosticRespInfo.h"
#include "DiagCode.h"

#include "DiagnosticStInfo.h"
#include "ImageAcquisitionReqInfo.h"
#include "ImageAcquisitionRespInfo.h"

#include "LogAcquisitionRespInfo.h"
#include "LogAcquisitionResInfo.h"

#include "per_encoder.h"
#include "per_decoder.h"

#include "PP_EcDc.h"
/*******************************************************
description： global variable definitions
*******************************************************/

/*******************************************************
description： static variable definitions
*******************************************************/
static asn_TYPE_descriptor_t *pduType_Body = &asn_DEF_Bodyinfo;
static asn_TYPE_descriptor_t *pduType_XcallReq = &asn_DEF_XcallReqinfo;
static asn_TYPE_descriptor_t *pduType_XcallResp = &asn_DEF_XcallRespinfo;

static asn_TYPE_descriptor_t *pduType_Cfg_check_req = &asn_DEF_CfgCheckReqInfo;
static asn_TYPE_descriptor_t *pduType_Cfg_check_resp = &asn_DEF_CfgCheckRespInfo;
static asn_TYPE_descriptor_t *pduType_Cfg_get_req = &asn_DEF_CfgGetReqInfo;
static asn_TYPE_descriptor_t *pduType_Cfg_get_resp = &asn_DEF_CfgGetRespInfo;
static asn_TYPE_descriptor_t *pduType_Cfg_end_req = &asn_DEF_CfgEndReqInfo;
static asn_TYPE_descriptor_t *pduType_Cfg_conn_resp = &asn_DEF_CfgConnRespInfo;
static asn_TYPE_descriptor_t *pduType_Cfg_read_req = &asn_DEF_CfgReadReqInfo;
static asn_TYPE_descriptor_t *pduType_Cfg_read_resp = &asn_DEF_CfgReadRespInfo;
static asn_TYPE_descriptor_t *pduType_Ctrl_Req = &asn_DEF_RmtCtrlReqInfo;
static asn_TYPE_descriptor_t *pduType_Rmt_Ctrl_resp = &asn_DEF_RmtCtrlStRespInfo;
static asn_TYPE_descriptor_t *pduType_Rmt_Ctrl_Bookingresp = &asn_DEF_BookingResp;

static asn_TYPE_descriptor_t *pduType_VS_req = &asn_DEF_VehicleStReqInfo;
static asn_TYPE_descriptor_t *pduType_VS_resp = &asn_DEF_VehicleStRespInfo;

static asn_TYPE_descriptor_t *pduType_GIAG_req = &asn_DEF_DiagnosticReqInfo;
static asn_TYPE_descriptor_t *pduType_GIAG_resp = &asn_DEF_DiagnosticRespInfo;

static asn_TYPE_descriptor_t *pduType_GIAG_st = &asn_DEF_DiagnosticStInfo;
static asn_TYPE_descriptor_t *pduType_GIAG_imageAcqReq = &asn_DEF_ImageAcquisitionReqInfo;
static asn_TYPE_descriptor_t *pduType_GIAG_imageAcqResp = &asn_DEF_ImageAcquisitionRespInfo;

static asn_TYPE_descriptor_t *pduType_GIAG_LogAcqResp = &asn_DEF_LogAcquisitionRespInfo;
static asn_TYPE_descriptor_t *pduType_GIAG_LogAcqRes = &asn_DEF_LogAcquisitionResInfo;

static PP_key_t PP_key;
/*******************************************************
description： function declaration
*******************************************************/
/*Global function declaration*/

/*Static function declaration*/
static int PP_writeout(const void *buffer,size_t size,void *key);
static int PP_msgPackageEncoding(uint8_t type,uint8_t *msgData,int *msgDataLen, \
					   void *disptrBody, void *appchoice);
static int PP_decodeMsgData(uint8_t *LeMessageData,int LeMessageDataLen,void *DisBody,void *appData);
static void PP_xcallreq(void);
static long PP_BSEndianReverse(long value);


static void PP_remotDiagnosticReq(void);
static void PP_remotDiagnosticResp(void);
static void PP_remotDiagnosticStatus(void);
static void PP_remotImageAcquisitionReq(void);
static void PP_remotImageAcquisitionResp(void);
static void PP_remotLogAcquisitionResp(void);
static void PP_remotLogAcquisitionRes(void);
/******************************************************
description： function code
******************************************************/
/******************************************************
*函数名：

*形  参：

*返回值：

*描  述：

*备  注：
******************************************************/
void main(void)
{
	//PP_xcallreq();

	//PP_remotDiagnosticReq();
	//PP_remotDiagnosticResp();

	//PP_remotDiagnosticStatus();
	//PP_remotImageAcquisitionReq();
	//PP_remotImageAcquisitionResp();
	//PP_remotLogAcquisitionResp();
	PP_remotLogAcquisitionRes();

}


/******************************************************
*函数名：

*形  参：

*返回值：

*描  述：xcall req

*备  注：
******************************************************/
static void PP_xcallreq(void)
{
	PP_pack_t pack_xcallreq;
	PP_DisptrBody_t disbody;
	PP_XcallReq_t app_xcallreq;
	int msgdatalen;
	int i;
	memset(&pack_xcallreq,0 , sizeof(PP_pack_t));
	memset(&disbody,0 , sizeof(PP_DisptrBody_t));
	memset(&app_xcallreq,0 , sizeof(PP_XcallReq_t));
/***************************
 * 编码
 */
	pack_xcallreq.Header.sign[0] = '*';
	pack_xcallreq.Header.sign[1] = '*';
	pack_xcallreq.Header.ver.Byte = 0x30;
	pack_xcallreq.Header.commtype.Byte = 0xe1;
	pack_xcallreq.Header.opera = 0x02;
	pack_xcallreq.Header.nonce  = PP_BSEndianReverse(0);
	pack_xcallreq.Header.tboxid = PP_BSEndianReverse(28);

	/*body*/
	memcpy(disbody.aID,"170",3);
	disbody.mID = 1;
	disbody.eventId = 170 + 1;
	disbody.eventTime = 123456;
	disbody.expTime   = 123456;
	disbody.ulMsgCnt++;	/* OPTIONAL */
	disbody.appDataProVer = 256;
	disbody.testFlag = 1;
	/*app data*/
	app_xcallreq.xcallType = 1;//紧急救援
	if(0 == PP_msgPackageEncoding(PP_ECDC_XCALLREQ,pack_xcallreq.msgdata,&msgdatalen, \
										&disbody,&app_xcallreq))
	{
		pack_xcallreq.Header.msglen = PP_BSEndianReverse(18 + msgdatalen);
		uint8_t *pack_ptr = pack_xcallreq.Header.sign;
		fprintf(stdout,"\n");
		fprintf(stdout,"\npackage is:\n");
		for(i = 0;i< (18 + msgdatalen);i++)
		{
			fprintf(stdout,"0x%x ", pack_ptr[i]);
		}
	}

/***************************
 * 解码
 */
	memset(&disbody,0 , sizeof(PP_DisptrBody_t));
	memset(&app_xcallreq,0 , sizeof(PP_XcallReq_t));
	PP_decodeMsgData(pack_xcallreq.msgdata,msgdatalen,&disbody,&app_xcallreq);
}



/******************************************************
*函数名：

*形  参：

*返回值：

*描  述：远程诊断( MID=1)

*备  注：
******************************************************/
static void PP_remotDiagnosticReq(void)
{
	PP_pack_t pp_pack;
	PP_DisptrBody_t disbody;
	PP_DiagnosticReq_t app_DiagnosticReq;
	int msgdatalen;
	int i;
	memset(&pp_pack,0 , sizeof(PP_pack_t));
	memset(&disbody,0 , sizeof(PP_DisptrBody_t));
	memset(&app_DiagnosticReq,0 , sizeof(PP_DiagnosticReq_t));
/***************************
 * 编码
 */
	pp_pack.Header.sign[0] = '*';
	pp_pack.Header.sign[1] = '*';
	pp_pack.Header.ver.Byte = 0x30;
	pp_pack.Header.commtype.Byte = 0xe1;
	pp_pack.Header.opera = 0x02;
	pp_pack.Header.nonce  = PP_BSEndianReverse(0);
	pp_pack.Header.tboxid = PP_BSEndianReverse(28);

	/*body*/
	memcpy(disbody.aID,"140",3);
	disbody.mID = 1;
	disbody.eventId = 140 + 1;
	disbody.eventTime = 123456;
	disbody.expTime   = 123456;
	disbody.ulMsgCnt++;	/* OPTIONAL */
	disbody.appDataProVer = 256;
	disbody.testFlag = 1;
	/*app data*/
	app_DiagnosticReq.diagType = 2;//
	if(0 == PP_msgPackageEncoding(PP_ECDC_RMTDIAG_REQ,pp_pack.msgdata,&msgdatalen, \
										&disbody,&app_DiagnosticReq))
	{
		pp_pack.Header.msglen = PP_BSEndianReverse(18 + msgdatalen);
		uint8_t *pack_ptr = pp_pack.Header.sign;
		fprintf(stdout,"\n");
		fprintf(stdout,"\npackage is:\n");
		for(i = 0;i< (18 + msgdatalen);i++)
		{
			fprintf(stdout,"0x%x ", pack_ptr[i]);
		}
	}

/***************************
 * 解码
 */
	memset(&disbody,0 , sizeof(PP_DisptrBody_t));
	memset(&app_DiagnosticReq,0 , sizeof(PP_DiagnosticReq_t));
	PP_decodeMsgData(pp_pack.msgdata,msgdatalen,&disbody,&app_DiagnosticReq);
}

/******************************************************
*函数名：

*形  参：

*返回值：

*描  述：远程诊断( MID=2)

*备  注：
******************************************************/
static void PP_remotDiagnosticResp(void)
{
	PP_pack_t pp_pack;
	PP_DisptrBody_t disbody;
	PP_DiagnosticResp_t app_PP_DiagnosticResp;
	int msgdatalen;
	int i;
	memset(&pp_pack,0 , sizeof(PP_pack_t));
	memset(&disbody,0 , sizeof(PP_DisptrBody_t));
	memset(&app_PP_DiagnosticResp,0 , sizeof(PP_DiagnosticResp_t));
/***************************
 * 编码
 */
	pp_pack.Header.sign[0] = '*';
	pp_pack.Header.sign[1] = '*';
	pp_pack.Header.ver.Byte = 0x30;
	pp_pack.Header.commtype.Byte = 0xe1;
	pp_pack.Header.opera = 0x02;
	pp_pack.Header.nonce  = PP_BSEndianReverse(0);
	pp_pack.Header.tboxid = PP_BSEndianReverse(28);

	/*body*/
	memcpy(disbody.aID,"140",3);
	disbody.mID = 2;
	disbody.eventId = 140 + 2;
	disbody.eventTime = 123456;
	disbody.expTime   = 123456;
	disbody.ulMsgCnt++;	/* OPTIONAL */
	disbody.appDataProVer = 256;
	disbody.testFlag = 1;
	/*app data*/
	app_PP_DiagnosticResp.diagType = 1;//
	app_PP_DiagnosticResp.result = 1;
	app_PP_DiagnosticResp.failureType = 0;
	for(i =0;i < 2;i++)
	{
		memcpy(app_PP_DiagnosticResp.diagCode[i].diagCode,"12345",5);
		app_PP_DiagnosticResp.diagCode[i].diagCodelen = 5;
		app_PP_DiagnosticResp.diagCode[i].diagTime = 123456+i;
		app_PP_DiagnosticResp.diagcodenum++;
	}

	if(0 == PP_msgPackageEncoding(PP_ECDC_RMTDIAG_RESP,pp_pack.msgdata,&msgdatalen, \
										&disbody,&app_PP_DiagnosticResp))
	{
		pp_pack.Header.msglen = PP_BSEndianReverse(18 + msgdatalen);
		uint8_t *pack_ptr = pp_pack.Header.sign;
		fprintf(stdout,"\n");
		fprintf(stdout,"\npackage is:\n");
		for(i = 0;i< (18 + msgdatalen);i++)
		{
			fprintf(stdout,"0x%x ", pack_ptr[i]);
		}
	}

/***************************
 * 解码
 */
	memset(&disbody,0 , sizeof(PP_DisptrBody_t));
	memset(&app_PP_DiagnosticResp,0 , sizeof(PP_DiagnosticResp_t));
	PP_decodeMsgData(pp_pack.msgdata,msgdatalen,&disbody,&app_PP_DiagnosticResp);
}

/******************************************************
*函数名：

*形  参：

*返回值：

*描  述：远程诊断( MID=3)

*备  注：
******************************************************/
static void PP_remotDiagnosticStatus(void)
{
	PP_pack_t pp_pack;
	PP_DisptrBody_t disbody;
	PP_DiagnosticStatus_t app_DiagnosticStatus;
	int msgdatalen;
	int i,j;
	memset(&pp_pack,0 , sizeof(PP_pack_t));
	memset(&disbody,0 , sizeof(PP_DisptrBody_t));
	memset(&app_DiagnosticStatus,0 , sizeof(PP_DiagnosticStatus_t));
/***************************
 * 编码
 */
	pp_pack.Header.sign[0] = '*';
	pp_pack.Header.sign[1] = '*';
	pp_pack.Header.ver.Byte = 0x30;
	pp_pack.Header.commtype.Byte = 0xe1;
	pp_pack.Header.opera = 0x02;
	pp_pack.Header.nonce  = PP_BSEndianReverse(0);
	pp_pack.Header.tboxid = PP_BSEndianReverse(28);

	/*body*/
	memcpy(disbody.aID,"140",3);
	disbody.mID = 3;
	disbody.eventId = 140 + 3;
	disbody.eventTime = 123456;
	disbody.expTime   = 123456;
	disbody.ulMsgCnt++;	/* OPTIONAL */
	disbody.appDataProVer = 256;
	disbody.testFlag = 1;
	/*app data*/
	for(i=0;i<3;i++)
	{
		app_DiagnosticStatus.diagStatus[i].diagType = i+1;//
		app_DiagnosticStatus.diagStatus[i].result = 1;
		app_DiagnosticStatus.diagStatus[i].failureType = 0;
		for(j=0;j<2;j++)
		{
			memcpy(app_DiagnosticStatus.diagStatus[i].diagCode[j].diagCode,"12345",5);
			app_DiagnosticStatus.diagStatus[i].diagCode[j].diagCodelen = 5;
			app_DiagnosticStatus.diagStatus[i].diagCode[j].diagTime = 123456+j;
			app_DiagnosticStatus.diagStatus[i].diagcodenum++;
		}
		app_DiagnosticStatus.faultnum++;
	}

	if(0 == PP_msgPackageEncoding(PP_ECDC_RMTDIAG_STATUS,pp_pack.msgdata,&msgdatalen, \
										&disbody,&app_DiagnosticStatus))
	{
		pp_pack.Header.msglen = PP_BSEndianReverse(18 + msgdatalen);
		uint8_t *pack_ptr = pp_pack.Header.sign;
		fprintf(stdout,"\n");
		fprintf(stdout,"\npackage is:\n");
		for(i = 0;i< (18 + msgdatalen);i++)
		{
			fprintf(stdout,"0x%x ", pack_ptr[i]);
		}
	}

/***************************
 * 解码
 */
	memset(&disbody,0 , sizeof(PP_DisptrBody_t));
	memset(&app_DiagnosticStatus,0 , sizeof(PP_DiagnosticStatus_t));
	PP_decodeMsgData(pp_pack.msgdata,msgdatalen,&disbody,&app_DiagnosticStatus);
}

/******************************************************
*函数名：

*形  参：

*返回值：

*描  述：远程诊断( MID=4)

*备  注：
******************************************************/
static void PP_remotImageAcquisitionReq(void)
{
	PP_pack_t pp_pack;
	PP_DisptrBody_t disbody;
	PP_ImageAcquisitionReq_t app_ImageAcquisitionReq;
	int msgdatalen;
	int i;
	memset(&pp_pack,0 , sizeof(PP_pack_t));
	memset(&disbody,0 , sizeof(PP_DisptrBody_t));
	memset(&app_ImageAcquisitionReq,0 , sizeof(PP_ImageAcquisitionReq_t));
/***************************
 * 编码
 */
	pp_pack.Header.sign[0] = '*';
	pp_pack.Header.sign[1] = '*';
	pp_pack.Header.ver.Byte = 0x30;
	pp_pack.Header.commtype.Byte = 0xe1;
	pp_pack.Header.opera = 0x02;
	pp_pack.Header.nonce  = PP_BSEndianReverse(0);
	pp_pack.Header.tboxid = PP_BSEndianReverse(28);

	/*body*/
	memcpy(disbody.aID,"140",3);
	disbody.mID = 4;
	disbody.eventId = 140 + 4;
	disbody.eventTime = 123456;
	disbody.expTime   = 123456;
	disbody.ulMsgCnt++;	/* OPTIONAL */
	disbody.appDataProVer = 256;
	disbody.testFlag = 1;
	/*app data*/
	app_ImageAcquisitionReq.dataType = 2;//
	app_ImageAcquisitionReq.cameraName = 1;//
	app_ImageAcquisitionReq.effectiveTime =123456;//
	app_ImageAcquisitionReq.sizeLimit = 100;//


	if(0 == PP_msgPackageEncoding(PP_ECDC_RMTDIAG_IMAGEACQREQ,pp_pack.msgdata,&msgdatalen, \
										&disbody,&app_ImageAcquisitionReq))
	{
		pp_pack.Header.msglen = PP_BSEndianReverse(18 + msgdatalen);
		uint8_t *pack_ptr = pp_pack.Header.sign;
		fprintf(stdout,"\n");
		fprintf(stdout,"\npackage is:\n");
		for(i = 0;i< (18 + msgdatalen);i++)
		{
			fprintf(stdout,"0x%x ", pack_ptr[i]);
		}
	}

/***************************
 * 解码
 */
	memset(&disbody,0 , sizeof(PP_DisptrBody_t));
	memset(&app_ImageAcquisitionReq,0 , sizeof(PP_ImageAcquisitionReq_t));
	PP_decodeMsgData(pp_pack.msgdata,msgdatalen,&disbody,&app_ImageAcquisitionReq);
}


/******************************************************
*函数名：

*形  参：

*返回值：

*描  述：远程诊断( MID=5)

*备  注：
******************************************************/
static void PP_remotImageAcquisitionResp(void)
{
	PP_pack_t pp_pack;
	PP_DisptrBody_t disbody;
	PP_ImageAcquisitionResp_t app_PP_ImageAcquisitionResp;
	int msgdatalen;
	int i;
	memset(&pp_pack,0 , sizeof(PP_pack_t));
	memset(&disbody,0 , sizeof(PP_DisptrBody_t));
	memset(&app_PP_ImageAcquisitionResp,0 , sizeof(PP_ImageAcquisitionResp_t));
/***************************
 * 编码
 */
	pp_pack.Header.sign[0] = '*';
	pp_pack.Header.sign[1] = '*';
	pp_pack.Header.ver.Byte = 0x30;
	pp_pack.Header.commtype.Byte = 0xe1;
	pp_pack.Header.opera = 0x02;
	pp_pack.Header.nonce  = PP_BSEndianReverse(0);
	pp_pack.Header.tboxid = PP_BSEndianReverse(28);

	/*body*/
	memcpy(disbody.aID,"140",3);
	disbody.mID = 5;
	disbody.eventId = 140 + 5;
	disbody.eventTime = 123456;
	disbody.expTime   = 123456;
	disbody.ulMsgCnt++;	/* OPTIONAL */
	disbody.appDataProVer = 256;
	disbody.testFlag = 1;
	/*app data*/
	app_PP_ImageAcquisitionResp.result = 1;
	app_PP_ImageAcquisitionResp.failureType = 0;
	memcpy(app_PP_ImageAcquisitionResp.fileName,"hozon_image",11);
	app_PP_ImageAcquisitionResp.fileNamelen = 11;

	if(0 == PP_msgPackageEncoding(PP_ECDC_RMTDIAG_IMAGEACQRESP,pp_pack.msgdata,&msgdatalen, \
										&disbody,&app_PP_ImageAcquisitionResp))
	{
		pp_pack.Header.msglen = PP_BSEndianReverse(18 + msgdatalen);
		uint8_t *pack_ptr = pp_pack.Header.sign;
		fprintf(stdout,"\n");
		fprintf(stdout,"\npackage is:\n");
		for(i = 0;i< (18 + msgdatalen);i++)
		{
			fprintf(stdout,"0x%x ", pack_ptr[i]);
		}
	}

/***************************
 * 解码
 */
	memset(&disbody,0 , sizeof(PP_DisptrBody_t));
	memset(&app_PP_ImageAcquisitionResp,0 , sizeof(PP_ImageAcquisitionResp_t));
	PP_decodeMsgData(pp_pack.msgdata,msgdatalen,&disbody,&app_PP_ImageAcquisitionResp);
}

/******************************************************
*函数名：

*形  参：

*返回值：

*描  述：远程诊断( MID=6)

*备  注：
******************************************************/
static void PP_remotLogAcquisitionResp(void)
{
	PP_pack_t pp_pack;
	PP_DisptrBody_t disbody;
	PP_LogAcquisitionResp_t app_LogAcquisitionResp;
	int msgdatalen;
	int i;
	memset(&pp_pack,0 , sizeof(PP_pack_t));
	memset(&disbody,0 , sizeof(PP_DisptrBody_t));
	memset(&app_LogAcquisitionResp,0 , sizeof(PP_LogAcquisitionResp_t));
/***************************
 * 编码
 */
	pp_pack.Header.sign[0] = '*';
	pp_pack.Header.sign[1] = '*';
	pp_pack.Header.ver.Byte = 0x30;
	pp_pack.Header.commtype.Byte = 0xe1;
	pp_pack.Header.opera = 0x02;
	pp_pack.Header.nonce  = PP_BSEndianReverse(0);
	pp_pack.Header.tboxid = PP_BSEndianReverse(28);

	/*body*/
	memcpy(disbody.aID,"140",3);
	disbody.mID = 6;
	disbody.eventId = 140 + 6;
	disbody.eventTime = 123456;
	disbody.expTime   = 123456;
	disbody.ulMsgCnt++;	/* OPTIONAL */
	disbody.appDataProVer = 256;
	disbody.testFlag = 1;
	/*app data*/
	app_LogAcquisitionResp.logType = 2;//
	app_LogAcquisitionResp.logLevel = 1;//
	app_LogAcquisitionResp.startTime =123456;//
	app_LogAcquisitionResp.durationTime = 100;//


	if(0 == PP_msgPackageEncoding(PP_ECDC_RMTDIAG_LOGACQRESP,pp_pack.msgdata,&msgdatalen, \
										&disbody,&app_LogAcquisitionResp))
	{
		pp_pack.Header.msglen = PP_BSEndianReverse(18 + msgdatalen);
		uint8_t *pack_ptr = pp_pack.Header.sign;
		fprintf(stdout,"\n");
		fprintf(stdout,"\npackage is:\n");
		for(i = 0;i< (18 + msgdatalen);i++)
		{
			fprintf(stdout,"0x%x ", pack_ptr[i]);
		}
	}

/***************************
 * 解码
 */
	memset(&disbody,0 , sizeof(PP_DisptrBody_t));
	memset(&app_LogAcquisitionResp,0 , sizeof(PP_LogAcquisitionResp_t));
	PP_decodeMsgData(pp_pack.msgdata,msgdatalen,&disbody,&app_LogAcquisitionResp);
}

/******************************************************
*函数名：

*形  参：

*返回值：

*描  述：远程诊断( MID=7)

*备  注：
******************************************************/
static void PP_remotLogAcquisitionRes(void)
{
	PP_pack_t pp_pack;
	PP_DisptrBody_t disbody;
	PP_LogAcquisitionRes_t app_LogAcquisitionRes;
	int msgdatalen;
	int i;
	memset(&pp_pack,0 , sizeof(PP_pack_t));
	memset(&disbody,0 , sizeof(PP_DisptrBody_t));
	memset(&app_LogAcquisitionRes,0 , sizeof(PP_LogAcquisitionRes_t));
/***************************
 * 编码
 */
	pp_pack.Header.sign[0] = '*';
	pp_pack.Header.sign[1] = '*';
	pp_pack.Header.ver.Byte = 0x30;
	pp_pack.Header.commtype.Byte = 0xe1;
	pp_pack.Header.opera = 0x02;
	pp_pack.Header.nonce  = PP_BSEndianReverse(0);
	pp_pack.Header.tboxid = PP_BSEndianReverse(28);

	/*body*/
	memcpy(disbody.aID,"140",3);
	disbody.mID = 7;
	disbody.eventId = 140 + 7;
	disbody.eventTime = 123456;
	disbody.expTime   = 123456;
	disbody.ulMsgCnt++;	/* OPTIONAL */
	disbody.appDataProVer = 256;
	disbody.testFlag = 1;
	/*app data*/
	app_LogAcquisitionRes.logType = 1;
	app_LogAcquisitionRes.result = 1;
	app_LogAcquisitionRes.failureType = 0;
	memcpy(app_LogAcquisitionRes.fileName,"hozon_log",9);
	app_LogAcquisitionRes.fileNamelen = 9;

	if(0 == PP_msgPackageEncoding(PP_ECDC_RMTDIAG_LOGACQRES,pp_pack.msgdata,&msgdatalen, \
										&disbody,&app_LogAcquisitionRes))
	{
		pp_pack.Header.msglen = PP_BSEndianReverse(18 + msgdatalen);
		uint8_t *pack_ptr = pp_pack.Header.sign;
		fprintf(stdout,"\n");
		fprintf(stdout,"\npackage is:\n");
		for(i = 0;i< (18 + msgdatalen);i++)
		{
			fprintf(stdout,"0x%x ", pack_ptr[i]);
		}
	}

/***************************
 * 解码
 */
	memset(&disbody,0 , sizeof(PP_DisptrBody_t));
	memset(&app_LogAcquisitionRes,0 , sizeof(PP_LogAcquisitionRes_t));
	PP_decodeMsgData(pp_pack.msgdata,msgdatalen,&disbody,&app_LogAcquisitionRes);
}

/******************************************************
*函数名：PrvtPro_msgPackage

*形  参：

*返回值：

*描  述：数据打包编码

*备  注：
******************************************************/
static int PP_msgPackageEncoding(uint8_t type,uint8_t *msgData,int *msgDataLen, \
					   void *disptrBody, void *appchoice)
{
	static uint8_t key;
	Bodyinfo_t Bodydata;
	PP_DisptrBody_t 	*DisptrBody = (PP_DisptrBody_t*)disptrBody;
	int i,j;
	
	memset(&Bodydata,0 , sizeof(Bodyinfo_t));
	Bodydata.expirationTime = NULL;/* OPTIONAL */
	Bodydata.eventId 		= NULL;/* OPTIONAL */
	Bodydata.ulMsgCnt 		= NULL;	/* OPTIONAL */
	Bodydata.dlMsgCnt 		= NULL;	/* OPTIONAL */
	Bodydata.msgCntAcked 	= NULL;/* OPTIONAL */
	Bodydata.ackReq			= NULL;/* OPTIONAL */
	Bodydata.appDataLen 	= NULL;/* OPTIONAL */
	Bodydata.appDataEncode	= NULL;/* OPTIONAL */
	Bodydata.appDataProVer	= NULL;/* OPTIONAL */
	Bodydata.testFlag		= NULL;/* OPTIONAL */
	Bodydata.result			= NULL;/* OPTIONAL */
/*********************************************
	填充 dispatcher body和application data
*********************************************/	
	Bodydata.aID.buf = DisptrBody->aID;
	fprintf(stdout, "Bodydata.aID = %s\n",Bodydata.aID.buf);
	Bodydata.aID.size = 3;

	Bodydata.mID = DisptrBody->mID;
	fprintf(stdout,"Bodydata.mID = %ld\n",Bodydata.mID);

	Bodydata.eventTime 		= DisptrBody->eventTime;
	fprintf(stdout, "Bodydata.eventTime = %ld\n",Bodydata.eventTime);

	Bodydata.expirationTime = &DisptrBody->expTime;	/* OPTIONAL */;
	fprintf(stdout, "Bodydata.expirationTime = %ld\n",*Bodydata.expirationTime);

	Bodydata.eventId 		= &DisptrBody->eventId;/* OPTIONAL */
	fprintf(stdout,"Bodydata.eventId = %ld\n",*Bodydata.eventId);

	Bodydata.ulMsgCnt 		= &DisptrBody->ulMsgCnt;	/* OPTIONAL */
	fprintf(stdout,"Bodydata.ulMsgCnt = %ld\n",*Bodydata.ulMsgCnt);

	Bodydata.dlMsgCnt 		= &DisptrBody->dlMsgCnt;	/* OPTIONAL */
	fprintf(stdout, "Bodydata.dlMsgCnt = %ld\n",*Bodydata.dlMsgCnt);

	Bodydata.msgCntAcked 	= &DisptrBody->msgCntAcked;/* OPTIONAL */
	fprintf(stdout,"Bodydata.msgCntAcked = %ld\n",*Bodydata.msgCntAcked);

	Bodydata.ackReq			= &DisptrBody->ackReq;/* OPTIONAL */
	fprintf(stdout,"Bodydata.ackReq = %d\n",*Bodydata.ackReq);

	Bodydata.appDataLen 	= &DisptrBody->appDataLen;/* OPTIONAL */
	fprintf(stdout,"Bodydata.appDataLen = %ld\n",*Bodydata.appDataLen);

	Bodydata.appDataEncode	= &DisptrBody->appDataEncode;/* OPTIONAL */
	fprintf(stdout, "Bodydata.appDataEncode = %ld\n",*Bodydata.appDataEncode);

	Bodydata.appDataProVer	= &DisptrBody->appDataProVer;/* OPTIONAL */
	fprintf(stdout, "Bodydata.appDataProVer = %ld\n",*Bodydata.appDataProVer);

	Bodydata.testFlag		= &DisptrBody->testFlag;/* OPTIONAL */
	fprintf(stdout,"Bodydata.testFlag = %ld\n",*Bodydata.testFlag);

	Bodydata.result			= &DisptrBody->result;/* OPTIONAL */
	fprintf(stdout, "Bodydata.result = %ld\n",*Bodydata.result);
	
	asn_enc_rval_t ec;
	fprintf(stdout, "**uper encode:appdata**\n");

	memset(&PP_key,0 , sizeof(PP_key_t));
	PP_key.type = 1;
	switch(type)
	{
		case PP_ECDC_XCALLREQ:
		{
			XcallReqinfo_t XcallReq;	
			PP_XcallReq_t *XcallReq_ptr = (PP_XcallReq_t*)appchoice;
			memset(&XcallReq,0 , sizeof(XcallReqinfo_t));
			XcallReq.xcallType = XcallReq_ptr->xcallType;
			
			ec = uper_encode(pduType_XcallReq,(void *) &XcallReq,PP_writeout,&PP_key);
			if(ec.encoded  == -1) 
			{
				fprintf(stdout, "Could not encode MessageFrame");
				return -1;
			}
		}
		break;
		case PP_ECDC_RMTDIAG_REQ:
		{
			DiagnosticReqInfo_t DiagnosticReq;
			PP_DiagnosticReq_t *DiagnosticReq_ptr = (PP_DiagnosticReq_t*)appchoice;
			memset(&DiagnosticReq,0 , sizeof(DiagnosticReqInfo_t));
			DiagnosticReq.diagType = DiagnosticReq_ptr->diagType;

			ec = uper_encode(pduType_GIAG_req,(void *) &DiagnosticReq,PP_writeout,&PP_key);
			if(ec.encoded  == -1)
			{
				fprintf(stdout, "Could not encode MessageFrame");
				return -1;
			}
		}
		break;
		case PP_ECDC_RMTDIAG_RESP:
		{
			PP_DiagnosticResp_t *DiagnosticResp_ptr = (PP_DiagnosticResp_t*)appchoice;
			DiagnosticRespInfo_t DiagnosticResp;
			struct diagCode diagcode;
			DiagCode_t DiagCode[255];
			//DiagCode_t *DiagCode_ptr = DiagCode;

			memset(&DiagnosticResp,0 , sizeof(DiagnosticRespInfo_t));
			DiagnosticResp.diagType = DiagnosticResp_ptr->diagType;
			DiagnosticResp.result = DiagnosticResp_ptr->result;
			DiagnosticResp.failureType = &(DiagnosticResp_ptr->failureType);
			for(i = 0;i < DiagnosticResp_ptr->diagcodenum;i++)
			{
				DiagCode[i].diagCode.buf = DiagnosticResp_ptr->diagCode[i].diagCode;
				DiagCode[i].diagCode.size = DiagnosticResp_ptr->diagCode[i].diagCodelen;
				DiagCode[i].diagTime = DiagnosticResp_ptr->diagCode[i].diagTime;

				ASN_SEQUENCE_ADD(&diagcode, &DiagCode[i]);
			}
			DiagnosticResp.diagCode = &diagcode;

			ec = uper_encode(pduType_GIAG_resp,(void *) &DiagnosticResp,PP_writeout,&PP_key);
			if(ec.encoded  == -1)
			{
				fprintf(stdout, "Could not encode MessageFrame");
				return -1;
			}
		}
		break;
		case PP_ECDC_RMTDIAG_STATUS:
		{
			PP_DiagnosticStatus_t *DiagnosticSt_ptr = (PP_DiagnosticStatus_t*)appchoice;

			DiagnosticStInfo_t DiagnosticSt;
			struct DiagnosticRespInfo DiagnosticResp[255];
			struct diagCode diagcode[255];
			DiagCode_t DiagCode[255];
			//struct diagStatus diagStatus[255];

			//DiagCode_t *DiagCode_ptr = &DiagCode;

			memset(&DiagnosticSt,0 , sizeof(DiagnosticStInfo_t));
			for(i = 0;i<DiagnosticSt_ptr->faultnum;i++)
			{
				DiagnosticResp[i].diagType = DiagnosticSt_ptr->diagStatus[i].diagType;
				DiagnosticResp[i].result = DiagnosticSt_ptr->diagStatus[i].result;
				DiagnosticResp[i].failureType = &DiagnosticSt_ptr->diagStatus[i].failureType;
				for(j = 0;j<DiagnosticSt_ptr->diagStatus[i].diagcodenum;j++)
				{
					DiagCode[j].diagCode.buf = DiagnosticSt_ptr->diagStatus[i].diagCode[j].diagCode;
					DiagCode[j].diagCode.size = DiagnosticSt_ptr->diagStatus[i].diagCode[j].diagCodelen;
					DiagCode[j].diagTime = DiagnosticSt_ptr->diagStatus[i].diagCode[j].diagTime;
					ASN_SEQUENCE_ADD(&diagcode[i], &DiagCode[j]);
				}
				DiagnosticResp[i].diagCode = &diagcode[i];
				ASN_SEQUENCE_ADD(&DiagnosticSt, &DiagnosticResp[i]);
			}

			ec = uper_encode(pduType_GIAG_st,(void *) &DiagnosticSt,PP_writeout,&PP_key);
			if(ec.encoded  == -1)
			{
				fprintf(stdout, "Could not encode MessageFrame");
				return -1;
			}
		}
		break;
		case PP_ECDC_RMTDIAG_IMAGEACQREQ:
		{
			PP_ImageAcquisitionReq_t *ImageAcquisitionReq_ptr = (PP_ImageAcquisitionReq_t*)appchoice;
			ImageAcquisitionReqInfo_t ImageAcquisitionReq;
			memset(&ImageAcquisitionReq,0 , sizeof(ImageAcquisitionReqInfo_t));

			ImageAcquisitionReq.dataType = ImageAcquisitionReq_ptr->dataType;
			ImageAcquisitionReq.cameraName = ImageAcquisitionReq_ptr->cameraName;
			ImageAcquisitionReq.effectiveTime = ImageAcquisitionReq_ptr->effectiveTime;
			ImageAcquisitionReq.sizeLimit = ImageAcquisitionReq_ptr->sizeLimit;

			ec = uper_encode(pduType_GIAG_imageAcqReq,(void *) &ImageAcquisitionReq,PP_writeout,&PP_key);
			if(ec.encoded  == -1)
			{
				fprintf(stdout, "Could not encode MessageFrame");
				return -1;
			}
		}
		break;
		case PP_ECDC_RMTDIAG_IMAGEACQRESP:
		{
			PP_ImageAcquisitionResp_t *PP_ImageAcquisitionResp_ptr = (PP_ImageAcquisitionResp_t*)appchoice;
			ImageAcquisitionRespInfo_t ImageAcquisitionResp;
			IA5String_t	fileName;
			memset(&ImageAcquisitionResp,0 , sizeof(ImageAcquisitionRespInfo_t));

			ImageAcquisitionResp.result = PP_ImageAcquisitionResp_ptr->result;
			ImageAcquisitionResp.failureType = &PP_ImageAcquisitionResp_ptr->failureType;
			fileName.buf = PP_ImageAcquisitionResp_ptr->fileName;
			fileName.size = PP_ImageAcquisitionResp_ptr->fileNamelen;
			ImageAcquisitionResp.fileName = &fileName;

			ec = uper_encode(pduType_GIAG_imageAcqResp,(void *) &ImageAcquisitionResp,PP_writeout,&PP_key);
			if(ec.encoded  == -1)
			{
				fprintf(stdout, "Could not encode MessageFrame");
				return -1;
			}
		}
		break;
		case PP_ECDC_RMTDIAG_LOGACQRESP:
		{
			PP_LogAcquisitionResp_t *PP_LogAcquisitionResp_ptr = (PP_LogAcquisitionResp_t*)appchoice;
			LogAcquisitionRespInfo_t LogAcquisitionResp;
			memset(&LogAcquisitionResp,0 , sizeof(LogAcquisitionRespInfo_t));

			LogAcquisitionResp.logType = PP_LogAcquisitionResp_ptr->logType;
			LogAcquisitionResp.logLevel = PP_LogAcquisitionResp_ptr->logLevel;
			LogAcquisitionResp.startTime = PP_LogAcquisitionResp_ptr->startTime;
			LogAcquisitionResp.durationTime = PP_LogAcquisitionResp_ptr->durationTime;

			ec = uper_encode(pduType_GIAG_LogAcqResp,(void *) &LogAcquisitionResp,PP_writeout,&PP_key);
			if(ec.encoded  == -1)
			{
				fprintf(stdout, "Could not encode MessageFrame");
				return -1;
			}
		}
		break;
		case PP_ECDC_RMTDIAG_LOGACQRES:
		{
			PP_LogAcquisitionRes_t *PP_LogAcquisitionRes_ptr = (PP_LogAcquisitionRes_t*)appchoice;
			LogAcquisitionResInfo_t LogAcquisitionRes;
			IA5String_t	fileName;
			memset(&LogAcquisitionRes,0 , sizeof(LogAcquisitionResInfo_t));

			LogAcquisitionRes.logType = PP_LogAcquisitionRes_ptr->logType;
			LogAcquisitionRes.result  = PP_LogAcquisitionRes_ptr->result;
			LogAcquisitionRes.failureType = &PP_LogAcquisitionRes_ptr->failureType;
			fileName.buf  = PP_LogAcquisitionRes_ptr->fileName;
			fileName.size = PP_LogAcquisitionRes_ptr->fileNamelen;
			LogAcquisitionRes.fileName = &fileName;

			ec = uper_encode(pduType_GIAG_LogAcqRes,(void *) &LogAcquisitionRes,PP_writeout,&PP_key);
			if(ec.encoded  == -1)
			{
				fprintf(stdout, "Could not encode MessageFrame");
				return -1;
			}
		}
		break;
		default:
		{
			fprintf(stdout,"unknow application request");
		}
		break;
	}
	
/*********************************************
				编码
*********************************************/
	DisptrBody->appDataLen = PP_key.appdatalen;
	uint8_t *appdata_ptr = PP_key.appdata;
	fprintf(stdout,"appdata is:\n");
	for(i = 0;i< PP_key.appdatalen;i++)
	{
		fprintf(stdout,"0x%x ", appdata_ptr[i]);
	}
	fprintf(stdout,"\n");
	fprintf(stdout,"\n**uper encode:disbody**\n");
	PP_key.type = 2;
	ec = uper_encode(pduType_Body,(void *) &Bodydata,PP_writeout,&PP_key);
	if(ec.encoded  == -1)
	{
		fprintf(stdout, "Could not encode MessageFrame");
		return -1;
	}

	uint8_t *bodydata_ptr = PP_key.bodydata;
	fprintf(stdout,"disbody is:\n");
	for(i = 0;i< PP_key.bodydatalen;i++)
	{
		fprintf(stdout,"0x%x ", bodydata_ptr[i]);
	}
/*********************************************
				填充 message data
*********************************************/	
	int tboxmsglen = 0;
	msgData[tboxmsglen++] = PP_key.bodydatalen +1;//填充 dispatcher header
	for(i = 0;i < PP_key.bodydatalen;i++)
	{
		msgData[tboxmsglen++]= PP_key.bodydata[i];
	}
	for(i = 0;i < PP_key.appdatalen;i++)
	{
		msgData[tboxmsglen++]= PP_key.appdata[i];
	}
	*msgDataLen = 1 + PP_key.bodydatalen +  PP_key.appdatalen;//填充 message data lengtn

	return 0;
}

/******************************************************
*函数名：PrvtPro_decodeMsgData

*形  参：

*返回值：

*描  述：解码message data

*备  注：
******************************************************/
static int PP_decodeMsgData(uint8_t *LeMessageData,int LeMessageDataLen,void *DisBody,void *appData)
{
	PP_DisptrBody_t *msgDataBody = (PP_DisptrBody_t*)DisBody;
	asn_dec_rval_t dc;
	asn_codec_ctx_t *asn_codec_ctx = 0 ;
	Bodyinfo_t RxBodydata;
	Bodyinfo_t *RxBodydata_ptr = &RxBodydata;
	int i,j;
	memset(&RxBodydata,0 , sizeof(Bodyinfo_t));
	uint16_t AID;
	uint8_t MID;
	fprintf(stdout, "\n\n**uper decode:bodydata**\n");
	fprintf(stdout, "dis header length = %d\n",LeMessageData[0]);
	dc = uper_decode(asn_codec_ctx,pduType_Body,(void *) &RxBodydata_ptr, \
					 &LeMessageData[1],LeMessageData[0] -1,0,0);
	if(dc.code  != RC_OK)
	{
		fprintf(stdout, "Could not decode dispatcher header Frame");
		return -1;
	}
	
	if(msgDataBody != NULL)
	{
		memcpy(msgDataBody->aID,RxBodydata.aID.buf,sizeof(char)*3);
		msgDataBody->mID 	= RxBodydata.mID;
		msgDataBody->eventTime 	= RxBodydata.eventTime;
		fprintf(stdout,"RxBodydata.aid = %s\n",msgDataBody->aID);
		fprintf(stdout, "RxBodydata.mID = %ld\n",RxBodydata.mID);
		fprintf(stdout,"RxBodydata.eventTime = %ld\n",RxBodydata.eventTime);
		if(NULL != RxBodydata.expirationTime)
		{
			fprintf(stdout, "RxBodydata.expirationTime = %ld\n",(*(RxBodydata.expirationTime)));
			msgDataBody->expTime = *(RxBodydata.expirationTime);/* OPTIONAL */
		}
		if(NULL != RxBodydata.eventId)
		{
			fprintf(stdout, "RxBodydata.eventId = %ld\n",(*(RxBodydata.eventId)));
			msgDataBody->eventId = *(RxBodydata.eventId);/* OPTIONAL */
		}
		if(NULL != RxBodydata.ulMsgCnt)
		{
			msgDataBody->ulMsgCnt = *(RxBodydata.ulMsgCnt);/* OPTIONAL */
			fprintf(stdout,"RxBodydata.ulMsgCnt = %ld\n",(*(RxBodydata.ulMsgCnt)));
		}
		if(NULL != RxBodydata.dlMsgCnt)
		{
			fprintf(stdout, "RxBodydata.dlMsgCnt = %ld\n",(*(RxBodydata.dlMsgCnt)));
			msgDataBody->dlMsgCnt = *(RxBodydata.dlMsgCnt);/* OPTIONAL */
		}
		if(NULL != RxBodydata.msgCntAcked)
		{
			fprintf(stdout, "RxBodydata.msgCntAcked = %ld\n",(*(RxBodydata.msgCntAcked)));
			msgDataBody->msgCntAcked = *(RxBodydata.msgCntAcked);/* OPTIONAL */
		}
		if(NULL != RxBodydata.ackReq)
		{
			fprintf(stdout, "RxBodydata.ackReq = %d\n",(*(RxBodydata.ackReq)));
			msgDataBody->ackReq	= *(RxBodydata.ackReq);/* OPTIONAL */
		}
		if(NULL != RxBodydata.appDataLen)
		{
			fprintf(stdout, "RxBodydata.appDataLen = %ld\n",(*(RxBodydata.appDataLen)));
			msgDataBody->appDataLen	= *(RxBodydata.appDataLen);/* OPTIONAL */
		}
		if(NULL != RxBodydata.appDataEncode)
		{
			fprintf(stdout, "RxBodydata.appDataEncode = %ld\n",(*(RxBodydata.appDataEncode)));
			msgDataBody->appDataEncode	= *(RxBodydata.appDataEncode);/* OPTIONAL */
		}
		if(NULL != RxBodydata.appDataProVer)
		{
			fprintf(stdout, "RxBodydata.appDataProVer = %ld\n",(*(RxBodydata.appDataProVer)));
			msgDataBody->appDataProVer	= *(RxBodydata.appDataProVer);/* OPTIONAL */
		}
		if(NULL != RxBodydata.testFlag)
		{
			fprintf(stdout, "RxBodydata.testFlag = %ld\n",(*(RxBodydata.testFlag)));
			msgDataBody->testFlag = *(RxBodydata.testFlag);/* OPTIONAL */
		}
		if(NULL != RxBodydata.result)
		{
			fprintf(stdout, "RxBodydata.result = %ld\n",(*(RxBodydata.result)));
			msgDataBody->result	= *(RxBodydata.result);/* OPTIONAL */
		}
	}

	if((appData != NULL) && ((LeMessageDataLen-LeMessageData[0]) > 0))
	{
		AID = (RxBodydata.aID.buf[0] - 0x30)*100 +  (RxBodydata.aID.buf[1] - 0x30)*10 + \
			  (RxBodydata.aID.buf[2] - 0x30);
		MID = RxBodydata.mID;
		fprintf(stdout, "\n**uper decode:appdata**\n");
		fprintf(stdout, "application data length = %d\n",LeMessageDataLen-LeMessageData[0]);
		switch(AID)
		{
			case 170://xcall
			{
				PP_XcallReq_t *app_xcall_ptr = (PP_XcallReq_t*)appData;
				if(1 == MID)//xcall req
				{
					XcallReqinfo_t RxXcallReq;
					XcallReqinfo_t *RxXcallReq_ptr = &RxXcallReq;
					memset(&RxXcallReq,0 , sizeof(XcallReqinfo_t));
					dc = uper_decode(asn_codec_ctx,pduType_XcallReq,(void *) &RxXcallReq_ptr, \
							 &LeMessageData[LeMessageData[0]],LeMessageDataLen - LeMessageData[0],0,0);
					if(dc.code  != RC_OK)
					{
						fprintf(stdout, "Could not decode application data Frame\n");
						return -1;
					}

					app_xcall_ptr->xcallType = RxXcallReq.xcallType;
					fprintf(stdout, "appData->xcallType = %ld\n",app_xcall_ptr->xcallType);
				}
				else
				{}
			}
			break;
			case 140://remote diag
			{
				if(1 == MID)//giag req
				{
					PP_DiagnosticReq_t *PP_DiagnosticReq_ptr = (PP_DiagnosticReq_t*)appData;

					DiagnosticReqInfo_t DiagnosticReq;
					DiagnosticReqInfo_t *DiagnosticReq_ptr = &DiagnosticReq;
					memset(&DiagnosticReq,0 , sizeof(DiagnosticReqInfo_t));
					dc = uper_decode(asn_codec_ctx,pduType_GIAG_req,(void *) &DiagnosticReq_ptr, \
							 &LeMessageData[LeMessageData[0]],LeMessageDataLen - LeMessageData[0],0,0);
					if(dc.code  != RC_OK)
					{
						fprintf(stdout, "Could not decode application data Frame\n");
						return -1;
					}

					PP_DiagnosticReq_ptr->diagType = DiagnosticReq.diagType;
					fprintf(stdout, "PP_DiagnosticReq_ptr->diagType = %ld\n",PP_DiagnosticReq_ptr->diagType);
				}
				else if(2 == MID)//giag resp
				{
					PP_DiagnosticResp_t *PP_DiagnosticResp_ptr = (PP_DiagnosticResp_t*)appData;

					DiagnosticRespInfo_t DiagnosticResp;
					DiagnosticRespInfo_t *DiagnosticResp_ptr = &DiagnosticResp;
					memset(&DiagnosticResp,0 , sizeof(DiagnosticRespInfo_t));
					dc = uper_decode(asn_codec_ctx,pduType_GIAG_resp,(void *) &DiagnosticResp_ptr, \
							 &LeMessageData[LeMessageData[0]],LeMessageDataLen - LeMessageData[0],0,0);
					if(dc.code  != RC_OK)
					{
						fprintf(stdout, "Could not decode application data Frame\n");
						return -1;
					}

					PP_DiagnosticResp_ptr->diagType = DiagnosticResp.diagType;
					PP_DiagnosticResp_ptr->result = DiagnosticResp.result;
					fprintf(stdout, "PP_DiagnosticResp_ptr->diagType = %ld\n",PP_DiagnosticResp_ptr->diagType);
					fprintf(stdout, "PP_DiagnosticResp_ptr->result = %d\n",PP_DiagnosticResp_ptr->result);
					if(DiagnosticResp.failureType!=NULL)
					{
						PP_DiagnosticResp_ptr->failureType = *DiagnosticResp.failureType;
						fprintf(stdout, "PP_DiagnosticResp_ptr->failureType = %ld\n",PP_DiagnosticResp_ptr->failureType);
					}

					if(DiagnosticResp.diagCode!=NULL)
					{
						for(i= 0;i < DiagnosticResp.diagCode->list.count;i++)
						{
							memcpy(PP_DiagnosticResp_ptr->diagCode[i].diagCode,DiagnosticResp.diagCode->list.array[i]->diagCode.buf, \
									DiagnosticResp.diagCode->list.array[i]->diagCode.size);
							PP_DiagnosticResp_ptr->diagCode[i].diagCodelen = DiagnosticResp.diagCode->list.array[i]->diagCode.size;
							PP_DiagnosticResp_ptr->diagCode[i].diagTime = DiagnosticResp.diagCode->list.array[i]->diagTime;

							fprintf(stdout, "PP_DiagnosticResp_ptr->diagCode.diagCode= %s\n",PP_DiagnosticResp_ptr->diagCode[i].diagCode);
							fprintf(stdout, "PP_DiagnosticResp_ptr->diagCode.diagCodelen = %d\n",PP_DiagnosticResp_ptr->diagCode[i].diagCodelen);
							fprintf(stdout, "PP_DiagnosticResp_ptr->diagCode.diagTime = %ld\n",PP_DiagnosticResp_ptr->diagCode[i].diagTime);
						}
					}
				}
				else if(3 == MID)//giag status
				{
					PP_DiagnosticStatus_t *PP_DiagnosticStatus_ptr = (PP_DiagnosticStatus_t*)appData;

					DiagnosticStInfo_t DiagnosticSt;
					DiagnosticStInfo_t *DiagnosticSt_ptr = &DiagnosticSt;
					memset(&DiagnosticSt,0 , sizeof(DiagnosticStInfo_t));
					dc = uper_decode(asn_codec_ctx,pduType_GIAG_st,(void *) &DiagnosticSt_ptr, \
							 &LeMessageData[LeMessageData[0]],LeMessageDataLen - LeMessageData[0],0,0);
					if(dc.code  != RC_OK)
					{
						fprintf(stdout, "Could not decode application data Frame\n");
						return -1;
					}

					for(i = 0;i < DiagnosticSt.diagStatus.list.count;i++)
					{
						//PP_DiagnosticResp_ptr->diagType = DiagnosticSt.diagStatus.list.array[i]->diagCode->list.array[j]->diagCode.buf;
						PP_DiagnosticStatus_ptr->diagStatus[i].diagType = DiagnosticSt.diagStatus.list.array[i]->diagType;
						PP_DiagnosticStatus_ptr->diagStatus[i].result = DiagnosticSt.diagStatus.list.array[i]->result;
						fprintf(stdout, "PP_DiagnosticStatus_ptr->diagStatus[i].diagType = %ld\n",PP_DiagnosticStatus_ptr->diagStatus[i].diagType);
						fprintf(stdout, "PP_DiagnosticStatus_ptr->diagStatus[i].result = %d\n",PP_DiagnosticStatus_ptr->diagStatus[i].result);
						if(DiagnosticSt.diagStatus.list.array[i]->failureType!=NULL)
						{

							PP_DiagnosticStatus_ptr->diagStatus[i].failureType = *DiagnosticSt.diagStatus.list.array[i]->failureType;
							fprintf(stdout, "PP_DiagnosticStatus_ptr->diagStatus[i].failureType = %ld\n",PP_DiagnosticStatus_ptr->diagStatus[i].failureType);
						}

						if(DiagnosticSt.diagStatus.list.array[i]->diagCode != NULL)
						{
							for(j = 0;j < DiagnosticSt.diagStatus.list.array[i]->diagCode->list.count;j++)
							{
								memcpy(PP_DiagnosticStatus_ptr->diagStatus[i].diagCode[j].diagCode,DiagnosticSt.diagStatus.list.array[i]->diagCode->list.array[j]->diagCode.buf, \
										DiagnosticSt.diagStatus.list.array[i]->diagCode->list.array[j]->diagCode.size);
								PP_DiagnosticStatus_ptr->diagStatus[i].diagCode[j].diagCodelen = DiagnosticSt.diagStatus.list.array[i]->diagCode->list.array[j]->diagCode.size;
								PP_DiagnosticStatus_ptr->diagStatus[i].diagCode[j].diagTime = DiagnosticSt.diagStatus.list.array[i]->diagCode->list.array[j]->diagTime;

								fprintf(stdout, "PP_DiagnosticStatus_ptr->diagStatus[i].diagCode[j].diagCode= %s\n", \
										PP_DiagnosticStatus_ptr->diagStatus[i].diagCode[j].diagCode);
								fprintf(stdout, "PP_DiagnosticStatus_ptr->diagStatus[i].diagCode[j].diagCodelen = %d\n", \
										PP_DiagnosticStatus_ptr->diagStatus[i].diagCode[j].diagCodelen);
								fprintf(stdout, "PP_DiagnosticStatus_ptr->diagStatus[i].diagCode[j].diagTime = %ld\n", \
										PP_DiagnosticStatus_ptr->diagStatus[i].diagCode[j].diagTime);
							}
						}
						fprintf(stdout, "\n");
					}
				}
				else if(4 == MID)//giag imageAcqReq
				{
					PP_ImageAcquisitionReq_t *PP_ImageAcquisitionReq_ptr = (PP_ImageAcquisitionReq_t*)appData;

					ImageAcquisitionReqInfo_t ImageAcquisitionReq;
					ImageAcquisitionReqInfo_t *ImageAcquisitionReq_ptr = &ImageAcquisitionReq;
					memset(&ImageAcquisitionReq,0 , sizeof(ImageAcquisitionReqInfo_t));
					dc = uper_decode(asn_codec_ctx,pduType_GIAG_imageAcqReq,(void *) &ImageAcquisitionReq_ptr, \
							 &LeMessageData[LeMessageData[0]],LeMessageDataLen - LeMessageData[0],0,0);
					if(dc.code  != RC_OK)
					{
						fprintf(stdout, "Could not decode application data Frame\n");
						return -1;
					}

					PP_ImageAcquisitionReq_ptr->dataType = ImageAcquisitionReq.dataType;
					PP_ImageAcquisitionReq_ptr->cameraName = ImageAcquisitionReq.cameraName;
					PP_ImageAcquisitionReq_ptr->effectiveTime = ImageAcquisitionReq.effectiveTime;
					PP_ImageAcquisitionReq_ptr->sizeLimit = ImageAcquisitionReq.sizeLimit;

					fprintf(stdout, "PP_ImageAcquisitionReq_ptr->dataType = %ld\n",PP_ImageAcquisitionReq_ptr->dataType);
					fprintf(stdout, "PP_ImageAcquisitionReq_ptr->cameraName = %ld\n",PP_ImageAcquisitionReq_ptr->cameraName);
					fprintf(stdout, "PP_ImageAcquisitionReq_ptr->effectiveTime = %ld\n",PP_ImageAcquisitionReq_ptr->effectiveTime);
					fprintf(stdout, "PP_ImageAcquisitionReq_ptr->sizeLimit = %ld\n",PP_ImageAcquisitionReq_ptr->sizeLimit);
				}
				else if(5 == MID)//giag imageAcqResp
				{
					PP_ImageAcquisitionResp_t *PP_ImageAcquisitionResp_ptr = (PP_ImageAcquisitionResp_t*)appData;

					ImageAcquisitionRespInfo_t ImageAcquisitionResp;
					ImageAcquisitionRespInfo_t *ImageAcquisitionResp_ptr = &ImageAcquisitionResp;
					memset(&ImageAcquisitionResp,0 , sizeof(ImageAcquisitionRespInfo_t));
					dc = uper_decode(asn_codec_ctx,pduType_GIAG_imageAcqResp,(void *) &ImageAcquisitionResp_ptr, \
							 &LeMessageData[LeMessageData[0]],LeMessageDataLen - LeMessageData[0],0,0);
					if(dc.code  != RC_OK)
					{
						fprintf(stdout, "Could not decode application data Frame\n");
						return -1;
					}

					PP_ImageAcquisitionResp_ptr->result = ImageAcquisitionResp.result;
					fprintf(stdout, "PP_ImageAcquisitionResp_ptr->result = %d\n",PP_ImageAcquisitionResp_ptr->result);
					if(ImageAcquisitionResp.failureType != NULL)
					{
						PP_ImageAcquisitionResp_ptr->failureType = *ImageAcquisitionResp.failureType;
						fprintf(stdout, "PP_ImageAcquisitionResp_ptr->failureType = %ld\n",PP_ImageAcquisitionResp_ptr->failureType);
					}

					if(ImageAcquisitionResp.fileName != NULL)
					{
						memcpy(PP_ImageAcquisitionResp_ptr->fileName,ImageAcquisitionResp.fileName->buf, \
								ImageAcquisitionResp.fileName->size);
						PP_ImageAcquisitionResp_ptr->fileNamelen =  ImageAcquisitionResp.fileName->size;
						fprintf(stdout, "PP_ImageAcquisitionResp_ptr->fileName = %s\n",PP_ImageAcquisitionResp_ptr->fileName);
						fprintf(stdout, "PP_ImageAcquisitionResp_ptr->fileNamelen = %d\n",PP_ImageAcquisitionResp_ptr->fileNamelen);
					}
				}
				else if(6 == MID)//LogAcquisitionResp
				{
					PP_LogAcquisitionResp_t *PP_LogAcquisitionResp_ptr = (PP_LogAcquisitionResp_t*)appData;

					LogAcquisitionRespInfo_t LogAcquisitionResp;
					LogAcquisitionRespInfo_t *LogAcquisitionResp_ptr = &LogAcquisitionResp;
					memset(&LogAcquisitionResp,0 , sizeof(LogAcquisitionRespInfo_t));
					dc = uper_decode(asn_codec_ctx,pduType_GIAG_LogAcqResp,(void *) &LogAcquisitionResp_ptr, \
							 &LeMessageData[LeMessageData[0]],LeMessageDataLen - LeMessageData[0],0,0);
					if(dc.code  != RC_OK)
					{
						fprintf(stdout, "Could not decode application data Frame\n");
						return -1;
					}

					PP_LogAcquisitionResp_ptr->logType = LogAcquisitionResp.logType;
					PP_LogAcquisitionResp_ptr->logLevel = LogAcquisitionResp.logLevel;
					PP_LogAcquisitionResp_ptr->startTime = LogAcquisitionResp.startTime;
					PP_LogAcquisitionResp_ptr->durationTime = LogAcquisitionResp.durationTime;

					fprintf(stdout, "PP_LogAcquisitionResp_ptr->logType = %ld\n",PP_LogAcquisitionResp_ptr->logType);
					fprintf(stdout, "PP_LogAcquisitionResp_ptr->logLevel = %ld\n",PP_LogAcquisitionResp_ptr->logLevel);
					fprintf(stdout, "PP_LogAcquisitionResp_ptr->startTime = %ld\n",PP_LogAcquisitionResp_ptr->startTime);
					fprintf(stdout, "PP_LogAcquisitionResp_ptr->durationTime = %ld\n",PP_LogAcquisitionResp_ptr->durationTime);
				}
				else if(7 == MID)//giag LogAcquisitionRes
				{
					PP_LogAcquisitionRes_t *PP_LogAcquisitionRes_ptr = (PP_LogAcquisitionRes_t*)appData;

					LogAcquisitionResInfo_t LogAcquisitionRes;
					LogAcquisitionResInfo_t *LogAcquisitionRes_ptr = &LogAcquisitionRes;
					memset(&LogAcquisitionRes,0 , sizeof(LogAcquisitionResInfo_t));
					dc = uper_decode(asn_codec_ctx,pduType_GIAG_LogAcqRes,(void *) &LogAcquisitionRes_ptr, \
							 &LeMessageData[LeMessageData[0]],LeMessageDataLen - LeMessageData[0],0,0);
					if(dc.code  != RC_OK)
					{
						fprintf(stdout, "Could not decode application data Frame\n");
						return -1;
					}

					PP_LogAcquisitionRes_ptr->logType = LogAcquisitionRes.result;
					fprintf(stdout, "PP_LogAcquisitionRes_ptr->logType = %ld\n",PP_LogAcquisitionRes_ptr->logType);

					PP_LogAcquisitionRes_ptr->result = LogAcquisitionRes.result;
					fprintf(stdout, "PP_LogAcquisitionRes_ptr->result = %d\n",PP_LogAcquisitionRes_ptr->result);
					if(LogAcquisitionRes.failureType != NULL)
					{
						PP_LogAcquisitionRes_ptr->failureType = *LogAcquisitionRes.failureType;
						fprintf(stdout, "PP_LogAcquisitionRes_ptr->failureType = %ld\n",PP_LogAcquisitionRes_ptr->failureType);
					}

					if(LogAcquisitionRes.fileName != NULL)
					{
						memcpy(PP_LogAcquisitionRes_ptr->fileName,LogAcquisitionRes.fileName->buf, \
								LogAcquisitionRes.fileName->size);
						PP_LogAcquisitionRes_ptr->fileNamelen =  LogAcquisitionRes.fileName->size;
						fprintf(stdout, "PP_LogAcquisitionRes_ptr->fileName = %s\n",PP_LogAcquisitionRes_ptr->fileName);
						fprintf(stdout, "PP_LogAcquisitionRes_ptr->fileNamelen = %d\n",PP_LogAcquisitionRes_ptr->fileNamelen);
					}
				}
			}
			break;
			default:
			break;
		}
	}

	return 0;
}


/******************************************************
*函数名：static void PrvtPro_writeout

*形  参：

*返回值：

*描  述：

*备  注：
******************************************************/
static int PP_writeout(const void *buffer,size_t size,void *key)
{
	int i;
	PP_key_t *pp_key_ptr = (PP_key_t*)key;
	if(size > 1024)
	{
		fprintf(stdout, "the size of data greater than PP_MSG_DATA_LEN");
		return 0;
	}
	
	switch(pp_key_ptr->type)
	{
		case 1:
		{
			//fprintf(stdout, "encode appdata <<<");
			for(i = 0;i < size;i++)
			{
				pp_key_ptr->appdata[i] = ((unsigned char *)buffer)[i];
			}
			pp_key_ptr->appdatalen = size;
		}
		break;
		case 2:
		{
			//fprintf(stdout, "encode body <<<");
			for(i = 0;i < size;i++)
			{
				pp_key_ptr->bodydata[i] = ((unsigned char *)buffer)[i];
			}
			pp_key_ptr->bodydatalen = size;
		}
		break;
		default:
		break;
	}
	return 0;
}

/******************************************************
*函数名：PrvtPro_BSEndianReverse

*形  参：void

*返回值：void

*描  述：大端模式和小端模式互相转换

*备  注：
******************************************************/
static long PP_BSEndianReverse(long value)
{
	return (value & 0x000000FFU) << 24 | (value & 0x0000FF00U) << 8 | \
		   (value & 0x00FF0000U) >> 8 | (value & 0xFF000000U) >> 24;
}
