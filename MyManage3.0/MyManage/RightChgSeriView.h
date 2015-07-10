#pragma once
#include "d:\健康云项目\cbtnst_source\btnst.h"
#include "xpgroupbox.h"


// CRightChgSeriView 对话框

class CRightChgSeriView : public CDialog
{
	DECLARE_DYNAMIC(CRightChgSeriView)

public:
	CRightChgSeriView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRightChgSeriView();

// 对话框数据
	enum { IDD = IDD_RIGHT_CHGSERI };
public:
		CString m_seriID;
		CListCtrl m_userinfo;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
private:
	CButtonST m_Btn;
public:
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	CXPGroupBox m_Group;
};
