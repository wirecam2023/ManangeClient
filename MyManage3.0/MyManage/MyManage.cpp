
// MyManage.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "MyManage.h"
#include "MyManageDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyManageApp

BEGIN_MESSAGE_MAP(CMyManageApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CMyManageApp 构造

CMyManageApp::CMyManageApp()
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
	m_LeftColr=RGB(101,165,51);
	m_RightColr=RGB(224,235,219);
	m_HintViewPoint=0;
	m_LineColor=RGB(128,138,135);
/*	m_EnterkeyMode=FALSE;*/
	/*m_pRightView=NULL;*/
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CMyManageApp 对象

CMyManageApp theApp;


// CMyManageApp 初始化

BOOL CMyManageApp::InitInstance()
{
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// 创建 shell 管理器，以防对话框包含
	// 任何 shell 树视图控件或 shell 列表视图控件。
	CShellManager *pShellManager = new CShellManager;

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));

	CMyManageDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: 在此放置处理何时用
		//  “确定”来关闭对话框的代码
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: 在此放置处理何时用
		//  “取消”来关闭对话框的代码
	}

	// 删除上面创建的 shell 管理器。
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。
	return FALSE;
}

int  CMyManageApp::SplitString(CString str_in, CString chSplit_in,
	BOOL bAllowNullString,vector<CString>& data)
{
	data.clear();

	str_in.TrimLeft();
	str_in.TrimRight();
	if(str_in.GetLength()==0)
       return 0;
	if(chSplit_in.GetLength()==0)
	{
		data.push_back(str_in);
		return 1;
	}
	CString s;
	int n;
	do
	{
		n = str_in.Find(chSplit_in);
		if(n>0)
		{
			data.push_back(str_in.Left(n));
			str_in = str_in.Right(str_in.GetLength()-n-chSplit_in.GetLength());
			str_in.TrimLeft();
		}
		else if(n==0)
		{
			if(bAllowNullString)
				data.push_back(_T(""));
			str_in = str_in.Right(str_in.GetLength()-chSplit_in.GetLength());
			str_in.TrimLeft();
		}
		else
		{
			if(str_in.GetLength()>0||bAllowNullString)
				data.push_back(str_in);
			break;
		}
	}
	while(1);
	return data.size();
}


