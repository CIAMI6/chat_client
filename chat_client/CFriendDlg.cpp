// CFriendDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "chat_client.h"
#include "CFriendDlg.h"
#include "afxdialogex.h"


// CFriendDlg 对话框

IMPLEMENT_DYNAMIC(CFriendDlg, CDialogEx)

CFriendDlg::CFriendDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FriendDlg, pParent)
{

}

CFriendDlg::~CFriendDlg()
{
}

void CFriendDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FriendList, m_FriendList);
}


BEGIN_MESSAGE_MAP(CFriendDlg, CDialogEx)
END_MESSAGE_MAP()


// CFriendDlg 消息处理程序


BOOL CFriendDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_FriendList.InsertCol(1, L"好友", 400);


	HWND hWnd = ::FindWindow(NULL,L"聊天软件");
	::SendMessage(hWnd, WM_UpdateFriend, (WPARAM)m_hWnd, NULL);
	

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
