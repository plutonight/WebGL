// MainDlg.h : interface of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////
#pragma once

#include "..\controls.extend\STurn3DView.h"
#include "ThreadObject.h"

//演示使用SNotifyCenter的异步事件
class EventThread : public TplEventArgs<EventThread>
{
	SOUI_CLASS_NAME(EventThread, L"on_event_thread")
public:
	EventThread(SObject *pSender) :TplEventArgs<EventThread>(pSender) {}
	enum { EventID = EVT_EXTERNAL_BEGIN + 30000 };

	int nData;
};

class CMainDlg : public SHostWnd
			   , public CThreadObject	//线程对象
			   , public TAutoEventMapReg<CMainDlg>	//通知中心自动注册
{
public:
	CMainDlg();
	~CMainDlg();

	void OnBtnSetting();
	void OnBtnSettingOK();
	void OnBtnSettingCancel();
	void OnBtnLogin();
	void OnBtnErrOk();
	void OnBtnNetOk();
	void OnBtnCancelLogin();
	void OnClose();
	void OnMaximize();
	void OnRestore();
	void OnMinimize();

	virtual UINT Run();

	//Event Sender ID
	enum { SENDER_ID = 30000 };
	virtual int GetID() const { return SENDER_ID; }
	void OnStartNotifyThread();
	void OnStopNotifyThread();
	bool OnEventThread(EventArgs *e);

	void OnSize(UINT nType, CSize size);
	int OnCreate(LPCREATESTRUCT lpCreateStruct);
	BOOL OnInitDialog(HWND wndFocus, LPARAM lInitParam);
	BOOL OnTurn3D(EventArgs *pEvt);
	int  GetReturnCode() { return m_nRetCode; }

protected:
	//soui消息
	EVENT_MAP_BEGIN()
		EVENT_NAME_COMMAND(L"btn_close", OnClose)
		//EVENT_ID_COMMAND(R.id.btn_close,OnClose)
		EVENT_NAME_COMMAND(L"btn_min", OnMinimize)
		EVENT_NAME_COMMAND(L"btn_max", OnMaximize)
		EVENT_NAME_COMMAND(L"btn_restore", OnRestore)
		EVENT_NAME_COMMAND(L"btn_setting", OnBtnSetting)
		EVENT_NAME_COMMAND(L"btn_setting_ok", OnBtnSettingOK)
		EVENT_NAME_COMMAND(L"btn_setting_cancel", OnBtnSettingCancel)
		EVENT_NAME_COMMAND(L"btn_login", OnBtnLogin)
		EVENT_NAME_COMMAND(L"btn_err_ok", OnBtnErrOk)
		EVENT_NAME_COMMAND(L"btn_ner_err", OnBtnNetOk)
		EVENT_NAME_COMMAND(L"btn_login_cancel", OnBtnCancelLogin)
		EVENT_NAME_HANDLER(L"turn3d", EventTurn3d::EventID, OnTurn3D);

		EVENT_ID_HANDLER(SENDER_ID, EventThread::EventID, OnEventThread)
	EVENT_MAP_END()
		
	//HostWnd真实窗口消息处理
	BEGIN_MSG_MAP_EX(CMainDlg)
		MSG_WM_CREATE(OnCreate)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_CLOSE(OnClose)
		MSG_WM_SIZE(OnSize)
		CHAIN_MSG_MAP(SHostWnd)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()
private:
	BOOL			m_bLayoutInited;	
	int             m_nRetCode;
	SStringT		account;
	SStringT		ipAdder;
	SStringT		passwd;
};
