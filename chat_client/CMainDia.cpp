// CMainDia.cpp: 实现文件
//

#include "stdafx.h"
#include "chat_client.h"
#include "CMainDia.h"
#include "afxdialogex.h"
#include "CFriendDlg.h"
#include "CChatRoom.h"


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
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CMainDia 消息处理程序


void CMainDia::InitMyTab()
{
	CDialogEx *m_Dia[2];
	m_Dia[0] = new CFriendDlg;
	m_Dia[1] = new CChatRoom;
	m_TabCtrl.InsertTab(2, L"好友列表", L"聊天室");
	m_TabCtrl.AddDlg(2, IDD_FriendDlg, m_Dia[0],
		IDD_ChatRoom, m_Dia[1]);
	m_TabCtrl.SetSelandShow(0);

}

BOOL CMainDia::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	InitMyTab();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CMainDia::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	ExitProcess(0);

	CDialogEx::OnClose();
}
