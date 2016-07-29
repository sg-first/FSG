#include "stdafx.h"
#include "双锅链接库.h"

void opfile (LPCSTR canyi,LPSTR caner)
{
STARTUPINFO si; //一些必备参数设置
memset(&si, 0, sizeof(STARTUPINFO));
si.cb = sizeof(STARTUPINFO);
si.dwFlags = STARTF_USESHOWWINDOW;
si.wShowWindow = SW_SHOW;
PROCESS_INFORMATION pi; //必备参数设置结束
CreateProcess(canyi,caner,NULL,NULL,FALSE,0,NULL,NULL,&si,&pi);
}

void 双锅链接库::调用(string fsgid,string 参数1,string 密码,string 要调用的函数)
{
LPCSTR Lfsgid=fsgid.c_str();
LPCSTR L密码=密码.c_str();
LPCSTR L要调用的函数=要调用的函数.c_str();
LPCSTR L参数1=参数1.c_str();
//创建文件
fstream newssg(fsgid+".ssg");
newssg.open(fsgid+".ssg",ios::out|ios::app);
//创建ini
fstream newini(fsgid+".ini");
newini.open(fsgid+".ini",ios::out|ios::app);
//写参数
string lujing=".\\"+fsgid+".ini";
LPCSTR Llujing=lujing.c_str();
WritePrivateProfileString(Lfsgid,"密码",L密码,Llujing);
WritePrivateProfileString(Lfsgid,"要调用的函数",L要调用的函数,Llujing);
WritePrivateProfileString(Lfsgid,"参数1",L参数1,Llujing);
//启动链接库
lujing=fsgid+".fsg";
Llujing=lujing.c_str();
opfile(Llujing,NULL);
}

bool 双锅链接库::阻滞(string fsgid)
{
string lujing=fsgid+".ssg";
LPCSTR Llujing=lujing.c_str();
LPCSTR Lfsgid=fsgid.c_str();
while(1)
{
	if(_access(Llujing,0)==-1)
	{return true;}
}
}

void 双锅链接库::清除缓存(string fsgid)
{
	string lujing=fsgid+".ini";
    LPCSTR Llujing=lujing.c_str();
	LPCSTR Lfsgid=fsgid.c_str();
	DeleteFile(Llujing);
}

string 双锅链接库::读返回值(string fsgid)
{
string lujing=".\\"+fsgid+".ini";
LPCSTR Llujing=lujing.c_str();
LPCSTR Lfsgid=fsgid.c_str();
LPSTR retvar=new char[1024];
GetPrivateProfileString(Lfsgid,"返回值",NULL,retvar,1024,Llujing);
//现在开始撸类型转换
string Sretvar=(LPSTR)retvar;
delete []retvar;
//撸完了
return Sretvar;
}

string 双锅链接库::简单调用(string fsgid,string 参数1,string 密码,string 要调用的函数)
{
双锅链接库::调用(fsgid,参数1,密码,要调用的函数);
双锅链接库::阻滞(fsgid);
string ret=双锅链接库::读返回值(fsgid);
双锅链接库::清除缓存(fsgid);
return ret;
}