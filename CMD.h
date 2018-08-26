#pragma once
#include <string>

class CMotorolaSetDlg
{
public:
	BOOL OpenCMDProcess();
	BOOL SndCmdToPipe(TCHAR *csCmd);
	BOOL RcvDataFromPipe(TCHAR* pwcBuff, DWORD dwLen);
	std::string TCHARtoSTRING(TCHAR *STR);

private:
	//�����ĸ�������������ܵ�����Ϣ
	HANDLE m_hReadPipe1 = NULL;
	HANDLE m_hReadPipe2 = NULL;
	HANDLE m_hWritePipe1 = NULL;
	HANDLE m_hWritePipe2 = NULL;

	PROCESS_INFORMATION pi = { 0 };
};
