#include "stdafx.h"
#include "AboutDialog.h"

AboutDialog::AboutDialog():SHostDialog(_T("LAYOUT:PAGE_ABOUT"))
{
}

AboutDialog::~AboutDialog(void)
{
}

void AboutDialog::OnClose()
{
	SHostDialog::OnOK();
}

BOOL AboutDialog::OnInitDialog(HWND wndFocus, LPARAM lInitParam)
{
	return 0;
}
