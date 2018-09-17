// CMainDia.cpp: 实现文件
//

#include "stdafx.h"
#include "chat_client.h"
#include "CMainDia.h"
#include "afxdialogex.h"


// CMainDia 对话框

IMPLEMENT_DYNAMIC(CMainDia, CDialogEx)

CMainDia::CMainDia(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ICQ, pParent)
{

}

CMainDia::~CMainDia()
{
}

void CMainDia::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_TabCtrl);
}


BEGIN_MESSAGE_MAP(CMainDia, CDialogEx)
END_MESSAGE_MAP()


// CMainDia 消息处理程序
