#pragma once
#include "helper/SMenu.h"
#include "AboutDialog.h"

class GLDialog : public SHostWnd
{
public:
	GLDialog();
	~GLDialog();

	void OnClose();
	void OnMaximize();
	void OnRestore();
	void OnMinimize();
	void OnSize(UINT nType, CSize size);
	int OnCreate(LPCREATESTRUCT lpCreateStruct);
	BOOL OnInitDialog(HWND wndFocus, LPARAM lInitParam);
	void OnBtnOpenMenu();

	//DUI菜单响应函数
	void OnCommand(UINT uNotifyCode, int nID, HWND wndCtl);

protected:
	//soui消息
	EVENT_MAP_BEGIN()
		EVENT_NAME_COMMAND(L"btn_close", OnClose)
		EVENT_NAME_COMMAND(L"btn_min", OnMinimize)
		EVENT_NAME_COMMAND(L"btn_max", OnMaximize)
		EVENT_NAME_COMMAND(L"btn_restore", OnRestore)
		EVENT_NAME_COMMAND(L"btn_menu", OnBtnOpenMenu)
	EVENT_MAP_END()

		//HostWnd真实窗口消息处理
		BEGIN_MSG_MAP_EX(GLDialog)
		MSG_WM_CREATE(OnCreate)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_CLOSE(OnClose)
		MSG_WM_SIZE(OnSize)
		MSG_WM_COMMAND(OnCommand)
		CHAIN_MSG_MAP(SHostWnd)
		REFLECT_NOTIFICATIONS_EX()
		END_MSG_MAP()
private:
	BOOL			m_bLayoutInited;
};

