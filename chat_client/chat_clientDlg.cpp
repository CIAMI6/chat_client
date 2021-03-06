
// chat_clientDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "chat_client.h"
#include "chat_clientDlg.h"
#include "afxdialogex.h"
#include <WinSock2.h>
#include "CRegDla.h"
#include "CMainDia.h"
#pragma comment(lib,"ws2_32.lib")


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框
CRegDla *pRegDlg;
CMainDia *pMainDlg;
HWND FriendWnd;

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CchatclientDlg 对话框



CchatclientDlg::CchatclientDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CHAT_CLIENT_DIALOG, pParent)
	, m_UserName(_T("haha"))
	, m_UserPassword(_T("123"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON2);
}

void CchatclientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_UserName);
	DDX_Text(pDX, IDC_EDIT2, m_UserPassword);
}

BEGIN_MESSAGE_MAP(CchatclientDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(WM_PrivateMessage, &CchatclientDlg::OnPrivatemessage)
	ON_MESSAGE(WM_LoginMessage, &CchatclientDlg::OnLoginmessage)
	ON_MESSAGE(WM_RegisterMessage, &CchatclientDlg::OnRegistermessage)
	ON_BN_CLICKED(IDC_BUTTON2, &CchatclientDlg::OnBnClickedButton2)
	ON_STN_CLICKED(IDC_STATIC1, &CchatclientDlg::OnStnClickedStatic1)
	ON_BN_CLICKED(IDC_BUTTON3, &CchatclientDlg::OnBnClickedButton3)
	ON_MESSAGE(WM_UpdateFriend, &CchatclientDlg::OnUpdatefriend)
END_MESSAGE_MAP()


// CchatclientDlg 消息处理程序

BOOL CchatclientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	InitWs();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CchatclientDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CchatclientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CchatclientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CchatclientDlg::OnReceive(char * szText)
{
	int type = *(int *)szText;
	switch (type)
	{
	case 0:
		//MessageBox(L"unconnect  server");
		//break;
	case 1:
		ShowWindow(SW_HIDE);
		pMainDlg = new CMainDia;
		pMainDlg->Create(IDD_ICQ);
		pMainDlg->ShowWindow(SW_SHOW);
		break;
	case 2:
		MessageBox(L"wrong password or wrong username");
		break;
	case 3:
		MessageBox(L"Rigister success");
		pRegDlg->EndDialog(0);
		delete pRegDlg;
		break;
	case 4:
		MessageBox(L"Rigister fail");
		break;
	//更新好友
	case 5:
		szText += 4;
		
		::SendMessage(FriendWnd, WM_UpdateFriend, (WPARAM)szText, NULL);
	case 6:
	{
		szText += 4;
		char name[20];
		for (int i = 0;i < 20;i++)
		{
			name[i] = *(szText + i);
		}
		szText += 20;
		HWND hwnd = ::FindWindow(NULL, CString(name));
		if (hwnd)
			::SendMessage(hwnd, PrivateMessage, (WPARAM)szText, NULL);
	}
	break;
		

	default:
		break;
	}
	//MessageBoxA(m_hWnd, szText, 0,0);
}



afx_msg LRESULT CchatclientDlg::OnPrivatemessage(WPARAM wParam, LPARAM lParam)
{
	ChatMeg chatmsg = {};
	chatmsg.hwnd = (HWND)wParam;
	chatmsg.Msg_type = PrivateMessage;
	chatmsg.dwMsgLen = sizeof(PmMsg);
	memcpy(chatmsg.m_content.buff, (char *)lParam, 2048);
	m_socket.Send(&chatmsg, sizeof(chatmsg));
	
	return 0;
}


afx_msg LRESULT CchatclientDlg::OnLoginmessage(WPARAM wParam, LPARAM lParam)
{
	
	ChatMeg chatmsg = {};
	chatmsg.hwnd = (HWND)wParam;
	chatmsg.Msg_type = LoginMessage;
	chatmsg.dwMsgLen = sizeof(LogMsg);
	memcpy(chatmsg.m_content.buff, (char *)lParam, 2048);
	m_socket.Send(&chatmsg, sizeof(chatmsg));
	return 0;
}


//处理注册消息
afx_msg LRESULT CchatclientDlg::OnRegistermessage(WPARAM wParam, LPARAM lParam)
{
	ChatMeg chatmsg = {};
	chatmsg.Msg_type = RegisterMessage;
	chatmsg.dwMsgLen = sizeof(RegMeg);
	memcpy(chatmsg.m_content.buff, (char *)lParam, 2048);
	m_socket.Send(&chatmsg, sizeof(chatmsg));
	return 0;
}

//点击登陆按钮
void CchatclientDlg::OnBnClickedButton2()
{
	
	// TODO: 在此添加控件通知处理程序代码
	
	UpdateData(TRUE);
	LogMsg log = {};
	USES_CONVERSION;
	memcpy_s(log.UserName, 20, W2A(m_UserName.GetBuffer()), m_UserName.GetLength() * 2);
	memcpy_s(log.UserPass, 20, W2A(m_UserPassword.GetBuffer()), m_UserPassword.GetLength() * 2);
	log.NameLen = strlen(log.UserName);
	log.PwdLen = strlen(log.UserPass);
	::SendMessage(m_hWnd, WM_LoginMessage, (WPARAM)m_hWnd, (LPARAM)&log);	
}

void CchatclientDlg::InitWs()
{
	WSADATA wa = {};
	int nIsSuccess = WSAStartup(MAKEWORD(2, 2), &wa);
	if (nIsSuccess)
	{
		MessageBox(L"初始化失败");
		return;
	}
	CString str;
	BOOL bRet = m_socket.Create();
	DWORD dwErr = GetLastError();
	if (!bRet && WSANOTINITIALISED == dwErr)
	{
		str = L"未调用WSAStartup";
		MessageBox(str);
		return;
	}
	int i = m_socket.Connect(L"127.0.0.1", 0x1234);
}

void CchatclientDlg::OnStnClickedStatic1()
{
	// TODO: 在此添加控件通知处理程序代码
	CRegDla *pRegDlg = new CRegDla;
	pRegDlg->Create(IDD_Register);
	pRegDlg->ShowWindow(SW_SHOW);
}

//点击取消按钮
void CchatclientDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(0);
}

//更新好友消息
afx_msg LRESULT CchatclientDlg::OnUpdatefriend(WPARAM wParam, LPARAM lParam)
{
	ChatMeg chatmsg = {};
	UserInfo user = {};
	USES_CONVERSION;
	memcpy_s(user.Name, 20, W2A(m_UserName), m_UserName.GetLength() * 2);
	user.NameLen = strlen(user.Name);
	chatmsg.Msg_type = UpdateFriend;
	FriendWnd = (HWND)wParam;
	memcpy(chatmsg.m_content.buff, (char *)&user, 2048);
	m_socket.Send(&chatmsg, sizeof(chatmsg));
	return 0;
}
