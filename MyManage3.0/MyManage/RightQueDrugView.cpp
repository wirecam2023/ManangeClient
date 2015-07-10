// RightQueDrugView.cpp : 实现文件
//

#include "stdafx.h"
#include "MyManage.h"
#include "RightQueDrugView.h"
#include "afxdialogex.h"


// CRightQueDrugView 对话框

IMPLEMENT_DYNAMIC(CRightQueDrugView, CDialog)

CRightQueDrugView::CRightQueDrugView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightQueDrugView::IDD, pParent)
{

}

CRightQueDrugView::~CRightQueDrugView()
{
}

void CRightQueDrugView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DRUG111, m_druguseinfo);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_start);
	DDX_Control(pDX, IDC_DATETIMEPICKER2, m_end);
	DDX_Control(pDX, IDC_QUE, m_Btn);
}


BEGIN_MESSAGE_MAP(CRightQueDrugView, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()


// CRightQueDrugView 消息处理程序


BOOL CRightQueDrugView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_druguseinfo.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_druguseinfo.InsertColumn(0,_T("药品名称"),LVCFMT_CENTER,100);
	m_druguseinfo.InsertColumn(1,_T("用量/片"),LVCFMT_CENTER,60);
	m_druguseinfo.InsertColumn(2,_T("开始日期"),LVCFMT_CENTER,105);
	m_druguseinfo.InsertColumn(3,_T("结束日期"),LVCFMT_CENTER,105);
	m_druguseinfo.InsertColumn(4,_T("时间1"),LVCFMT_CENTER,100);
	m_druguseinfo.InsertColumn(5,_T("时间2"),LVCFMT_CENTER,100);
	m_druguseinfo.InsertColumn(6,_T("时间3"),LVCFMT_CENTER,100);

	m_druguseinfo.InsertItem(0,_T("1"));
	m_druguseinfo.InsertItem(1,_T("2"));
	m_druguseinfo.SetItemText(0,1,_T("111"));

	m_Btn.SetFlat(FALSE);
	m_Btn.DrawTransparent(TRUE);
	m_Btn.SetTooltipText(_T("点击查询！"));
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CRightQueDrugView::OnPaint()
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


HBRUSH CRightQueDrugView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


BOOL CRightQueDrugView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(pWnd->GetDlgCtrlID()==IDC_QUE)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}
