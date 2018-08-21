//stamp:0ccd8fbf4839fa6d
/*<------------------------------------------------------------------------------------------------->*/
/*该文件由uiresbuilder生成，请不要手动修改*/
/*<------------------------------------------------------------------------------------------------->*/
#pragma once
#include <res.mgr/snamedvalue.h>
#define ROBJ_IN_CPP \
namespace SOUI \
{\
    const _R R;\
    const _UIRES UIRES;\
}
namespace SOUI
{
	class _UIRES{
		public:
		class _UIDEF{
			public:
			_UIDEF(){
				XML_INIT = _T("UIDEF:XML_INIT");
			}
			const TCHAR * XML_INIT;
		}UIDEF;
		class _LAYOUT{
			public:
			_LAYOUT(){
				XML_MAINWND = _T("LAYOUT:XML_MAINWND");
				PAGE_LOGIN = _T("LAYOUT:PAGE_LOGIN");
				PAGE_SETTINGS = _T("LAYOUT:PAGE_SETTINGS");
				PAGE_MAIN = _T("LAYOUT:PAGE_MAIN");
				PAGE_INDEX = _T("LAYOUT:PAGE_INDEX");
			}
			const TCHAR * XML_MAINWND;
			const TCHAR * PAGE_LOGIN;
			const TCHAR * PAGE_SETTINGS;
			const TCHAR * PAGE_MAIN;
			const TCHAR * PAGE_INDEX;
		}LAYOUT;
		class _IMG{
			public:
			_IMG(){
				IMG_LOGIN_BORDER = _T("IMG:IMG_LOGIN_BORDER");
				BTN_LOGIN_SETTING = _T("IMG:BTN_LOGIN_SETTING");
				BTN_LOGIN_BUTTON = _T("IMG:BTN_LOGIN_BUTTON");
				BTN_KEYBOARD = _T("IMG:BTN_KEYBOARD");
				IMG_AVATARS = _T("IMG:IMG_AVATARS");
				IMG_LOGIN_BG = _T("IMG:IMG_LOGIN_BG");
				bkg_mask_png = _T("IMG:bkg_mask_png");
				sysbtn_close_png = _T("IMG:sysbtn_close_png");
				sysbtn_max_png = _T("IMG:sysbtn_max_png");
				sysbtn_min_png = _T("IMG:sysbtn_min_png");
				sysbtn_restore_png = _T("IMG:sysbtn_restore_png");
			}
			const TCHAR * IMG_LOGIN_BORDER;
			const TCHAR * BTN_LOGIN_SETTING;
			const TCHAR * BTN_LOGIN_BUTTON;
			const TCHAR * BTN_KEYBOARD;
			const TCHAR * IMG_AVATARS;
			const TCHAR * IMG_LOGIN_BG;
			const TCHAR * bkg_mask_png;
			const TCHAR * sysbtn_close_png;
			const TCHAR * sysbtn_max_png;
			const TCHAR * sysbtn_min_png;
			const TCHAR * sysbtn_restore_png;
		}IMG;
		class _ICON{
			public:
			_ICON(){
				ICON_LOGO = _T("ICON:ICON_LOGO");
			}
			const TCHAR * ICON_LOGO;
		}ICON;
		class _SMENU{
			public:
			_SMENU(){
				menu_template = _T("SMENU:menu_template");
			}
			const TCHAR * menu_template;
		}SMENU;
	};
	const SNamedID::NAMEDVALUE namedXmlID[]={
		{L"_name_start",65535},
		{L"btn_close",65538},
		{L"btn_login",65543},
		{L"btn_max",65549},
		{L"btn_min",65539},
		{L"btn_restore",65550},
		{L"btn_setting",65540},
		{L"btn_setting_cancel",65547},
		{L"btn_setting_ok",65548},
		{L"btn_test_net_set",136},
		{L"cbx_account",65542},
		{L"img_avatar",65541},
		{L"net_cfg_addr_edt",137},
		{L"net_cfg_port_edt",65546},
		{L"net_cfg_type_cmb",65545},
		{L"set_form",65544},
		{L"tab_main",65536},
		{L"turn3d",65537}		};
	class _R{
	public:
		class _name{
		public:
		_name(){
			_name_start = namedXmlID[0].strName;
			btn_close = namedXmlID[1].strName;
			btn_login = namedXmlID[2].strName;
			btn_max = namedXmlID[3].strName;
			btn_min = namedXmlID[4].strName;
			btn_restore = namedXmlID[5].strName;
			btn_setting = namedXmlID[6].strName;
			btn_setting_cancel = namedXmlID[7].strName;
			btn_setting_ok = namedXmlID[8].strName;
			btn_test_net_set = namedXmlID[9].strName;
			cbx_account = namedXmlID[10].strName;
			img_avatar = namedXmlID[11].strName;
			net_cfg_addr_edt = namedXmlID[12].strName;
			net_cfg_port_edt = namedXmlID[13].strName;
			net_cfg_type_cmb = namedXmlID[14].strName;
			set_form = namedXmlID[15].strName;
			tab_main = namedXmlID[16].strName;
			turn3d = namedXmlID[17].strName;
		}
		 const wchar_t * _name_start;
		 const wchar_t * btn_close;
		 const wchar_t * btn_login;
		 const wchar_t * btn_max;
		 const wchar_t * btn_min;
		 const wchar_t * btn_restore;
		 const wchar_t * btn_setting;
		 const wchar_t * btn_setting_cancel;
		 const wchar_t * btn_setting_ok;
		 const wchar_t * btn_test_net_set;
		 const wchar_t * cbx_account;
		 const wchar_t * img_avatar;
		 const wchar_t * net_cfg_addr_edt;
		 const wchar_t * net_cfg_port_edt;
		 const wchar_t * net_cfg_type_cmb;
		 const wchar_t * set_form;
		 const wchar_t * tab_main;
		 const wchar_t * turn3d;
		}name;

		class _id{
		public:
		const static int _name_start	=	65535;
		const static int btn_close	=	65538;
		const static int btn_login	=	65543;
		const static int btn_max	=	65549;
		const static int btn_min	=	65539;
		const static int btn_restore	=	65550;
		const static int btn_setting	=	65540;
		const static int btn_setting_cancel	=	65547;
		const static int btn_setting_ok	=	65548;
		const static int btn_test_net_set	=	136;
		const static int cbx_account	=	65542;
		const static int img_avatar	=	65541;
		const static int net_cfg_addr_edt	=	137;
		const static int net_cfg_port_edt	=	65546;
		const static int net_cfg_type_cmb	=	65545;
		const static int set_form	=	65544;
		const static int tab_main	=	65536;
		const static int turn3d	=	65537;
		}id;

		class _string{
		public:
		const static int title	=	0;
		const static int ver	=	1;
		}string;

		class _color{
		public:
		}color;

	};

#ifdef R_IN_CPP
	 extern const _R R;
	 extern const _UIRES UIRES;
#else
	 extern const __declspec(selectany) _R & R = _R();
	 extern const __declspec(selectany) _UIRES & UIRES = _UIRES();
#endif//R_IN_CPP
}
