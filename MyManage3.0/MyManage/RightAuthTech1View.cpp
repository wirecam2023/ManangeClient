// RightAuthTech1View.cpp : 实现文件
//

#include "stdafx.h"
#include "MyManage.h"
#include "RightAuthTech1View.h"
#include "afxdialogex.h"


// CRightAuthTech1View 对话框

IMPLEMENT_DYNAMIC(CRightAuthTech1View, CDialog)

CRightAuthTech1View::CRightAuthTech1View(CWnd* pParent /*=NULL*/)
	: CDialog(CRightAuthTech1View::IDD, pParent)
{

}

CRightAuthTech1View::~CRightAuthTech1View()
{
}

void CRightAuthTech1View::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TMLIST, m_tmlist);
	DDX_Control(pDX, IDC_CHOTMLIST, m_chotmlist);
	DDX_Control(pDX, IDC_COMBO1, m_QueType);
	DDX_Control(pDX, IDC_BTN_QUETM, m_BtnQueTech);
	DDX_Control(pDX, IDC_ADDTM, m_AddTech);
	DDX_Control(pDX, IDC_DELTM, m_DelTech);
	DDX_Control(pDX, IDC_GROUP, m_Group);
}


BEGIN_MESSAGE_MAP(CRightAuthTech1View, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()


// CRightAuthTech1View 消息处理程序


BOOL CRightAuthTech1View::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_tmlist.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_tmlist.InsertColumn(0,_T("姓名"),LVCFMT_CENTER,50);
	m_tmlist.InsertColumn(1,_T("账号"),LVCFMT_CENTER,100);

	m_chotmlist.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_chotmlist.InsertColumn(0,_T("姓名"),LVCFMT_CENTER,50);
	m_chotmlist.InsertColumn(1,_T("账号"),LVCFMT_CENTER,100);

	m_QueType.SetCurSel(0);

	m_BtnQueTech.DrawTransparent(TRUE);
	m_BtnQueTech.SetFlat(FALSE);
	m_BtnQueTech.SetTooltipText(_T("查询技师主管"));

	m_AddTech.DrawTransparent(TRUE);
	m_AddTech.SetFlat(FALSE);
	m_AddTech.SetTooltipText(_T("添加技师主管"));

	m_DelTech.DrawTransparent(TRUE);
	m_DelTech.SetFlat(FALSE);
	m_DelTech.SetTooltipText(_T("剔除技师主管"));

	m_Group.SetBackgroundColor(theApp.m_RightColr);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CRightAuthTech1View::OnPaint()
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


HBRUSH CRightAuthTech1View::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


BOOL CRightAuthTech1View::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(pWnd->GetDlgCtrlID()==IDC_BTN_QUETM)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_ADDTM)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_DELTM)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}
