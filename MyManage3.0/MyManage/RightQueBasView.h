#pragma once
#include "xpgroupbox.h"


// CRightQueBasView 对话框

class CRightQueBasView : public CDialog
{
	DECLARE_DYNAMIC(CRightQueBasView)

public:
	CRightQueBasView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRightQueBasView();

// 对话框数据
	enum { IDD = IDD_RIGHT_QUEBAS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_name;
	CString m_cell;
	CString m_birth;
	CString m_password;
	//	CString m_ID;
	CString m_gender;
	CString m_usertype;
	CString m_seri;
	CString m_job;
	CString m_address;
	CString m_bloodtype;
	CString m_pairdoc;
	CString m_emercont;
	CString m_emercontnum;
	CString m_sur;
	CString m_drug;
	CString m_dis;
	CString m_smoke;
	CString m_family;
	CString m_drink;
	CComboBox m_Gender;
	CComboBox m_BloodType;
	CComboBox m_SmoHistory;
	CComboBox m_DrinkHistory;
	CButtonST m_Btn;
	CComboBox m_usertype1;
public:
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnBnClickedSub();
	CXPGroupBox m_Group;
	CXPGroupBox m_Group1;
	afx_msg void OnBnClickedGroup();
};
