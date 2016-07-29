#include "stdafx.h"
#include <fstream>//文件读写
using namespace std;//数据类型支持
#include <io.h>
#include <Windows.h>
#include <string>

#define FSG 双锅链接库
#define Call 调用
#define ClearCache 清除缓存
#define ReadingValues 读返回值
#define EasyCall 简单调用

class 双锅链接库
{
public:
	    static void 调用(CString fsgid,CString 参数1,CString 密码,CString 要调用的函数);
	    static bool 阻滞(CString fsgid);
        static void 清除缓存(CString fsgid);
        static CString 读返回值(CString fsgid);
        static CString 简单调用(CString fsgid,CString 参数1,CString 密码,CString 要调用的函数);
};


