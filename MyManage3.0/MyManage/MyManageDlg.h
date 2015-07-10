
#pragma once
#include "afxwin.h"
#include "d:\健康云项目\cbtnst_source\btnst.h"
#include "d:\健康云项目\cbtnst_source\btnst.h"
#include "atltypes.h"
#include "RightLoginView.h"
#include "LeftPaneView.h"
#include "HeadTextView.h"
#include "RightWelView.h"
#include "TopView.h"
#include "RightAddUserAccView.h"
#include "RightChgUserAccView.h"
#include "RightAdddocaccView.h"
#include "RightChgDocAccView.h"
#include "RightAddManAccView.h"
#include "RightChgManAccView.h"
#include "RightMessSendView.h"
#include "RightAddSeriView.h"
#include "RightChgSeriView.h"
#include "RightMessSendView1.h"
#include "RightEmployee.h"
#include "RightAuthorizeView.h"

// CMyManageDlg 对话框
class CMyManageDlg : public CDialogEx
{
	// 构造
public:
	CMyManageDlg(CWnd* pParent = NULL);	// 标准构造函数

	// 对话框数据
	enum { IDD = IDD_MYMANAGE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


	// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	CBrush m_Brush;
	
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CButtonST m_BtnMin;
	CButtonST m_BtnOff;
	afx_msg void OnBnClickedBtnOff();
	afx_msg void OnBnClickedBtnMin();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	void ShowView(CDialog* RightView, CDialog* PreView);
private:


	CPoint m_Point2;

	CLeftPaneView          m_LeftPaneView;

	CRightWelView          m_RightWelView;
	CTopView               m_TopView;
	CRightChgUserAccView   m_RightChgUserAccView;
	CRightAddDocAccView    m_RightAddDocAccView;
	CRightChgDocAccView    m_RightChgDocAccView;
	CRightAddManAccView    m_RightAddManAccView;
	CRightChgManAccView    m_RightChgManAccView;
	CRightMessSendView     m_RightMessSendView;
	CRightAddSeriView      m_RightAddSeriView;
	CRightChgSeriView      m_RightChgSeriView;
	CRightMessSendView1    m_RightMessSendView1;
	CRightEmployee         m_RightEmployee;
	CRightAuthorizeView    m_RightAuthorizeView;

public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	CRightAddUserAccView m_RightAddUserAccView;
	CRightLoginView        m_RightLoginView;
	CHeadTextView          m_HeadTextView;
public:
    BOOL m_MoveMode;
	CPoint m_PosOri;
	CPoint m_Point1;
public:
//	afx_msg void OnBnClickedBtnLogin();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
