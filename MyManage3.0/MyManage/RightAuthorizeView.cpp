// RightAuthorizeView.cpp : 实现文件
//

#include "stdafx.h"
#include "MyManage.h"
#include "RightAuthorizeView.h"
#include "afxdialogex.h"


// CRightAuthorizeView 对话框

IMPLEMENT_DYNAMIC(CRightAuthorizeView, CDialog)

CRightAuthorizeView::CRightAuthorizeView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightAuthorizeView::IDD, pParent)
{

}

CRightAuthorizeView::~CRightAuthorizeView()
{
}

void CRightAuthorizeView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRightAuthorizeView, CDialog)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CRightAuthorizeView 消息处理程序


void CRightAuthorizeView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialog::OnPaint()
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BIT_BKIN);
	CBrush Brush;
	Brush.CreatePatternBrush(&bitmap);
	CBrush* pOldBrush=dc.SelectObject(&Brush);
	CRect rect;
	GetClientRect(&rect);
	dc.FillRect(rect,&Brush);
	dc.SelectObject(pOldBrush);
}
