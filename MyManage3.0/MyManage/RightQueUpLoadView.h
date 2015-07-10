#pragma once


// CRightQueUpLoadView 对话框

class CRightQueUpLoadView : public CDialog
{
	DECLARE_DYNAMIC(CRightQueUpLoadView)

public:
	CRightQueUpLoadView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRightQueUpLoadView();

// 对话框数据
	enum { IDD = IDD_RIGHT_QUEUPLOAD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_uploadinfo;
	CDateTimeCtrl m_start;
	CDateTimeCtrl m_end;
	CButtonST m_Btn;
public:
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnPaint();
};
