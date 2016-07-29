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

void 双锅链接库::调用(CString fsgid,CString 参数1,CString 密码,CString 要调用的函数)
{
//创建文件
fstream newssg(fsgid+".ssg");
newssg.open(fsgid+".ssg",ios::out|ios::app);
//创建ini
fstream newini(fsgid+".ini");
newini.open(fsgid+".ini",ios::out|ios::app);
//写参数
WritePrivateProfileString(fsgid,"密码",密码,".\\"+fsgid+".ini");
WritePrivateProfileString(fsgid,"要调用的函数",要调用的函数,".\\"+fsgid+".ini");
WritePrivateProfileString(fsgid,"参数1",参数1,".\\"+fsgid+".ini");
//启动链接库
opfile(fsgid+".fsg",NULL);
}

bool 双锅链接库::阻滞(CString fsgid)
{
while(1)
{
	if(_access(fsgid+".ssg",0)==-1)
	{return true;}
}
}

void 双锅链接库::清除缓存(CString fsgid)
{DeleteFile(fsgid+".ini");}

CString 双锅链接库::读返回值(CString fsgid)
{
CString retvar;
GetPrivateProfileString(fsgid,"返回值",NULL,retvar.GetBuffer(1024),1024,".\\"+fsgid+".ini");
return retvar;
}

CString 双锅链接库::简单调用(CString fsgid,CString 参数1,CString 密码,CString 要调用的函数)
{
双锅链接库::调用(fsgid,参数1,密码,要调用的函数);
双锅链接库::阻滞(fsgid);
CString ret=双锅链接库::读返回值(fsgid);
双锅链接库::清除缓存(fsgid);
return ret;
}