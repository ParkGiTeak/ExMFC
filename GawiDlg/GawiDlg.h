
// GawiDlg.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CGawiDlgApp:
// �� Ŭ������ ������ ���ؼ��� GawiDlg.cpp�� �����Ͻʽÿ�.
//

class CGawiDlgApp : public CWinApp
{
public:
	CGawiDlgApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CGawiDlgApp theApp;