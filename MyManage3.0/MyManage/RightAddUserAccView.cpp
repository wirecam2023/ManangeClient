// RightAddUserAccView.cpp : 实现文件
//

#include "stdafx.h"
#include "MyManage.h"
#include "RightAddUserAccView.h"
#include "afxdialogex.h"


// CRightAddUserAccView 对话框

IMPLEMENT_DYNAMIC(CRightAddUserAccView, CDialog)

CRightAddUserAccView::CRightAddUserAccView(CWnd* pParent /*=NULL*/)
	: CDialog(CRightAddUserAccView::IDD, pParent)
{

}

CRightAddUserAccView::~CRightAddUserAccView()
{
}

void CRightAddUserAccView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NAME, m_name);
	//  DDX_Text(pDX, IDC_IDNUMBER, m_idnum);
	DDX_Text(pDX, IDC_CELLNUMBER, m_cellnum);
	DDX_Text(pDX, IDC_GENDER, m_gender);
	DDX_Text(pDX, IDC_USERTYPE, m_usertype);
	DDX_Text(pDX, IDC_SERIALNUM, m_serinum);
	DDX_Text(pDX, IDC_BLOODTYPE, m_bloodtype);
	DDX_Text(pDX, IDC_JOB, m_job);
	DDX_Text(pDX, IDC_PAIRDOC, m_pairdoc);
	DDX_Text(pDX, IDC_ADDRESS, m_address);
	DDX_Text(pDX, IDC_EMERCONT, m_emercont);
	DDX_Text(pDX, IDC_CONTACTNUM, m_contactnum);
	DDX_Text(pDX, IDC_SURGERY, m_surgery);
	DDX_Text(pDX, IDC_DRUG, m_drug);
	DDX_Text(pDX, IDC_DISEASE, m_disease);
	DDX_Text(pDX, IDC_FAMILY, m_family);
	DDX_Text(pDX, IDC_SMOKE, m_smoke);
	DDX_Text(pDX, IDC_DRINGK, m_drink);
	DDX_Text(pDX, IDC_BIRTH, m_birth);
	DDX_Text(pDX, IDC_PASSWORD, m_password);
	DDX_Control(pDX, IDC_USERTYPE, m_usertype1);
	DDX_Control(pDX, IDC_SUB, m_Btn);
	DDX_Control(pDX, IDC_GENDER, m_Gender);
	DDX_Control(pDX, IDC_BLOODTYPE, m_BloodType);
	DDX_Control(pDX, IDC_SMOKE, m_SmoHistory);
	DDX_Control(pDX, IDC_DRINGK, m_DrinkHistory);
	DDX_Control(pDX, IDC_GROUP, m_Group);
	DDX_Control(pDX, IDC_Group1, m_Group1);
}


BEGIN_MESSAGE_MAP(CRightAddUserAccView, CDialog)
	ON_WM_SETCURSOR()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_SUB, &CRightAddUserAccView::OnBnClickedSub)
	ON_WM_PAINT()
	ON_MESSAGE(WM_SMADDUSEREX,&CRightAddUserAccView::OnSmAddUserEx)
END_MESSAGE_MAP()


// CRightAddUserAccView 消息处理程序


BOOL CRightAddUserAccView::OnInitDialog()
{
	CDialog::OnInitDialog();

	/*m_Brush.CreateSolidBrush(theApp.m_RightColr);*/
	// TODO:  在此添加额外的初始化
	m_Btn.SetFlat(FALSE);
	m_Btn.DrawTransparent(TRUE);
	m_Btn.SetTooltipText(_T("点击提交！"));
	m_usertype1.SetCurSel(0);
	m_SmoHistory.SetCurSel(0);
	m_DrinkHistory.SetCurSel(0);
	m_BloodType.SetCurSel(0);
	m_Gender.SetCurSel(0);

	m_Group.SetBackgroundColor(theApp.m_RightColr);
	m_Group1.SetBackgroundColor(theApp.m_RightColr);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


BOOL CRightAddUserAccView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(pWnd->GetDlgCtrlID()==IDC_SUB)
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return true;
	}
	
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}


HBRUSH CRightAddUserAccView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
	/*return m_Brush;*/
}


void CRightAddUserAccView::OnBnClickedSub()
{
	// TODO: 在此添加控件通知处理程序代码
	User_BaseInfo userbaseinfoup;
	UpdateData(TRUE);
	userbaseinfoup.cellnumber=m_cellnum;
	userbaseinfoup.username=m_name;
	userbaseinfoup.gender=m_gender;
	userbaseinfoup.job=m_job;
	userbaseinfoup.bloodtype=m_bloodtype;
	userbaseinfoup.homeaddress=m_address;
	userbaseinfoup.emercontactor=m_emercont;
	userbaseinfoup.emercontactornum=m_contactnum;
	userbaseinfoup.surgeryhistory=m_surgery;
	userbaseinfoup.diseaseshistory=m_disease;
	userbaseinfoup.familyhistory=m_family;
	userbaseinfoup.drughistory=m_drug;
	userbaseinfoup.smokehistory=m_smoke;
	userbaseinfoup.drinkhistory=m_drink;
	userbaseinfoup.birth=m_birth;
	userbaseinfoup.password=m_password;

	int index;
	CString usertype;
	index=m_usertype1.GetCurSel();
	usertype.Format(_T("%d"),index);

	theApp.m_SockManageCtrl.ManAddUser(userbaseinfoup);
}


void CRightAddUserAccView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialog::OnPaint()
// 	CRect rc;
// 	GetWindowRect(rc);
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BIT_BKIN);
	CBrush Brush;
	Brush.CreatePatternBrush(&bitmap);
	CBrush* pOldBrush=dc.SelectObject(&Brush);
	dc.FillRect(CRect(0,0,783,659),&Brush);
	dc.SelectObject(pOldBrush);

}


afx_msg LRESULT CRightAddUserAccView::OnSmAddUserEx(WPARAM wParam,LPARAM lParam)
{
	vector<CString> vec_smadduser;
	theApp.SplitString(*(CString*)lParam,_T(";"),TRUE,vec_smadduser);
	MessageBox(vec_smadduser.at(1));
	return 0;
}