#pragma once
#include "afxwin.h"
#include "d:\健康云项目\cbtnst_source\btnst.h"
#include "d:\健康云项目\cbtnst_source\btnst.h"
#include "d:\健康云项目\cbtnst_source\btnst.h"
#include "xpgroupbox.h"


// CRightAuthDoc1View 对话框

class CRightAuthDoc1View : public CDialog
{
	DECLARE_DYNAMIC(CRightAuthDoc1View)

public:
	CRightAuthDoc1View(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRightAuthDoc1View();

// 对话框数据
	enum { IDD = IDD_AUTH_DOC1 };
public:
	CListCtrl m_doclist;
	CListCtrl m_chodoclist;
	int docrow,chodocrow;
	CString docname,doccellnum;

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
	CButtonST m_BtnQue;
	CButtonST m_Btn;
public:
	CButtonST m_DelDoc1;
	CXPGroupBox m_Group;
};
