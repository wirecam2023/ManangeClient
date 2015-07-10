// RightAddSeriView.cpp : 实现文件
//

#include "stdafx.h"
#include "MyManage.h"
#include "RightAddSeriView.h"
#include "afxdialogex.h"


// CRightAddSeriView 对话框

IMPLEMENT_DYNAMIC(CRightAddSeriView, CDialog)

CRightAddSeriView::CRightAddSeriView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightAddSeriView::IDD, pParent)
{

}

CRightAddSeriView::~CRightAddSeriView()
{
}

void CRightAddSeriView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BTN_MANU, m_Btn1);
	DDX_Control(pDX, IDC_BTN, m_Btn2);
}


BEGIN_MESSAGE_MAP(CRightAddSeriView, CDialog)
	ON_WM_PAINT()
	ON_WM_SETCURSOR()
	ON_BN_CLICKED(IDC_BTN_MANU, &CRightAddSeriView::OnBnClickedBtnManu)
	ON_BN_CLICKED(IDC_BTN, &CRightAddSeriView::OnBnClickedBtn)
END_MESSAGE_MAP()


// CRightAddSeriView 消息处理程序


void CRightAddSeriView::OnPaint()
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


BOOL CRightAddSeriView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(pWnd->GetDlgCtrlID()==IDC_BTN_MANU)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_BTN)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_BUTTON1)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_BUTTON7)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_BUTTON8)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}


BOOL CRightAddSeriView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_Btn1.SetTooltipText(_T("手动导入"));
	/*m_Btn1.SetFlat(FALSE);*/
	m_Btn1.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS,RGB(128,42,42));
	m_Btn1.SetColor(CButtonST::BTNST_COLOR_BK_IN,RGB(106,90,205));
	m_Btn1.SetColor(CButtonST::BTNST_COLOR_BK_OUT,RGB(106,90,205));

	m_Btn2.SetTooltipText(_T("批量导入"));
	/*m_Btn2.SetFlat(FALSE);*/
	m_Btn2.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS,RGB(128,42,42));
	m_Btn2.SetColor(CButtonST::BTNST_COLOR_BK_IN,RGB(106,90,205));
	m_Btn2.SetColor(CButtonST::BTNST_COLOR_BK_OUT,RGB(106,90,205));

	CRect rc1;
	GetDlgItem(IDC_BTN_MANU)->GetClientRect(rc1);
	GetDlgItem(IDC_BTN_MANU)->SetWindowPos(0,30,70-rc1.Height(),0,0,SWP_NOSIZE);
	GetDlgItem(IDC_BTN)->SetWindowPos(0,30+rc1.Width(),70-rc1.Height(),0,0,SWP_NOSIZE);

	CRect rc(30,70,750,600);
	//////////////////创建手动导入界面////////////////////////////////
	m_RightSeriManView.Create(IDD_SERI_MAN,this);
	m_RightSeriManView.MoveWindow(rc);
	m_RightSeriManView.ShowWindow(SW_SHOW);

	////////////////创建批量导入界面/////////////////////////////////
	m_RightSeriBatView.Create(IDD_SERI_BAT,this);
	m_RightSeriBatView.MoveWindow(rc);
	m_RightSeriBatView.ShowWindow(SW_HIDE);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CRightAddSeriView::OnBnClickedBtnManu()
{
	// TODO: 在此添加控件通知处理程序代码
	m_RightSeriManView.ShowWindow(SW_SHOW);
	m_RightSeriBatView.ShowWindow(SW_HIDE);
}


void CRightAddSeriView::OnBnClickedBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	m_RightSeriManView.ShowWindow(SW_HIDE);
	m_RightSeriBatView.ShowWindow(SW_SHOW);
}
