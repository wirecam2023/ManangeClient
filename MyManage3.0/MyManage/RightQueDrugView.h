#pragma once


// CRightQueDrugView 对话框

class CRightQueDrugView : public CDialog
{
	DECLARE_DYNAMIC(CRightQueDrugView)

public:
	CRightQueDrugView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRightQueDrugView();

// 对话框数据
	enum { IDD = IDD_RIGHT_QUEDRUG };
public:
	CListCtrl m_druguseinfo;
	CDateTimeCtrl m_start;
	CDateTimeCtrl m_end;
	CButtonST m_Btn;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
};
