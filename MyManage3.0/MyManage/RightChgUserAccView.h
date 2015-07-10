#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "RightQueBasView.h"
#include "RightQueUpLoadView.h"
#include "RightQueRepView.h"
#include "RightQueExecpView.h"
#include "RightQueDrugView.h"
#include "RightQueMessView.h"

// CRightChgUserAccView 对话框

class CRightChgUserAccView : public CDialog
{
	DECLARE_DYNAMIC(CRightChgUserAccView)

public:
	CRightChgUserAccView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRightChgUserAccView();

// 对话框数据
	enum { IDD = IDD_RIGHT_CHGUSERACC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg LRESULT OnSmQueUser(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT OnSmQueUserEx(WPARAM wParam,LPARAM lParam);
public:
//	CStatic m_BasInfo;
	CListCtrl m_userinfo;
	CString m_quetype;
	CString m_quetext;
	CString sel_user;
	CString m_selItem;
	CComboBox m_quetype1;
	CButtonST m_Btn;
	CButtonST m_BtnInfo;
	CButtonST m_BtnUL;
	CButtonST m_BtnH;
	CButtonST m_BtnE;
	CButtonST m_BtnD;
	CButtonST m_BtnM;
	vector<CString> vec_userinfo;
/*private:*/
	CRightQueBasView     m_RightQueBasView;
	CRightQueUpLoadView  m_RightQueUpLoadView;
	CRightQueRepView     m_RightQueRepView;
	CRightQueExecpView   m_RightQueExecpView; 
	CRightQueDrugView    m_RightQueDrugView;
	CRightQueMessView    m_RightQueMessView;
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_userInfo;
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnBnClickedBtnInfo();
	afx_msg void OnBnClickedBtnUpload();
	afx_msg void OnBnClickedBtnDoc();
	afx_msg void OnBnClickedBtnExcep();
	afx_msg void OnBnClickedBtnDrug1();
	afx_msg void OnBnClickedBtnMess();
	afx_msg void OnBnClickedBtnQue();
	afx_msg void OnNMClickUserinfo(NMHDR *pNMHDR, LRESULT *pResult);
	CXPGroupBox m_Group;
};
