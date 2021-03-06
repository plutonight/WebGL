//stamp:1f17f1e644f53f10
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
				PAGE_HOME = _T("LAYOUT:PAGE_HOME");
				PAGE_WEB = _T("LAYOUT:PAGE_WEB");
				PAGE_FTP = _T("LAYOUT:PAGE_FTP");
				PAGE_SQL = _T("LAYOUT:PAGE_SQL");
				PAGE_CONTROL = _T("LAYOUT:PAGE_CONTROL");
				PAGE_SAFT = _T("LAYOUT:PAGE_SAFT");
				PAGE_FILE = _T("LAYOUT:PAGE_FILE");
				PAGE_PLAN = _T("LAYOUT:PAGE_PLAN");
				PAGE_SHELL = _T("LAYOUT:PAGE_SHELL");
				PAGE_ABOUT = _T("LAYOUT:PAGE_ABOUT");
			}
			const TCHAR * XML_MAINWND;
			const TCHAR * PAGE_LOGIN;
			const TCHAR * PAGE_SETTINGS;
			const TCHAR * PAGE_MAIN;
			const TCHAR * PAGE_INDEX;
			const TCHAR * PAGE_HOME;
			const TCHAR * PAGE_WEB;
			const TCHAR * PAGE_FTP;
			const TCHAR * PAGE_SQL;
			const TCHAR * PAGE_CONTROL;
			const TCHAR * PAGE_SAFT;
			const TCHAR * PAGE_FILE;
			const TCHAR * PAGE_PLAN;
			const TCHAR * PAGE_SHELL;
			const TCHAR * PAGE_ABOUT;
		}LAYOUT;
		class _IMG{
			public:
			_IMG(){
				IMG_LOGIN_BORDER = _T("IMG:IMG_LOGIN_BORDER");
				BTN_LOGIN_SETTING = _T("IMG:BTN_LOGIN_SETTING");
				BTN_LOGIN_BUTTON = _T("IMG:BTN_LOGIN_BUTTON");
				BTN_KEYBOARD = _T("IMG:BTN_KEYBOARD");
				IMG_LOGIN_BG = _T("IMG:IMG_LOGIN_BG");
				bkg_mask_png = _T("IMG:bkg_mask_png");
				sysbtn_close_png = _T("IMG:sysbtn_close_png");
				sysbtn_max_png = _T("IMG:sysbtn_max_png");
				sysbtn_min_png = _T("IMG:sysbtn_min_png");
				sysbtn_restore_png = _T("IMG:sysbtn_restore_png");
				sysbtn_menu_png = _T("IMG:sysbtn_menu_png");
			}
			const TCHAR * IMG_LOGIN_BORDER;
			const TCHAR * BTN_LOGIN_SETTING;
			const TCHAR * BTN_LOGIN_BUTTON;
			const TCHAR * BTN_KEYBOARD;
			const TCHAR * IMG_LOGIN_BG;
			const TCHAR * bkg_mask_png;
			const TCHAR * sysbtn_close_png;
			const TCHAR * sysbtn_max_png;
			const TCHAR * sysbtn_min_png;
			const TCHAR * sysbtn_restore_png;
			const TCHAR * sysbtn_menu_png;
		}IMG;
		class _ICON{
			public:
			_ICON(){
				ICON_LOGO = _T("ICON:ICON_LOGO");
			}
			const TCHAR * ICON_LOGO;
		}ICON;
		class _SMENUEX{
			public:
			_SMENUEX(){
				MENU_OPEN = _T("SMENUEX:MENU_OPEN");
			}
			const TCHAR * MENU_OPEN;
		}SMENUEX;
		class _PNG{
			public:
			_PNG(){
				home_icon_png = _T("PNG:home_icon_png");
				tab_icon_png = _T("PNG:tab_icon_png");
				tab_left_png = _T("PNG:tab_left_png");
				ID_BMP_MENU_SKIN = _T("PNG:ID_BMP_MENU_SKIN");
				ID_BMP_MENU_SEP = _T("PNG:ID_BMP_MENU_SEP");
				shadow_about_png = _T("PNG:shadow_about_png");
				system_close_png = _T("PNG:system_close_png");
				soft_png = _T("PNG:soft_png");
				common_shadow_png = _T("PNG:common_shadow_png");
				menu_arrow_png = _T("PNG:menu_arrow_png");
				user_list_delete_png = _T("PNG:user_list_delete_png");
				Err_Info_png = _T("PNG:Err_Info_png");
				tips_warning_png = _T("PNG:tips_warning_png");
				tips_close_png = _T("PNG:tips_close_png");
			}
			const TCHAR * home_icon_png;
			const TCHAR * tab_icon_png;
			const TCHAR * tab_left_png;
			const TCHAR * ID_BMP_MENU_SKIN;
			const TCHAR * ID_BMP_MENU_SEP;
			const TCHAR * shadow_about_png;
			const TCHAR * system_close_png;
			const TCHAR * soft_png;
			const TCHAR * common_shadow_png;
			const TCHAR * menu_arrow_png;
			const TCHAR * user_list_delete_png;
			const TCHAR * Err_Info_png;
			const TCHAR * tips_warning_png;
			const TCHAR * tips_close_png;
		}PNG;
		class _JPG{
			public:
			_JPG(){
				avatars_jpg = _T("JPG:avatars_jpg");
			}
			const TCHAR * avatars_jpg;
		}JPG;
		class _GIF{
			public:
			_GIF(){
				loading_gif = _T("GIF:loading_gif");
			}
			const TCHAR * loading_gif;
		}GIF;
	};
	const SNamedID::NAMEDVALUE namedXmlID[]={
		{L"_name_start",65535},
		{L"btn_close",65538},
		{L"btn_err_ok",65550},
		{L"btn_login",65546},
		{L"btn_login_cancel",65548},
		{L"btn_max",65558},
		{L"btn_menu",65560},
		{L"btn_min",65539},
		{L"btn_ner_err",65552},
		{L"btn_restore",65559},
		{L"btn_setting",65540},
		{L"btn_setting_cancel",65556},
		{L"btn_setting_ok",65557},
		{L"btn_test_net_set",136},
		{L"cbx_ipadder",65543},
		{L"edit_account",65544},
		{L"edit_passwd",65545},
		{L"err_login",65549},
		{L"err_net_login",65551},
		{L"img_avatar",65542},
		{L"loading_login",65547},
		{L"login_bg",65541},
		{L"net_cfg_addr_edt",137},
		{L"net_cfg_port_edt",65555},
		{L"net_cfg_type_cmb",65554},
		{L"set_form",65553},
		{L"tab_main",65536},
		{L"turn3d",65537}		};
	class _R{
	public:
		class _name{
		public:
		_name(){
			_name_start = namedXmlID[0].strName;
			btn_close = namedXmlID[1].strName;
			btn_err_ok = namedXmlID[2].strName;
			btn_login = namedXmlID[3].strName;
			btn_login_cancel = namedXmlID[4].strName;
			btn_max = namedXmlID[5].strName;
			btn_menu = namedXmlID[6].strName;
			btn_min = namedXmlID[7].strName;
			btn_ner_err = namedXmlID[8].strName;
			btn_restore = namedXmlID[9].strName;
			btn_setting = namedXmlID[10].strName;
			btn_setting_cancel = namedXmlID[11].strName;
			btn_setting_ok = namedXmlID[12].strName;
			btn_test_net_set = namedXmlID[13].strName;
			cbx_ipadder = namedXmlID[14].strName;
			edit_account = namedXmlID[15].strName;
			edit_passwd = namedXmlID[16].strName;
			err_login = namedXmlID[17].strName;
			err_net_login = namedXmlID[18].strName;
			img_avatar = namedXmlID[19].strName;
			loading_login = namedXmlID[20].strName;
			login_bg = namedXmlID[21].strName;
			net_cfg_addr_edt = namedXmlID[22].strName;
			net_cfg_port_edt = namedXmlID[23].strName;
			net_cfg_type_cmb = namedXmlID[24].strName;
			set_form = namedXmlID[25].strName;
			tab_main = namedXmlID[26].strName;
			turn3d = namedXmlID[27].strName;
		}
		 const wchar_t * _name_start;
		 const wchar_t * btn_close;
		 const wchar_t * btn_err_ok;
		 const wchar_t * btn_login;
		 const wchar_t * btn_login_cancel;
		 const wchar_t * btn_max;
		 const wchar_t * btn_menu;
		 const wchar_t * btn_min;
		 const wchar_t * btn_ner_err;
		 const wchar_t * btn_restore;
		 const wchar_t * btn_setting;
		 const wchar_t * btn_setting_cancel;
		 const wchar_t * btn_setting_ok;
		 const wchar_t * btn_test_net_set;
		 const wchar_t * cbx_ipadder;
		 const wchar_t * edit_account;
		 const wchar_t * edit_passwd;
		 const wchar_t * err_login;
		 const wchar_t * err_net_login;
		 const wchar_t * img_avatar;
		 const wchar_t * loading_login;
		 const wchar_t * login_bg;
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
		const static int btn_err_ok	=	65550;
		const static int btn_login	=	65546;
		const static int btn_login_cancel	=	65548;
		const static int btn_max	=	65558;
		const static int btn_menu	=	65560;
		const static int btn_min	=	65539;
		const static int btn_ner_err	=	65552;
		const static int btn_restore	=	65559;
		const static int btn_setting	=	65540;
		const static int btn_setting_cancel	=	65556;
		const static int btn_setting_ok	=	65557;
		const static int btn_test_net_set	=	136;
		const static int cbx_ipadder	=	65543;
		const static int edit_account	=	65544;
		const static int edit_passwd	=	65545;
		const static int err_login	=	65549;
		const static int err_net_login	=	65551;
		const static int img_avatar	=	65542;
		const static int loading_login	=	65547;
		const static int login_bg	=	65541;
		const static int net_cfg_addr_edt	=	137;
		const static int net_cfg_port_edt	=	65555;
		const static int net_cfg_type_cmb	=	65554;
		const static int set_form	=	65553;
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
