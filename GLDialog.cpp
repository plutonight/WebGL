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
	rc_menuex.LoadMenu(_T("MENU_OPEN"));

	m_bLayoutInited = TRUE;
	return 0;
}
void GLDialog::OnBtnOpenMenu()
{
	CRect rc_menu;		// �����洢�ɶԳ��ֵĲ���
	SWindow *pBtn = FindChildByName(L"btn_menu");	// �����Ӵ�������
	if (pBtn)
	{
		pBtn->GetClientRect(&rc_menu);	// ��ȡ�Ӵ���Rect����
		ClientToScreen(&rc_menu);		// ��������ת��Ϊ��Ļ����
		rc_menuex.TrackPopupMenu(0, rc_menu.left, rc_menu.bottom, m_hWnd);
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
//TODO:��Ϣӳ��
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
