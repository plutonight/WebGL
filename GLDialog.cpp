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
//TODO:ÏûÏ¢Ó³Éä
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
