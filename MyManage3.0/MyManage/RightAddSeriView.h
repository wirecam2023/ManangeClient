#pragma once
#include "d:\健康云项目\cbtnst_source\btnst.h"
#include "d:\健康云项目\cbtnst_source\btnst.h"
#include "RightSeriManView.h"
#include "RightSeriBatView.h"

// CRightAddSeriView 对话框

class CRightAddSeriView : public CDialog
{
	DECLARE_DYNAMIC(CRightAddSeriView)

public:
	CRightAddSeriView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRightAddSeriView();

// 对话框数据
	enum { IDD = IDD_RIGHT_ADDSERI };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CButtonST m_Btn1;
	CRightSeriManView  m_RightSeriManView;
	CRightSeriBatView  m_RightSeriBatView;
public:
	CButtonST m_Btn2;
	afx_msg void OnPaint();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBtnManu();
	afx_msg void OnBnClickedBtn();
};
