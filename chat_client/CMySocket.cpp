// CMySocket.cpp: 实现文件
//

#include "stdafx.h"
#include "chat_client.h"
#include "CMySocket.h"
#include "chat_clientDlg.h"


// CMySocket

CMySocket::CMySocket()
{
}

CMySocket::~CMySocket()
{
}


// CMySocket 成员函数


void CMySocket::OnReceive(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	char s[2048] = { 0 };
	Receive(s, sizeof(s));
	CchatclientDlg *pDlg = (CchatclientDlg *)AfxGetMainWnd();
	pDlg->OnReceive(s);

	CSocket::OnReceive(nErrorCode);
}
