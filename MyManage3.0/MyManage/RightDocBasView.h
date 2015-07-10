#pragma once
#include "xpgroupbox.h"


// CRightDocBasView 对话框

class CRightDocBasView : public CDialog
{
	DECLARE_DYNAMIC(CRightDocBasView)

public:
	CRightDocBasView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRightDocBasView();

// 对话框数据
	enum { IDD = IDD_DOC_BAS };
public:
	CString m_name;
	CString m_cell;
	CString m_ID;
	CString m_hospital;
	CString m_adminoff;
	CString m_school;
	CString m_eduback;
	CString m_doctype;
	CString m_gender;
	CString m_password;
	CString m_title;
	CString m_duty;
	CString m_major;
	CString m_contime;
	CString m_reptime;
	CButtonST m_Btn1;
	CButtonST m_Btn2;
	CComboBox m_DocType;
	CComboBox m_Gender;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CXPGroupBox m_Group;
};
