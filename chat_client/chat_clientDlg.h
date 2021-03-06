
// chat_clientDlg.h: 头文件
//

#pragma once
#include "CMySocket.h"


// CchatclientDlg 对话框
class CchatclientDlg : public CDialogEx
{
// 构造
public:
	CchatclientDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHAT_CLIENT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	void OnReceive(char *szText);
	afx_msg void OnBnClickedButton2();
	void InitWs();

protected:
	afx_msg LRESULT OnPrivatemessage(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnLoginmessage(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnRegistermessage(WPARAM wParam, LPARAM lParam);
public:
	CString m_UserName;
	CString m_UserPassword;	
	CMySocket m_socket;
	afx_msg void OnStnClickedStatic1();
	afx_msg void OnBnClickedButton3();
protected:
	afx_msg LRESULT OnUpdatefriend(WPARAM wParam, LPARAM lParam);
};
