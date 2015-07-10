#pragma once
#include "afxwin.h"
#include "d:\健康云项目\cbtnst_source\btnst.h"
#include "d:\健康云项目\cbtnst_source\btnst.h"
#include "d:\健康云项目\cbtnst_source\btnst.h"
#include "xpgroupbox.h"


// CRightChgManAccView 对话框

class CRightChgManAccView : public CDialog
{
	DECLARE_DYNAMIC(CRightChgManAccView)

public:
	CRightChgManAccView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRightChgManAccView();

// 对话框数据
	enum { IDD = IDD_RIGHT_CHGMANACC };
public:
	CString m_quetype;
	CString m_quetext;
	CString manduty;
	CListCtrl m_manlist;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
private:
	CComboBox m_QueType;
	CButtonST m_BtnQue;
public:
	CButtonST m_BtnOK;
	CButtonST m_BtnSub;
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	CXPGroupBox m_Group;
	CXPGroupBox m_Group1;
};
