// RightAuthCS2View.cpp : 实现文件
//

#include "stdafx.h"
#include "MyManage.h"
#include "RightAuthCS2View.h"
#include "afxdialogex.h"


// CRightAuthCS2View 对话框

IMPLEMENT_DYNAMIC(CRightAuthCS2View, CDialog)

CRightAuthCS2View::CRightAuthCS2View(CWnd* pParent /*=NULL*/)
	: CDialog(CRightAuthCS2View::IDD, pParent)
{

}

CRightAuthCS2View::~CRightAuthCS2View()
{
}

void CRightAuthCS2View::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_USERLIST, m_userlist);
	DDX_Control(pDX, IDC_CHOUSERLIST, m_chouserlist);
	DDX_Control(pDX, IDC_DOCLIST, m_doclist);
	DDX_Control(pDX, IDC_CHODOCLIST, m_chodoclist);
	DDX_Control(pDX, IDC_CSRLIST, m_csrlist);
	DDX_CBString(pDX, IDC_USERTYPE, m_usertype);
	DDX_Text(pDX, IDC_USERTEXT, m_usertext);
	DDX_CBString(pDX, IDC_DOCTYPE, m_doctype);
	DDX_Text(pDX, IDC_DOCTEXT, m_doctext);
	DDX_Control(pDX, IDC_CHOCSRLIST, m_chocsrlist);
	DDX_CBString(pDX, IDC_QUECSRTYPE, m_quecsrtype);
	DDX_Text(pDX, IDC_QUECSRTEXT, m_quecsrtext);
	DDX_Control(pDX, IDC_USERTYPE, m_QueTypeUser);
	DDX_Control(pDX, IDC_DOCTYPE, m_QueTypeDoc);
	DDX_Control(pDX, IDC_QUECSRTYPE, m_QueTypeMan);
	DDX_Control(pDX, IDC_BTN_QUEUSER, m_BtnQueUser);
	DDX_Control(pDX, IDC_ADDUSER, m_AddUser);
	DDX_Control(pDX, IDC_DELUSER, m_DelUser);
	DDX_Control(pDX, IDC_BTN_QUEDOC, m_BtnQueDoc);
	DDX_Control(pDX, IDC_ADDDOC, m_AddDoc);
	DDX_Control(pDX, IDC_DELDOC, m_DelDoc);
	DDX_Control(pDX, IDC_QUECSR, m_BtnQueMan);
	DDX_Control(pDX, IDC_ADDCSR, m_AddMan);
	DDX_Control(pDX, IDC_DELCSR, m_DelMan);
	DDX_Control(pDX, IDC_GROUP, m_Group);
	DDX_Control(pDX, IDC_Group1, m_Group1);
	DDX_Control(pDX, IDC_GROUP2, m_Group2);
}


BEGIN_MESSAGE_MAP(CRightAuthCS2View, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()


// CRightAuthCS2View 消息处理程序


void CRightAuthCS2View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialog::OnPaint()
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BIT_BKIN);
	CBrush Brush;
	Brush.CreatePatternBrush(&bitmap);
	CBrush* pOldBrush=dc.SelectObject(&Brush);
	dc.FillRect(CRect(0,0,702,445),&Brush);
	dc.SelectObject(pOldBrush);
}


HBRUSH CRightAuthCS2View::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	if ((pWnd->GetDlgCtrlID()==IDC_STATIC))
	{
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	}
	return hbr;
}


BOOL CRightAuthCS2View::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_userlist.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_userlist.InsertColumn(0,_T("姓名"),LVCFMT_CENTER,50);
	m_userlist.InsertColumn(1,_T("账号"),LVCFMT_CENTER,100);

	m_chouserlist.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_chouserlist.InsertColumn(0,_T("姓名"),LVCFMT_CENTER,50);
	m_chouserlist.InsertColumn(1,_T("账号"),LVCFMT_CENTER,100);

	m_doclist.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_doclist.InsertColumn(0,_T("姓名"),LVCFMT_CENTER,50);
	m_doclist.InsertColumn(1,_T("账号"),LVCFMT_CENTER,100);

	m_chodoclist.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_chodoclist.InsertColumn(0,_T("姓名"),LVCFMT_CENTER,50);
	m_chodoclist.InsertColumn(1,_T("账号"),LVCFMT_CENTER,100);

	m_csrlist.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_csrlist.InsertColumn(0,_T("姓名"),LVCFMT_CENTER,50);
	m_csrlist.InsertColumn(1,_T("账号"),LVCFMT_CENTER,100);

	m_chocsrlist.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_chocsrlist.InsertColumn(0,_T("姓名"),LVCFMT_CENTER,50);
	m_chocsrlist.InsertColumn(1,_T("账号"),LVCFMT_CENTER,100);

	m_QueTypeUser.SetCurSel(0);
	m_QueTypeDoc.SetCurSel(0);
	m_QueTypeMan.SetCurSel(0);

	m_BtnQueUser.DrawTransparent(TRUE);
	m_BtnQueUser.SetFlat(FALSE);
	m_BtnQueUser.SetTooltipText(_T("查询用户"));

	m_BtnQueDoc.DrawTransparent(TRUE);
	m_BtnQueDoc.SetFlat(FALSE);
	m_BtnQueDoc.SetTooltipText(_T("查询医生"));

	m_BtnQueMan.DrawTransparent(TRUE);
	m_BtnQueMan.SetFlat(FALSE);
	m_BtnQueMan.SetTooltipText(_T("查询客户经理"));

	m_AddUser.DrawTransparent(TRUE);
	m_AddUser.SetFlat(FALSE);
	m_AddUser.SetTooltipText(_T("添加用户"));

	m_DelUser.DrawTransparent(TRUE);
	m_DelUser.SetFlat(FALSE);
	m_DelUser.SetTooltipText(_T("剔除用户"));

	m_AddDoc.DrawTransparent(TRUE);
	m_AddDoc.SetFlat(FALSE);
	m_AddDoc.SetTooltipText(_T("添加医生"));

	m_DelDoc.DrawTransparent(TRUE);
	m_DelDoc.SetFlat(FALSE);
	m_DelDoc.SetTooltipText(_T("剔除医生"));

	m_AddMan.DrawTransparent(TRUE);
	m_AddMan.SetFlat(FALSE);
	m_AddMan.SetTooltipText(_T("添加客户经理"));

	m_DelMan.DrawTransparent(TRUE);
	m_DelMan.SetFlat(FALSE);
	m_DelMan.SetTooltipText(_T("剔除客户经理"));

	m_Group.SetBackgroundColor(theApp.m_RightColr);
	m_Group1.SetBackgroundColor(theApp.m_RightColr);
	m_Group2.SetBackgroundColor(theApp.m_RightColr);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


BOOL CRightAuthCS2View::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(pWnd->GetDlgCtrlID()==IDC_BTN_QUEUSER)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_ADDUSER)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_DELUSER)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_BTN_QUEDOC)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_ADDDOC)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_DELDOC)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_BTN_QUEMAN)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_ADDCSR)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_DELCSR)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}
