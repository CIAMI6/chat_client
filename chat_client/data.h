#pragma once
#include <Windows.h>

typedef enum MessageType
{
	//ע����Ϣ
	RegisterMessage,
	//��½��Ϣ
	LoginMessage,
	//������Ϣ
	Online,
	//������Ϣ
	Offline,
	//�����ļ���Ϣ
	OnFile,
	//��Ӻ���
	FriendRequests,
	//ɾ������
	DeleteFriend,
	//���Һ���
	SearchFriend,
	//�鿴�����¼
	QueryRecord,
	//���º�����Ϣ
	UpdateFriend,
	//˽����Ϣ
	PrivateMessage,
	//Ⱥ����Ϣ
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
	//Ŀ��ID���û���
	char szDesId[20];
	//˽������
	char szContent[1024];
}PmMsg;

struct UserInfo
{
	int NameLen;
	char Name[20];
};




typedef struct MESSAGECONTENT
{
	//��Ϣ����
	MsgType Msg_type;
	//��Ϣ���ĳ���
	DWORD dwMsgLen;
	//���ھ��
	HWND hwnd;
	//��Ϣ����
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
	WM_RegisterMessage,
	WM_UpdateFriend
};