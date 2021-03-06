// CFriendDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "chat_client.h"
#include "CFriendDlg.h"
#include "afxdialogex.h"
#include "CPrivateDlg.h"



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
	ON_MESSAGE(WM_UpdateFriend, &CFriendDlg::OnUpdatefriend)
	ON_NOTIFY(NM_DBLCLK, IDC_FriendList, &CFriendDlg::OnDblclkFriendlist)
END_MESSAGE_MAP()


// CFriendDlg 消息处理程序


BOOL CFriendDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_FriendList.InsertCol(2, L"好友", 300 , L"状态", 50);


	HWND hWnd = ::FindWindow(NULL,L"聊天软件");
	::SendMessage(hWnd, WM_UpdateFriend, (WPARAM)m_hWnd, NULL);
	

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


afx_msg LRESULT CFriendDlg::OnUpdatefriend(WPARAM wParam, LPARAM lParam)
{
	/*void SetItemColor(DWORD dwIndex, COLORREF clrTextColor = RGB(0, 0, 0),
		COLORREF clrBkColor = RGB(255, 255, 255));*/
	int NameLen;
	int Status;
	int FriNum = *(int *)wParam;
	char * s = ((char *)wParam + 4);
	char temp[20];
	for (int i = 0;i < FriNum;++i)
	{
		NameLen = *(int *)s + 1;
		s += 4;
		Status = *(int *)s;
		s += 4;
		for (int j = 0;j < NameLen;j++)
		{
			temp[j] = *(s + j);
		}
		//m_FriendList.InsertItem(i, CString(temp));
		if (Status)
		{
			m_FriendList.InsertOnLineItem(2, CString(temp), L"在线");
			//m_FriendList.SetItemText(i, 1, L"在线");
			m_FriendList.SetItemColor(i, RGB(0, 0, 0),RGB(180, 238, 180));
		}	
		else
		{
			m_FriendList.InsertOnLineItem(2, CString(temp), L"离线");
			//m_FriendList.SetItemText(i, 1, L"离线");
			m_FriendList.SetItemColor(i, RGB(0, 0, 0), RGB(255,181,197));
		}
			
		s += 20;
	}
	

	return 0;
}


void CFriendDlg::OnDblclkFriendlist(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	int nIndex = m_FriendList.GetNextItem(-1, LVNI_SELECTED);
	char name[20];
	USES_CONVERSION;
	CString cname =  m_FriendList.GetItemText(nIndex, 0);
	memcpy_s(name, 20, T2A(cname), cname.GetLength() * 2);
		
	CPrivateDlg *pPD = new CPrivateDlg(name);
	pPD->Create(IDD_PrivateMsg);
	pPD->ShowWindow(SW_SHOW);

	*pResult = 0;
}
