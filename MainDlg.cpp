// MainDlg.cpp : implementation of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MainDlg.h"	
#include <helper/SAdapterBase.h>
#include <shellapi.h>
#include <windows.h>
#include "CMD.h"

class CTestAdapterFix : public SAdapterBase
{
public:
	struct UserInfo {
		SStringT strName;
		int      iIcon;
	};

protected:

	SArray<UserInfo>    m_userInfo;
public:
	CTestAdapterFix()
	{
		UserInfo ui[] =
		{//SOUI管理员列表
			{
				_T("192.168.1.129"),
				0
			},
		};
		for (int i = 0; i < ARRAYSIZE(ui); i++)
		{
			m_userInfo.Add(ui[i]);
		}
	}
	virtual int getCount()
	{
		return m_userInfo.GetCount();
	}

	virtual void getView(int position, SWindow * pItem, pugi::xml_node xmlTemplate)
	{
		if (pItem->GetChildrenCount() == 0)
		{
			pItem->InitFromXml(xmlTemplate);
		}
		SImageWnd *pAvatar = pItem->FindChildByID2<SImageWnd>(1);
		pAvatar->SetIcon(m_userInfo.GetAt(position).iIcon);
		SWindow *pName = pItem->FindChildByID(2);
		pName->SetWindowText(m_userInfo.GetAt(position).strName);
		SWindow *pBtn = pItem->FindChildByID(3);
		pBtn->SetUserData(position);
		pBtn->GetEventSet()->subscribeEvent(EVT_CMD, Subscriber(&CTestAdapterFix::OnButtonClick, this));
		pItem->GetEventSet()->subscribeEvent(EventItemPanelClick::EventID, Subscriber(&CTestAdapterFix::OnItemClick, this));
	}

	bool OnButtonClick(EventArgs *pEvt)
	{
		SButton *pBtn = sobj_cast<SButton>(pEvt->sender);
		int iItem = pBtn->GetUserData();
		STRACE(SStringT().Format(_T("button of %d item was clicked"), iItem));
		m_userInfo.RemoveAt(iItem);
		this->notifyDataSetChanged();
		return true;
	}

	bool OnItemClick(EventArgs *pEvt)
	{
		EventItemPanelClick *pEvt2 = sobj_cast<EventItemPanelClick>(pEvt);
		SASSERT(pEvt2);
		SWindow *pPanel = sobj_cast<SWindow>(pEvt2->sender);
		CPoint pt(GET_X_LPARAM(pEvt2->lParam), GET_Y_LPARAM(pEvt2->lParam));
		SWND swnd = pPanel->SwndFromPoint(pt, FALSE);
		SWindow *pClicked = NULL;
		if (swnd) pClicked = SWindowMgr::GetWindow(swnd);

		if (pClicked && pClicked->GetID() == 3)
		{//点击删除按钮
			pEvt->bubbleUp = false;
		}
		return true;
	}

	SStringT getItemDesc(int position)
	{
		return m_userInfo.GetAt(position).strName;
	}

	UserInfo getItem(int position)
	{
		SASSERT(position >= 0 && position < m_userInfo.GetCount());
		return m_userInfo[position];
	}
};

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
	SComboView *pComboView = FindChildByName2<SComboView>(L"cbx_ipadder");
	if (pComboView)
	{
		SListView *pListView = pComboView->GetListView();
		CTestAdapterFix *pAdapter = new CTestAdapterFix;
		pListView->SetAdapter(pAdapter);
		pAdapter->Release();
		pComboView->SetCurSel(0);
	}
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
	SEdit *pEditAccount = FindChildByName2<SEdit>(L"edit_account");
	SEdit *pEditPasswd = FindChildByName2<SEdit>(L"edit_passwd");
	SComboView *pComboView = FindChildByName2<SComboView>(L"cbx_ipadder");
	SWindow *pLoginBd = FindChildByName(L"login_bg");
	SWindow *pLoging = FindChildByName(L"loading_login");
	ipAdder = pComboView->GetWindowTextW();
	account = pEditAccount->GetWindowTextW();
	passwd = pEditPasswd->GetWindowTextW();
	if (pLoginBd) pLoginBd->SetVisible(FALSE, TRUE);
	if (pLoging) pLoging->SetVisible(TRUE, TRUE);
	OnStartNotifyThread();	//启用登录子线程
}

