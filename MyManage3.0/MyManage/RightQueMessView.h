#pragma once


// CRightQueMessView 对话框

class CRightQueMessView : public CDialog
{
	DECLARE_DYNAMIC(CRightQueMessView)

public:
	CRightQueMessView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRightQueMessView();

// 对话框数据
	enum { IDD = IDD_RIGHT_QUEMESS };
public:
	CListCtrl m_usermess;
	CDateTimeCtrl m_start;
	CDateTimeCtrl m_end;
	int m_row;
	CButtonST m_Btn;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
