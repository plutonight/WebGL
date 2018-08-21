// MainDlg.cpp : implementation of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MainDlg.h"	

CMainDlg::CMainDlg() : SHostWnd(_T("LAYOUT:XML_MAINWND"))
{
	m_nRetCode = -1;
	m_bLayoutInited = FALSE;
}

CMainDlg::~CMainDlg()
{
}

int CMainDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	SetMsgHandled(FALSE);
	return 0;
}

BOOL CMainDlg::OnInitDialog(HWND hWnd, LPARAM lParam)
{
	m_bLayoutInited = TRUE;
	return 0;
}
//TODO:消息映射
void CMainDlg::OnBtnSetting()
{
	STabCtrl *pTab = FindChildByName2<STabCtrl>(L"tab_main");
	if (pTab)
	{
		STurn3dView *pTurn3d = FindChildByName2<STurn3dView>(L"turn3d");
		if (pTurn3d)
		{
			pTurn3d->Turn(pTab->GetPage(_T("login")), pTab->GetPage(_T("settings")), FALSE);
		}
	}
}

void CMainDlg::OnBtnSettingOK()
{
	STabCtrl *pTab = FindChildByName2<STabCtrl>(L"tab_main");
	if (pTab)
	{
		STurn3dView * pTurn3d = FindChildByName2<STurn3dView>(L"turn3d");
		if (pTurn3d)
		{
			pTurn3d->Turn(pTab->GetPage(_T("settings")), pTab->GetPage(_T("login")), TRUE);
		}
	}
}

void CMainDlg::OnBtnSettingCancel()
{
	STabCtrl *pTab = FindChildByName2<STabCtrl>(L"tab_main");
	if (pTab)
	{
		STurn3dView * pTurn3d = FindChildByName2<STurn3dView>(L"turn3d");
		if (pTurn3d)
		{
			pTurn3d->Turn(pTab->GetPage(_T("settings")), pTab->GetPage(_T("login")), TRUE);
		}
	}
}

void CMainDlg::OnBtnLogin()
{
	m_nRetCode = 0; //登录标志
	OnClose();
}

BOOL CMainDlg::OnTurn3D(EventArgs *pEvt)
{
	EventTurn3d *pEvt3dTurn = (EventTurn3d*)pEvt;
	STabCtrl *pTab = FindChildByName2<STabCtrl>(L"tab_main");
	if (pEvt3dTurn->bTurn2Front_)
	{
		pTab->SetCurSel(_T("login"));
	}
	else
	{
		pTab->SetCurSel(_T("settings"));
	}
	return TRUE;
}

void CMainDlg::OnClose()
{
	AnimateHostWindow(200, AW_CENTER | AW_HIDE);
	CSimpleWnd::DestroyWindow();
}

void CMainDlg::OnMaximize()
{
	SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE);
}
void CMainDlg::OnRestore()
{
	SendMessage(WM_SYSCOMMAND, SC_RESTORE);
}
void CMainDlg::OnMinimize()
{
	SendMessage(WM_SYSCOMMAND, SC_MINIMIZE);
}

void CMainDlg::OnSize(UINT nType, CSize size)
{
	SetMsgHandled(FALSE);
	if (!m_bLayoutInited) return;
	
	SWindow *pBtnMax = FindChildByName(L"btn_max");
	SWindow *pBtnRestore = FindChildByName(L"btn_restore");
	if(!pBtnMax || !pBtnRestore) return;
	
	if (nType == SIZE_MAXIMIZED)
	{
		pBtnRestore->SetVisible(TRUE);
		pBtnMax->SetVisible(FALSE);
	}
	else if (nType == SIZE_RESTORED)
	{
		pBtnRestore->SetVisible(FALSE);
		pBtnMax->SetVisible(TRUE);
	}
}

