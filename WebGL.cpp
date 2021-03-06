// dui-demo.cpp : main source file
//

#include "stdafx.h"
#include "MainDlg.h"
#include "../controls.extend/SChromeTabCtrl.h"
#include "../controls.extend/gif/SGifPlayer.h"
#include "GLDialog.h"
//从PE文件加载，注意从文件加载路径位置
#define RES_TYPE 0
//#define SYSRES_TYPE 0
// #define RES_TYPE 0   //PE
// #define RES_TYPE 1   //ZIP
// #define RES_TYPE 2   //7z
// #define RES_TYPE 2   //文件
//去掉多项支持，以免代码显得混乱
#if (RES_TYPE==1)
#include "resprovider-zip\zipresprovider-param.h"
#else 
#if (RES_TYPE==2)
#include "resprovider-7zip\zip7resprovider-param.h"
#endif
#endif
#ifdef _DEBUG
#define SYS_NAMED_RESOURCE _T("soui-sys-resourced.dll")
#else
#define SYS_NAMED_RESOURCE _T("soui-sys-resource.dll")
#endif


//定义唯一的一个R,UIRES对象,ROBJ_IN_CPP是resource.h中定义的宏。
ROBJ_IN_CPP

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPTSTR lpstrCmdLine, int /*nCmdShow*/)
{
	//必须要调用OleInitialize来初始化运行环境
	HRESULT hRes = OleInitialize(NULL);
	SASSERT(SUCCEEDED(hRes));

	int nRet = 0;

	//切换到当前目录
	SComMgr *pComMgr = new SComMgr;
	TCHAR szCurrentDir[MAX_PATH] = { 0 };
	GetModuleFileName(NULL, szCurrentDir, sizeof(szCurrentDir));

	LPTSTR lpInsertPos = _tcsrchr(szCurrentDir, _T('\\'));
#ifdef _DEBUG
	_tcscpy(lpInsertPos + 1, _T("..\\WebGL"));
#else
	_tcscpy(lpInsertPos + 1, _T("\0"));
#endif
	SetCurrentDirectory(szCurrentDir);
	{
		//定义一组类SOUI系统中使用的类COM组件
		//CAutoRefPtr是一个SOUI系统中使用的智能指针类
		BOOL bLoaded = FALSE;
		CAutoRefPtr<IImgDecoderFactory> pImgDecoderFactory;	//图片解码器
		CAutoRefPtr<IRenderFactory> pRenderFactory;	//UI渲染模块
		bLoaded = pComMgr->CreateRender_Skia((IObjRef**)&pRenderFactory);	//使用Skia渲染引擎
		SASSERT_FMT(bLoaded, _T("load interface [render] failed!"));
		bLoaded = pComMgr->CreateImgDecoder((IObjRef**)&pImgDecoderFactory);
		SASSERT_FMT(bLoaded, _T("load interface [%s] failed!"), _T("imgdecoder"));
		//为渲染模块设置它需要引用的图片解码模块
		pRenderFactory->SetImgDecoderFactory(pImgDecoderFactory);
		//定义一个唯一的SApplication对象，SApplication管理整个应用程序的资源
		SApplication *theApp = new SApplication(pRenderFactory, hInstance);
#ifdef _DEBUG
		//选择了仅在Release版本打包资源则系统资源在DEBUG下始终使用DLL加载
		{
			HMODULE hModSysResource = LoadLibrary(SYS_NAMED_RESOURCE);
			if (hModSysResource)
			{
				CAutoRefPtr<IResProvider> sysResProvider;
				CreateResProvider(RES_PE, (IObjRef**)&sysResProvider);
				sysResProvider->Init((WPARAM)hModSysResource, 0);
				theApp->LoadSystemNamedResource(sysResProvider);
				FreeLibrary(hModSysResource);
			}
			else
			{
				SASSERT(0);
			}
		}
#else		
		//钩选了复制系统资源选项
		{
			CAutoRefPtr<IResProvider> pSysResProvider;
			CreateResProvider(RES_PE, (IObjRef**)&pSysResProvider);
			bLoaded = pSysResProvider->Init((WPARAM)hInstance, 0);
			SASSERT(bLoaded);
			bLoaded = theApp->LoadSystemNamedResource(pSysResProvider);
			SASSERT(bLoaded);
		}
#endif
		//控件注册要放到AddResProvider前
		//向SApplication系统中注册由外部扩展的控件及SkinObj类
		theApp->RegisterWindowClass<STurn3dView>();
		theApp->RegisterWindowClass<SChromeTabCtrl>();//注册ChromeTabCtrl
		theApp->RegisterWindowClass<SGifPlayer>();
		theApp->RegisterSkinClass<SSkinGif>();

		//如果需要在代码中使用R::id::namedid这种方式来使用控件必须要这一行代码
		theApp->InitXmlNamedID(namedXmlID, ARRAYSIZE(namedXmlID), TRUE);

		SSkinGif::Gdiplus_Startup();

		CAutoRefPtr<IResProvider>   pResProvider;

#ifdef _DEBUG		
		//选择了仅在Release版本打包资源则在DEBUG下始终使用文件加载
		{
			CreateResProvider(RES_FILE, (IObjRef**)&pResProvider);
			bLoaded = pResProvider->Init((LPARAM)_T("uires"), 0);
			SASSERT(bLoaded);
		}
#else
		{
			CreateResProvider(RES_PE, (IObjRef**)&pResProvider);
			bLoaded = pResProvider->Init((WPARAM)hInstance, 0);
			SASSERT(bLoaded);
		}
#endif
		//将创建的IResProvider交给SApplication对象
		theApp->AddResProvider(pResProvider);

		SNotifyCenter *pNotifyCenter = new SNotifyCenter;

		// BLOCK: Run application
		{
			CMainDlg dlgMain;
			dlgMain.Create(GetActiveWindow());
			dlgMain.SendMessage(WM_INITDIALOG);
			dlgMain.CenterWindow(dlgMain.m_hWnd);
			dlgMain.ShowWindow(SW_SHOWNORMAL);
			nRet = theApp->Run(dlgMain.m_hWnd);

			if (dlgMain.GetReturnCode() == 0)
			{
				GLDialog glMain;
				glMain.Create(GetActiveWindow(), 0, 0, 0, 0);
				glMain.SendMessage(WM_INITDIALOG);
				glMain.CenterWindow(glMain.m_hWnd);
				glMain.ShowWindow(SW_SHOWNORMAL);
				nRet = theApp->Run(glMain.m_hWnd);
			}
		}
		delete pNotifyCenter;
		theApp->UnregisterWindowClass<SGifPlayer>();
		SSkinGif::Gdiplus_Shutdown();

		delete theApp;
	}

	delete pComMgr;

	OleUninitialize();
	return nRet;
}
