#include "stdafx.h"
#include "˫�����ӿ�.h"

void opfile (LPCSTR canyi,LPSTR caner)
{
STARTUPINFO si; //һЩ�ر���������
memset(&si, 0, sizeof(STARTUPINFO));
si.cb = sizeof(STARTUPINFO);
si.dwFlags = STARTF_USESHOWWINDOW;
si.wShowWindow = SW_SHOW;
PROCESS_INFORMATION pi; //�ر��������ý���
CreateProcess(canyi,caner,NULL,NULL,FALSE,0,NULL,NULL,&si,&pi);
}

void ˫�����ӿ�::����(CString fsgid,CString ����1,CString ����,CString Ҫ���õĺ���)
{
//�����ļ�
fstream newssg(fsgid+".ssg");
newssg.open(fsgid+".ssg",ios::out|ios::app);
//����ini
fstream newini(fsgid+".ini");
newini.open(fsgid+".ini",ios::out|ios::app);
//д����
WritePrivateProfileString(fsgid,"����",����,".\\"+fsgid+".ini");
WritePrivateProfileString(fsgid,"Ҫ���õĺ���",Ҫ���õĺ���,".\\"+fsgid+".ini");
WritePrivateProfileString(fsgid,"����1",����1,".\\"+fsgid+".ini");
//�������ӿ�
opfile(fsgid+".fsg",NULL);
}

bool ˫�����ӿ�::����(CString fsgid)
{
while(1)
{
	if(_access(fsgid+".ssg",0)==-1)
	{return true;}
}
}

void ˫�����ӿ�::�������(CString fsgid)
{DeleteFile(fsgid+".ini");}

CString ˫�����ӿ�::������ֵ(CString fsgid)
{
CString retvar;
GetPrivateProfileString(fsgid,"����ֵ",NULL,retvar.GetBuffer(1024),1024,".\\"+fsgid+".ini");
return retvar;
}

CString ˫�����ӿ�::�򵥵���(CString fsgid,CString ����1,CString ����,CString Ҫ���õĺ���)
{
˫�����ӿ�::����(fsgid,����1,����,Ҫ���õĺ���);
˫�����ӿ�::����(fsgid);
CString ret=˫�����ӿ�::������ֵ(fsgid);
˫�����ӿ�::�������(fsgid);
return ret;
}