//////////////////自定义消息循环//////////////////////
DWORD WINAPI RecvProc()
{
	USES_CONVERSION;

	int count = 0;
	vector<CString> vec_str;
	while(1)
	{
		char charRecv[4096];
		int szData=recv(theApp.m_SockManageCtrl.m_sockManage,charRecv,4096,0);
		if(0!=szData&&-1!=szData)
		{
			theApp.m_strRecv=A2T(charRecv);
			int vec_str_cmd;
			theApp.SplitString(theApp.m_strRecv,_T(";"),TRUE,vec_str);
			vec_str_cmd=_ttoi(vec_str.at(0));
			
			switch(vec_str_cmd)
			{
			case -1:
				AfxMessageBox(vec_str[1]);
				break;
			case cmdSMAddUser:
				::PostMessage(theApp.m_pRightAddUserAccView->m_hWnd,WM_SMADDUSEREX,0,(LPARAM)&theApp.m_strRecv);
				break;
			case cmdSMQueUser:
				::PostMessage(theApp.m_pRightChgUserAccView->m_hWnd,WM_SMQUEUSER,0,(LPARAM)&theApp.m_strRecv);

				break;
				// 			case cmdSMQueUserEx:
				// 				::PostMessage(theApp.m_prightchguseraccview->m_hWnd,WM_SMQUEUSEREX,0,(LPARAM)&theApp.strRecv);
				//  				break;
				//  			case cmdSMChgUserBasInfoEx:
				//  				::PostMessage(theApp.m_prightquebasview->m_hWnd,WM_SMCHGUSERBASINfOEX,0,(LPARAM)theApp.vecstr);
				//  				break;
			case cmdSMQueUserDrug:
				::PostMessage(theApp.m_pRightChgUserAccView->m_RightQueDrugView.m_hWnd,WM_SMQUEUSERDRUG,0,(LPARAM)&theApp.m_strRecv);
				break;
				//  			case cmdSMQueUserDrugEx:
				//  				::PostMessage(theApp.m_prightquedrugview->m_hWnd,WM_SMQUEUSERDRUGEX,0,(LPARAM)theApp.vecstr);
				// 				break;
				//  			case cmdSMChgUserDrugEx:
				//  				::PostMessage(theApp.m_prightquedrugview->m_hWnd,WM_SMCHGUSERDRUGEX,0,(LPARAM)theApp.vecstr);
				//  				break;
			case cmdSMQueUserExcep:
				::PostMessage(theApp.m_pRightChgUserAccView->m_RightQueExecpView.m_hWnd,WM_SMQUEUSEREXCEP,0,(LPARAM)&theApp.m_strRecv);
				break;
				// 			case cmdSMQueUserExcepEx:
				// 				::PostMessage(theApp.m_prightqueexcepview->m_hWnd,WM_SMQUEUSEREXCEPEX,0,(LPARAM)theApp.vecstr);
				// 				break;
			case cmdSMQueUserMess:
				::PostMessage(theApp.m_pRightChgUserAccView->m_RightQueMessView.m_hWnd,WM_SMQUEUSERMESS,0,(LPARAM)&theApp.m_strRecv);
				break;
				// 			case cmdSMQueUserMessEx:
				// 				::PostMessage(theApp.m_prightquemessview->m_hWnd,WM_SMQUEUSERMESSEX,0,(LPARAM)theApp.vecstr);
				// 				break;
			case cmdSMQueUserRep:
				::PostMessage(theApp.m_pRightChgUserAccView->m_RightQueRepView.m_hWnd,WM_SMQUEUSERREP,0,(LPARAM)&theApp.m_strRecv);
				break;
				// 			case cmdSMQueUserRepEx:
				// 				::PostMessage(theApp.m_prightquerepview->m_hWnd,WM_SMQUEUSERREPEX,0,(LPARAM)theApp.vecstr);
				// 				break;
			case cmdSMQueUserUpload:
				::PostMessage(theApp.m_pRightChgUserAccView->m_RightQueUpLoadView.m_hWnd,WM_SMQUEUSERUPLOAD,0,(LPARAM)&theApp.m_strRecv);
				break;
				// 			case cmdSMQueUserUploadEx:
				// 				::PostMessage(theApp.m_prightqueuploadview->m_hWnd,WM_SMQUEUSERUPLOADEX,0,(LPARAM)theApp.vecstr);
				// 				break;
				//  			case cmdSMAddDocEx:
				// 				::PostMessage(theApp.m_prightadddocaccview->m_hWnd,WM_SMADDDOCEX,0,(LPARAM)theApp.vecstr);
				//  				break;
			case cmdSMQueDoc:
				::PostMessage(theApp.m_pRightChgDocAccView->m_hWnd,WM_SMQUEDOC,0,(LPARAM)&theApp.m_strRecv);
				break;
				//  			case cmdSMQueDocEx:
				//  				::PostMessage(theApp.m_prightchgdocaccview->m_hWnd,WM_SMQUEDOCEX,0,(LPARAM)theApp.vecstr);
				//  				break;
				//  			case cmdSMChgDocBasInfoEx:
				//  				::PostMessage(theApp.m_pdocbasview->m_hWnd,WM_SMCHGDOCBASINFOEX,0,(LPARAM)theApp.vecstr);
				//  				break;
			case cmdSMQueDocRep:
				::PostMessage(theApp.m_pRightChgDocAccView->m_RightDocDiagView.m_hWnd,WM_SMQUEDOCREP,0,(LPARAM)&theApp.m_strRecv);
				break;
				//  			case cmdSMQueDocRepEx:
				//  				::PostMessage(theApp.m_pdocdiagview->m_hWnd,WM_SMQUEDOCREPEX,0,(LPARAM)theApp.vecstr);
				//  				break;
			case cmdSMQueDocMess:
				::PostMessage(theApp.m_pRightChgDocAccView->m_RightDocMessView.m_hWnd,WM_SMQUEDOCMESS,0,(LPARAM)&theApp.m_strRecv);
				break;
				//  			case cmdSMQueDocMessEx:
				//  				::PostMessage(theApp.m_pdocmessview->m_hWnd,WM_SMQUEDOCMESSEX,0,(LPARAM)theApp.vecstr);
				//  				break;

			case cmdSMQueUser1:
				if (vec_str.at(1)==_T("1"))
				{
					::PostMessage(theApp.m_pRightAddManAccView->m_RightAuthCS1View.m_hWnd,WM_SMQUEUSER11,0,(LPARAM)&theApp.m_strRecv);
				}
				else
				{
					::PostMessage(theApp.m_pRightAddManAccView->m_RightAuthCS2View.m_hWnd,WM_SMQUEUSER12,0,(LPARAM)&theApp.m_strRecv);
				}
				break;

				// 			case cmdSMQueUser1Ex:
				// 				if (vec_str.at(1)==_T("1"))
				// 				{
				// 					::PostMessage(theApp.m_pauthcs1view->m_hWnd,WM_SMQUEUSER1EX1,0,(LPARAM)theApp.vecstr);
				// 				}
				// 				else
				// 				{
				// 					::PostMessage(theApp.m_pauthcs2view->m_hWnd,WM_SMQUEUSER1EX2,0,(LPARAM)theApp.vecstr);
				// 				}
				// 				break;

			case cmdSMQueDoc1:
				if (vec_str.at(1)==_T("1"))
				{
					::PostMessage(theApp.m_pRightAddManAccView->m_RightAuthDoc1View.m_hWnd,WM_SMQUEDOC11,0,(LPARAM)&theApp.m_strRecv);
				}
				else
				{
					::PostMessage(theApp.m_pRightAddManAccView->m_RightAuthDoc2View.m_hWnd,WM_SMQUEDOC12,0,(LPARAM)&theApp.m_strRecv);
				}
				break;

				// 			case cmdSMQueDoc1Ex:
				// 				if (vec_str.at(1)==_T("1"))
				// 				{
				// 					::PostMessage(theApp.m_pauthcs1view->m_hWnd,WM_SMQUEDOC1EX1,0,(LPARAM)theApp.vecstr);
				// 				}
				// 				else
				// 				{
				// 					::PostMessage(theApp.m_pauthcs2view->m_hWnd,WM_SMQUEDOC1EX2,0,(LPARAM)theApp.vecstr);
				// 				}
				// 				break;

			case cmdSMQueCSM:
				::PostMessage(theApp.m_pRightAddManAccView->m_RightAuthCS1View.m_hWnd,WM_SMQUECSM,0,(LPARAM)&theApp.m_strRecv);
				break;
				// 			case cmdSMQueCSMEx:
				// 				::PostMessage(theApp.m_pauthcs1view->m_hWnd,WM_SMQUECSMEX,0,(LPARAM)theApp.vecstr);
				// 				break;
				//  			case cmdSMAddManSREx:
				// 				::PostMessage(theApp.m_rightaddmanaccview->m_hWnd,WM_SMADDMANSREX,0,(LPARAM)theApp.vecstr);
				//  				break;
			case cmdSMQueCSR:
				::PostMessage(theApp.m_pRightAddManAccView->m_RightAuthCS2View.m_hWnd,WM_SMQUECSR,0,(LPARAM)&theApp.m_strRecv);
				break;
				// 			case cmdSMQueCSREx:
				// 				::PostMessage(theApp.m_pauthcs2view->m_hWnd,WM_SMQUECSREX,0,(LPARAM)theApp.vecstr);
				// 				break;
				// 			case cmdSMAddManSMEx:
				// 				::PostMessage(theApp.m_rightaddmanaccview->m_hWnd,WM_SMADDMANSMEX,0,(LPARAM)theApp.vecstr);
				// 				break;
			case cmdSMQueTM:
				::PostMessage(theApp.m_pRightAddManAccView->m_RightAuthTech1View.m_hWnd,WM_SMQUETM,0,(LPARAM)&theApp.m_strRecv);
				break;
				// 			case cmdSMQueTMEx:
				// 				::PostMessage(theApp.m_pauthtech1view->m_hWnd,WM_SMQUETMEX,0,(LPARAM)theApp.vecstr);
				// 				break;
				// 			case cmdSMAddManTPEX:
				// 				::PostMessage(theApp.m_rightaddmanaccview->m_hWnd,WM_SMADDMANTPEX,0,(LPARAM)theApp.vecstr);
				// 				break;
			case cmdSMQueTP:
				::PostMessage(theApp.m_pRightAddManAccView->m_RightAuthTech2View.m_hWnd,WM_SMQUETP,0,(LPARAM)&theApp.m_strRecv);
				break;
				// 			case cmdSMQueTPEx:
				// 				::PostMessage(theApp.m_pauthtech2view->m_hWnd,WM_SMQUETPEX,0,(LPARAM)theApp.vecstr);
				// 				break;
				// 			case cmdSMAddManTMEx:
				// 				::PostMessage(theApp.m_rightaddmanaccview->m_hWnd,WM_SMADDMANTMEX,0,(LPARAM)theApp.vecstr);
				// 				break;
			case cmdSMQueDM:
				::PostMessage(theApp.m_pRightAddManAccView->m_RightAuthDoc1View.m_hWnd,WM_SMQUEDM,0,(LPARAM)&theApp.m_strRecv);
				break;
				// 			case cmdSMQueDMEx:
				// 				::PostMessage(theApp.m_pauthdoc1view->m_hWnd,WM_SMQUEDMEX,0,(LPARAM)theApp.vecstr);
				// 				break;	
				// 			case cmdSMAddManDPEx:
				// 				::PostMessage(theApp.m_rightaddmanaccview->m_hWnd,WM_SMADDMANDPEX,0,(LPARAM)theApp.vecstr);
				// 				break;
			case cmdSMQueDP:
				::PostMessage(theApp.m_pRightAddManAccView->m_RightAuthDoc2View.m_hWnd,WM_SMQUEDP,0,(LPARAM)&theApp.m_strRecv);
				break;
				// 			case cmdSMQueDPEx:
				// 				::PostMessage(theApp.m_pauthdoc2view->m_hWnd,WM_SMQUEDPEX,0,(LPARAM)theApp.vecstr);
				// 				break;
				// 			case cmdSMAddManDMEx:
				// 				::PostMessage(theApp.m_rightaddmanaccview->m_hWnd,WM_SMADDMANDMEX,0,(LPARAM)theApp.vecstr);
				// 				break;
			case cmdSMQueMan:
				::PostMessage(theApp.m_pRightAddManAccView->m_hWnd,WM_SMQUEMAN,0,(LPARAM)&theApp.m_strRecv);
				break;
				// 			case cmdSMQueManEx:
				// 				::PostMessage(theApp.m_rightaddmanaccview->m_hWnd,WM_SMQUEMANEX,0,(LPARAM)theApp.vecstr);
				// 				break;

			case cmdSMQue:
				::PostMessage(theApp.m_pRightMessSendView->m_hWnd,WM_SMQUE,0,(LPARAM)&theApp.m_strRecv);
				break;
				// 			case cmdSMSendMessEx:
				// 				::PostMessage(theApp.m_pmesssendview->m_hWnd,WM_SMSENDMESSEX,0,(LPARAM)theApp.vecstr);
				// 				break;
				// 			case cmdSMSendMessOTEx:
				// 				::PostMessage(theApp.m_pmesssendview->m_hWnd,WM_SMSENDMESSOTEX,0,(LPARAM)theApp.vecstr);
				// 				break;
				// 			case cmdSMAddSeriManuEx:
				// 				::PostMessage(theApp.m_pserimanview->m_hWnd,WM_SMADDSERIMANUEX,0,(LPARAM)theApp.vecstr);
				// 				break;
				// 			case cmdSMAddSeriBatEx:
				// 				::PostMessage(theApp.m_pseribatview->m_hWnd,WM_SMADDSERIBATEX,0,(LPARAM)theApp.vecstr);
				// 				break;
			case cmdSMQueSeri:
				::PostMessage(theApp.m_pRightAddSeriView->m_hWnd,WM_SMQUESERI,0,(LPARAM)&theApp.m_strRecv);	
				break;
				// 			case cmdSMQueSeriEx:
				// 				::PostMessage(theApp.m_prightchgseriview->m_hWnd,WM_SMQUESERIEX,0,(LPARAM)theApp.vecstr);
				// 				break;
			case cmdSMLogin:
				::PostMessage(theApp.m_pRightLoginView->m_hWnd,WM_SMLOGINEX/*0x04A1*//*WM_SMLOGINEX*/,0,(LPARAM)&theApp.m_strRecv);
				break;
			case cmdManQueEmplyee:
				::PostMessage(theApp.m_pRightEmployee->m_hWnd,WM_SMQUEEMPLOYEE,0,(LPARAM)&theApp.m_strRecv);
				break;
			default:
				break;
			}
		}
		else
			break;
	}
	return 1;
			
}

