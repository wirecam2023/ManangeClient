#pragma once
#include "afxwin.h"
#include "d:\健康云项目\cbtnst_source\btnst.h"
#include "d:\健康云项目\cbtnst_source\btnst.h"
#include "d:\健康云项目\cbtnst_source\btnst.h"
#include "d:\健康云项目\cbtnst_source\btnst.h"
#include "xpgroupbox.h"


// CRightAuthDoc2View 对话框

class CRightAuthDoc2View : public CDialog
{
	DECLARE_DYNAMIC(CRightAuthDoc2View)

public:
	CRightAuthDoc2View(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRightAuthDoc2View();

// 对话框数据
	enum { IDD = IDD_AUTH_DOC2 };
public:
	CListCtrl m_dplist;
	CListCtrl m_chodplist;
	int dprow,chodprow;
	CString dpname,dpcellnum;
	CString m_quedptype;
	CString m_quedptext;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
private:
	CComboBox m_QueType;
//	CButtonST m_;
public:
	CButtonST m_BtnQue;
	CButtonST m_Add;
	CButtonST m_Del;
	CXPGroupBox m_Group;
};
