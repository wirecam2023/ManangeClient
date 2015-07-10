#pragma once
#include "d:\健康云项目\cbtnst_source\btnst.h"
/*#include "MyManageDlg.h"*/


// CRightLoginView 对话框

class CRightLoginView : public CDialog
{
	DECLARE_DYNAMIC(CRightLoginView)

public:
	CRightLoginView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRightLoginView();

// 对话框数据
	enum { IDD = IDD_RIGHT_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
private:
	CButtonST m_Btn;
	/*CMyManageDlg m_MyManageDlg;*/

public:
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	
	afx_msg void OnBnClickedBtnLogin();
	afx_msg LRESULT OnSmLoginEx(WPARAM wParam,LPARAM lParam);
//	BOOL m_HideMode;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
