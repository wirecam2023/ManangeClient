// RightAuthTech2View.cpp : 实现文件
//

#include "stdafx.h"
#include "MyManage.h"
#include "RightAuthTech2View.h"
#include "afxdialogex.h"


// CRightAuthTech2View 对话框

IMPLEMENT_DYNAMIC(CRightAuthTech2View, CDialog)

CRightAuthTech2View::CRightAuthTech2View(CWnd* pParent /*=NULL*/)
	: CDialog(CRightAuthTech2View::IDD, pParent)
{

}

CRightAuthTech2View::~CRightAuthTech2View()
{
}

void CRightAuthTech2View::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TPLIST, m_tplist);
	DDX_Control(pDX, IDC_CHOTPLIST, m_chotplist);
	DDX_CBString(pDX, IDC_QUETECHTYPE, m_quetechtype);
	DDX_Text(pDX, IDC_QUETECHTEXT, m_quetechtext);
	DDX_Control(pDX, IDC_QUETECHTYPE, m_QueType);
	DDX_Control(pDX, IDC_BTN_QUETP, m_BtnQue);
	DDX_Control(pDX, IDC_ADDTP, m_AddTech);
	DDX_Control(pDX, IDC_DELTP, m_DelTech);
	DDX_Control(pDX, IDC_GROUP, m_Group);
}


BEGIN_MESSAGE_MAP(CRightAuthTech2View, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()


// CRightAuthTech2View 消息处理程序


BOOL CRightAuthTech2View::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_tplist.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_tplist.InsertColumn(0,_T("姓名"),LVCFMT_CENTER,50);
	m_tplist.InsertColumn(1,_T("账号"),LVCFMT_CENTER,100);

	m_chotplist.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_chotplist.InsertColumn(0,_T("姓名"),LVCFMT_CENTER,50);
	m_chotplist.InsertColumn(1,_T("账号"),LVCFMT_CENTER,100);

	m_QueType.SetCurSel(0);

	m_BtnQue.DrawTransparent(TRUE);
	m_BtnQue.SetFlat(FALSE);
	m_BtnQue.SetTooltipText(_T("点击查询"));

	m_AddTech.DrawTransparent(TRUE);
	m_AddTech.SetFlat(FALSE);
	m_AddTech.SetTooltipText(_T("添加技师"));

	m_DelTech.DrawTransparent(TRUE);
	m_DelTech.SetFlat(FALSE);
	m_DelTech.SetTooltipText(_T("剔除技师"));

	m_Group.SetBackgroundColor(theApp.m_RightColr);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CRightAuthTech2View::OnPaint()
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


HBRUSH CRightAuthTech2View::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


BOOL CRightAuthTech2View::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(pWnd->GetDlgCtrlID()==IDC_BTN_QUETP)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_ADDTP)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_ADDTP)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}
