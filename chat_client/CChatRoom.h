#pragma once
#include "CMyListCtrl.h"

// CChatRoom 对话框

class CChatRoom : public CDialogEx
{
	DECLARE_DYNAMIC(CChatRoom)

public:
	CChatRoom(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CChatRoom();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ChatRoom };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CMyListCtrl m_RoomList;
};
