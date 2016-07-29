#include "stdafx.h"
#include <io.h>
#include <Windows.h>
#include <string>
#include <fstream>//文件读写
using namespace std;//数据类型支持

#define FSG 双锅链接库
#define Call 调用
#define ClearCache 清除缓存
#define ReadingValues 读返回值
#define EasyCall 简单调用

class 双锅链接库
{
public:
    static void 调用(string fsgid,string 参数1,string 密码,string 要调用的函数);
    static bool 阻滞(string fsgid);
    static void 清除缓存(string fsgid);
    static string 读返回值(string fsgid);
    static string 简单调用(string fsgid,string 参数1,string 密码,string 要调用的函数);
};


