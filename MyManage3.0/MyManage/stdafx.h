
// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件

#pragma once
#include <vector>

using std::vector;

#ifndef _SECURE_ATL
#define _SECURE_ATL 1
#endif

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // 从 Windows 头中排除极少使用的资料
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // 某些 CString 构造函数将是显式的

// 关闭 MFC 对某些常见但经常可放心忽略的警告消息的隐藏
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC 核心组件和标准组件
#include <afxext.h>         // MFC 扩展


#include <afxdisp.h>        // MFC 自动化类



#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC 对 Internet Explorer 4 公共控件的支持
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // MFC 对 Windows 公共控件的支持
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // 功能区和控件条的 MFC 支持









#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif


struct User_BaseInfo 
{
	CString cellnumber; 	//手机号0
	CString password;		//密码1
	CString username; 		//用户姓名2
	CString gender;			//性别3
	CString birth; 			//年龄4
	CString job;			//职业5
	CString bloodtype;		//血型6
	CString homeaddress;	//家庭住址7
	CString regionCode;		//区域编码(暂时还没加入)8
	CString emercontactor;	//紧急联系人9
	CString emercontactornum;//紧急联系人号码10
	CString surgeryhistory;	//手术史11
	CString diseaseshistory;//疾病史12
	CString familyhistory;	//家族史13
	CString drughistory;	//用药史14
	CString smokehistory;	//吸烟史15
	CString drinkhistory;	//饮酒史16
};

enum{cmdUserDrugRead,cmdUserDrugUpdate,cmdUserBaseInfoRead,cmdUserBaseInfoInput,cmdUserDoctorInfo,cmdUserDoctorChoose,
	cmdUserDocInfo,cmdUserHealInfoInput,cmdUserLogOn,cmdUserPlatInfoRead,cmdUserRegVery,cmdUserRegVery1,cmdUserReg,cmdUserReg1,
	cmdUserVeriCodeSend,cmdUserVeriCodeSubmit,cmdUserPWResetCode,cmdUserWel,cmdUserLatestHealRead,cmdUserHisHealRead,cmdUserRepRead,
	cmdUserExcepRead,cmdUserSendCode,cmdUserSubCode,cmdUserNewPass,cmdUserMessRead,cmdUserMessSend,cmdUserUploadFile,//用户端发送
	cmdManAddUser,cmdManQueUser,cmdManChgUserBasInfo,cmdManQueUserDrug,cmdManChgUserDrug,
	cmdManQueUserExcep,cmdManQueUserMess,cmdManQueUserRep,cmdManQueUserUpload,cmdManAddDoc,cmdManQueDoc,
	cmdManChgDocBasInfo,cmdManQueDocRep,cmdManQueDocMess,cmdManQueUser1,cmdManQueDoc1,cmdManQueCSM,cmdManAddManSR,
	cmdManQueCSR,cmdManAddManSM,cmdManQueTM,cmdManAddManTP,cmdManQueTP,cmdManAddManTM,cmdManQueDM,cmdManAddManDP,
	cmdManQueDP,cmdManAddManDM,cmdManQueMan,cmdManQue,cmdManSendMess,cmdManSendMessOT,cmdManAddSeriManu,cmdManAddSeriBat,
	cmdManQueSeri,cmdManLogin//管理端接口

} cmdClient;

enum{
	cmdServerError=-1,/*cmdServerDrugRead=0x0400*/cmdServerDrugRead,cmdSUDrugUpdate,cmdSUBaseInfoRead,cmdSUBaseInfoInput,cmdSUDoctorInfo,cmdSUDoctorChoose,cmdSUDocInfo,
	cmdSUHealInfoInput,cmdServerLogOn,cmdSUPlatInfoRead,cmdSURegVery,cmdSURegVery1,cmdSUReg,cmdSUReg1,cmdServerPWReset,
	cmdServerVeriCode,cmdSUPWResetCode,cmdSUWel,cmdSULatestHealRead,cmdSUHisHealRead,cmdSURepRead,cmdSUExcepRead,cmdSUSendCode,
	cmdSUSubCode,cmdSUNewPass,cmdSUMessRead,cmdSUMessSend,//用户端接口
	cmdSMAddUser,cmdSMQueUser,cmdSMChgUserBasInfo,cmdSMQueUserDrug,cmdSMChgUserDrug,
	cmdSMQueUserExcep,cmdSMQueUserMess,cmdSMQueUserRep,cmdSMQueUserUpload,cmdSMAddDoc,cmdSMQueDoc,
	cmdSMChgDocBasInfo,cmdSMQueDocRep,cmdSMQueDocMess,cmdSMQueUser1,cmdSMQueDoc1,cmdSMQueCSM,cmdSMAddManSR,
	cmdSMQueCSR,cmdSMAddManSM,cmdSMQueTM,cmdSMAddManTP,cmdSMQueTP,cmdSMAddManTM,cmdSMQueDM,cmdSMAddManDP,
	cmdSMQueDP,cmdSMAddManDM,cmdSMQueMan,cmdSMQue,cmdSMSendMess,cmdSMSendMessOT,cmdSMAddSeriManu,cmdSMAddSeriBat,
	cmdSMQueSeri,cmdSMLogin//管理端接口
} cmdServer;

enum{
	cmdManQueEmplyee=200,cmdManLogin1
};