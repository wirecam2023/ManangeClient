// RightAddManAccView.cpp : 实现文件
//

#include "stdafx.h"
#include "MyManage.h"
#include "RightAddManAccView.h"
#include "afxdialogex.h"


// CRightAddManAccView 对话框

IMPLEMENT_DYNAMIC(CRightAddManAccView, CDialog)

CRightAddManAccView::CRightAddManAccView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightAddManAccView::IDD, pParent)
{

}

CRightAddManAccView::~CRightAddManAccView()
{
}

void CRightAddManAccView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	/*	DDX_Control(pDX, IDC_AUTHTAB, m_authtab);*/
	DDX_Text(pDX, IDC_NAME, m_name);
	DDX_Text(pDX, IDC_DUTY, m_duty);
	DDX_Text(pDX, IDC_CELL, m_cell);
	DDX_Text(pDX, IDC_PASSWORD, m_password);
	DDX_Control(pDX, IDC_CS, m_cs);
	DDX_Control(pDX, IDC_TECH, m_tech);
	DDX_Control(pDX, IDC_DOC, m_doc);
	DDX_Text(pDX, IDC_EDIT1, m_jobtime);
	DDX_Text(pDX, IDC_EDIT2, m_jobphome);
	/*	DDX_Control(pDX, IDC_CS, m_BtnCS);*/
	//  DDX_Control(pDX, IDC_CS, m_BtnCS);
	DDX_Control(pDX, IDC_AUTH_RANGE, m_Btn);
}


BEGIN_MESSAGE_MAP(CRightAddManAccView, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_CS1, &CRightAddManAccView::OnBnClickedCs1)
	ON_BN_CLICKED(IDC_CS2, &CRightAddManAccView::OnBnClickedCs2)
	ON_BN_CLICKED(IDC_TECH1, &CRightAddManAccView::OnBnClickedTech1)
	ON_BN_CLICKED(IDC_TECH2, &CRightAddManAccView::OnBnClickedTech2)
	ON_BN_CLICKED(IDC_DOC1, &CRightAddManAccView::OnBnClickedDoc1)
	ON_BN_CLICKED(IDC_DOC2, &CRightAddManAccView::OnBnClickedDoc2)
	ON_WM_SETCURSOR()
	ON_BN_CLICKED(IDC_AUTH_RANGE, &CRightAddManAccView::OnBnClickedAuthRange)
END_MESSAGE_MAP()


// CRightAddManAccView 消息处理程序


void CRightAddManAccView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialog::OnPaint()
// 	CBitmap bitmap;
// 	bitmap.LoadBitmap(IDB_BIT_BKIN);
// 	CBrush Brush;
// 	Brush.CreatePatternBrush(&bitmap);
// 	CBrush* pOldBrush=dc.SelectObject(&Brush);
// 	dc.FillRect(CRect(0,0,783,659),&Brush);
// 	dc.SelectObject(pOldBrush);
	CPen pen;
	pen.CreatePen(PS_SOLID,1,theApp.m_LineColor);

	CBrush* Brush=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	CPen* pOldPen=dc.SelectObject(&pen);
	CBrush* pOldBrush=dc.SelectObject(Brush);
	dc.Rectangle(CRect(40,5,744,90));
	dc.Rectangle(CRect(40,100,744,186));
	dc.Rectangle(CRect(40,195,744,640));
	dc.SelectObject(pOldPen);
	dc.SelectObject(pOldBrush);

// 	CPen pen1;
// 	pen1.CreatePen(PS_SOLID,1,RGB(255,255,255));
// 
// 	CBrush* Brush1=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
// 	CPen* pOldPen1=dc.SelectObject(&pen1);
// 	CBrush* pOldBrush1=dc.SelectObject(Brush1);
// 	dc.Rectangle(CRect(40,100,744,1));
// 
// 	dc.SelectObject(pOldPen1);
// 	dc.SelectObject(pOldBrush1);


}


