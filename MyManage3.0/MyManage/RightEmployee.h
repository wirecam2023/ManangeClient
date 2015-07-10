#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "afxdtctl.h"


// CRightEmployee 对话框

class CRightEmployee : public CDialog
{
	DECLARE_DYNAMIC(CRightEmployee)

public:
	CRightEmployee(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRightEmployee();

// 对话框数据
	enum { IDD = IDD_RIGHT_EMPLOYEE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	CListCtrl m_EmployeeList;
	virtual BOOL OnInitDialog();
	CComboBox m_QueType;
	CDateTimeCtrl m_StartTime;
	CDateTimeCtrl m_EndTime;
	afx_msg void OnBnClickedBtnQue();
	afx_msg LRESULT OnSmQueEmployee(WPARAM wParam,LPARAM lParam);
};
