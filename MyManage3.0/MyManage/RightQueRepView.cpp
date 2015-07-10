// RightQueRepView.cpp : 实现文件
//

#include "stdafx.h"
#include "MyManage.h"
#include "RightQueRepView.h"
#include "afxdialogex.h"


// CRightQueRepView 对话框

IMPLEMENT_DYNAMIC(CRightQueRepView, CDialog)

CRightQueRepView::CRightQueRepView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightQueRepView::IDD, pParent)
{

}

CRightQueRepView::~CRightQueRepView()
{
}

void CRightQueRepView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_REP, m_rep);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_start);
	DDX_Control(pDX, IDC_DATETIMEPICKER2, m_end);
	DDX_CBString(pDX, IDC_COMBO1, m_reptype);
	DDX_Control(pDX, IDC_COMBO1, m_index);
	DDX_Control(pDX, IDC_SUB, m_Btn);
}


BEGIN_MESSAGE_MAP(CRightQueRepView, CDialog)
	ON_WM_SETCURSOR()
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CRightQueRepView 消息处理程序


BOOL CRightQueRepView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_rep.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_rep.InsertColumn(0,_T("名称"),LVCFMT_CENTER,50);
	m_rep.InsertColumn(1,_T("时间"),LVCFMT_CENTER,60);
	m_rep.InsertColumn(2,_T("异常"),LVCFMT_CENTER,50);
	m_rep.InsertColumn(3,_T("签发"),LVCFMT_CENTER,50);
	m_rep.InsertColumn(4,_T("医生"),LVCFMT_CENTER,50);
	m_rep.InsertColumn(5,_T("已读"),LVCFMT_CENTER,50);

	m_rep.InsertItem(0,_T(""));
	m_rep.InsertItem(1,_T(""));

	m_Btn.SetFlat(FALSE);
	m_Btn.DrawTransparent(TRUE);
	m_Btn.SetTooltipText(_T("点击查询！"));

	m_index.SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


BOOL CRightQueRepView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(pWnd->GetDlgCtrlID()==IDC_SUB)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}


HBRUSH CRightQueRepView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	if (pWnd->GetDlgCtrlID()==IDC_STATIC)
	{

		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	}
	return hbr;
}


void CRightQueRepView::OnPaint()
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
