#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CLeftPaneView 对话框

class CLeftPaneView : public CDialog
{
	DECLARE_DYNAMIC(CLeftPaneView)

public:
	CLeftPaneView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLeftPaneView();

// 对话框数据
	enum { IDD = IDD_LEFT_PANE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	//***********************管理端所有功能分支*************************************
	HTREEITEM hItem13,hItem131,hItem132,hItem133,hItem2,hItem21,hItem22;
	HTREEITEM hItem1,hItem11,hItem111,hItem112,hItem12,hItem121,hItem122,hItem3,hItem4,hItem41,hItem42;
	//***********************客服经理功能分支***************************************
	HTREEITEM CS1Item1,CS1Item11,CS1Item12;
	HTREEITEM CS1Item2,CS1Item21,CS1Item22,CS1Item23;
	HTREEITEM CS1Item3;
	HTREEITEM CS1Item4,CS1Item41,CS1Item42;
	//**********************客服代表功能分支****************************************
	HTREEITEM CS2Item1,CS2Item11,CS2Item111,CS2Item112,CS2Item12,CS2Item121,CS2Item122;
	HTREEITEM CS2Item2,CS2Item21,CS2Item22;
	HTREEITEM CS2Item3;
	HTREEITEM CS2Item4;

	//*********************平台经理**************************************************
	HTREEITEM MANItem1,MANItem11,MANItem12;
	HTREEITEM MANItem2,MANItem21,MANItem22;
	HTREEITEM MANItem3;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
private:
	CTreeCtrl m_tree;
	CFont m_myFont;
	
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
private:
	CBrush m_Brush;
public:
	afx_msg void OnTvnSelchangedDirectree(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual void OnOK();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnTvnSelchangingDirectree(NMHDR *pNMHDR, LRESULT *pResult);
	CTreeCtrl m_TreeCS2;
	CTreeCtrl m_TreeCS1;
	afx_msg void OnTvnSelchangedTreeCs1(NMHDR *pNMHDR, LRESULT *pResult);
	CTreeCtrl m_TreeMan;
	afx_msg void OnTvnSelchangedTreeCs2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnTvnSelchangedTreeMan(NMHDR *pNMHDR, LRESULT *pResult);
};
