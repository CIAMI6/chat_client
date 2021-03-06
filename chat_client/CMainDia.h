#pragma once
#include "CMyTabCtrl.h"

// CMainDia 对话框

class CMainDia : public CDialogEx
{
	DECLARE_DYNAMIC(CMainDia)

public:
	CMainDia(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CMainDia();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ICQ };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

	void InitMyTab();
public:
	CMyTabCtrl m_TabCtrl;
	virtual BOOL OnInitDialog();

	afx_msg void OnClose();
};
