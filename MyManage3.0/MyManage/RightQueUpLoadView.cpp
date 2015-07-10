// RightQueUpLoadView.cpp : 实现文件
//

#include "stdafx.h"
#include "MyManage.h"
#include "RightQueUpLoadView.h"
#include "afxdialogex.h"


// CRightQueUpLoadView 对话框

IMPLEMENT_DYNAMIC(CRightQueUpLoadView, CDialog)

CRightQueUpLoadView::CRightQueUpLoadView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightQueUpLoadView::IDD, pParent)
{

}

CRightQueUpLoadView::~CRightQueUpLoadView()
{
}

void CRightQueUpLoadView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_UPLOADINFO, m_uploadinfo);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_start);
	DDX_Control(pDX, IDC_DATETIMEPICKER2, m_end);
	DDX_Control(pDX, IDC_SUB, m_Btn);
}


BEGIN_MESSAGE_MAP(CRightQueUpLoadView, CDialog)
	ON_WM_SETCURSOR()
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CRightQueUpLoadView 消息处理程序


BOOL CRightQueUpLoadView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_uploadinfo.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_uploadinfo.InsertColumn(0,_T("序号"),LVCFMT_CENTER,50);
	m_uploadinfo.InsertColumn(1,_T("上传时间"),LVCFMT_CENTER,100);
	m_uploadinfo.InsertColumn(2,_T("上传内容"),LVCFMT_CENTER,150);
	m_uploadinfo.InsertColumn(3,_T("文件大小"),LVCFMT_CENTER,100);
	m_uploadinfo.InsertColumn(4,_T("上传方式"),LVCFMT_CENTER,100);


	m_uploadinfo.InsertItem(0,_T("1"));
	m_uploadinfo.InsertItem(1,_T("2"));

	m_Btn.SetFlat(FALSE);
	m_Btn.DrawTransparent(TRUE);
	m_Btn.SetTooltipText(_T("点击查询！"));
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


BOOL CRightQueUpLoadView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(pWnd->GetDlgCtrlID()==IDC_SUB)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}


HBRUSH CRightQueUpLoadView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if ((pWnd->GetDlgCtrlID()==IDC_STATIC))
	{
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void CRightQueUpLoadView::OnPaint()
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
