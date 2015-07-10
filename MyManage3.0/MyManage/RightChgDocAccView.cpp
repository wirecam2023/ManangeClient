// RightChgDocAccView.cpp : 实现文件
//

#include "stdafx.h"
#include "MyManage.h"
#include "RightChgDocAccView.h"
#include "afxdialogex.h"


// CRightChgDocAccView 对话框

IMPLEMENT_DYNAMIC(CRightChgDocAccView, CDialog)

CRightChgDocAccView::CRightChgDocAccView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightChgDocAccView::IDD, pParent)
{

}

CRightChgDocAccView::~CRightChgDocAccView()
{
}

void CRightChgDocAccView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DOCINFO, m_docinfo);
	DDX_CBString(pDX, IDC_QUETYPE, m_quetype);
	DDX_Text(pDX, IDC_QUETEXT, m_quetext);
	DDX_Control(pDX, IDC_BTN_INFO, m_Btn1);
	DDX_Control(pDX, IDC_BTN_REC, m_Btn2);
	DDX_Control(pDX, IDC_BTN_MESS, m_Btn);
	DDX_Control(pDX, IDC_QUE, m_Btn4);
	DDX_Control(pDX, IDC_QUETYPE, m_QueType);
	DDX_Control(pDX, IDC_GROUP, m_Group);
}


BEGIN_MESSAGE_MAP(CRightChgDocAccView, CDialog)
	ON_WM_SETCURSOR()
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BTN_INFO, &CRightChgDocAccView::OnBnClickedBtnInfo)
	ON_BN_CLICKED(IDC_BTN_REC, &CRightChgDocAccView::OnBnClickedBtnRec)
	ON_BN_CLICKED(IDC_BTN_MESS, &CRightChgDocAccView::OnBnClickedBtnMess)
END_MESSAGE_MAP()


// CRightChgDocAccView 消息处理程序


BOOL CRightChgDocAccView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_docinfo.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_docinfo.InsertColumn(0,_T("姓名"),LVCFMT_CENTER,100);
	m_docinfo.InsertColumn(1,_T("性别"),LVCFMT_CENTER,100);
	m_docinfo.InsertColumn(2,_T("账号"),LVCFMT_CENTER,100);
	m_docinfo.InsertColumn(3,_T("身份证号"),LVCFMT_CENTER,100);

	m_docinfo.InsertItem(0,_T("1"));
	m_docinfo.InsertItem(1,_T("2"));

	m_QueType.SetCurSel(1);

	m_Btn1.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS,RGB(128,42,42));
	m_Btn1.SetColor(CButtonST::BTNST_COLOR_BK_IN,RGB(106,90,205));
	m_Btn1.SetColor(CButtonST::BTNST_COLOR_BK_OUT,RGB(106,90,205));

	m_Btn2.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS,RGB(128,42,42));
	m_Btn2.SetColor(CButtonST::BTNST_COLOR_BK_IN,RGB(106,90,205));
	m_Btn2.SetColor(CButtonST::BTNST_COLOR_BK_OUT,RGB(106,90,205));

	m_Btn.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS,RGB(128,42,42));
	m_Btn.SetColor(CButtonST::BTNST_COLOR_BK_IN,RGB(106,90,205));
	m_Btn.SetColor(CButtonST::BTNST_COLOR_BK_OUT,RGB(106,90,205));

	m_Btn4.SetFlat(FALSE);
	m_Btn4.DrawTransparent(TRUE);
	m_Btn4.SetTooltipText(_T("点击查询！"));

	CRect rc(30,206,756,651);
	///////////////////创建医生基本信息界面/////////////////////////
	m_RightDocBasView.Create(IDD_DOC_BAS,this);
	m_RightDocBasView.MoveWindow(rc);
	m_RightDocBasView.ShowWindow(SW_SHOW);

	//////////////////创建医生诊断记录界面//////////////////////////
	m_RightDocDiagView.Create(IDD_DOC_DIAG,this);
	m_RightDocDiagView.MoveWindow(rc);
	m_RightDocDiagView.ShowWindow(SW_HIDE);

	/////////////////创建医生消息界面////////////////////////////////
	m_RightDocMessView.Create(IDD_DOC_MESS,this);
	m_RightDocMessView.MoveWindow(rc);
	m_RightDocMessView.ShowWindow(SW_HIDE);

	m_Group.SetBackgroundColor(theApp.m_RightColr);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


BOOL CRightChgDocAccView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(pWnd->GetDlgCtrlID()==IDC_QUE)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_BTN_INFO)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_BTN_REC)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_BTN_MESS)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}


void CRightChgDocAccView::OnPaint()
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


HBRUSH CRightChgDocAccView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


void CRightChgDocAccView::OnBnClickedBtnInfo()
{
	// TODO: 在此添加控件通知处理程序代码
	m_RightDocBasView.ShowWindow(SW_SHOW);
	m_RightDocDiagView.ShowWindow(SW_HIDE);
	m_RightDocMessView.ShowWindow(SW_HIDE);
}


void CRightChgDocAccView::OnBnClickedBtnRec()
{
	// TODO: 在此添加控件通知处理程序代码
	m_RightDocDiagView.ShowWindow(SW_SHOW);
	m_RightDocBasView.ShowWindow(SW_HIDE);
	m_RightDocMessView.ShowWindow(SW_HIDE);

}


void CRightChgDocAccView::OnBnClickedBtnMess()
{
	// TODO: 在此添加控件通知处理程序代码
	m_RightDocMessView.ShowWindow(SW_SHOW);
	m_RightDocDiagView.ShowWindow(SW_HIDE);
	m_RightDocBasView.ShowWindow(SW_HIDE);

}
