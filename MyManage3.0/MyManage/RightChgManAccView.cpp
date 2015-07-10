// RightChgManAccView.cpp : 实现文件
//

#include "stdafx.h"
#include "MyManage.h"
#include "RightChgManAccView.h"
#include "afxdialogex.h"


// CRightChgManAccView 对话框

IMPLEMENT_DYNAMIC(CRightChgManAccView, CDialog)

CRightChgManAccView::CRightChgManAccView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightChgManAccView::IDD, pParent)
{

}

CRightChgManAccView::~CRightChgManAccView()
{
}

void CRightChgManAccView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_QUETYPE, m_quetype);
	DDX_Text(pDX, IDC_QUETEXT, m_quetext);
	DDX_Control(pDX, IDC_MANLIST, m_manlist);
	DDX_Control(pDX, IDC_QUETYPE, m_QueType);
	DDX_Control(pDX, IDC_BTN_QUE, m_BtnQue);
	DDX_Control(pDX, IDC_BUTTON2, m_BtnOK);
	DDX_Control(pDX, IDC_SUB, m_BtnSub);
	DDX_Control(pDX, IDC_GROUP, m_Group);
	DDX_Control(pDX, IDC_Group1, m_Group1);
}


BEGIN_MESSAGE_MAP(CRightChgManAccView, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()


// CRightChgManAccView 消息处理程序


BOOL CRightChgManAccView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_manlist.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_manlist.InsertColumn(0,_T("姓名"),LVCFMT_CENTER,100);
	m_manlist.InsertColumn(1,_T("账号"),LVCFMT_CENTER,100);
	m_manlist.InsertColumn(2,_T("管理员类型"),LVCFMT_CENTER,150);

	m_QueType.SetCurSel(0);

	m_BtnQue.DrawTransparent(TRUE);
	m_BtnQue.SetFlat(FALSE);
	m_BtnQue.SetTooltipText(_T("查询"));

	m_BtnOK.DrawTransparent(TRUE);
	m_BtnOK.SetFlat(FALSE);
	m_BtnOK.SetTooltipText(_T("点击确定"));

	m_BtnSub.DrawTransparent(TRUE);
	m_BtnSub.SetFlat(FALSE);
	m_BtnSub.SetTooltipText(_T("点击提交"));

	m_Group.SetBackgroundColor(theApp.m_RightColr);
	m_Group1.SetBackgroundColor(theApp.m_RightColr);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CRightChgManAccView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialog::OnPaint()
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BIT_BKIN);
	CBrush Brush;
	Brush.CreatePatternBrush(&bitmap);
	CBrush* pOldBrush=dc.SelectObject(&Brush);
	dc.FillRect(CRect(0,0,783,659),&Brush);
	dc.SelectObject(pOldBrush);
}


HBRUSH CRightChgManAccView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	if ((pWnd->GetDlgCtrlID()==IDC_STATIC))
	{
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	}
	if ((pWnd->GetDlgCtrlID()==IDC_SELMAN))
	{
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	}
	if ((pWnd->GetDlgCtrlID()==IDC_MANTYPE))
	{
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	}
	return hbr;
}


BOOL CRightChgManAccView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(pWnd->GetDlgCtrlID()==IDC_BTN_QUE)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_SUB)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_BUTTON2)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}
