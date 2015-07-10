#pragma once


// CRightAuthorizeView 对话框

class CRightAuthorizeView : public CDialog
{
	DECLARE_DYNAMIC(CRightAuthorizeView)

public:
	CRightAuthorizeView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRightAuthorizeView();

// 对话框数据
	enum { IDD = IDD_RIGHT_AUTHORIZE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
