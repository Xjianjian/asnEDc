
#ifndef		_PP_ECDC_H
#define		_PP_ECDC_H
/*******************************************************
description£º include the header file
*******************************************************/


/*******************************************************
description£º macro definitions
*******************************************************/
#define PP_ECDC_RMTDIAG_STATUS 4

/*******************************************************
description£º struct definitions
*******************************************************/
/*****struct definitions*****/
typedef struct
{
	unsigned char sign[2U];
	union
	{
		unsigned char Byte;/* */
		struct
		{
			unsigned char mnr : 4;
			unsigned char mjr : 4;
		}bits; /**/
	}ver;
	uint32_t nonce;

	union
	{
		unsigned char Byte;/* */
		struct
		{
			unsigned char encode : 4;
			unsigned char mode : 1;
			unsigned char connt  : 1;
			unsigned char asyn : 1;
			unsigned char dir  : 1;
		}bits; /**/
	}commtype;

	union
	{
		unsigned char Byte;/* */
		struct
		{
			unsigned char encrypt   : 4;
			unsigned char signature : 4;
		}bits; /**/
	}safetype;

	unsigned char opera;
	uint32_t msglen;
	uint32_t tboxid;
}__attribute__((packed)) PP_pack_Header_t;

typedef struct
{
	PP_pack_Header_t Header;/* */
	unsigned char msgdata[1024];
	unsigned char msgtype;
}PP_pack_t;

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


/*******************************************************
description£º typedef definitions
*******************************************************/
/******enum definitions******/

/*****struct definitions*****/

/******union definitions*****/

/*******************************************************
description£º variable External declaration
*******************************************************/

/*******************************************************
description£º function External declaration
*******************************************************/

#endif 
