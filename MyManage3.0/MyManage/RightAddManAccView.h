#pragma once
#include "d:\健康云项目\cbtnst_source\btnst.h"
#include "afxwin.h"
#include "d:\健康云项目\cbtnst_source\btnst.h"
#include "RightAuthCS1View.h"
#include "d:\健康云项目\cbtnst_source\btnst.h"
#include "RightAuthCS2View.h"
#include "RightAuthTech1View.h"
#include "RightAuthTech2View.h"
#include "RightAuthDoc1View.h"
#include "RightAuthDoc2View.h"
// CRightAddManAccView 对话框

class CRightAddManAccView : public CDialog
{
	DECLARE_DYNAMIC(CRightAddManAccView)

public:
	CRightAddManAccView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRightAddManAccView();

// 对话框数据
	enum { IDD = IDD_RIGHT_ADDMANACC };
public:
	CString m_name;
	CString m_duty;
	CString m_cell;
	CString m_password;
	CString m_jobtime;
	CString m_jobphome;
	CButton m_cs;
	CButton m_tech;
	CButton m_doc;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
private:
//	CButtonST m_BtnCS;
public:
	CRightAuthCS1View    m_RightAuthCS1View;
	CRightAuthCS2View    m_RightAuthCS2View;
	CRightAuthTech1View  m_RightAuthTech1View;
	CRightAuthTech2View  m_RightAuthTech2View;
	CRightAuthDoc1View   m_RightAuthDoc1View;
	CRightAuthDoc2View   m_RightAuthDoc2View;
public:
	virtual BOOL OnInitDialog();
	CBrush m_Brush;
private:
//	CButtonST m_BtnCS;
public:
	afx_msg void OnBnClickedCs1();
	afx_msg void OnBnClickedCs2();
	afx_msg void OnBnClickedTech1();
	afx_msg void OnBnClickedTech2();
	afx_msg void OnBnClickedDoc1();
	afx_msg void OnBnClickedDoc2();
private:
	CButtonST m_Btn;
public:
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnBnClickedAuthRange();
};
