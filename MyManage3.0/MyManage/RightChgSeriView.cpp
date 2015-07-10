// RightChgSeriView.cpp : 实现文件
//

#include "stdafx.h"
#include "MyManage.h"
#include "RightChgSeriView.h"
#include "afxdialogex.h"


// CRightChgSeriView 对话框

IMPLEMENT_DYNAMIC(CRightChgSeriView, CDialog)

CRightChgSeriView::CRightChgSeriView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightChgSeriView::IDD, pParent)
{

}

CRightChgSeriView::~CRightChgSeriView()
{
}

void CRightChgSeriView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SERIID, m_seriID);
	DDX_Control(pDX, IDC_USERINFO, m_userinfo);
	DDX_Control(pDX, IDC_QUE, m_Btn);
	DDX_Control(pDX, IDC_GROUP, m_Group);
}


BEGIN_MESSAGE_MAP(CRightChgSeriView, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()


// CRightChgSeriView 消息处理程序


BOOL CRightChgSeriView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_userinfo.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT|LVS_EX_ONECLICKACTIVATE);
	m_userinfo.InsertColumn(0,_T("姓名"),0,60);
	m_userinfo.InsertColumn(1,_T("手机号"),0,100);
	m_userinfo.InsertColumn(2,_T("注册时间"),0,100);
	m_userinfo.InsertColumn(3,_T("邀约医生"),0,80);
	m_userinfo.InsertColumn(4,_T("紧急联系人"),0,100);
	m_userinfo.InsertColumn(5,_T("紧急联系人号码"),0,120);

	m_Btn.DrawTransparent(TRUE);
	m_Btn.SetFlat(FALSE);
	m_Btn.SetTooltipText(_T("查询"));

	m_Group.SetBackgroundColor(theApp.m_RightColr);


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CRightChgSeriView::OnPaint()
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


HBRUSH CRightChgSeriView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


BOOL CRightChgSeriView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(pWnd->GetDlgCtrlID()==IDC_QUE)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}
