// RightEmployee.cpp : 实现文件
//

#include "stdafx.h"
#include "MyManage.h"
#include "RightEmployee.h"
#include "afxdialogex.h"


// CRightEmployee 对话框

IMPLEMENT_DYNAMIC(CRightEmployee, CDialog)

CRightEmployee::CRightEmployee(CWnd* pParent /*=NULL*/)
	: CDialog(CRightEmployee::IDD, pParent)
{

}

CRightEmployee::~CRightEmployee()
{
}

void CRightEmployee::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_EmployeeList);
	DDX_Control(pDX, IDC_QUETYPE, m_QueType);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_StartTime);
	DDX_Control(pDX, IDC_DATETIMEPICKER2, m_EndTime);
}


BEGIN_MESSAGE_MAP(CRightEmployee, CDialog)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BTN_QUE, &CRightEmployee::OnBnClickedBtnQue)
	ON_MESSAGE(WM_SMQUEEMPLOYEE,&CRightEmployee::OnSmQueEmployee)
END_MESSAGE_MAP()


// CRightEmployee 消息处理程序


void CRightEmployee::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialog::OnPaint()
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BIT_BKIN);
	CBrush Brush;
	Brush.CreatePatternBrush(&bitmap);
	CBrush* pOldBrush=dc.SelectObject(&Brush);
	CRect rect;
	GetClientRect(&rect);
	dc.FillRect(rect,&Brush);
	dc.SelectObject(pOldBrush);
}


BOOL CRightEmployee::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_EmployeeList.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_EmployeeList.InsertColumn(0,_T("姓名"),LVCFMT_CENTER,80);
	m_EmployeeList.InsertColumn(1,_T("职位"),LVCFMT_CENTER,100);
	m_EmployeeList.InsertColumn(2,_T("工作时间"),LVCFMT_CENTER,130);
	m_EmployeeList.InsertColumn(3,_T("电话/手机"),LVCFMT_CENTER,140);
	m_EmployeeList.InsertColumn(4,_T("主管"),LVCFMT_CENTER,80);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CRightEmployee::OnBnClickedBtnQue()
{
	// TODO: 在此添加控件通知处理程序代码
	CTime stTime,edTime;
	CString str_st,str_et;
	CString Type;
	int index;
	index = m_QueType.GetCurSel();
	Type.Format(_T("%d"),index);
	m_StartTime.GetTime(stTime);
	m_EndTime.GetTime(edTime);
	str_st = stTime.Format(_T("%Y-%m-%d"));
	str_et = edTime.Format(_T("%Y-%m-%d"));
	theApp.m_SockManageCtrl.ManQueEmployee(Type,str_st,str_et);
}

LRESULT CRightEmployee::OnSmQueEmployee(WPARAM wParam,LPARAM lParam)
{
	vector<CString> vec;
	theApp.SplitString(*(CString*)lParam,_T(";"),TRUE,vec);
	if(vec.at(0)==_T("200")&&vec.at(1)!=_T("-1"))
	{
		int num = vec.size();
		vector<CString> vec1;
		for(int i=1;i<num;i++)
		{
			CString str;
			str.Format(_T("%d"),i);
			vec1.clear();
			theApp.SplitString(vec.at(i),_T(","),TRUE,vec1);
			m_EmployeeList.InsertItem(i-1,str);
			m_EmployeeList.SetItemText(i-1,1,vec1.at(0));
			m_EmployeeList.SetItemText(i-1,2,vec1.at(1));
			m_EmployeeList.SetItemText(i-1,3,vec1.at(2));
			m_EmployeeList.SetItemText(i-1,4,vec1.at(3));
			m_EmployeeList.SetItemText(i-1,5,vec1.at(4));
		}
	}
	else
	{
		AfxMessageBox(_T("无符合条件的职员"));
	}
	return 0;
}