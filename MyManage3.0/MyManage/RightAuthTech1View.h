#pragma once
#include "afxwin.h"
#include "d:\健康云项目\cbtnst_source\btnst.h"
#include "d:\健康云项目\cbtnst_source\btnst.h"
#include "d:\健康云项目\cbtnst_source\btnst.h"
#include "xpgroupbox.h"


// CRightAuthTech1View 对话框

class CRightAuthTech1View : public CDialog
{
	DECLARE_DYNAMIC(CRightAuthTech1View)

public:
	CRightAuthTech1View(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRightAuthTech1View();

// 对话框数据
	enum { IDD = IDD_AUTH_TECH1 };
public:
	CListCtrl m_tmlist;
	CListCtrl m_chotmlist;
	int tmrow,chotmrow;
	CString tmname,tmcellnum;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
private:
	CComboBox m_QueType;
public:
	CButtonST m_BtnQueTech;
private:
	CButtonST m_AddTech;
public:
	CButtonST m_DelTech;
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	CXPGroupBox m_Group;
};
