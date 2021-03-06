#pragma once


// CMyTabCtrl

class CMyTabCtrl : public CTabCtrl
{
	DECLARE_DYNAMIC(CMyTabCtrl)

public:
	CMyTabCtrl();
	virtual ~CMyTabCtrl();
	//插入选项卡
	void InsertTab(DWORD dwCount, ...);
	//增加对话框
	void AddDlg(DWORD dwCount, ...);
	//设置当前选中的对话框并显示
	void SetSelandShow(int nSel);
	//选项卡中存储的对话框数组
	CDialogEx* m_pDlg[20];
	//当前选项卡中对话框的数量
	DWORD m_dwCount;

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTcnSelchange(NMHDR *pNMHDR, LRESULT *pResult);
};


