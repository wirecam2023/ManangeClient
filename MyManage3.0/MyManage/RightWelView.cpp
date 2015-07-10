// RightWelView.cpp : 实现文件
//

#include "stdafx.h"
#include "MyManage.h"
#include "RightWelView.h"
#include "afxdialogex.h"


// CRightWelView 对话框

IMPLEMENT_DYNAMIC(CRightWelView, CDialog)

CRightWelView::CRightWelView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightWelView::IDD, pParent)
{
    m_Brush.CreateSolidBrush(theApp.m_RightColr);
	m_MsgFont.CreatePointFont(150,_T("楷体"));
	m_HintFont.CreatePointFont(150,_T("楷体"));
	m_WelFont.CreatePointFont(200,_T("楷体"));
}

CRightWelView::~CRightWelView()
{
}

void CRightWelView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRightWelView, CDialog)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CRightWelView 消息处理程序


HBRUSH CRightWelView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	if ((pWnd->GetDlgCtrlID()==IDC_WEL)) 
	{ 
		pDC->SelectObject(&m_WelFont);
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
	}
	if ((pWnd->GetDlgCtrlID()==IDC_INFO)) 
	{ 
		pDC->SelectObject(&m_HintFont);
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
	}
	if ((pWnd->GetDlgCtrlID()==IDC_INFOTEXT)) 
	{ 
		pDC->SelectObject(&m_MsgFont);
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
	}
	return m_Brush;
	/*return hbr;*/
}
