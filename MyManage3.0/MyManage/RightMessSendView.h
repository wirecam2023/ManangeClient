#pragma once
#include "xpgroupbox.h"
#include "btnst.h"
#include "btnst.h"
#include "afxwin.h"
/*#include "BtnST.h"*/

// CRightMessSendView 对话框

class CRightMessSendView : public CDialog
{
	DECLARE_DYNAMIC(CRightMessSendView)

public:
	CRightMessSendView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRightMessSendView();

// 对话框数据
	enum { IDD = IDD_RIGHT_MESSSEND };
public:
		CListCtrl m_sendmess;
/*		CString m_messtext;*/
		CDateTimeCtrl m_date;
		CDateTimeCtrl m_time;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
/*	CButtonST m_BtnQue;*/
	CComboBox m_SendTo;
	CComboBox m_QueType;
/*	CButtonST m_Send;*/
//	CXPGroupBox m_Group;
//	CXPGroupBox m_Group;
//	CXPGroupBox m_Group;
	CButtonST m_Btn;
	//CButtonST m_Send;
//	CButton m_btttttt;
};
