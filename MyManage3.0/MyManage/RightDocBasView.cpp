// RightDocBasView.cpp : 实现文件
//

#include "stdafx.h"
#include "MyManage.h"
#include "RightDocBasView.h"
#include "afxdialogex.h"


// CRightDocBasView 对话框

IMPLEMENT_DYNAMIC(CRightDocBasView, CDialog)

CRightDocBasView::CRightDocBasView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightDocBasView::IDD, pParent)
{

}

CRightDocBasView::~CRightDocBasView()
{
}

void CRightDocBasView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NAME, m_name);
	DDX_Text(pDX, IDC_CELL, m_cell);
	DDX_Text(pDX, IDC_ID, m_ID);
	DDX_Text(pDX, IDC_HOSPIATL, m_hospital);
	DDX_Text(pDX, IDC_ADMINOFFICE, m_adminoff);
	DDX_Text(pDX, IDC_SCHOOL, m_school);
	DDX_Text(pDX, IDC_EDUBACK, m_eduback);
	DDX_CBString(pDX, IDC_DOCTYPE, m_doctype);
	DDX_CBString(pDX, IDC_GENDER, m_gender);
	DDX_Text(pDX, IDC_PASSWORD, m_password);
	DDX_Text(pDX, IDC_TITLE, m_title);
	DDX_Text(pDX, IDC_DUTY, m_duty);
	DDX_Text(pDX, IDC_MAJOR, m_major);
	DDX_Text(pDX, IDC_CONTIME, m_contime);
	DDX_Text(pDX, IDC_REPTIME, m_reptime);
	DDX_Control(pDX, IDC_BUTTON1, m_Btn1);
	DDX_Control(pDX, IDC_SUB, m_Btn2);
	DDX_Control(pDX, IDC_DOCTYPE, m_DocType);
	DDX_Control(pDX, IDC_GENDER, m_Gender);
	DDX_Control(pDX, IDC_GROUP, m_Group);
}


BEGIN_MESSAGE_MAP(CRightDocBasView, CDialog)
	ON_WM_SETCURSOR()
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CRightDocBasView 消息处理程序


BOOL CRightDocBasView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_DocType.SetCurSel(0);
	m_Gender.SetCurSel(1);

	m_Btn1.SetFlat(FALSE);
	m_Btn1.DrawTransparent(TRUE);
	m_Btn1.SetTooltipText(_T("点击修改！"));

	m_Btn2.SetFlat(FALSE);
	m_Btn2.DrawTransparent(TRUE);
	m_Btn2.SetTooltipText(_T("点击查询！"));

	m_Group.SetBackgroundColor(theApp.m_RightColr);

// 	m_Group.SetBackgroundColor(theApp.m_RightColr);
// 	m_Group1.SetBackgroundColor(theApp.m_RightColr);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


BOOL CRightDocBasView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(pWnd->GetDlgCtrlID()==IDC_BUTTON1)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_SUB)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}


void CRightDocBasView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialog::OnPaint()
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BIT_BKIN);
	CBrush Brush;
	CPen   Pen;
	Pen.CreatePen(PS_SOLID,1,theApp.m_LineColor);
	Brush.CreatePatternBrush(&bitmap);
	CBrush* pOldBrush=dc.SelectObject(&Brush);
	CPen*   pOldPen=dc.SelectObject(&Pen);
	dc.Rectangle(CRect(0,0,726,445));
	dc.SelectObject(pOldBrush);
	dc.SelectObject(pOldPen);
}


HBRUSH CRightDocBasView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
