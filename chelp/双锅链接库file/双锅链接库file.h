
// 双锅链接库file.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// C双锅链接库fileApp:
// 有关此类的实现，请参阅 双锅链接库file.cpp
//

class C双锅链接库fileApp : public CWinApp
{
public:
	C双锅链接库fileApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern C双锅链接库fileApp theApp;