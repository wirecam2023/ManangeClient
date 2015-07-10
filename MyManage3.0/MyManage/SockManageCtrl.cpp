#include "StdAfx.h"
#include "SockManageCtrl.h"


CSockManageCtrl::CSockManageCtrl(void)
{
	InitialSocket();
}


CSockManageCtrl::~CSockManageCtrl(void)
{
	CloseSocket();
}

BOOL CSockManageCtrl::InitialSocket(void)
{
	WORD wVersionRequested;
	WSADATA wasData;
	int err;

	wVersionRequested = MAKEWORD(1,1);

	err = WSAStartup(wVersionRequested,&wasData);
	if(err!=0)
	{
		return FALSE;
	}

	if(LOBYTE(wasData.wVersion)!=1||HIBYTE(wasData.wVersion)!=1)
	{
		WSACleanup();
		return FALSE;
	}

	m_sockManage=socket(AF_INET,SOCK_STREAM,0);

	m_addrSrv.sin_addr.S_un.S_addr=inet_addr("112.124.48.81");
/*	m_addrSrv.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");*/
	m_addrSrv.sin_family=AF_INET;
	m_addrSrv.sin_port=htons(6000);

	if(SOCKET_ERROR==connect(m_sockManage,(SOCKADDR*)&m_addrSrv,sizeof(SOCKADDR)))
	{
		AfxMessageBox(_T("连接服务器失败，请检查后重新连接！"));
		return FALSE;
	}

	return TRUE;
}

void CSockManageCtrl::CloseSocket(void)
{
	closesocket(m_sockManage);
	WSACleanup();
}

int CSockManageCtrl::GetStringLength(CString strInput)
{
	int szInput=0;
	int len=strInput.GetLength();
	for(int i=0;i<len;i++)
	{
		if(0!=HIBYTE(strInput[i]))
			szInput+=2;
		else
			szInput+=1;
	}
	return szInput;
}

BOOL CSockManageCtrl::SendCmd(void)
{
	USES_CONVERSION;
	m_szOfCmd=GetStringLength(m_strCmd);
	if(m_szOfCmd>4095)
	{
		CString szCmd;
		szCmd.Format(_T("%d,%d"),-1,m_szOfCmd+1);
		if(SOCKET_ERROR == send(m_sockManage,T2A(szCmd),szCmd.GetLength()+1,0))
		{
			AfxMessageBox(_T("发送失败，请检查网络后重新发送！"));
			return FALSE;
		}
		Sleep(200);
	}

	if(SOCKET_ERROR == send(m_sockManage,T2A(m_strCmd),m_szOfCmd+1,0))
	{
		AfxMessageBox(_T("发送失败，请检查网络后重新发送！"));
		return FALSE;
	}
	return TRUE;
}

/////////////////////发送登陆信息////////////////////////
BOOL CSockManageCtrl::ManLogin(CString Name, CString Pass)
{
	m_strCmd.Format(_T("%d;"),cmdManLogin1);
	m_strCmd+=Name;
	m_strCmd+=_T(";");
	m_strCmd+=Pass;

	return SendCmd();
}
BOOL CSockManageCtrl::ManAddUser(User_BaseInfo userBaseInfo)
{
	m_strCmd.Format(_T("%d;"),cmdManAddUser);
	m_strCmd+=userBaseInfo.username; 		//用户姓名
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.gender;			//性别
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.birth; 			//年龄（感觉用出生年月比较好）  这个起始没必要了，因为身份证号码里面有
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.cellnumber; 	//手机号
	m_strCmd+=_T("','0','");
	m_strCmd+=userBaseInfo.password;		//密码
	m_strCmd+=_T("','");	
	m_strCmd+=userBaseInfo.job;				//职业
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.bloodtype;		//血型
	m_strCmd+=_T("','");	
	m_strCmd+=userBaseInfo.homeaddress;	//家庭住址
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.regionCode;		//身份证号码
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.emercontactor;	//紧急联系人
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.emercontactornum;//紧急联系人号码
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.surgeryhistory;	//手术史
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.diseaseshistory;	//疾病史
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.familyhistory;	//家族史
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.drughistory;		//用药史
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.smokehistory;	//吸烟史
	m_strCmd+=_T("','");
	m_strCmd+=userBaseInfo.drinkhistory;	//饮酒史
	m_strCmd+=_T("'");

	return SendCmd();
}
BOOL CSockManageCtrl::ManQueUser(CString quetype, CString quetext)
{
	m_strCmd.Format(_T("%d;"),cmdManQueUser);
	m_strCmd+=quetype;
	m_strCmd+=_T(";");
	m_strCmd+=quetext;
	return SendCmd();
}

BOOL CSockManageCtrl::ManChgUserBasInfo(CString selecteduser, User_BaseInfo  userbaseinfo)
{
	m_strCmd.Format(_T("%d;"),cmdManChgUserBasInfo);
	m_strCmd+=selecteduser;
	m_strCmd+=_T(";");
	// 	m_strCmd+=userbaseinfo.serialnumber;
	// 	m_strCmd+=_T(",");
	m_strCmd+=userbaseinfo.cellnumber;
	m_strCmd+=_T(",");
	m_strCmd+=userbaseinfo.password;
	m_strCmd+=_T(",");
	m_strCmd+=userbaseinfo.username;
	m_strCmd+=_T(",");
	m_strCmd+=userbaseinfo.gender;
	m_strCmd+=_T(",");
	m_strCmd+=userbaseinfo.birth;
	m_strCmd+=_T(",");
	m_strCmd+=userbaseinfo.job;
	m_strCmd+=_T(",");
	m_strCmd+=userbaseinfo.bloodtype;
	m_strCmd+=_T(",");
	//m_strCmd+=userbaseinfo.IDcardnum;

	m_strCmd+=userbaseinfo.homeaddress;
	m_strCmd+=_T(",");
	m_strCmd+=userbaseinfo.emercontactor;
	m_strCmd+=_T(",");
	m_strCmd+=userbaseinfo.emercontactornum;
	m_strCmd+=_T(",");
	m_strCmd+=userbaseinfo.surgeryhistory;
	m_strCmd+=_T(",");
	m_strCmd+=userbaseinfo.diseaseshistory;
	m_strCmd+=_T(",");
	m_strCmd+=userbaseinfo.familyhistory;
	m_strCmd+=_T(",");
	m_strCmd+=userbaseinfo.drughistory;
	m_strCmd+=_T(",");
	m_strCmd+=userbaseinfo.smokehistory;
	m_strCmd+=_T(",");
	m_strCmd+=userbaseinfo.drinkhistory;
	m_strCmd+=_T(",");
	// 	m_strCmd+=userbaseinfo.pairdoc;
	// 	m_strCmd+=_T(",");
	// 	m_strCmd+=userbaseinfo.usertype;
	// 	m_strCmd+=_T(",");
	m_strCmd+=userbaseinfo.password;

	return SendCmd();
}

//***********************查询职员信息*************************
BOOL CSockManageCtrl::ManQueEmployee(CString Type,CString stTime,CString edTime)
{
	m_strCmd.Format(_T("%d;"),cmdManQueEmplyee);
	m_strCmd += Type;
	m_strCmd +=_T(";");
	m_strCmd +=stTime;
	m_strCmd +=_T(";");
	m_strCmd +=edTime;
	return SendCmd();
}