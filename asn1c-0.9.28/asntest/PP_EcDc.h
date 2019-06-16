/******************************************************
文件名：	PP_EcDc.h

描述：	企业私有协议（浙江合众）	

Data			  Vasion			author
2019/4/29		V1.0			liujian
*******************************************************/
#ifndef		_PP_ECDC_H
#define		_PP_ECDC_H
/*******************************************************
description： include the header file
*******************************************************/


/*******************************************************
description： macro definitions
*******************************************************/
/**********宏开关定义*********/

/**********宏常量定义*********/
#define PP_ECDC_XCALLREQ 1

/***********宏函数***********/

/*******************************************************
description： struct definitions
*******************************************************/
/*****struct definitions*****/
typedef struct
{
	unsigned char sign[2U];/* 起始符标志位，取值0x2A，0x2A*/
	union
	{
		unsigned char Byte;/* */
		struct
		{
			unsigned char mnr : 4;/* 小版本(由TSP平台定义)*/
			unsigned char mjr : 4;/* 大版本(由TSP平台定义)*/
		}bits; /**/
	}ver;
	uint32_t nonce;/* TCP会话ID 由TSP平台产生 */

	union
	{
		unsigned char Byte;/* */
		struct
		{
			unsigned char encode : 4;/* 编码方式0：none；1NGTP；2：GZIP；3：JSON*/
			unsigned char mode : 1;/* 类型0：normal；1：debug*/
			unsigned char connt  : 1;/* 连接方式0：短连接；1：长连接*/
			unsigned char asyn : 1;/* 通讯方式0：同步；1：异步*/
			unsigned char dir  : 1;/* 报文方向0：To Tbox；1：To TSP*/
		}bits; /**/
	}commtype;

	union
	{
		unsigned char Byte;/* */
		struct
		{
			unsigned char encrypt   : 4;/* 加密方式0：none；1：AES128；2：AES256；3RSA2048*/
			unsigned char signature : 4;/* 签名方式:0 -- none ;1 -- SHA1;2 -- SHA256*/
		}bits; /**/
	}safetype;

	unsigned char opera;/* 操作类型:0 -- national standard ;1 -- heartbeat;2 -- ngtp ;3 -- OTA */
	uint32_t msglen;/* 报文长度 */
	uint32_t tboxid;/* 平台通过tboxID与tboxSN映射 */
}__attribute__((packed)) PP_pack_Header_t; /*报文头结构体*/

typedef struct
{
	PP_pack_Header_t Header;/* */
	unsigned char msgdata[1024];/* 消息体 */
	unsigned char msgtype;/* 消息类型 */
}PP_pack_t; /*报文结构体*/

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
/*******************************************************
description： typedef definitions
*******************************************************/
/******enum definitions******/

/*****struct definitions*****/

/******union definitions*****/

/*******************************************************
description： variable External declaration
*******************************************************/

/*******************************************************
description： function External declaration
*******************************************************/

#endif 
