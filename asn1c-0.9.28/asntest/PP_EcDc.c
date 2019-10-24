/******************************************************
文件名：	PrvtProt_EcDc.c

描述：	企业私有协议,编解码
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
#include "Bodyinfo.h"
#include "DiagnosticRespInfo.h"
#include "DiagCode.h"
#include "DiagnosticStInfo.h"
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
static asn_TYPE_descriptor_t *pduType_GIAG_st = &asn_DEF_DiagnosticStInfo;
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
static long PP_BSEndianReverse(long value);
static void PP_remotDiagnosticStatus(void);
//static void PP_remoteCertificateDownloadReq(void);
/******************************************************
description： function code
******************************************************/
void main(void)
{
	int i;
	for(i =0 ;i < 3;i++)
	{
		PP_remotDiagnosticStatus();
	}
}


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
 *encode
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
	app_DiagnosticStatus.faultnum =0;
	app_DiagnosticStatus.diagStatus[i].diagcodenum = 0;
	for(i=0;i<2;i++)
	{
		app_DiagnosticStatus.diagStatus[i].diagType = i+1;//
		app_DiagnosticStatus.diagStatus[i].result = 1;
		app_DiagnosticStatus.diagStatus[i].failureType = 0;
		for(j=0;j<1;j++)
		{
			memcpy(app_DiagnosticStatus.diagStatus[i].diagCode[j].diagCode,"12345",5);
			app_DiagnosticStatus.diagStatus[i].diagCode[j].diagCodelen = 5;
			app_DiagnosticStatus.diagStatus[i].diagCode[j].diagTime = 0;
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
 * decode
 */
	memset(&disbody,0 , sizeof(PP_DisptrBody_t));
	memset(&app_DiagnosticStatus,0 , sizeof(PP_DiagnosticStatus_t));
	PP_decodeMsgData(pp_pack.msgdata,msgdatalen,&disbody,&app_DiagnosticStatus);
}


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
		case PP_ECDC_RMTDIAG_STATUS:
		{
			PP_DiagnosticStatus_t *DiagnosticSt_ptr = (PP_DiagnosticStatus_t*)appchoice;

			DiagnosticStInfo_t DiagnosticSt;
			struct DiagnosticRespInfo DiagnosticResp[255];
			struct diagCode diagcode[255];
			DiagCode_t DiagCode[255];

			memset(&DiagnosticSt,0 , sizeof(DiagnosticStInfo_t));
			for(i = 0;i<DiagnosticSt_ptr->faultnum;i++)
			{
				DiagnosticResp[i].diagType = DiagnosticSt_ptr->diagStatus[i].diagType;
				DiagnosticResp[i].result = DiagnosticSt_ptr->diagStatus[i].result;
				DiagnosticResp[i].failureType = &DiagnosticSt_ptr->diagStatus[i].failureType;
				fprintf(stdout, "DiagnosticSt_ptr->diagStatus[%d].diagcodenum = %d\n",i,DiagnosticSt_ptr->diagStatus[i].diagcodenum);
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
			for(i = 0;i<DiagnosticSt_ptr->faultnum;i++)
				asn_set_empty(&diagcode[i]);

			asn_set_empty(&DiagnosticSt);
		}
		break;
		default:
		{
			fprintf(stdout,"unknow application request");
		}
		break;
	}
	
/*********************************************

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
				 message data
*********************************************/	
	int tboxmsglen = 0;
	msgData[tboxmsglen++] = PP_key.bodydatalen +1;// dispatcher header
	for(i = 0;i < PP_key.bodydatalen;i++)
	{
		msgData[tboxmsglen++]= PP_key.bodydata[i];
	}
	for(i = 0;i < PP_key.appdatalen;i++)
	{
		msgData[tboxmsglen++]= PP_key.appdata[i];
	}
	*msgDataLen = 1 + PP_key.bodydatalen +  PP_key.appdatalen;// message data lengtn

	return 0;
}


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
			case 140://remote diag
			{
				if(3 == MID)//giag status
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
				else
				{

				}
			}
			break;
			default:
			break;
		}
	}

	return 0;
}


static int PP_writeout(const void *buffer,size_t size,void *key)
{
	int i;
	PP_key_t *pp_key_ptr = (PP_key_t*)key;
	if(size > 1024)
	{
		fprintf(stdout, "the size of data greater than 1024\n");
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


static long PP_BSEndianReverse(long value)
{
	return (value & 0x000000FFU) << 24 | (value & 0x0000FF00U) << 8 | \
		   (value & 0x00FF0000U) >> 8 | (value & 0xFF000000U) >> 24;
}
