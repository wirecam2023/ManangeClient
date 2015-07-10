#pragma once
#include "d:\健康云项目\cbtnst_source\btnst.h"
#include "d:\健康云项目\cbtnst_source\btnst.h"
#include "afxcmn.h"


// CTopView 对话框

class CTopView : public CDialog
{
	DECLARE_DYNAMIC(CTopView)

public:
	CTopView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTopView();

// 对话框数据
	enum { IDD = IDD_TOP };
private:
	CBrush m_BrushLeft;
	CBrush m_BrushRight;
	CRect  m_Rc;
// 	CPoint m_PosOri;
// 	CPoint m_Point1;
// 	CPoint m_Point2;
//     BOOL   m_MoveMode;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CButtonST m_BtnMin;
	virtual BOOL OnInitDialog();
	CButtonST m_BtnOff;
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
//	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
//	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
private:
	int m_nWidth;
public:
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
private:
	CToolTipCtrl m_tt;
public:
	afx_msg void OnBnClickedBtnOff();
	afx_msg void OnBnClickedBtnMin();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};
