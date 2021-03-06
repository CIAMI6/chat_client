// CChatRoom.cpp: 实现文件
//

#include "stdafx.h"
#include "chat_client.h"
#include "CChatRoom.h"
#include "afxdialogex.h"


// CChatRoom 对话框

IMPLEMENT_DYNAMIC(CChatRoom, CDialogEx)

CChatRoom::CChatRoom(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ChatRoom, pParent)
{

}

CChatRoom::~CChatRoom()
{
}

void CChatRoom::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RoomList, m_RoomList);
}


BEGIN_MESSAGE_MAP(CChatRoom, CDialogEx)
END_MESSAGE_MAP()


// CChatRoom 消息处理程序
