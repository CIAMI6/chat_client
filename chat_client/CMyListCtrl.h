#pragma once
#include <vector>
using std::vector;

// CMyListCtrl

typedef struct _ITEM_COLOR
{
	COLORREF clrtextColor;
	COLORREF clrBkColor;
	_ITEM_COLOR():clrtextColor(RGB(0,0,0)),
		clrBkColor(RGB(255,255,255)){}
}ITEM_COLOR, *PITEM_COLOR;

class CMyListCtrl : public CListCtrl
{
	DECLARE_DYNAMIC(CMyListCtrl)

public:
	CMyListCtrl();
	virtual ~CMyListCtrl();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult);
	int m_nItem;

	virtual void PreSubclassWindow();
	//插入列信息
	void InsertCol(DWORD dwCount, ...);
	//插入行信息
	void InsertOnLineItem(DWORD dwCount, ...);
	//设置指定行的背景色和文本色
	void SetItemColor(DWORD dwIndex, COLORREF clrTextColor = RGB(0, 0, 0),
		COLORREF clrBkColor = RGB(255, 255, 255));
	DWORD m_dwColCount;
	DWORD m_dwItemCount;
	vector<ITEM_COLOR> m_vecItemColor;

};


