// RightChgUserAccView.cpp : 实现文件
//

#include "stdafx.h"
#include "MyManage.h"
#include "RightChgUserAccView.h"
#include "afxdialogex.h"


// CRightChgUserAccView 对话框

IMPLEMENT_DYNAMIC(CRightChgUserAccView, CDialog)

CRightChgUserAccView::CRightChgUserAccView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightChgUserAccView::IDD, pParent)
{

}

CRightChgUserAccView::~CRightChgUserAccView()
{
}

void CRightChgUserAccView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_BASINFO, m_BasInfo);
	DDX_CBString(pDX, IDC_QUETYPE, m_quetype);
	DDX_Text(pDX, IDC_QUETEXT, m_quetext);
	DDX_Control(pDX, IDC_QUETYPE, m_quetype1);
	DDX_Control(pDX, IDC_BTN_QUE, m_Btn);
	DDX_Control(pDX, IDC_BTN_INFO, m_BtnInfo);
	DDX_Control(pDX, IDC_BTN_UPLOAD, m_BtnUL);
	DDX_Control(pDX, IDC_BTN_DOC, m_BtnH);
	DDX_Control(pDX, IDC_BTN_EXCEP, m_BtnE);
	DDX_Control(pDX, IDC_BTN_DRUG1, m_BtnD);
	DDX_Control(pDX, IDC_BTN_MESS, m_BtnM);
	DDX_Control(pDX, IDC_USERINFO, m_userInfo);
	DDX_Control(pDX, IDC_BASINFO, m_Group);
}


BEGIN_MESSAGE_MAP(CRightChgUserAccView, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_WM_SETCURSOR()
	ON_BN_CLICKED(IDC_BTN_INFO, &CRightChgUserAccView::OnBnClickedBtnInfo)
	ON_BN_CLICKED(IDC_BTN_UPLOAD, &CRightChgUserAccView::OnBnClickedBtnUpload)
	ON_BN_CLICKED(IDC_BTN_DOC, &CRightChgUserAccView::OnBnClickedBtnDoc)
	ON_BN_CLICKED(IDC_BTN_EXCEP, &CRightChgUserAccView::OnBnClickedBtnExcep)
	ON_BN_CLICKED(IDC_BTN_DRUG1, &CRightChgUserAccView::OnBnClickedBtnDrug1)
	ON_BN_CLICKED(IDC_BTN_MESS, &CRightChgUserAccView::OnBnClickedBtnMess)
	ON_BN_CLICKED(IDC_BTN_QUE, &CRightChgUserAccView::OnBnClickedBtnQue)
	ON_MESSAGE(WM_SMQUEUSER,&CRightChgUserAccView::OnSmQueUser)
	ON_MESSAGE(WM_SMQUECSREX,&CRightChgUserAccView::OnSmQueUserEx)
	ON_NOTIFY(NM_CLICK, IDC_USERINFO, &CRightChgUserAccView::OnNMClickUserinfo)
END_MESSAGE_MAP()


// CRightChgUserAccView 消息处理程序


void CRightChgUserAccView::OnPaint()
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


HBRUSH CRightChgUserAccView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	if ((pWnd->GetDlgCtrlID()==IDC_STATIC))
	{
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	}
	if ((pWnd->GetDlgCtrlID()==IDC_SELUSER))
	{
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	}
	return hbr;
}


