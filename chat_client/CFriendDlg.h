#pragma once


// CFriendDlg 对话框

class CFriendDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFriendDlg)

public:
	CFriendDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CFriendDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FriendDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
