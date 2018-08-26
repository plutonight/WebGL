#pragma once
#include <string>

namespace SOUI {
	class CMotorolaSetDlg
	{
	public:
		BOOL OpenCMDProcess();
		BOOL SndCmdToPipe(TCHAR *csCmd);
		BOOL RcvDataFromPipe(TCHAR* pwcBuff, DWORD dwLen);
		BOOL CloseCMDProcess();
		void CharToTchar(const char * _char, TCHAR * tchar);
		void TcharToChar(const TCHAR * tchar, char * _char);
		std::string TCHARtoSTRING(TCHAR *STR);

	private:
		//定义四个句炳保留两个管道的信息
		HANDLE m_hReadPipe1 = NULL;
		HANDLE m_hReadPipe2 = NULL;
		HANDLE m_hWritePipe1 = NULL;
		HANDLE m_hWritePipe2 = NULL;

		PROCESS_INFORMATION pi = { 0 };
	};
}
