
// LogicTree_nodever.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CLogicTree_nodeverApp:
// �� Ŭ������ ������ ���ؼ��� LogicTree_nodever.cpp�� �����Ͻʽÿ�.
//

class CLogicTree_nodeverApp : public CWinApp
{
public:
	CLogicTree_nodeverApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CLogicTree_nodeverApp theApp;