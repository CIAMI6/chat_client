#pragma once


// CRegDla 对话框

class CRegDla : public CDialogEx
{
	DECLARE_DYNAMIC(CRegDla)

public:
	CRegDla(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CRegDla();
	afx_msg void OnBnClickedButton2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Register };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_NickName;
	int m_sex;
	CString m_Password;
};
