#include "stdafx.h"
#include "GLDialog.h"
#include <shellapi.h>

GLDialog::GLDialog() : SHostWnd(_T("LAYOUT:PAGE_MAIN"))
{
	m_bLayoutInited = FALSE;
}

GLDialog::~GLDialog()
{
}

int GLDialog::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	SetMsgHandled(FALSE);
	return 0;
}

BOOL GLDialog::OnInitDialog(HWND hWnd, LPARAM lParam)
{
	m_bLayoutInited = TRUE;
	return 0;
}
void GLDialog::OnBtnOpenMenu()
{
	CRect rc_menu;		// 用来存储成对出现的参数
	SMenu menu_Setting;	// 窗口右上角设置按钮的弹出菜单
	SWindow *pBtn = FindChildByName(L"btn_menu");	// 查找子窗口名称
	if (pBtn)
	{
		pBtn->GetClientRect(&rc_menu);	// 获取子窗口Rect坐标
		ClientToScreen(&rc_menu);		// 窗口坐标转换为屏幕坐标
		menu_Setting.LoadMenuW(_T("MENU_OPEN"), _T("SMENU"));	// 读取菜单XML
		menu_Setting.TrackPopupMenu(0, rc_menu.left, rc_menu.bottom, m_hWnd);	// 显示菜单
	}
}
void GLDialog::OnCommand(UINT uNotifyCode, int nID, HWND wndCtl)
{
	if (uNotifyCode == 0)
	{
		if (nID == 102)
		{
			AboutDialog dlg;
			dlg.DoModal(m_hWnd);
		}
	}
}
//TODO:消息映射
void GLDialog::OnClose()
{
	AnimateHostWindow(200, AW_CENTER | AW_HIDE);
	CSimpleWnd::DestroyWindow();
}

void GLDialog::OnMaximize()
{
	SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE);
}
void GLDialog::OnRestore()
{
	SendMessage(WM_SYSCOMMAND, SC_RESTORE);
}
void GLDialog::OnMinimize()
{
	SendMessage(WM_SYSCOMMAND, SC_MINIMIZE);
}

void GLDialog::OnSize(UINT nType, CSize size)
{
	SetMsgHandled(FALSE);
	if (!m_bLayoutInited) return;

	SWindow *pBtnMax = FindChildByName(L"btn_max");
	SWindow *pBtnRestore = FindChildByName(L"btn_restore");
	if (!pBtnMax || !pBtnRestore) return;

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
