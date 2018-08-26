#include "stdafx.h"
#include "CMD.h"
#include <stdio.h>

void CMotorolaSetDlg::CharToTchar(const char * _char, TCHAR * tchar)
{
	int iLength;
	//��ȡ�ֽڳ���  
	iLength = MultiByteToWideChar(CP_ACP, 0, _char, strlen(_char) + 1, NULL, 0);
	//��_charֵ����tchar
	MultiByteToWideChar(CP_ACP, 0, _char, strlen(_char) + 1, tchar, iLength);
}

void CMotorolaSetDlg::TcharToChar(const TCHAR * tchar, char * _char)
{
	int iLength;
	//��ȡ�ֽڳ���   
	iLength = WideCharToMultiByte(CP_ACP, 0, tchar, -1, NULL, 0, NULL, NULL);
	//��tcharֵ����_char    
	WideCharToMultiByte(CP_ACP, 0, tchar, -1, _char, iLength, NULL, NULL);
}

BOOL CMotorolaSetDlg::OpenCMDProcess()
{
	SECURITY_ATTRIBUTES sa = { 0 };
	STARTUPINFO si = { 0 };

	TCHAR cmdLine[256] = { 0 };
	TCHAR wcRcvBuff[1024] = { 0 };

	sa.nLength = sizeof(sa);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = TRUE;

	//�����ܵ������������ӽ��̵����
	if (!CreatePipe(&(this->m_hReadPipe1), &(this->m_hWritePipe1), &sa, 0))
	{
		return FALSE;
	}
	//�����ܵ������������ӽ��̵�����
	if (!CreatePipe(&(this->m_hReadPipe2), &(this->m_hWritePipe2), &sa, 0))
	{
		return FALSE;
	}

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	//��GetStartupInfo��õ�ǰ���̵Ĳ���������STARTUPINFO����̫�࣬������ץ��
	GetStartupInfo(&si);
	si.hStdInput = this->m_hReadPipe2;
	si.hStdError = this->m_hWritePipe1;
	si.hStdOutput = this->m_hWritePipe1;
	//Ҫ��STARTF_USESTDHANDLES������hStdInput, hStdOutput, hStdError��Ч
	si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
	si.wShowWindow = SW_HIDE;
	GetSystemDirectory(cmdLine, sizeof(cmdLine));
	_tcscat(cmdLine, _T("\\cmd.exe"));
	
	if (CreateProcess(cmdLine, NULL, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi) == 0)
	{
		return FALSE;
	}

	CloseHandle(m_hReadPipe2);
	CloseHandle(m_hWritePipe1);

	return TRUE;

}

BOOL CMotorolaSetDlg::SndCmdToPipe(TCHAR *csCmd)
{
	BOOL bRet = FALSE;
	unsigned long ulBytesRead = 0;
	CHAR szMsg[257];
	TcharToChar(csCmd, szMsg);
	bRet = WriteFile(this->m_hWritePipe2, &szMsg, strlen(szMsg), &ulBytesRead, NULL);

	return bRet;
}

BOOL CMotorolaSetDlg::RcvDataFromPipe(TCHAR* pwcBuff, DWORD dwLen)
{
    BOOL bRet = FALSE;
    DWORD ulBytesRead = 0;
	CHAR szBuffer[257];
	CHAR oldBuff[2048] = { 0 };
    if(dwLen > sizeof(pwcBuff) && pwcBuff == NULL)
    {
        bRet = FALSE;
    }
    else
    {
        bRet = PeekNamedPipe(this->m_hReadPipe1, &szBuffer, dwLen, &ulBytesRead, 0, 0);
		while (TRUE)
		{
			bRet = ReadFile(this->m_hReadPipe1,	&szBuffer, dwLen, &ulBytesRead, NULL);

			if (!bRet) {
				break;
			}
			szBuffer[ulBytesRead] = 0;
			strcat(oldBuff, szBuffer);
			if ('>' == szBuffer[ulBytesRead - 1]) break;
		}
    }

	CharToTchar(oldBuff, pwcBuff);
	//CharToTchar(szBuffer, pwcBuff);
    return bRet;
}

BOOL SOUI::CMotorolaSetDlg::CloseCMDProcess()
{
	SndCmdToPipe(L"exit\n");
	// Wait for CONSPAWN to finish.
	WaitForSingleObject(pi.hProcess, INFINITE);

	// Close all remaining handles
	CloseHandle(pi.hProcess);
	CloseHandle(this->m_hReadPipe1);
	CloseHandle(this->m_hWritePipe2);
	return TRUE;
}

std::string CMotorolaSetDlg::TCHARtoSTRING(TCHAR *STR)
{
	int iLen = WideCharToMultiByte(CP_ACP, 0,STR, -1, NULL, 0, NULL, NULL);
	char* chRtn = new char[iLen * sizeof(char)];

	WideCharToMultiByte(CP_ACP, 0, STR, -1, chRtn, iLen, NULL, NULL);
	std::string str(chRtn);

	return str;
}