HBRUSH CRightAddManAccView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	switch(nCtlColor)
	{
	case CTLCOLOR_STATIC:
		if(pDC)
			pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
		break;
// 	case CTLCOLOR_MAX:
// 			if(pDC)
// 				pDC->SetBkMode(TRANSPARENT);
// 			return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
// 			break;
	default:
		break;
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
// 	if(pWnd->GetDlgCtrlID()==IDC_STATIC)
// 	{	
// 		pDC->SetBkMode(TRANSPARENT);
// 		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
// 	}
// 	if(pWnd->GetDlgCtrlID()==IDC_CS1)
// 	{	
// 		pDC->SetBkMode(TRANSPARENT);
// 		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
// 	}
	if(pWnd==this)
	{
		return m_Brush;
	}
	return hbr;
}


BOOL CRightAddManAccView::OnInitDialog()
{
	CDialog::OnInitDialog();
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BIT_BKIN);
	/*CBrush Brush;*/
	m_Brush.CreatePatternBrush(&bitmap);
	bitmap.DeleteObject();
// 	CBrush* pOldBrush=dc.SelectObject(&Brush);
// 	dc.FillRect(CRect(0,0,783,659),&Brush);
// 	dc.SelectObject(pOldBrush);
	// TODO:  在此添加额外的初始化
	/*m_BtnCS.DrawTransparent(TRUE);*/
	/*m_BtnCS.SetColor(CButtonST::BTNST_COLOR_BK_OUT,theApp.m_RightColr);*/
/*	m_BtnCS.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,30);*/
// 	m_BtnCS.DrawTransparent(TRUE);
// 	m_BtnCS.SetIcon(IDB_ICON_CHECED,IDB_ICON_UNCHECED1);
	
	m_Btn.DrawTransparent(TRUE);
	m_Btn.SetFlat(FALSE);
	m_Btn.SetTooltipText(_T("点击选择授权范围"));


	CRect rc(41,196,743,639);
	///////////////////创建客服代表界面//////////////////////////////
	m_RightAuthCS1View.Create(IDD_AUTH_CS1,this);
	m_RightAuthCS1View.MoveWindow(rc);
	m_RightAuthCS1View.ShowWindow(SW_HIDE);

	//////////////////创建客服主管界面///////////////////////////////
	m_RightAuthCS2View.Create(IDD_AUTH_CS2,this);
	m_RightAuthCS2View.MoveWindow(rc);
	m_RightAuthCS2View.ShowWindow(SW_HIDE);

    /////////////////创建初级技师界面////////////////////////////////
	m_RightAuthTech1View.Create(IDD_AUTH_TECH1,this);
	m_RightAuthTech1View.MoveWindow(rc);
	m_RightAuthTech1View.ShowWindow(SW_HIDE);

	////////////////创建技师主管界面/////////////////////////////////
	m_RightAuthTech2View.Create(IDD_AUTH_TECH2,this);
	m_RightAuthTech2View.MoveWindow(rc);
	m_RightAuthTech2View.ShowWindow(SW_HIDE);

	////////////////创建初级全科医生界面////////////////////////////
	m_RightAuthDoc1View.Create(IDD_AUTH_DOC1,this);
	m_RightAuthDoc1View.MoveWindow(rc);
	m_RightAuthDoc1View.ShowWindow(SW_HIDE);

	////////////////创建技师主管界面////////////////////////////////
	m_RightAuthDoc2View.Create(IDD_AUTH_DOC2,this);
	m_RightAuthDoc2View.MoveWindow(rc);
	m_RightAuthDoc2View.ShowWindow(SW_HIDE);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CRightAddManAccView::OnBnClickedCs1()
{
	// TODO: 在此添加控件通知处理程序代码
	m_cs.SetCheck(BST_CHECKED);
	m_tech.SetCheck(BST_UNCHECKED);
	m_doc.SetCheck(BST_UNCHECKED);

	CButton* radio1=(CButton*)GetDlgItem(IDC_TECH1);
	radio1->SetCheck(0);

	CButton* radio2=(CButton*)GetDlgItem(IDC_TECH2);
	radio2->SetCheck(0);

	CButton* radio3=(CButton*)GetDlgItem(IDC_DOC1);
	radio3->SetCheck(0);

	CButton* radio4=(CButton*)GetDlgItem(IDC_DOC2);
	radio4->SetCheck(0);
}


