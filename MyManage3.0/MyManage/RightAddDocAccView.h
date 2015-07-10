#pragma once
#include "xpgroupbox.h"


// CRightAddDocAccView 对话框

class CRightAddDocAccView : public CDialog
{
	DECLARE_DYNAMIC(CRightAddDocAccView)

public:
	CRightAddDocAccView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRightAddDocAccView();

// 对话框数据
	enum { IDD = IDD_RIGHT_ADDDOCACC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_doctorname;
	CString m_cellnumber;
	CString m_IDnumber;
	CString m_hospital;
	CString m_adminoffice;
	CString m_school;
	CString m_eduback;
	CString m_gender;
	CString m_password;
	CString m_title;
	CString m_duty;
	CString m_major;
	CString m_consulttime;
	CString m_replytime;
	CString m_doctype;
	CComboBox m_DocType;
	CComboBox m_Gender;
	CButtonST m_Btn;
public:
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	CXPGroupBox m_Group;
};
