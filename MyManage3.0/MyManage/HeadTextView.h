#pragma once


// CHeadTextView 对话框

class CHeadTextView : public CDialog
{
	DECLARE_DYNAMIC(CHeadTextView)

public:
	CHeadTextView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CHeadTextView();

// 对话框数据
	enum { IDD =IDD_HEADTEXT };
private:
	CFont m_head;
	CFont m_head1;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
};
