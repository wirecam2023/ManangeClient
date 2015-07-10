// HeadTextView.cpp : 实现文件
//

#include "stdafx.h"
#include "MyManage.h"
#include "HeadTextView.h"
#include "afxdialogex.h"


// CHeadTextView 对话框

IMPLEMENT_DYNAMIC(CHeadTextView, CDialog)

CHeadTextView::CHeadTextView(CWnd* pParent /*=NULL*/)
	: CDialog(CHeadTextView::IDD, pParent)
{
	m_head.CreatePointFont(350,_T("隶书"));
	m_head1.CreatePointFont(300,_T("隶书"));
}

CHeadTextView::~CHeadTextView()
{
}

void CHeadTextView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CHeadTextView, CDialog)
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CHeadTextView 消息处理程序


HBRUSH CHeadTextView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	if ((pWnd->GetDlgCtrlID()==IDC_HEAD)) 
	{ 
		pDC->SelectObject(&m_head);
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
	}

	if ((pWnd->GetDlgCtrlID()==IDC_HEAD1)) 
	{ 
		pDC->SelectObject(&m_head1);
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
	}
	return hbr;
}


BOOL CHeadTextView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	GetDlgItem(IDC_HEAD)->MoveWindow(220,50,600,50);
	GetDlgItem(IDC_HEAD1)->MoveWindow(431,100,200,50);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CHeadTextView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialog::OnPaint()
	CBitmap   bitmap;
	bitmap.LoadBitmap(IDB_BIT_HEAD); 
	CBrush   brush;
	brush.CreatePatternBrush(&bitmap);
	CBrush*   pOldBrush   =   dc.SelectObject(&brush);
	/*dc.Rectangle(CRect(0,0,240,683));  */
	dc.FillRect(CRect(0,0,1200,200),&brush);
	dc.SelectObject(pOldBrush);
}
