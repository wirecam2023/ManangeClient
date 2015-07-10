// LeftPaneView.cpp : 实现文件
//

#include "stdafx.h"
#include "MyManage.h"
#include "LeftPaneView.h"
#include "afxdialogex.h"


// CLeftPaneView 对话框

IMPLEMENT_DYNAMIC(CLeftPaneView, CDialog)

CLeftPaneView::CLeftPaneView(CWnd* pParent /*=NULL*/)
	: CDialog(CLeftPaneView::IDD, pParent)
{
	m_Brush.CreateSolidBrush(theApp.m_LeftColr);
	m_myFont.CreatePointFont(100,_T("隶书")); 
}

CLeftPaneView::~CLeftPaneView()
{
}

void CLeftPaneView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DIRECTREE, m_tree);
	DDX_Control(pDX, IDC_TREE_CS2, m_TreeCS2);
	DDX_Control(pDX, IDC_TREE_CS1, m_TreeCS1);
	DDX_Control(pDX, IDC_TREE_MAN, m_TreeMan);
}


BEGIN_MESSAGE_MAP(CLeftPaneView, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_NOTIFY(TVN_SELCHANGED, IDC_DIRECTREE, &CLeftPaneView::OnTvnSelchangedDirectree)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_KEYDOWN()
	ON_NOTIFY(TVN_SELCHANGING, IDC_DIRECTREE, &CLeftPaneView::OnTvnSelchangingDirectree)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE_CS1, &CLeftPaneView::OnTvnSelchangedTreeCs1)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE_CS2, &CLeftPaneView::OnTvnSelchangedTreeCs2)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE_MAN, &CLeftPaneView::OnTvnSelchangedTreeMan)
END_MESSAGE_MAP()


// CLeftPaneView 消息处理程序


