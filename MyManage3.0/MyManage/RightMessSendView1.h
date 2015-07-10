#pragma once
#include "d:\健康云项目\cbtnst_source\btnst.h"
#include "afxcmn.h"
#include "afxwin.h"
#include "xpgroupbox.h"
#include "afxdtctl.h"


// CRightMessSendView1 对话框

class CRightMessSendView1 : public CDialog
{
	DECLARE_DYNAMIC(CRightMessSendView1)

public:
	CRightMessSendView1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRightMessSendView1();

// 对话框数据
	enum { IDD = IDD_MESS_SEND1 };
	
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CButtonST m_Btn2;
	CButtonST m_Btn1;
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CListCtrl m_sendmess;
	CComboBox m_Cmb1;
	CComboBox m_Cmb2;
	CXPGroupBox m_Group;
	afx_msg void OnBnClickedCheck1();
	CDateTimeCtrl m_Data;
	CDateTimeCtrl m_Time;
};