BOOL CRightChgUserAccView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_userInfo.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	m_userInfo.InsertColumn(0,_T("姓名"),LVCFMT_CENTER,100);
	m_userInfo.InsertColumn(1,_T("性别"),LVCFMT_CENTER,100);
	m_userInfo.InsertColumn(2,_T("年龄"),LVCFMT_CENTER,50);
	m_userInfo.InsertColumn(3,_T("手机号"),LVCFMT_CENTER,100);
	m_userInfo.InsertColumn(4,_T("注册时间"),LVCFMT_CENTER,150);

	m_Btn.SetFlat(FALSE);
	m_Btn.DrawTransparent(TRUE);
	m_Btn.SetTooltipText(_T("点击查询！"));
	m_quetype1.SetCurSel(0);

	m_BtnInfo.SetFlat(TRUE);
	m_BtnInfo.SetTooltipText(_T("点击查询个人信息"));
	
	m_BtnInfo.SetFlat(TRUE);
	m_BtnInfo.SetTooltipText(_T("点击查询个人信息"));
    m_BtnInfo.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS,RGB(128,42,42));
	m_BtnInfo.SetColor(CButtonST::BTNST_COLOR_BK_IN,RGB(106,90,205));
	m_BtnInfo.SetColor(CButtonST::BTNST_COLOR_BK_OUT,RGB(106,90,205));

	m_BtnUL.SetFlat(TRUE);
	m_BtnUL.SetTooltipText(_T("点击查询上传记录"));
	m_BtnUL.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS,RGB(128,42,42));
	m_BtnUL.SetColor(CButtonST::BTNST_COLOR_BK_IN,RGB(106,90,205));
	m_BtnUL.SetColor(CButtonST::BTNST_COLOR_BK_OUT,RGB(106,90,205));

	m_BtnD.SetFlat(TRUE);
	m_BtnD.SetTooltipText(_T("点击查询用药情况"));
	m_BtnD.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS,RGB(128,42,42));
	m_BtnD.SetColor(CButtonST::BTNST_COLOR_BK_IN,RGB(106,90,205));
	m_BtnD.SetColor(CButtonST::BTNST_COLOR_BK_OUT,RGB(106,90,205));

	m_BtnE.SetFlat(TRUE);
	m_BtnE.SetTooltipText(_T("点击查询异常情况"));
	m_BtnE.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS,RGB(128,42,42));
	m_BtnE.SetColor(CButtonST::BTNST_COLOR_BK_IN,RGB(106,90,205));
	m_BtnE.SetColor(CButtonST::BTNST_COLOR_BK_OUT,RGB(106,90,205));

	m_BtnH.SetFlat(TRUE);
	m_BtnH.SetTooltipText(_T("点击查询历史记录"));
	m_BtnH.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS,RGB(128,42,42));
	m_BtnH.SetColor(CButtonST::BTNST_COLOR_BK_IN,RGB(106,90,205));
	m_BtnH.SetColor(CButtonST::BTNST_COLOR_BK_OUT,RGB(106,90,205));

	m_BtnM.SetFlat(TRUE);
	m_BtnM.SetTooltipText(_T("点击查询消息"));
	m_BtnM.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS,RGB(128,42,42));
	m_BtnM.SetColor(CButtonST::BTNST_COLOR_BK_IN,RGB(106,90,205));
	m_BtnM.SetColor(CButtonST::BTNST_COLOR_BK_OUT,RGB(106,90,205));

	m_Group.SetBackgroundColor(theApp.m_RightColr);

	CRect rc(18,206,744,651);

    //////////////////////创建基本信息界面//////////////////////
	m_RightQueBasView.Create(IDD_RIGHT_QUEBAS,this);
	m_RightQueBasView.MoveWindow(rc);
	m_RightQueBasView.ShowWindow(SW_SHOW);
	
    /////////////////////创建上传记录界面///////////////////////
	m_RightQueUpLoadView.Create(IDD_RIGHT_QUEUPLOAD,this);
	m_RightQueUpLoadView.MoveWindow(rc);
	m_RightQueUpLoadView.ShowWindow(SW_HIDE);

	////////////////////创建历史报告界面////////////////////////
	m_RightQueRepView.Create(IDD_RIGHT_QUEREP,this);
	m_RightQueRepView.MoveWindow(rc);
	m_RightQueRepView.ShowWindow(SW_HIDE);

	///////////////////创建异常界面/////////////////////////////
	m_RightQueExecpView.Create(IDD_RIGHT_QUEEXCEP,this);
	m_RightQueExecpView.MoveWindow(rc);
	m_RightQueExecpView.ShowWindow(SW_HIDE);

	//////////////////创建用药情况界面//////////////////////////
	m_RightQueDrugView.Create(IDD_RIGHT_QUEDRUG,this);
	m_RightQueDrugView.MoveWindow(rc);
	m_RightQueDrugView.ShowWindow(SW_HIDE);

	/////////////////创建消息记录界面//////////////////////////
	m_RightQueMessView.Create(IDD_RIGHT_QUEMESS,this);
	m_RightQueMessView.MoveWindow(rc);
	m_RightQueMessView.ShowWindow(SW_HIDE);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


BOOL CRightChgUserAccView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(pWnd->GetDlgCtrlID()==IDC_BTN_QUE)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_BTN_INFO)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	if(pWnd->GetDlgCtrlID()==IDC_BTN_DRUG1)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}

	if(pWnd->GetDlgCtrlID()==IDC_BTN_MESS)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}

	if(pWnd->GetDlgCtrlID()==IDC_BTN_DOC)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}

	if(pWnd->GetDlgCtrlID()==IDC_BTN_UPLOAD)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}

	if(pWnd->GetDlgCtrlID()==IDC_BTN_EXCEP)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}


void CRightChgUserAccView::OnBnClickedBtnInfo()
{
	// TODO: 在此添加控件通知处理程序代码
	m_RightQueBasView.ShowWindow(SW_SHOW);
	m_RightQueUpLoadView.ShowWindow(SW_HIDE);
	m_RightQueRepView.ShowWindow(SW_HIDE);
	m_RightQueExecpView.ShowWindow(SW_HIDE);
	m_RightQueDrugView.ShowWindow(SW_HIDE);
	m_RightQueMessView.ShowWindow(SW_HIDE);
}


void CRightChgUserAccView::OnBnClickedBtnUpload()
{
	// TODO: 在此添加控件通知处理程序代码
	m_RightQueUpLoadView.ShowWindow(SW_SHOW);
	m_RightQueBasView.ShowWindow(SW_HIDE);
	m_RightQueRepView.ShowWindow(SW_HIDE);
	m_RightQueExecpView.ShowWindow(SW_HIDE);
	m_RightQueDrugView.ShowWindow(SW_HIDE);
	m_RightQueMessView.ShowWindow(SW_HIDE);
}


