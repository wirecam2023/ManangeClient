// RightLoginView.cpp : 实现文件
//

#include "stdafx.h"
#include "MyManage.h"
#include "RightLoginView.h"
#include "afxdialogex.h"


// CRightLoginView 对话框

IMPLEMENT_DYNAMIC(CRightLoginView, CDialog)

CRightLoginView::CRightLoginView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightLoginView::IDD, pParent)
	/*, m_HideMode(FALSE)*/
{
	 theApp.m_LGMoveMode=FALSE;
}

CRightLoginView::~CRightLoginView()
{
}

void CRightLoginView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BTN_LOGIN, m_Btn);
}


BEGIN_MESSAGE_MAP(CRightLoginView, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_WM_SETCURSOR()
	ON_BN_CLICKED(IDC_BTN_LOGIN, &CRightLoginView::OnBnClickedBtnLogin)
	ON_MESSAGE(WM_SMLOGINEX,&CRightLoginView::OnSmLoginEx)
END_MESSAGE_MAP()


// CRightLoginView 消息处理程序


void CRightLoginView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialog::OnPaint()
	if(!theApp.m_LGMoveMode)
	{
	CBitmap   bitmap;
	bitmap.LoadBitmap(IDB_BIT_LOGIN); 
	CBrush   brush;
	brush.CreatePatternBrush(&bitmap);
	CBrush*   pOldBrush   =   dc.SelectObject(&brush);
	dc.Rectangle(CRect(0,0,300,120));  
	dc.SelectObject(pOldBrush);
	}
	else
	{
// 		CDC memDC;
// 
// 		CBitmap bitmap;
// 		bitmap.LoadBitmap(IDB_BIT_BK);
// 		bitmap.CreateCompatibleBitmap(&dc,1023,683);
// 		memDC.SelectObject(&bitmap);

// 		CBrush Brush;
// 		Brush.CreatePatternBrush(&bitmap);
// 		CBrush* pOldBrush = memDC.SelectObject(&Brush);

		/*memDC.Rectangle(CRect(0,0,1023,683));*/
/*		memDC.SelectObject(pOldBrush);*/

/*		dc.BitBlt(0,0,300,120,&memDC,481,283,SRCCOPY);*/

		CBitmap   bitmap;
		bitmap.LoadBitmap(IDB_BIT_LOGIN1); 
		CBrush   brush;
		brush.CreatePatternBrush(&bitmap);
		CBrush*   pOldBrush   =   dc.SelectObject(&brush);
		dc.Rectangle(CRect(0,0,300,120));  
		dc.SelectObject(pOldBrush);

		m_Btn.DrawTransparent(TRUE);
		m_Btn.SetTooltipText(_T("点击登录！"));

	}
}


HBRUSH CRightLoginView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	if ((pWnd->GetDlgCtrlID()==IDC_STATIC)) 
	{ 
		/*pDC->SelectObject(&m_log);*/
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
	}
	
	return hbr;
}


BOOL CRightLoginView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	/*m_Btn.SetFlat(TRUE);*/
	if(!theApp.m_LGMoveMode)
	{
		m_Btn.DrawTransparent(TRUE);
		//m_Btn.SetFlat(FALSE);
		m_Btn.SetTooltipText(_T("点击登录！"));
	}

	HANDLE hThread=::CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)RecvProc,NULL,0,NULL);
	CloseHandle(hThread);


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


BOOL CRightLoginView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(pWnd->GetDlgCtrlID()==IDC_BTN_LOGIN)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}