BOOL CLeftPaneView::OnInitDialog()
{
	CDialog::OnInitDialog();



	// TODO:  在此添加额外的初始化
	m_tree.SetWindowPos(NULL,10,20,0,0,SWP_NOSIZE);
	m_TreeCS1.SetWindowPos(NULL,10,20,0,0,SWP_NOSIZE);
	m_TreeCS2.SetWindowPos(NULL,10,20,0,0,SWP_NOSIZE);
	m_TreeMan.SetWindowPos(NULL,10,20,0,0,SWP_NOSIZE);

	m_tree.ModifyStyle(NULL,TVS_HASBUTTONS | TVS_HASLINES | TVS_LINESATROOT);
	m_TreeCS1.ModifyStyle(NULL,TVS_HASBUTTONS | TVS_HASLINES | TVS_LINESATROOT);
	m_TreeCS2.ModifyStyle(NULL,TVS_HASBUTTONS | TVS_HASLINES | TVS_LINESATROOT);
	m_TreeMan.ModifyStyle(NULL,TVS_HASBUTTONS | TVS_HASLINES | TVS_LINESATROOT);

	hItem1 = m_tree.InsertItem(_T("账户管理"),TVI_ROOT);

	hItem11 = m_tree.InsertItem(_T("用户账户管理"),hItem1);
	hItem111=m_tree.InsertItem(_T("添加用户账户"),hItem11);
	hItem112=m_tree.InsertItem(_T("查看用户账户"),hItem11,hItem111 );

	hItem12 = m_tree.InsertItem(_T("医生账户管理"),hItem1,hItem11);
	hItem121=m_tree.InsertItem(_T("添加医生账户"),hItem12);
	hItem122=m_tree.InsertItem(_T("查看医生账户"),hItem12,hItem121 );

	hItem13 = m_tree.InsertItem(_T("管理员账户管理"),hItem1,hItem12);
	hItem131=m_tree.InsertItem(_T("添加管理员账户"),hItem13);
	hItem132=m_tree.InsertItem(_T("查看管理员账户"),hItem13,hItem131 );
	hItem133=m_tree.InsertItem(_T("查看公司职员"),hItem13,hItem133);

	hItem2 = m_tree.InsertItem(_T("序列号管理"),TVI_ROOT,hItem1);
	hItem21 = m_tree.InsertItem(_T("添加序列号"),hItem2);
	hItem22 = m_tree.InsertItem(_T("查看序列号"),hItem2,hItem21);

	hItem3 = m_tree.InsertItem(_T("推送信息"),TVI_ROOT,hItem1);

	hItem4 = m_tree.InsertItem(_T("管理平台"),TVI_ROOT,hItem1);
	hItem41 = m_tree.InsertItem(_T("登录"),hItem4);
	hItem42 = m_tree.InsertItem(_T("欢迎"),hItem4,hItem41);
	m_tree.InsertItem(_T("退出"),hItem4,hItem42);
	m_tree.SetBkColor(theApp.m_LeftColr);
	m_TreeCS1.SetBkColor(theApp.m_LeftColr);
	m_TreeCS2.SetBkColor(theApp.m_LeftColr);
	m_TreeMan.SetBkColor(theApp.m_LeftColr);

	//***********************客服经理**********************************
	CS1Item1 = m_TreeCS1.InsertItem(_T("账户管理"),TVI_ROOT);
	CS1Item11 = m_TreeCS1.InsertItem(_T("添加及授权账户"),CS1Item1);
	CS1Item12 = m_TreeCS1.InsertItem(_T("查看客服代表账户"),CS1Item1,CS1Item11);

	CS1Item2 = m_TreeCS1.InsertItem(_T("管理平台"),TVI_ROOT,CS1Item1);
	CS1Item21 = m_TreeCS1.InsertItem(_T("欢迎"),CS1Item2);
	CS1Item22 = m_TreeCS1.InsertItem(_T("登录"),CS1Item2,CS1Item21);

	m_TreeCS1.InsertItem(_T("退出"),CS1Item2,CS1Item22);

	CS1Item3 = m_TreeCS1.InsertItem(_T("推送信息"),TVI_ROOT,CS1Item2);

	CS1Item4 = m_TreeCS1.InsertItem(_T("序列号管理"),TVI_ROOT,CS1Item3);
	CS1Item41 = m_TreeCS1.InsertItem(_T("添加序列号"),CS1Item4);
	CS1Item42 = m_TreeCS1.InsertItem(_T("查看序列号"),CS1Item4,CS1Item41);

	//**************************客服代表******************************
	CS2Item1 = m_TreeCS2.InsertItem(_T("账户管理"),TVI_ROOT);
	CS2Item11= m_TreeCS2.InsertItem(_T("用户账户管理"),CS2Item1);
	CS2Item111 = m_TreeCS2.InsertItem(_T("添加用户账户"),CS2Item11);
	CS2Item112 = m_TreeCS2.InsertItem(_T("查看用户账户"),CS2Item11,CS2Item111);
	CS2Item12 = m_TreeCS2.InsertItem(_T("医生账户管理"),CS2Item1,CS2Item11);
	CS2Item121 = m_TreeCS2.InsertItem(_T("添加医生账户"),CS2Item12);
	CS2Item122 = m_TreeCS2.InsertItem(_T("查看医生账户"),CS2Item12,CS2Item121);

	CS2Item2 = m_TreeCS2.InsertItem(_T("管理平台"),TVI_ROOT,CS2Item1);
	CS2Item21 = m_TreeCS2.InsertItem(_T("登录"),CS2Item2);
	CS2Item22 = m_TreeCS2.InsertItem(_T("欢迎"),CS2Item2,CS2Item21);

	m_TreeCS2.InsertItem(_T("退出"),CS2Item2,CS2Item22);

	CS2Item3 = m_TreeCS2.InsertItem(_T("推送消息"),TVI_ROOT,CS2Item2);
	CS2Item4 = m_TreeCS2.InsertItem(_T("查看序列号"),TVI_ROOT,CS2Item3);

	//****************************平台经理*****************************
	MANItem1 = m_TreeMan.InsertItem(_T("账户管理"),TVI_ROOT);
	MANItem11 = m_TreeMan.InsertItem(_T("授权"),MANItem1);
    MANItem12 = m_TreeMan.InsertItem(_T("查看公司职员"),MANItem1,MANItem11);

	MANItem2 = m_TreeMan.InsertItem(_T("管理平台"),TVI_ROOT,MANItem1);
	MANItem21 = m_TreeMan.InsertItem(_T("登录"),MANItem2);
	MANItem22 = m_TreeMan.InsertItem(_T("欢迎"),MANItem2,MANItem21);
    m_TreeMan.InsertItem(_T("退出"),MANItem2,MANItem22);

	MANItem3 = m_TreeMan.InsertItem(_T("推送信息"));
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CLeftPaneView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialog::OnPaint()
// 	CBitmap   bitmap;
// 	bitmap.LoadBitmap(IDB_BIT_LEFT); 
// 	CBrush   brush;
// 	brush.CreatePatternBrush(&bitmap);
// 	CBrush*   pOldBrush   =   dc.SelectObject(&brush);
// 	/*dc.Rectangle(CRect(0,0,240,683));  */
// 	dc.FillRect(CRect(0,0,240,683),&brush);
// 	dc.SelectObject(pOldBrush);
}


