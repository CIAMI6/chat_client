// CRegDla.cpp: 实现文件
//

#include "stdafx.h"
#include "chat_client.h"
#include "CRegDla.h"
#include "afxdialogex.h"


// CRegDla 对话框

IMPLEMENT_DYNAMIC(CRegDla, CDialogEx)

CRegDla::CRegDla(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Register, pParent)
	, m_NickName(_T(""))
	, m_sex(0)
	, m_Password(_T(""))
{

}

CRegDla::~CRegDla()
{
}

void CRegDla::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_NickName);
	DDX_Radio(pDX, IDC_RADIO1, m_sex);
	DDX_Text(pDX, IDC_EDIT2, m_Password);
}


BEGIN_MESSAGE_MAP(CRegDla, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &CRegDla::OnBnClickedButton2)
END_MESSAGE_MAP()


// CRegDla 消息处理程序



void CRegDla::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	RegMeg regmsg = {};
	USES_CONVERSION;
	memcpy_s(regmsg.Name, 20, W2A(m_NickName.GetBuffer()), m_NickName.GetLength() * 2);
	memcpy_s(regmsg.Pwd, 20, W2A(m_Password.GetBuffer()), m_Password.GetLength() * 2);
	regmsg.NameLen = strlen(regmsg.Name);
	regmsg.PwdLen = strlen(regmsg.Pwd);
	regmsg.Sex = m_sex;
	HWND hWnd = AfxGetMainWnd()->m_hWnd;
	::SendMessage(hWnd, WM_RegisterMessage, (WPARAM)m_hWnd, (LPARAM)&regmsg);
}
