#pragma once
#include "afxwin.h"
#include "d:\健康云项目\cbtnst_source\btnst.h"
#include "d:\健康云项目\cbtnst_source\btnst.h"
#include "d:\健康云项目\cbtnst_source\btnst.h"
#include "xpgroupbox.h"


// CRightAuthTech2View 对话框

class CRightAuthTech2View : public CDialog
{
	DECLARE_DYNAMIC(CRightAuthTech2View)

public:
	CRightAuthTech2View(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRightAuthTech2View();

// 对话框数据
	enum { IDD = IDD_AUTH_TECH2 };
public:
	CListCtrl m_tplist;
	CListCtrl m_chotplist;
	int tprow,chotprow;
	CString tpname,tpcellnum;
	CString m_quetechtype;
	CString m_quetechtext;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
private:
	CComboBox m_QueType;
	CButtonST m_BtnQue;
public:
	CButtonST m_AddTech;
private:
	CButtonST m_DelTech;
public:
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	CXPGroupBox m_Group;
};