HBRUSH CLeftPaneView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
//  	if (pWnd->GetDlgCtrlID()==IDC_DIRECTREE) 
//  	{ 
// 		pDC->SelectObject(&m_myFont);
//  		pDC->SetBkMode(TRANSPARENT);
//  		return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
// 	}
	return m_Brush;
	/*return hbr;*/
}


void CLeftPaneView::OnTvnSelchangedDirectree(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	HTREEITEM hItem=m_tree.GetSelectedItem();
	CString s=m_tree.GetItemText(hItem);
	if(s==_T("添加用户账户"))
	{
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddUserAccView->ShowWindow(SW_SHOW);
		theApp.m_pRightChgUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddManAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgManAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);
		theApp.m_pRightEmployee->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	if(s==_T("查看用户账户"))
	{
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgUserAccView->ShowWindow(SW_SHOW);
		theApp.m_pRightAddDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddManAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgManAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);
		theApp.m_pRightEmployee->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	if(s==_T("添加医生账户"))
	{
		theApp.m_pRightAddDocAccView->ShowWindow(SW_SHOW);
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddManAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgManAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);
		theApp.m_pRightEmployee->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	if(s==_T("查看医生账户"))
	{
		theApp.m_pRightChgDocAccView->ShowWindow(SW_SHOW);
		theApp.m_pRightAddDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddManAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgManAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);
		theApp.m_pRightEmployee->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	if(s==_T("添加管理员账户"))
	{
		theApp.m_pRightAddManAccView->ShowWindow(SW_SHOW);
		theApp.m_pRightChgDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgManAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);
		theApp.m_pRightEmployee->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	if(s==_T("查看管理员账户"))
	{
		theApp.m_pRightChgManAccView->ShowWindow(SW_SHOW);
		theApp.m_pRightAddManAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);
		theApp.m_pRightEmployee->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	if(s==_T("查看公司职员"))
	{
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddManAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgManAccView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);

		theApp.m_pRightEmployee->ShowWindow(SW_SHOW);
	}
	if (s==_T("登录"))
	{
	
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddManAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgManAccView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);
		theApp.m_pRightEmployee->ShowWindow(SW_HIDE);
		theApp.m_pRightEmployee->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_SHOW);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_SHOW);

		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);

		CRect rc,rc1,rc2;
		theApp.m_MyManageDlg->GetClientRect(&rc);
		theApp.m_MyManageDlg->m_RightLoginView.GetClientRect(&rc1);

		rc2 = rc;
		rc.left = rc2.left+240+(rc2.Width()-240)/2-rc1.Width()/2;
		rc.top = rc2.bottom-rc2.Height()/2-rc1.Height()/2;

		theApp.m_MyManageDlg->m_RightLoginView.MoveWindow(rc.left,rc.top,rc1.Width(),rc1.Height());
		theApp.m_pRightLoginView->ShowWindow(SW_SHOW);

		theApp.m_LGMoveMode=TRUE;
	}
	if(s==_T("欢迎"))
	{
		theApp.m_pRightWelView->ShowWindow(SW_SHOW);
		theApp.m_pRightChgManAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddManAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);
		theApp.m_pRightEmployee->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);

	}
	if(s==_T("退出"))
	{
		exit(0);
	}
	if(s==_T("推送信息"))
	{
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgManAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddManAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightAddSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_SHOW);
		theApp.m_pRightEmployee->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	if(s==_T("添加序列号"))
	{
		theApp.m_pRightAddSeriView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgManAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddManAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightChgSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);
		theApp.m_pRightEmployee->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	if(s==_T("查看序列号"))
	{
		theApp.m_pRightChgSeriView->ShowWindow(SW_SHOW);
		theApp.m_pRightAddSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgManAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddManAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);
		theApp.m_pRightEmployee->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	*pResult = 0;
}


void CLeftPaneView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect rc(0,0,240,28);
	if(PtInRect(rc,point))
	{
		theApp.m_MyManageDlg->m_Point1=point;
		theApp.m_MyManageDlg->m_MoveMode=TRUE;
	}
	
	CDialog::OnLButtonDown(nFlags, point);
}



void CLeftPaneView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	theApp.m_MyManageDlg->m_MoveMode=FALSE;
	CDialog::OnLButtonUp(nFlags, point);
}


