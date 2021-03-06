// CMyTabCtrl.cpp: 实现文件
//

#include "stdafx.h"
#include "chat_client.h"
#include "CMyTabCtrl.h"


// CMyTabCtrl

IMPLEMENT_DYNAMIC(CMyTabCtrl, CTabCtrl)

CMyTabCtrl::CMyTabCtrl()
{

}

CMyTabCtrl::~CMyTabCtrl()
{
}

void CMyTabCtrl::InsertTab(DWORD dwCount, ...)
{
	va_list argptr;
	va_start(argptr, dwCount);
	for (DWORD i = 0;i < dwCount;++i)
	{
		TCHAR* pTabName = va_arg(argptr, TCHAR*);
		InsertItem(i, pTabName);
	}
	va_end(argptr);
	m_dwCount = dwCount;
}

void CMyTabCtrl::AddDlg(DWORD dwCount, ...)
{
	va_list argptr;
	va_start(argptr, dwCount);
	for (DWORD i = 0;i < dwCount;++i)
	{
		UINT uId = va_arg(argptr, UINT);
		m_pDlg[i] = va_arg(argptr, CDialogEx*);
		m_pDlg[i]->Create(uId, this);
	}
	va_end(argptr);
}

void CMyTabCtrl::SetSelandShow(int nSel)
{
	CRect rt;
	//获取客户区大小
	GetClientRect(rt);
	//将对话框移动到客户区范围内
	rt.DeflateRect(2, 24, 3, 2);
	//获取当前选中的选项卡
	SetCurSel(nSel);
	m_pDlg[nSel]->ShowWindow(SW_SHOW);
	m_pDlg[nSel]->MoveWindow(rt);
}


BEGIN_MESSAGE_MAP(CMyTabCtrl, CTabCtrl)
	ON_NOTIFY_REFLECT(TCN_SELCHANGE, &CMyTabCtrl::OnTcnSelchange)
END_MESSAGE_MAP()



// CMyTabCtrl 消息处理程序




void CMyTabCtrl::OnTcnSelchange(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	CRect rt;
	//获取客户区大小
	GetClientRect(rt);
	//将对话框移动到客户区范围内
	rt.DeflateRect(2, 24, 3, 2);
	//获取当前选中的选项卡
	DWORD dwSel = GetCurSel();
	//遍历所有添加的对话框
	for (DWORD i = 0;i < m_dwCount;++i)
	{
		if (dwSel == i)
		{
			m_pDlg[i]->ShowWindow(SW_SHOW);
			m_pDlg[i]->MoveWindow(rt);
		}
		else
		{
			m_pDlg[i]->ShowWindow(SW_HIDE);
		}
	}
	*pResult = 0;
}
