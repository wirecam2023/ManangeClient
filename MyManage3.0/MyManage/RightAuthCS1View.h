#pragma once
#include "d:\健康云项目\cbtnst_source\btnst.h"
#include "d:\健康云项目\cbtnst_source\btnst.h"
#include "d:\健康云项目\cbtnst_source\btnst.h"
#include "d:\健康云项目\cbtnst_source\btnst.h"
#include "d:\健康云项目\cbtnst_source\btnst.h"
#include "d:\健康云项目\cbtnst_source\btnst.h"
#include "d:\健康云项目\cbtnst_source\btnst.h"
#include "afxwin.h"
#include "xpgroupbox.h"


// CRightAuthCS1View 对话框

class CRightAuthCS1View : public CDialog
{
	DECLARE_DYNAMIC(CRightAuthCS1View)

public:
	CRightAuthCS1View(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRightAuthCS1View();

// 对话框数据
	enum { IDD = IDD_AUTH_CS1 };
public:
	CListCtrl m_userlist;
	CListCtrl m_chouserlist;
	CString username,usercellnum,docname,doccellnum;
	int userrow,chouserrow,docrow,chodocrow;
	int chouserlistrow,chodoclistrow;
	CListCtrl m_doclist;
	CListCtrl m_chodoclist;
	CListCtrl m_csmlist;
	CString csmcellnum;
	CString m_queusertype;
	CString m_queusertext;
	CString m_quedoctype;
	CString m_quedoctext;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
private:
	CButtonST m_BtnSelUser;
	CButtonST m_BtnAddUser;
public:
	CButtonST m_BtnDelUser;
	CButtonST m_BtnSelDoc;
	CButtonST m_BtnAddDoc;
	CButtonST m_BtnDelDoc;
	CButtonST m_BtnSelMan;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	CComboBox m_QueTypeUser;
	CComboBox m_QueTypeDoc;
	CXPGroupBox m_Group;
	CXPGroupBox m_Group1;
	CXPGroupBox m_Group2;
};
