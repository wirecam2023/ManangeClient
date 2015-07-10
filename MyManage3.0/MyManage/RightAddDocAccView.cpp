// RightAddDocAccView.cpp : 实现文件
//

#include "stdafx.h"
#include "MyManage.h"
#include "RightAddDocAccView.h"
#include "afxdialogex.h"


// CRightAddDocAccView 对话框

IMPLEMENT_DYNAMIC(CRightAddDocAccView, CDialog)

CRightAddDocAccView::CRightAddDocAccView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightAddDocAccView::IDD, pParent)
{

}

CRightAddDocAccView::~CRightAddDocAccView()
{
}

void CRightAddDocAccView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_doctorname);
	DDX_Text(pDX, IDC_EDIT19, m_cellnumber);
	DDX_Text(pDX, IDC_EDIT24, m_IDnumber);
	DDX_Text(pDX, IDC_EDIT20, m_hospital);
	DDX_Text(pDX, IDC_EDIT21, m_adminoffice);
	DDX_Text(pDX, IDC_EDIT22, m_school);
	DDX_Text(pDX, IDC_EDIT23, m_eduback);
	DDX_CBString(pDX, IDC_COMBO3, m_gender);
	DDX_Text(pDX, IDC_EDIT7, m_password);
	DDX_Text(pDX, IDC_EDIT2, m_title);
	DDX_Text(pDX, IDC_EDIT3, m_duty);
	DDX_Text(pDX, IDC_EDIT4, m_major);
	DDX_Text(pDX, IDC_EDIT5, m_consulttime);
	DDX_Text(pDX, IDC_EDIT6, m_replytime);
	DDX_CBString(pDX, IDC_COMBO2, m_doctype);
	DDX_Control(pDX, IDC_COMBO2, m_DocType);
	DDX_Control(pDX, IDC_COMBO3, m_Gender);
	DDX_Control(pDX, IDC_SUB, m_Btn);
	DDX_Control(pDX, IDC_GROUP, m_Group);
}


BEGIN_MESSAGE_MAP(CRightAddDocAccView, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()


// CRightAddDocAccView 消息处理程序


void CRightAddDocAccView::OnPaint()
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


HBRUSH CRightAddDocAccView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


BOOL CRightAddDocAccView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_DocType.SetCurSel(0);
	m_Gender.SetCurSel(0);

	m_Btn.SetFlat(FALSE);
	m_Btn.DrawTransparent(TRUE);
	m_Btn.SetTooltipText(_T("点击提交！"));

	m_Group.SetBackgroundColor(theApp.m_RightColr);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


BOOL CRightAddDocAccView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(pWnd->GetDlgCtrlID()==IDC_SUB)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}
