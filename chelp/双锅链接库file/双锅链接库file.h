
// ˫�����ӿ�file.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C˫�����ӿ�fileApp:
// �йش����ʵ�֣������ ˫�����ӿ�file.cpp
//

class C˫�����ӿ�fileApp : public CWinApp
{
public:
	C˫�����ӿ�fileApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C˫�����ӿ�fileApp theApp;