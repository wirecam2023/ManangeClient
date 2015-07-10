// RightMessSendView.cpp : 实现文件
//

#include "stdafx.h"
#include "MyManage.h"
#include "RightMessSendView.h"
#include "afxdialogex.h"


// CRightMessSendView 对话框

IMPLEMENT_DYNAMIC(CRightMessSendView, CDialog)

CRightMessSendView::CRightMessSendView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightMessSendView::IDD, pParent)
{

}

CRightMessSendView::~CRightMessSendView()
{
}

void CRightMessSendView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	/*	DDX_Control(pDX, IDC_MESSTAB, m_messtab);*/
	DDX_Control(pDX, IDC_SYSMESSLIST, m_sendmess);
	/*	DDX_Text(pDX, IDC_MESSTEXT, m_messtext);*/
	DDX_Control(pDX, IDC_DATE, m_date);
	DDX_Control(pDX, IDC_TIME, m_time);
	/*	DDX_Control(pDX, IDC_BUTTON1, m_BtnQue);*/
	DDX_Control(pDX, IDC_COMBO1, m_SendTo);
	DDX_Control(pDX, IDC_COMBO2, m_QueType);
	/*	DDX_Control(pDX, IDC_SUB, m_Send);*/
	//  DDX_Control(pDX, IDC_GROUP, m_Group);
	//DDX_Control(pDX, IDC_GROUP, m_Group);
	//  DDX_Control(pDX, IDC_S, m_Group);
	DDX_Control(pDX, IDC_BUTTON1, m_Btn);
	//DDX_Control(pDX, IDC_SUB, m_Send);
	//  DDX_Control(pDX, IDC_BTTTTTTTT, m_btttttt);
}


BEGIN_MESSAGE_MAP(CRightMessSendView, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()


// CRightMessSendView 消息处理程序


BOOL CRightMessSendView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_sendmess.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_sendmess.InsertColumn(0,_T("姓名"),LVCFMT_CENTER,100);
	m_sendmess.InsertColumn(1,_T("账号"),LVCFMT_CENTER,300);
	m_sendmess.InsertColumn(2,_T("性别"),LVCFMT_CENTER,100);

	m_QueType.SetCurSel(1);
	m_SendTo.SetCurSel(1);

	m_Btn.SetFlat(FALSE);
	m_Btn.DrawTransparent(TRUE);
	m_Btn.SetTooltipText(_T("点击查询"));

// 	m_Send.SetFlat(FALSE);
// 	m_Send.DrawTransparent(TRUE);
// 	m_Send.SetTooltipText(_T("点击发送"));

 //   m_Group.SetBackgroundColor(theApp.m_RightColr);
// 	m_BtnQue.DrawTransparent(TRUE);
// 	m_BtnQue.SetTooltipText(_T("点击查询"));

// 	m_Send.DrawTransparent(TRUE);
// 	m_Send.SetTooltipText(_T("点击发送"));
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CRightMessSendView::OnPaint()
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



HBRUSH CRightMessSendView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


BOOL CRightMessSendView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(pWnd->GetDlgCtrlID()==IDC_BUTTON1)
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
