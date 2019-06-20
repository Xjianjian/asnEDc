/******************************************************
�ļ�����	PP_EcDc.h

������	��ҵ˽��Э�飨�㽭���ڣ�	

Data			  Vasion			author
2019/4/29		V1.0			liujian
*******************************************************/
#ifndef		_PP_ECDC_H
#define		_PP_ECDC_H
/*******************************************************
description�� include the header file
*******************************************************/


/*******************************************************
description�� macro definitions
*******************************************************/
/**********�꿪�ض���*********/

/**********�곣������*********/
#define PP_ECDC_XCALLREQ 1
#define PP_ECDC_RMTDIAG_REQ 2
#define PP_ECDC_RMTDIAG_RESP 3

#define PP_ECDC_RMTDIAG_STATUS 4
#define PP_ECDC_RMTDIAG_IMAGEACQREQ  5
#define PP_ECDC_RMTDIAG_IMAGEACQRESP  6

#define PP_ECDC_RMTDIAG_LOGACQRESP  7
#define PP_ECDC_RMTDIAG_LOGACQRES	8

/* ֤�� */
#define PP_ECDC_CREDDOWNLOADREQ 	1
#define PP_ECDC_CREDDOWNLOADRESP	2
#define PP_ECDC_CREDDOWNLOADST	 	3


/***********�꺯��***********/

/*******************************************************
description�� struct definitions
*******************************************************/
/*****struct definitions*****/
typedef struct
{
	unsigned char sign[2U];/* ��ʼ����־λ��ȡֵ0x2A��0x2A*/
	union
	{
		unsigned char Byte;/* */
		struct
		{
			unsigned char mnr : 4;/* С�汾(��TSPƽ̨����)*/
			unsigned char mjr : 4;/* ��汾(��TSPƽ̨����)*/
		}bits; /**/
	}ver;
	uint32_t nonce;/* TCP�ỰID ��TSPƽ̨���� */

	union
	{
		unsigned char Byte;/* */
		struct
		{
			unsigned char encode : 4;/* ���뷽ʽ0��none��1NGTP��2��GZIP��3��JSON*/
			unsigned char mode : 1;/* ����0��normal��1��debug*/
			unsigned char connt  : 1;/* ���ӷ�ʽ0�������ӣ�1��������*/
			unsigned char asyn : 1;/* ͨѶ��ʽ0��ͬ����1���첽*/
			unsigned char dir  : 1;/* ���ķ���0��To Tbox��1��To TSP*/
		}bits; /**/
	}commtype;

	union
	{
		unsigned char Byte;/* */
		struct
		{
			unsigned char encrypt   : 4;/* ���ܷ�ʽ0��none��1��AES128��2��AES256��3RSA2048*/
			unsigned char signature : 4;/* ǩ����ʽ:0 -- none ;1 -- SHA1;2 -- SHA256*/
		}bits; /**/
	}safetype;

	unsigned char opera;/* ��������:0 -- national standard ;1 -- heartbeat;2 -- ngtp ;3 -- OTA */
	uint32_t msglen;/* ���ĳ��� */
	uint32_t tboxid;/* ƽ̨ͨ��tboxID��tboxSNӳ�� */
}__attribute__((packed)) PP_pack_Header_t; /*����ͷ�ṹ��*/

typedef struct
{
	PP_pack_Header_t Header;/* */
	unsigned char msgdata[1024];/* ��Ϣ�� */
	unsigned char msgtype;/* ��Ϣ���� */
}PP_pack_t; /*���Ľṹ��*/

/* Dispatcher Body struct */
typedef struct
{
	uint8_t	 	aID[4];
	uint8_t	 	mID;
	long	eventTime;
	long	expTime	/* OPTIONAL */;
	long	eventId	/* OPTIONAL */;
	long	ulMsgCnt	/* OPTIONAL */;
	long	dlMsgCnt	/* OPTIONAL */;
	long	msgCntAcked	/* OPTIONAL */;
	int		ackReq	/* OPTIONAL */;
	long	appDataLen	/* OPTIONAL */;
	long	appDataEncode	/* OPTIONAL */;
	long	appDataProVer	/* OPTIONAL */;
	long	testFlag	/* OPTIONAL */;
	long	result	/* OPTIONAL */;
}__attribute__((packed)) PP_DisptrBody_t;

/* key */
typedef struct
{
	uint8_t type;//1--appdata;2--disbody
	unsigned char appdata[1024];
	int appdatalen;
	unsigned char bodydata[1024];
	int bodydatalen;
} PP_key_t;

/* XcallReq */
typedef struct
{
	long	 xcallType;
}PP_XcallReq_t;

/* remote Diagnostic*/
typedef struct
{
	long	diagType;
}PP_DiagnosticReq_t;

typedef struct
{
	uint8_t diagCode[5];
	uint8_t diagCodelen;
	long 	diagTime;
}PP_DiagCode_t;

typedef struct
{
	long	diagType;
	int		result;
	long	failureType;
	PP_DiagCode_t		diagCode[255];
	uint8_t diagcodenum;
}PP_DiagnosticResp_t;

typedef struct
{
	PP_DiagnosticResp_t		diagStatus[255];
	uint8_t faultnum;
}PP_DiagnosticStatus_t;

typedef struct
{
	long dataType;
	long cameraName;
	long effectiveTime;
	long sizeLimit;
}PP_ImageAcquisitionReq_t;

typedef struct
{
	int result;
	long failureType ;
	uint8_t fileName[255];
	uint8_t fileNamelen;
}PP_ImageAcquisitionResp_t;


typedef struct
{
	long logType;
	long logLevel;
	long startTime;
	long durationTime;
}PP_LogAcquisitionResp_t;

typedef struct
{
	long logType;
	int  result;
	long failureType;
	uint8_t fileName[255];
	uint8_t fileNamelen;
}PP_LogAcquisitionRes_t;


/* ֤�� */
typedef struct
{
	long	 mid;
	long	 eventId;
	long	 cerType;
	long	 infoListLength;
	uint8_t  infoList[65535];
}PP_CertificateDownloadReq_t;



/*******************************************************
description�� typedef definitions
*******************************************************/
/******enum definitions******/

/*****struct definitions*****/

/******union definitions*****/

/*******************************************************
description�� variable External declaration
*******************************************************/

/*******************************************************
description�� function External declaration
*******************************************************/

#endif 
