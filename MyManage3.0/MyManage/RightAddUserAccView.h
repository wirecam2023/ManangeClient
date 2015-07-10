#pragma once
#include "afxwin.h"
#include "xpgroupbox.h"


// CRightAddUserAccView 对话框

class CRightAddUserAccView : public CDialog
{
	DECLARE_DYNAMIC(CRightAddUserAccView)

public:
	CRightAddUserAccView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRightAddUserAccView();
	CString m_name;
	//	CString m_idnum;
	CString m_cellnum;
	CString m_gender;
	CString m_usertype;
	CString m_serinum;
	CString m_bloodtype;
	CString m_job;
	CString m_pairdoc;
	CString m_address;
	CString m_emercont;
	CString m_contactnum;
	CString m_surgery;
	CString m_drug;
	CString m_disease;
	CString m_family;
	CString m_smoke;
	CString m_drink;
	CString m_birth;
	CString m_password;

	CComboBox m_Gender;
	CComboBox m_BloodType;
	CComboBox m_SmoHistory;
	CComboBox m_DrinkHistory;
	CComboBox m_usertype1;

// 对话框数据
	enum { IDD = IDD_RIGHT_ADDUSERACC };
private:
	CButtonST m_Btn;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg LRESULT OnSmAddUserEx(WPARAM wParam,LPARAM lParam);
private:
	CBrush m_Brush;
public:
	afx_msg void OnBnClickedSub();
	afx_msg void OnPaint();
	afx_msg void OnBnClickedGroup();
	CXPGroupBox m_Group;
	CXPGroupBox m_Group1;
};
