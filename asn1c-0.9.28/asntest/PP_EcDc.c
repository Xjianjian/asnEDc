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
	PP_xcallreq();
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
	int i;
	
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
	int i;
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
