// RightAuthDoc1View.cpp : 实现文件
//

#include "stdafx.h"
#include "MyManage.h"
#include "RightAuthDoc1View.h"
#include "afxdialogex.h"


// CRightAuthDoc1View 对话框

IMPLEMENT_DYNAMIC(CRightAuthDoc1View, CDialog)

CRightAuthDoc1View::CRightAuthDoc1View(CWnd* pParent /*=NULL*/)
	: CDialog(CRightAuthDoc1View::IDD, pParent)
{

}

CRightAuthDoc1View::~CRightAuthDoc1View()
{
}

void CRightAuthDoc1View::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DOCLIST, m_doclist);
	DDX_Control(pDX, IDC_CHODOCLIST, m_chodoclist);
	DDX_Control(pDX, IDC_COMBO1, m_QueType);
	DDX_Control(pDX, IDC_BTN_QUEDOC, m_BtnQue);
	DDX_Control(pDX, IDC_ADD, m_Btn);
	DDX_Control(pDX, IDC_DEL, m_DelDoc1);
	DDX_Control(pDX, IDC_GROUP, m_Group);
}


BEGIN_MESSAGE_MAP(CRightAuthDoc1View, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()


// CRightAuthDoc1View 消息处理程序


BOOL CRightAuthDoc1View::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_doclist.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_doclist.InsertColumn(0,_T("姓名"),LVCFMT_CENTER,50);
	m_doclist.InsertColumn(1,_T("账号"),LVCFMT_CENTER,100);

	m_chodoclist.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_chodoclist.InsertColumn(0,_T("姓名"),LVCFMT_CENTER,50);
	m_chodoclist.InsertColumn(1,_T("账号"),LVCFMT_CENTER,100);

	m_QueType.SetCurSel(0);

	m_BtnQue.DrawTransparent(TRUE);
	m_BtnQue.SetFlat(FALSE);
	m_BtnQue.SetTooltipText(_T("查询技师主管"));

	m_Btn.DrawTransparent(TRUE);
	m_Btn.SetFlat(FALSE);
	m_Btn.SetTooltipText(_T("添加技师主管"));

	m_DelDoc1.DrawTransparent(TRUE);
	m_DelDoc1.SetFlat(FALSE);
	m_DelDoc1.SetTooltipText(_T("剔除技师主管"));

	m_Group.SetBackgroundColor(theApp.m_RightColr);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CRightAuthDoc1View::OnPaint()
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


HBRUSH CRightAuthDoc1View::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


BOOL CRightAuthDoc1View::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(pWnd->GetDlgCtrlID()==IDC_BTN_QUEDOC)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_ADD)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_DEL)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}
