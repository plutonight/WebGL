#pragma once
#include "core/SHostDialog.h"

class AboutDialog : public SHostDialog
{
	SOUI_CLASS_NAME(AboutDialog, L"aboutdlg");

public:
	AboutDialog();
	~AboutDialog();

	void OnClose();
	BOOL OnInitDialog(HWND wndFocus, LPARAM lInitParam);

protected:
	//soui消息
	EVENT_MAP_BEGIN()
		EVENT_NAME_COMMAND(L"btn_close", OnClose)
	EVENT_MAP_END()

		//HostWnd真实窗口消息处理
	BEGIN_MSG_MAP_EX(AboutDialog)
		MSG_WM_INITDIALOG(OnInitDialog)
		CHAIN_MSG_MAP(SHostWnd)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()
};