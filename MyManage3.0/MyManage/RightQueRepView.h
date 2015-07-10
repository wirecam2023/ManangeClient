#pragma once


// CRightQueRepView 对话框

class CRightQueRepView : public CDialog
{
	DECLARE_DYNAMIC(CRightQueRepView)

public:
	CRightQueRepView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRightQueRepView();

// 对话框数据
	enum { IDD = IDD_RIGHT_QUEREP };
public:
	CListCtrl m_rep;
	CDateTimeCtrl m_start;
	CDateTimeCtrl m_end;
	CString m_reptype;
	CComboBox m_index;
	CButtonST m_Btn;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnPaint();
};
