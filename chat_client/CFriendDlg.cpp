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
}


BEGIN_MESSAGE_MAP(CFriendDlg, CDialogEx)
END_MESSAGE_MAP()


// CFriendDlg 消息处理程序