void CRightLoginView::OnBnClickedBtnLogin()
{
	// TODO: 在此添加控件通知处理程序代码
	CString UserName, Password;
	GetDlgItemText(IDC_NAME,UserName);
	GetDlgItemText(IDC_PASSWORD,Password);
	theApp.m_SockManageCtrl.ManLogin(UserName,Password);
	//////////////发送至数据库///////////////////
	if(theApp.m_SockManageCtrl.ManLogin(UserName,Password))
	{

	theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
	theApp.m_LeftPaneView->ShowWindow(SW_SHOW);
	theApp.m_pHeadTextView->ShowWindow(SW_HIDE);
	theApp.m_pRightWelView->ShowWindow(SW_SHOW);
	theApp.m_pTopView->ShowWindow(SW_SHOW);
// 	theApp.m_MyManageView->GetDlgItem(IDC_HEAD)->SetWindowText(_T(""));
// 	theApp.m_MyManageView->GetDlgItem(IDC_HEAD1)->SetWindowText(_T(""));
	/*theApp.m_MyManageView->ShowHead(FALSE);*/
// 	m_HideMode=TRUE;
// 	Invalidate();
	GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
	GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);

	
	theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
	theApp.m_LeftPaneView->ShowWindow(SW_SHOW);
	theApp.m_pHeadTextView->ShowWindow(SW_HIDE);
	theApp.m_pRightWelView->ShowWindow(SW_SHOW);
	theApp.m_pTopView->ShowWindow(SW_SHOW);
	// 	theApp.m_MyManageView->GetDlgItem(IDC_HEAD)->SetWindowText(_T(""));
	// 	theApp.m_MyManageView->GetDlgItem(IDC_HEAD1)->SetWindowText(_T(""));
	/*theApp.m_MyManageView->ShowHead(FALSE);*/
	// 	m_HideMode=TRUE;
	// 	Invalidate();
	GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
	GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
	}
	

}


BOOL CRightLoginView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam==VK_ESCAPE|| pMsg->wParam == VK_RETURN)//退出键Esc
			return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}

afx_msg LRESULT CRightLoginView::OnSmLoginEx(WPARAM wParam,LPARAM lParam)
{
	vector<CString> vec_smLoginEx;
	theApp.SplitString(*(CString*)lParam,_T(";"),TRUE,vec_smLoginEx);
// 	MessageBox(_T("登陆成功！"));
// 	if((vec_smLoginEx.at(1)==_T("6"))||(vec_smLoginEx.at(1)==_T("7")))
// 	{
// 		theApp.m_AuthLimit=1;
// 	}
// 	else if((vec_smLoginEx.at(1)==_T("2"))||(vec_smLoginEx.at(1)==_T("5")))
// 	{
// 		theApp.m_AuthLimit=2;
// 	}
// 	theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
// 	theApp.m_LeftPaneView->ShowWindow(SW_SHOW);
// 	theApp.m_pHeadTextView->ShowWindow(SW_HIDE);
// 	theApp.m_pRightWelView->ShowWindow(SW_SHOW);
// 	theApp.m_pTopView->ShowWindow(SW_SHOW);
// 	if(vec_smLoginEx.at(1)!=_T("-1"))
// 	{
// 		AfxMessageBox(_T("登录成功！"));
// 		int cmd = _ttoi(vec_smLoginEx.at(1));
// 		switch(cmd)
// 		{
// 		case 7:
// 			theApp.m_LeftPaneView->m_TreeMan.ShowWindow(SW_SHOW);
// 			theApp.m_LeftPaneView->m_TreeCS1.ShowWindow(SW_HIDE);
// 			theApp.m_LeftPaneView->m_TreeCS2.ShowWindow(SW_HIDE);
// 			break;
// 		case 6:
// 			theApp.m_LeftPaneView->m_TreeCS1.ShowWindow(SW_SHOW);
// 			theApp.m_LeftPaneView->m_TreeCS2.ShowWindow(SW_HIDE);
// 			theApp.m_LeftPaneView->m_TreeMan.ShowWindow(SW_HIDE);
// 			break;
// 		case 5:
// 			theApp.m_LeftPaneView->m_TreeCS2.ShowWindow(SW_SHOW);
// 			theApp.m_LeftPaneView->m_TreeCS1.ShowWindow(SW_HIDE);
// 			theApp.m_LeftPaneView->m_TreeMan.ShowWindow(SW_HIDE);
// 			break;
// 		default:
// 			break;
// 		}
// 	 	theApp.m_pRightLoginView->ShowWindow(SW_HIDE);
// 	 	theApp.m_LeftPaneView->ShowWindow(SW_SHOW);
// 	 	theApp.m_pHeadTextView->ShowWindow(SW_HIDE);
// 	 	theApp.m_pRightWelView->ShowWindow(SW_SHOW);
// 	 	theApp.m_pTopView->ShowWindow(SW_SHOW);
// 		GetParent()->GetDlgItem(IDC_BTN_OFF)->ShowWindow(SW_HIDE);
// 		GetParent()->GetDlgItem(IDC_BTN_MIN)->ShowWindow(SW_HIDE);
// 	}

	return 0;
}

