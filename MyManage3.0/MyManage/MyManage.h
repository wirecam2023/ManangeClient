
// MyManage.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#define  WM_SMADDUSEREX     WM_USER+100
#define  WM_SMQUEUSER       WM_USER+101
#define  WM_SMQUEUSEREX     WM_USER+102
#define  WM_SHOWUSERINFO    WM_USER+103
#define  WM_SMCHGUSERBASINfOEX WM_USER+104
#define  WM_SMQUEUSERDRUG   WM_USER+105
#define  WM_SMQUEUSERDRUGEX WM_USER+106
#define  WM_SMCHGUSERDRUGEX WM_USER+107
#define  WM_SMQUEUSEREXCEP  WM_USER+108
#define  WM_SMADDDOCEX      WM_USER+109
#define  WM_SMQUEDOC        WM_USER+110
#define  WM_SHOWDOCINFO     WM_USER+111
#define  WM_SMQUEDOCEX      WM_USER+112
#define  WM_SMCHGDOCBASINFOEX WM_USER+113
#define  WM_SMQUEDOCREP     WM_USER+114
#define  WM_SMQUEDOCREPEX   WM_USER+115
#define  WM_SMQUEDOCMESS    WM_USER+116
#define  WM_SMQUEDOCMESSEX  WM_USER+117
#define  WM_SMQUEUSER11     WM_USER+118
#define  WM_SMQUEUSER12     WM_USER+119
#define  WM_SMQUEUSER1EX1   WM_USER+120
#define  WM_SMQUEUSER1EX2   WM_USER+121
#define  WM_SMQUEDOC11      WM_USER+122
#define  WM_SMQUEDOC12      WM_USER+123
#define  WM_SMQUEDOC1EX1    WM_USER+124
#define  WM_SMQUEDOC1EX2    WM_USER+125
#define  WM_SMQUECSM	    WM_USER+126
#define  WM_SMQUECSMEX	    WM_USER+127
#define  WM_SMADDMANSREX    WM_USER+128
#define  WM_SMQUECSR		WM_USER+129
#define  WM_SMQUECSREX		WM_USER+130
#define  WM_SMADDMANSMEX	WM_USER+131
#define  WM_SMQUETM			WM_USER+132
#define  WM_SMQUETMEX		WM_USER+133
#define  WM_SMADDMANTPEX	WM_USER+134
#define  WM_SMQUETP			WM_USER+135
#define  WM_SMQUETPEX		WM_USER+136
#define  WM_SMADDMANTMEX	WM_USER+137
#define  WM_SMQUEDM      	WM_USER+138
#define  WM_SMQUEDMEX      	WM_USER+139
#define  WM_SMADDMANDPEX    WM_USER+140
#define  WM_SMQUEDP         WM_USER+141
#define  WM_SMQUEDPEX       WM_USER+142
#define  WM_SMADDMANDMEX    WM_USER+143
#define  WM_SMQUEMAN        WM_USER+144
#define  WM_SMQUEMANEX      WM_USER+145
#define  WM_SMQUE           WM_USER+146
#define  WM_SMQUEEX         WM_USER+147
#define  WM_SMSENDMESSEX    WM_USER+148
#define  WM_SMSENDMESSOTEX  WM_USER+149
#define  WM_SMADDSERIMANUEX WM_USER+150
#define  WM_SMADDSERIBATEX  WM_USER+151
#define  WM_SMQUEUSEREXCEPEX  WM_USER+152
#define  WM_SMQUEUSERMESS   WM_USER+153
#define  WM_SMQUEUSERMESSEX WM_USER+154
#define  WM_SMQUEUSERREP    WM_USER+155
#define  WM_SMQUEUSERREPEX  WM_USER+156
#define  WM_SMQUEUSERUPLOAD WM_USER+157
#define  WM_SMQUEUSERUPLOADEX WM_USER+158
#define  WM_SMQUESERI       WM_USER+159
#define  WM_SMQUESERIEX     WM_USER+160
#define  WM_SMLOGINEX       WM_USER+161
#define  WM_SMQUEEMPLOYEE   WM_USER+162

#include "resource.h"		// 主符号
#include "RightLoginView.h"
#include "LeftPaneView.h"
#include "HeadTextView.h"
#include "RightWelView.h"
#include "TopView.h"
#include "RightAdduseraccView.h"
#include "RightChgUserAccView.h"
#include "RightAdddocaccView.h"
#include "RightChgDocAccView.h"
#include "RightAddManAccView.h"
#include "RightChgManAccView.h"
#include "RightMessSendView.h"
#include "RightAddSeriView.h"
#include "RightChgSeriView.h"
#include "MyManageDlg.h"
#include "SockManageCtrl.h"
#include "RightMessSendView1.h"
#include "RightEmployee.h"
#include "RightAuthorizeView.h"

/*#include "MyManageDlg.h"*/
// CMyManageApp:
// 有关此类的实现，请参阅 MyManage.cpp
//
DWORD WINAPI RecvProc();
class CMyManageApp : public CWinApp
{
public:
	CMyManageApp();

// 重写
public:
	virtual BOOL InitInstance();
	CMyManageDlg* m_MyManageDlg;
// 	CDialog*  m_pRightView;             //当前视图
// 	CDialog*  m_pPreView;               //需要隐藏的视图
	CRightLoginView*         m_pRightLoginView;
	CLeftPaneView*           m_LeftPaneView;
	CHeadTextView*           m_pHeadTextView;
	CRightWelView*           m_pRightWelView;
	CTopView*                m_pTopView;
	CRightAddUserAccView*    m_pRightAddUserAccView;
	CRightChgUserAccView*    m_pRightChgUserAccView;
	CRightAddDocAccView*     m_pRightAddDocAccView;
	CRightChgDocAccView*     m_pRightChgDocAccView;
	CRightAddManAccView*     m_pRightAddManAccView;
	CRightChgManAccView*     m_pRightChgManAccView;
	CRightMessSendView*      m_pRightMessSendView;
	CRightAddSeriView*       m_pRightAddSeriView;
	CRightChgSeriView*       m_pRightChgSeriView;
	CRightMessSendView1*     m_pRightMessSendView1;
	CRightEmployee*          m_pRightEmployee;
	CRightAuthorizeView*     m_pRightAuthorizeView;

	CSockManageCtrl          m_SockManageCtrl;
	/*CMyManageDlg*  m_pMyManageDlg;*/
	COLORREF m_LeftColr;
	COLORREF m_RightColr;
	CPoint   m_HintViewPoint;
	BOOL     m_LGMoveMode;
	CString  m_strRecv;
	int      m_AuthLimit;                    //设置权限
	COLORREF m_LineColor;
	int  SplitString(CString str_in, CString chSplit_in,
		BOOL bAllowNullString,vector<CString>& data); 
/*	BOOL    m_EnterkeyMode;*/
// 实现


	DECLARE_MESSAGE_MAP()

};

extern CMyManageApp theApp;