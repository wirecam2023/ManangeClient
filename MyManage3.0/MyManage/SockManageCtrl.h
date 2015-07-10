#pragma once
class CSockManageCtrl
{
public:
	CSockManageCtrl(void);
	~CSockManageCtrl(void);

	BOOL InitialSocket(void);
	void CloseSocket(void);
	int  GetStringLength(CString strInput);
	BOOL SendCmd(void);

	SOCKET m_sockManage;
	SOCKADDR_IN m_addrSrv;
	int m_szOfCmd;
	CString m_strCmd;

	BOOL ManLogin(CString Name,CString Pass);
	BOOL ManAddUser(User_BaseInfo UserBasInfo);
	BOOL ManQueUser(CString quetype,CString quetext);
	BOOL ManChgUserBasInfo(CString selecteduser, User_BaseInfo  userbaseinfo);
	BOOL ManQueEmployee(CString Type,CString stTime,CString edTime);
};

