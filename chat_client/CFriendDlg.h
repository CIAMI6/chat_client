#pragma once
#include "CMyListCtrl.h"

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
public:
	CMyListCtrl m_FriendList;
	virtual BOOL OnInitDialog();
protected:
	afx_msg LRESULT OnUpdatefriend(WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnDblclkFriendlist(NMHDR *pNMHDR, LRESULT *pResult);
};
