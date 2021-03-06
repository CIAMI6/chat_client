#pragma once


// CPrivateDlg 对话框

class CPrivateDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPrivateDlg)

public:
	CPrivateDlg(char *name,CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CPrivateDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PrivateMsg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	char *m_name;
	afx_msg void OnBnClickedBsend();
	CString m_MyMsg;
protected:
	afx_msg LRESULT OnPrivatemessage(WPARAM wParam, LPARAM lParam);
public:
	CString m_MsgRec;
};