void CMainDlg::OnBtnErrOk()
{
	SWindow * pErrLogin = FindChildByName(L"err_login");
	if (pErrLogin) pErrLogin->SetVisible(FALSE, TRUE); // 第二个参数更新界面，不然会残留
}

void CMainDlg::OnBtnNetOk()
{
	SWindow *pNetErrLogin = FindChildByName(L"err_net_login");
	if (pNetErrLogin) pNetErrLogin->SetVisible(FALSE, TRUE);
}

void CMainDlg::OnBtnCancelLogin()
{
	SWindow *pLoginBd = FindChildByName(L"login_bg");
	SWindow *pLoging = FindChildByName(L"loading_login");
	if (pLoging) pLoging->SetVisible(FALSE, TRUE);
	if (pLoginBd) pLoginBd->SetVisible(TRUE, TRUE);
	m_nRetCode = -1;
	OnStopNotifyThread();
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
	OnStopNotifyThread();
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

UINT CMainDlg::Run()
{
	TCHAR RecData[2048];
	TCHAR szFilePath[MAX_PATH + 1] = { 0 };
	TCHAR shortPathPtr[MAX_PATH + 1] = { 0 };

	if (ipAdder.IsEmpty() || account.IsEmpty() || passwd.IsEmpty())
	{
		SMessageBox(NULL, _T("错误"), _T("IP地址、用户名或密码不能为空"), MB_OK | MB_ICONEXCLAMATION);
		m_nRetCode = 3;
	}
	else
	{
		GetModuleFileName(NULL, szFilePath, MAX_PATH);
		PathRemoveFileSpec(szFilePath); // 删除文件名，只获得路径字串
		GetShortPathName(szFilePath, shortPathPtr, MAX_PATH + 1);
		_tcscat(shortPathPtr, _T("\\plink.exe -ssh -l "));
		_tcscat(shortPathPtr, S_CT2W(account).Append(_T(" -pw ")));
		_tcscat(shortPathPtr, S_CT2W(passwd).Append(_T(" -batch ")));
		_tcscat(shortPathPtr, S_CT2W(ipAdder).Append(_T(" cat /etc/issue\n")));

		CMotorolaSetDlg CMD;
		CMD.OpenCMDProcess();
		CMD.RcvDataFromPipe(RecData, 256);
		CMD.SndCmdToPipe(shortPathPtr);
		CMD.RcvDataFromPipe(RecData, 256);

		std::string Msg = CMD.TCHARtoSTRING(RecData);
		std::string NetworkErr("Network error");
		std::string LoginErr("Access denied");
		std::size_t found2 = Msg.find(LoginErr);
		std::size_t found1 = Msg.find(NetworkErr);
		CMD.CloseCMDProcess();
		if (found1 != std::string::npos)
		{
			m_nRetCode = 2;
		}
		else if (found2 != std::string::npos)
		{
			m_nRetCode = 1;
		}
		else
		{
			m_nRetCode = 0; //登录标志
		}
	}
	EventThread *pEvt = new EventThread(this);
	pEvt->nData = m_nRetCode;
	SNotifyCenter::getSingleton().FireEventAsync(pEvt);
	pEvt->Release();
	return 0;
}

void CMainDlg::OnStartNotifyThread()
{
	if (IsRunning()) return;
	SNotifyCenter::getSingleton().addEvent(EVENTID(EventThread));

	BeginThread();
}

void CMainDlg::OnStopNotifyThread()
{
	if (!IsRunning()) return;

	EndThread();

	SNotifyCenter::getSingleton().removeEvent(EventThread::EventID);
}
bool CMainDlg::OnEventThread(EventArgs *e)
{
	EventThread *pEvt = sobj_cast<EventThread>(e);
	switch (pEvt->nData)
	{
	case 0: OnClose(); break;
	case 1: {
		SWindow * pErrLogin = FindChildByName(L"err_login");
		if (pErrLogin) pErrLogin->SetVisible(TRUE, TRUE);
		OnBtnCancelLogin();
		break;
	}
	case 2: {
		SWindow *pNetErrLogin = FindChildByName(L"err_net_login");
		if (pNetErrLogin) pNetErrLogin->SetVisible(TRUE, TRUE);
		OnBtnCancelLogin();
		break; }
	case 3: {
		m_nRetCode = -1;
		OnBtnCancelLogin();
		break;
	}
	default: {
		m_nRetCode = -1;
		OnBtnCancelLogin();
		break;
	}
	}
	return true;
}

void CMainDlg::OnSize(UINT nType, CSize size)
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

