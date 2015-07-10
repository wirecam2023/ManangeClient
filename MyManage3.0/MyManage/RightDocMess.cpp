// RightDocMess.cpp : 实现文件
//

#include "stdafx.h"
#include "MyManage.h"
#include "RightDocMess.h"
#include "afxdialogex.h"


// CRightDocMess 对话框

IMPLEMENT_DYNAMIC(CRightDocMess, CDialog)

CRightDocMess::CRightDocMess(CWnd* pParent /*=NULL*/)
	: CDialog(CRightDocMess::IDD, pParent)
{

}

CRightDocMess::~CRightDocMess()
{
}

void CRightDocMess::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DOCMESS, m_docmess);
	DDX_Control(pDX, IDC_STARTDATE, m_startdate);
	DDX_Control(pDX, IDC_ENDDATE, m_enddate);
	DDX_Control(pDX, IDC_QUE, m_Btn);
	DDX_Control(pDX, IDC_BUTTON2, m_Btn1);
}


BEGIN_MESSAGE_MAP(CRightDocMess, CDialog)
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()


// CRightDocMess 消息处理程序


BOOL CRightDocMess::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_docmess.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_docmess.InsertColumn(0,_T("收信/发信"),LVCFMT_CENTER,100);
	m_docmess.InsertColumn(1,_T("对象"),LVCFMT_CENTER,80);
	m_docmess.InsertColumn(2,_T("生成时间"),LVCFMT_CENTER,100);
	m_docmess.InsertColumn(3,_T("摘要"),LVCFMT_CENTER,100);
	m_docmess.InsertColumn(4,_T("已读"),LVCFMT_CENTER,100);

	m_docmess.InsertItem(0,_T("1"));
	m_docmess.InsertItem(1,_T("2"));

	m_Btn1.SetFlat(FALSE);
	m_Btn1.DrawTransparent(TRUE);
	m_Btn1.SetTooltipText(_T("点击确定！"));

	m_Btn.SetFlat(FALSE);
	m_Btn.DrawTransparent(TRUE);
	m_Btn.SetTooltipText(_T("点击查询！"));
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


HBRUSH CRightDocMess::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


void CRightDocMess::OnPaint()
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


BOOL CRightDocMess::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(pWnd->GetDlgCtrlID()==IDC_BUTTON2)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_QUE)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}
