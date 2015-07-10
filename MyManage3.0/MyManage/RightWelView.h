#pragma once


// CRightWelView 对话框

class CRightWelView : public CDialog
{
	DECLARE_DYNAMIC(CRightWelView)

public:
	CRightWelView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRightWelView();

// 对话框数据
	enum { IDD = IDD_RIGHT_WEL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
private:
	CBrush m_Brush;
	CFont  m_WelFont;
	CFont  m_HintFont;
	CFont  m_MsgFont;
};
