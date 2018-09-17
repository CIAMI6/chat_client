#pragma once
#include <Windows.h>

typedef enum MessageType
{
	//注册消息
	RegisterMessage,
	//登陆消息
	LoginMessage,
	//上线消息
	Online,
	//下线消息
	Offline,
	//发送文件消息
	OnFile,
	//添加好友
	FriendRequests,
	//删除好友
	DeleteFriend,
	//查找好友
	SearchFriend,
	//查看聊天记录
	QueryRecord,
	//更新好友消息
	UpdateFriend,
	//私聊消息
	PrivateMessage,
	//群聊消息
	GroupMessage
}MsgType;

typedef struct LOGGINMESSAGE
{
	int NameLen;
	int PwdLen;
	char UserName[20];
	char UserPass[20];
}LogMsg, *pLogMsg;

struct RegMeg
{
	int NameLen;
	int PwdLen;
	
	int Sex;
	CHAR Name[20];
	CHAR Pwd[20];
};


typedef struct PRIVATEMESSAGE
{
	//目标ID或用户名
	CHAR szDesId[40];
	//私聊正文
	CHAR szContent[40];
}PmMsg;

typedef struct MESSAGECONTENT
{
	//消息类型
	MsgType Msg_type;
	//消息正文长度
	DWORD dwMsgLen;
	//窗口句柄
	HWND hwnd;
	//消息正文
	union MyUnion
	{
		CHAR buff[2048];
		LogMsg login;
		PmMsg pmmsg; 
	}m_content;
	
}ChatMeg;

enum UserMessage
{
	WM_PrivateMessage = WM_USER + 1,
	WM_LoginMessage,
	WM_RegisterMessage
};