void CRightAddManAccView::OnBnClickedCs2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_cs.SetCheck(BST_CHECKED);
	m_tech.SetCheck(BST_UNCHECKED);
	m_doc.SetCheck(BST_UNCHECKED);

	CButton* radio1=(CButton*)GetDlgItem(IDC_TECH1);
	radio1->SetCheck(0);

	CButton* radio2=(CButton*)GetDlgItem(IDC_TECH2);
	radio2->SetCheck(0);

	CButton* radio3=(CButton*)GetDlgItem(IDC_DOC1);
	radio3->SetCheck(0);

	CButton* radio4=(CButton*)GetDlgItem(IDC_DOC2);
	radio4->SetCheck(0);
}


void CRightAddManAccView::OnBnClickedTech1()
{
	// TODO: 在此添加控件通知处理程序代码
	m_cs.SetCheck(BST_UNCHECKED);
	m_tech.SetCheck(BST_CHECKED);
	m_doc.SetCheck(BST_UNCHECKED);

	CButton* radio1=(CButton*)GetDlgItem(IDC_CS1);
	radio1->SetCheck(0);

	CButton* radio2=(CButton*)GetDlgItem(IDC_CS2);
	radio2->SetCheck(0);

	CButton* radio3=(CButton*)GetDlgItem(IDC_DOC1);
	radio3->SetCheck(0);

	CButton* radio4=(CButton*)GetDlgItem(IDC_DOC2);
	radio4->SetCheck(0);
}



void CRightAddManAccView::OnBnClickedTech2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_cs.SetCheck(BST_UNCHECKED);
	m_tech.SetCheck(BST_CHECKED);
	m_doc.SetCheck(BST_UNCHECKED);

	CButton* radio1=(CButton*)GetDlgItem(IDC_CS1);
	radio1->SetCheck(0);

	CButton* radio2=(CButton*)GetDlgItem(IDC_CS2);
	radio2->SetCheck(0);

	CButton* radio3=(CButton*)GetDlgItem(IDC_DOC1);
	radio3->SetCheck(0);

	CButton* radio4=(CButton*)GetDlgItem(IDC_DOC2);
	radio4->SetCheck(0);
}



void CRightAddManAccView::OnBnClickedDoc1()
{
	// TODO: 在此添加控件通知处理程序代码
	m_cs.SetCheck(BST_UNCHECKED);
	m_tech.SetCheck(BST_UNCHECKED);
	m_doc.SetCheck(BST_CHECKED);

	CButton* radio1=(CButton*)GetDlgItem(IDC_CS1);
	radio1->SetCheck(0);

	CButton* radio2=(CButton*)GetDlgItem(IDC_CS2);
	radio2->SetCheck(0);

	CButton* radio3=(CButton*)GetDlgItem(IDC_TECH1);
	radio3->SetCheck(0);

	CButton* radio4=(CButton*)GetDlgItem(IDC_TECH2);
	radio4->SetCheck(0);
}



void CRightAddManAccView::OnBnClickedDoc2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_cs.SetCheck(BST_UNCHECKED);
	m_tech.SetCheck(BST_UNCHECKED);
	m_doc.SetCheck(BST_CHECKED);

	CButton* radio1=(CButton*)GetDlgItem(IDC_CS1);
	radio1->SetCheck(0);

	CButton* radio2=(CButton*)GetDlgItem(IDC_CS2);
	radio2->SetCheck(0);

	CButton* radio3=(CButton*)GetDlgItem(IDC_TECH1);
	radio3->SetCheck(0);

	CButton* radio4=(CButton*)GetDlgItem(IDC_TECH2);
	radio4->SetCheck(0);
}