void CLeftPaneView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	theApp.m_MyManageDlg->OnMouseMove(nFlags,point);
	CDialog::OnMouseMove(nFlags, point);
}


void CLeftPaneView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(nChar==0x0d)
	{
	/*	theApp.m_EnterkeyMode=TRUE;*/
	}
	CDialog::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CLeftPaneView::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类
	return;
/*	CDialog::OnOK();*/
}


BOOL CLeftPaneView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam==VK_ESCAPE|| pMsg->wParam == VK_RETURN)//退出键Esc
			return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}


void CLeftPaneView::OnTvnSelchangingDirectree(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
/*	if()*/
	NM_TREEVIEW* pTreeView=(NM_TREEVIEW*)pNMTreeView; 
// 	if (theApp.m_AuthLimit==0)
// 	{
// 		if((pTreeView->itemNew.hItem==hItem111)||
// 			(pTreeView->itemNew.hItem==hItem112)||
// 			(pTreeView->itemNew.hItem==hItem121)||
// 			(pTreeView->itemNew.hItem==hItem122)||
// 			(pTreeView->itemNew.hItem==hItem131)||
// 			(pTreeView->itemNew.hItem==hItem132)||
// 			(pTreeView->itemNew.hItem==hItem3)||
// 			(pTreeView->itemNew.hItem==hItem21)||
// 			(pTreeView->itemNew.hItem==hItem22)||
// 			(pTreeView->itemNew.hItem==hItem42))
// 		{
// 			MessageBox(_T("您无此权限"));
// 			*pResult = 1;
// 			return;
// 		}
// 	}
// 	else if (theApp.m_AuthLimit==1)
// 	{
// 		*pResult = 0;
// 	}
// 	else if (theApp.m_AuthLimit==2)
// 	{
// 		if((pTreeView->itemNew.hItem==hItem13)||
// 			(pTreeView->itemNew.hItem==hItem131)||
// 			(pTreeView->itemNew.hItem==hItem132)||
// 			(pTreeView->itemNew.hItem==hItem2)||
// 			(pTreeView->itemNew.hItem==hItem21)||
// 			(pTreeView->itemNew.hItem==hItem22))
// 		{
// 			MessageBox(_T("您无此权限"));
// 			*pResult = 1;
// 			return;
// 		}
// 	}

	*pResult = 0;
}


