// CPrivateDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "chat_client.h"
#include "CPrivateDlg.h"
#include "afxdialogex.h"


// CPrivateDlg 对话框

IMPLEMENT_DYNAMIC(CPrivateDlg, CDialogEx)

CPrivateDlg::CPrivateDlg(char *name, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PrivateMsg, pParent)
	, m_MyMsg(_T(""))
	, m_MsgRec(_T(""))
{
	m_name = _strdup(name);
}

CPrivateDlg::~CPrivateDlg()
{
}

void CPrivateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_MyMsg);
	DDX_Text(pDX, IDC_EDIT1, m_MsgRec);
}


BEGIN_MESSAGE_MAP(CPrivateDlg, CDialogEx)
	ON_BN_CLICKED(IDC_Bsend, &CPrivateDlg::OnBnClickedBsend)
	ON_MESSAGE(WM_PrivateMessage, &CPrivateDlg::OnPrivatemessage)
END_MESSAGE_MAP()


// CPrivateDlg 消息处理程序


BOOL CPrivateDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	SetWindowText(CString(m_name));
	

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

//点击发送按钮
void CPrivateDlg::OnBnClickedBsend()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	PmMsg pmsg = {};
	USES_CONVERSION;
	memcpy_s(pmsg.szDesId, 20, m_name, strlen(m_name));
	memcpy_s(pmsg.szContent, 1024, T2A(m_MyMsg), m_MyMsg.GetLength() * 2);
	m_MsgRec = L"我：" + m_MyMsg;
	UpdateData(FALSE);


	HWND hWnd = ::FindWindow(NULL, L"聊天软件");

	::SendMessage(hWnd, WM_PrivateMessage, (WPARAM)m_hWnd, (LPARAM)&pmsg );

}


afx_msg LRESULT CPrivateDlg::OnPrivatemessage(WPARAM wParam, LPARAM lParam)
{

	m_MsgRec = (CString)m_name + L":" + (CString)(char *)wParam;
	UpdateData(FALSE);
	return 0;
}