BOOL CRightAddManAccView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(pWnd->GetDlgCtrlID()==IDC_AUTH_RANGE)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}


void CRightAddManAccView::OnBnClickedAuthRange()
{
	// TODO: 在此添加控件通知处理程序代码
	if((IsDlgButtonChecked(IDC_CS)==BST_CHECKED)&&IsDlgButtonChecked(IDC_CS1)==BST_CHECKED)
	{
		m_RightAuthCS1View.ShowWindow(SW_SHOW);
		m_RightAuthCS2View.ShowWindow(SW_HIDE);
		m_RightAuthTech1View.ShowWindow(SW_HIDE);
		m_RightAuthTech2View.ShowWindow(SW_HIDE);
		m_RightAuthDoc1View.ShowWindow(SW_HIDE);
		m_RightAuthDoc2View.ShowWindow(SW_HIDE);
	}
	else if((IsDlgButtonChecked(IDC_CS)==BST_CHECKED)&&IsDlgButtonChecked(IDC_CS2)==BST_CHECKED)
	{
		m_RightAuthCS2View.ShowWindow(SW_SHOW);
		m_RightAuthCS1View.ShowWindow(SW_HIDE);
		m_RightAuthTech1View.ShowWindow(SW_HIDE);
		m_RightAuthTech2View.ShowWindow(SW_HIDE);
		m_RightAuthDoc1View.ShowWindow(SW_HIDE);
		m_RightAuthDoc2View.ShowWindow(SW_HIDE);
	}
	else if((IsDlgButtonChecked(IDC_TECH)==BST_CHECKED)&&IsDlgButtonChecked(IDC_TECH1)==BST_CHECKED)
	{
		m_RightAuthTech1View.ShowWindow(SW_SHOW);
		m_RightAuthCS2View.ShowWindow(SW_HIDE);
		m_RightAuthCS1View.ShowWindow(SW_HIDE);
		m_RightAuthTech2View.ShowWindow(SW_HIDE);
		m_RightAuthDoc1View.ShowWindow(SW_HIDE);
		m_RightAuthDoc2View.ShowWindow(SW_HIDE);
	}
	else if((IsDlgButtonChecked(IDC_TECH)==BST_CHECKED)&&IsDlgButtonChecked(IDC_TECH2)==BST_CHECKED)
	{
		m_RightAuthTech2View.ShowWindow(SW_SHOW);
		m_RightAuthTech1View.ShowWindow(SW_HIDE);
		m_RightAuthCS2View.ShowWindow(SW_HIDE);
		m_RightAuthCS1View.ShowWindow(SW_HIDE);
		m_RightAuthDoc1View.ShowWindow(SW_HIDE);
		m_RightAuthDoc2View.ShowWindow(SW_HIDE);
	}
	else if((IsDlgButtonChecked(IDC_DOC)==BST_CHECKED)&&IsDlgButtonChecked(IDC_DOC1)==BST_CHECKED)
	{
		m_RightAuthDoc1View.ShowWindow(SW_SHOW);
		m_RightAuthTech2View.ShowWindow(SW_HIDE);
		m_RightAuthTech1View.ShowWindow(SW_HIDE);
		m_RightAuthCS2View.ShowWindow(SW_HIDE);
		m_RightAuthCS1View.ShowWindow(SW_HIDE);
		m_RightAuthDoc2View.ShowWindow(SW_HIDE);
	}
	else if((IsDlgButtonChecked(IDC_DOC)==BST_CHECKED)&&IsDlgButtonChecked(IDC_DOC2)==BST_CHECKED)
	{
		m_RightAuthDoc2View.ShowWindow(SW_SHOW);
		m_RightAuthDoc1View.ShowWindow(SW_HIDE);
		m_RightAuthTech2View.ShowWindow(SW_HIDE);
		m_RightAuthTech1View.ShowWindow(SW_HIDE);
		m_RightAuthCS2View.ShowWindow(SW_HIDE);
		m_RightAuthCS1View.ShowWindow(SW_HIDE);
	}
}
