// CMyListCtrl.cpp: 实现文件
//

#include "stdafx.h"
#include "chat_client.h"
#include "CMyListCtrl.h"


// CMyListCtrl

IMPLEMENT_DYNAMIC(CMyListCtrl, CListCtrl)

CMyListCtrl::CMyListCtrl()
{

}

CMyListCtrl::~CMyListCtrl()
{
}


BEGIN_MESSAGE_MAP(CMyListCtrl, CListCtrl)
	ON_NOTIFY_REFLECT(NM_CUSTOMDRAW, &CMyListCtrl::OnNMCustomdraw)
END_MESSAGE_MAP()



// CMyListCtrl 消息处理程序




void CMyListCtrl::OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void CMyListCtrl::PreSubclassWindow()
{
	// TODO: 在此添加专用代码和/或调用基类
	SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	CListCtrl::PreSubclassWindow();
}

void CMyListCtrl::InsertCol(DWORD dwCount, ...)
{
	va_list argptr;
	va_start(argptr, dwCount);
	for (DWORD i = 0;i < dwCount;++i)
	{
		TCHAR *pStrTabName = va_arg(argptr, TCHAR*);
		DWORD dwWidth = va_arg(argptr, UINT);
		InsertColumn(i, pStrTabName, 0, dwWidth);
	}
	va_end(argptr);
	m_dwColCount = dwCount;
}

void CMyListCtrl::InsertOnLineItem(DWORD dwCount, ...)
{
	va_list argptr;
	va_start(argptr, dwCount);
	TCHAR* pStrItemName = va_arg(argptr, TCHAR*);
	InsertItem(m_dwItemCount, pStrItemName);
	for (DWORD i = 1; i < dwCount; i++)
	{
		TCHAR *pStrItemName = va_arg(argptr, TCHAR*);
		SetItemText(m_dwItemCount, i, pStrItemName);
	}
	va_end(argptr);	
	ITEM_COLOR stcInfo;
	//保存每一行的颜色信息
	m_vecItemColor.push_back(stcInfo);
	//保存有多少行
	++m_dwItemCount;
}

void CMyListCtrl::SetItemColor(DWORD dwIndex, COLORREF clrTextColor, COLORREF clrBkColor)
{
	m_vecItemColor[dwIndex].clrtextColor = clrTextColor;
	m_vecItemColor[dwIndex].clrBkColor = clrBkColor;
}
