#pragma once
#include "d:\健康云项目\cbtnst_source\btnst.h"
#include "d:\健康云项目\cbtnst_source\btnst.h"
#include "d:\健康云项目\cbtnst_source\btnst.h"


// CRightSeriManView 对话框

class CRightSeriManView : public CDialog
{
	DECLARE_DYNAMIC(CRightSeriManView)

public:
	CRightSeriManView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRightSeriManView();

// 对话框数据
	enum { IDD = IDD_SERI_MAN };
public:
	CListCtrl m_seriman;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
private:
	CButtonST m_Add;
	CButtonST m_Del;
public:
	CButtonST m_Sub;
};