void CLeftPaneView::OnTvnSelchangedTreeCs1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	//*****************客服经理****************************
	HTREEITEM hItemCS1=m_TreeCS1.GetSelectedItem();
	CString CS1=m_TreeCS1.GetItemText(hItemCS1);
	if(CS1==_T("添加及授权账户"))
	{

	}
	if(CS1==_T("查看客服代表账户"))
	{

	}
	if(CS1==_T("欢迎"))
	{
		theApp.m_pRightWelView->ShowWindow(SW_SHOW);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	if(CS1==_T("登录"))
	{
		theApp.m_pRightLoginView->ShowWindow(SW_SHOW);
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_SHOW);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_SHOW);

		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);

		CRect rc,rc1,rc2;
		theApp.m_MyManageDlg->GetClientRect(&rc);
		theApp.m_MyManageDlg->m_RightLoginView.GetClientRect(&rc1);

		rc2 = rc;
		rc.left = rc2.left+240+(rc2.Width()-240)/2-rc1.Width()/2;
		rc.top = rc2.bottom-rc2.Height()/2-rc1.Height()/2;

		theApp.m_MyManageDlg->m_RightLoginView.MoveWindow(rc.left,rc.top,rc1.Width(),rc1.Height());
		theApp.m_pRightLoginView->ShowWindow(SW_SHOW);

		theApp.m_LGMoveMode=TRUE;
	}
	if(CS1==_T("退出"))
	{
		if(AfxMessageBox(_T("是否退出？"),MB_OKCANCEL)==IDOK)
		{
			exit(0);
		}
	}
	if(CS1==_T("添加序列号"))
	{
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddSeriView->ShowWindow(SW_SHOW);
		theApp.m_pRightChgSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	if(CS1==_T("查看序列号"))
	{
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgSeriView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	if(CS1==_T("推送信息"))
	{
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_SHOW);
		theApp.m_pRightAddSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	*pResult = 0;
}


void CLeftPaneView::OnTvnSelchangedTreeCs2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	HTREEITEM hItemCS2=m_TreeCS2.GetSelectedItem();
	CString CS2=m_TreeCS2.GetItemText(hItemCS2);
	if(CS2==_T("添加用户账户"))
	{
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddUserAccView->ShowWindow(SW_SHOW);
		theApp.m_pRightChgUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	if(CS2==_T("查看用户账户"))
	{
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgUserAccView->ShowWindow(SW_SHOW);
		theApp.m_pRightAddDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	if(CS2==_T("添加医生账户"))
	{
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddDocAccView->ShowWindow(SW_SHOW);
		theApp.m_pRightChgDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	if(CS2==_T("查看医生账户"))
	{
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgDocAccView->ShowWindow(SW_SHOW);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	if (CS2==_T("登录"))
	{
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_SHOW);
		theApp.m_pTopView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_SHOW);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_SHOW);

		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);

		CRect rc,rc1,rc2;
		theApp.m_MyManageDlg->GetClientRect(&rc);
		theApp.m_MyManageDlg->m_RightLoginView.GetClientRect(&rc1);

		rc2 = rc;
		rc.left = rc2.left+240+(rc2.Width()-240)/2-rc1.Width()/2;
		rc.top = rc2.bottom-rc2.Height()/2-rc1.Height()/2;

		theApp.m_MyManageDlg->m_RightLoginView.MoveWindow(rc.left,rc.top,rc1.Width(),rc1.Height());
		theApp.m_pRightLoginView->ShowWindow(SW_SHOW);

		theApp.m_LGMoveMode=TRUE;
	}
	if(CS2==_T("欢迎"))
	{
		theApp.m_pRightWelView->ShowWindow(SW_SHOW);
		theApp.m_pRightAddUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	if(CS2==_T("退出"))
	{
		if(AfxMessageBox(_T("是否退出？"),MB_OKCANCEL)==IDOK)
			exit(0);
	}
	if(CS2==_T("推送消息"))
	{
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_SHOW);
		theApp.m_pRightChgSeriView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	if(CS2==_T("查看序列号"))
	{
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgUserAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightAddDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgDocAccView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightChgSeriView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	*pResult = 0;
}


void CLeftPaneView::OnTvnSelchangedTreeMan(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	HTREEITEM hItemMAN=m_TreeMan.GetSelectedItem();
	CString MAN=m_TreeCS2.GetItemText(hItemMAN);
	if(MAN==_T("授权"))
	{
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);
		theApp.m_pRightEmployee->ShowWindow(SW_HIDE);
		theApp.m_pRightAuthorizeView->ShowWindow(SW_SHOW);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	if(MAN==_T("查看公司职员"))
	{
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);
		theApp.m_pRightEmployee->ShowWindow(SW_SHOW);
		theApp.m_pRightAuthorizeView->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	if(MAN==_T("登录"))
	{
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_SHOW);
		theApp.m_pTopView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);
		theApp.m_pRightEmployee->ShowWindow(SW_HIDE);
		theApp.m_pRightAuthorizeView->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_SHOW);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_SHOW);

		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);

		CRect rc,rc1,rc2;
		theApp.m_MyManageDlg->GetClientRect(&rc);
		theApp.m_MyManageDlg->m_RightLoginView.GetClientRect(&rc1);

		rc2 = rc;
		rc.left = rc2.left+240+(rc2.Width()-240)/2-rc1.Width()/2;
		rc.top = rc2.bottom-rc2.Height()/2-rc1.Height()/2;

		theApp.m_MyManageDlg->m_RightLoginView.MoveWindow(rc.left,rc.top,rc1.Width(),rc1.Height());
		theApp.m_pRightLoginView->ShowWindow(SW_SHOW);

		theApp.m_LGMoveMode=TRUE;
	}
	if(MAN==_T("退出"))
	{
		if(AfxMessageBox(_T("是否退出？"),MB_OKCANCEL)==IDOK)
			exit(0);
	}
	if(MAN==_T("推送信息"))
	{
		theApp.m_pRightWelView->ShowWindow(SW_HIDE);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);
		theApp.m_pRightEmployee->ShowWindow(SW_HIDE);
		theApp.m_pRightAuthorizeView->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	if(MAN==_T("欢迎"))
	{
		theApp.m_pRightWelView->ShowWindow(SW_SHOW);
		theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
		theApp.m_pTopView->ShowWindow(SW_SHOW);
		theApp.m_pRightMessSendView->ShowWindow(SW_HIDE);
		theApp.m_pRightMessSendView1->ShowWindow(SW_HIDE);
		theApp.m_pRightEmployee->ShowWindow(SW_HIDE);
		theApp.m_pRightAuthorizeView->ShowWindow(SW_HIDE);

		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	*pResult = 0;
}
