// RightSeriManView.cpp : 实现文件
//

#include "stdafx.h"
#include "MyManage.h"
#include "RightSeriManView.h"
#include "afxdialogex.h"


// CRightSeriManView 对话框

IMPLEMENT_DYNAMIC(CRightSeriManView, CDialog)

CRightSeriManView::CRightSeriManView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightSeriManView::IDD, pParent)
{

}

CRightSeriManView::~CRightSeriManView()
{
}

void CRightSeriManView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SERIMAN, m_seriman);
	DDX_Control(pDX, IDC_BUTTON8, m_Add);
	DDX_Control(pDX, IDC_BUTTON1, m_Del);
	DDX_Control(pDX, IDC_BUTTON7, m_Sub);
}


BEGIN_MESSAGE_MAP(CRightSeriManView, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CRightSeriManView 消息处理程序


BOOL CRightSeriManView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_seriman.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_seriman.InsertColumn(0,_T("序号"),LVCFMT_CENTER,50);
	m_seriman.InsertColumn(1,_T("序列号"),LVCFMT_CENTER,200);
	m_seriman.InsertColumn(2,_T("设备名称"),LVCFMT_CENTER,100);
	m_seriman.InsertColumn(3,_T("上传者"),LVCFMT_CENTER,100);
	m_seriman.InsertColumn(4,_T("上传时间"),LVCFMT_CENTER,100);

	m_Add.DrawTransparent(TRUE);
	m_Add.SetFlat(FALSE);
	m_Add.SetTooltipText(_T("添加"));

	m_Del.DrawTransparent(TRUE);
	m_Del.SetFlat(FALSE);
	m_Del.SetTooltipText(_T("删除"));

	m_Sub.DrawTransparent(TRUE);
	m_Sub.SetFlat(FALSE);
	m_Sub.SetTooltipText(_T("提交"));
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CRightSeriManView::OnPaint()
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
	dc.Rectangle(CRect(0,0,720,530));
	dc.SelectObject(pOldBrush);
	dc.SelectObject(pOldPen);
}


HBRUSH CRightSeriManView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	if(pWnd->GetDlgCtrlID()==IDC_STATIC)
	{
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	}
	return hbr;
}