void CRightChgUserAccView::OnBnClickedBtnDoc()
{
	// TODO: 在此添加控件通知处理程序代码
	m_RightQueRepView.ShowWindow(SW_SHOW);
	m_RightQueBasView.ShowWindow(SW_HIDE);
	m_RightQueUpLoadView.ShowWindow(SW_HIDE);
	m_RightQueExecpView.ShowWindow(SW_HIDE);
	m_RightQueDrugView.ShowWindow(SW_HIDE);
	m_RightQueMessView.ShowWindow(SW_HIDE);

}


void CRightChgUserAccView::OnBnClickedBtnExcep()
{
	// TODO: 在此添加控件通知处理程序代码
	m_RightQueExecpView.ShowWindow(SW_SHOW);
	m_RightQueBasView.ShowWindow(SW_HIDE);
	m_RightQueUpLoadView.ShowWindow(SW_HIDE);
	m_RightQueRepView.ShowWindow(SW_HIDE);
	m_RightQueDrugView.ShowWindow(SW_HIDE);
	m_RightQueMessView.ShowWindow(SW_HIDE);
}


void CRightChgUserAccView::OnBnClickedBtnDrug1()
{
	// TODO: 在此添加控件通知处理程序代码
	m_RightQueDrugView.ShowWindow(SW_SHOW);
	m_RightQueExecpView.ShowWindow(SW_HIDE);
	m_RightQueBasView.ShowWindow(SW_HIDE);
	m_RightQueUpLoadView.ShowWindow(SW_HIDE);
	m_RightQueRepView.ShowWindow(SW_HIDE);
	m_RightQueMessView.ShowWindow(SW_HIDE);
}


void CRightChgUserAccView::OnBnClickedBtnMess()
{
	// TODO: 在此添加控件通知处理程序代码
	m_RightQueMessView.ShowWindow(SW_SHOW);
	m_RightQueDrugView.ShowWindow(SW_HIDE);
	m_RightQueExecpView.ShowWindow(SW_HIDE);
	m_RightQueBasView.ShowWindow(SW_HIDE);
	m_RightQueUpLoadView.ShowWindow(SW_HIDE);
	m_RightQueRepView.ShowWindow(SW_HIDE);

}


void CRightChgUserAccView::OnBnClickedBtnQue()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString QueType;
	int index=m_quetype1.GetCurSel();
	QueType.Format(_T("%d"),index);
	theApp.m_SockManageCtrl.ManQueUser(QueType,m_quetext);
}

afx_msg LRESULT CRightChgUserAccView::OnSmQueUser(WPARAM wParam, LPARAM lParam)
{
	vector<CString> vec_smqueuser;
	vector<CString> vec_smqueuser_baseinfo;
	theApp.SplitString(*(CString*)lParam,_T(";"),TRUE,vec_smqueuser);
	vec_userinfo=vec_smqueuser;
	for (int i=0;i<vec_smqueuser.size()-1;i++)
	{
		theApp.SplitString(vec_smqueuser.at(i+1),_T(","),TRUE,vec_smqueuser_baseinfo);
		m_userinfo.InsertItem(i,_T(""));
		m_userinfo.SetItemText(i,0,vec_smqueuser_baseinfo.at(0));
		m_userinfo.SetItemText(i,1,vec_smqueuser_baseinfo.at(1));
		m_userinfo.SetItemText(i,2,vec_smqueuser_baseinfo.at(2));
		m_userinfo.SetItemText(i,3,vec_smqueuser_baseinfo.at(3));
		m_userinfo.SetItemText(i,4,vec_smqueuser_baseinfo.at(4));
	}


	return 0;
}

afx_msg LRESULT CRightChgUserAccView::OnSmQueUserEx(WPARAM wParam, LPARAM lParam)
{
	vector<CString> vec_smqueuserex;
	theApp.SplitString(*(CString*)lParam,_T(";"),TRUE,vec_smqueuserex);
	MessageBox(vec_smqueuserex.at(1));
	return 0;
}

void CRightChgUserAccView::OnNMClickUserinfo(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	NMLISTVIEW* pList=(NMLISTVIEW*) pNMItemActivate;
	int row=pList->iItem;
	vector<CString> userinfo;
	m_selItem=vec_userinfo.at(row+1);
	//theApp.SplitString(vec_userinfo.at(row+1),_T(","),TRUE,userinfo);
	::PostMessage(theApp.m_pRightChgUserAccView->m_RightQueBasView.m_hWnd,WM_SHOWUSERINFO,0,(LPARAM)&m_selItem);

	vector<CString> astring;
	theApp.SplitString(vec_userinfo.at(row+1),_T(","),TRUE,astring);
	sel_user=astring.at(3);
	*pResult = 0;
}
