
// test_nomainframe.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Ctest_nomainframeApp:
// �йش����ʵ�֣������ test_nomainframe.cpp
//

class Ctest_nomainframeApp : public CWinApp
{
public:
	Ctest_nomainframeApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Ctest_nomainframeApp theApp;