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

void ˫�����ӿ�::����(string fsgid,string ����1,string ����,string Ҫ���õĺ���)
{
LPCSTR Lfsgid=fsgid.c_str();
LPCSTR L����=����.c_str();
LPCSTR LҪ���õĺ���=Ҫ���õĺ���.c_str();
LPCSTR L����1=����1.c_str();
//�����ļ�
fstream newssg(fsgid+".ssg");
newssg.open(fsgid+".ssg",ios::out|ios::app);
//����ini
fstream newini(fsgid+".ini");
newini.open(fsgid+".ini",ios::out|ios::app);
//д����
string lujing=".\\"+fsgid+".ini";
LPCSTR Llujing=lujing.c_str();
WritePrivateProfileString(Lfsgid,"����",L����,Llujing);
WritePrivateProfileString(Lfsgid,"Ҫ���õĺ���",LҪ���õĺ���,Llujing);
WritePrivateProfileString(Lfsgid,"����1",L����1,Llujing);
//�������ӿ�
lujing=fsgid+".fsg";
Llujing=lujing.c_str();
opfile(Llujing,NULL);
}

bool ˫�����ӿ�::����(string fsgid)
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

void ˫�����ӿ�::�������(string fsgid)
{
	string lujing=fsgid+".ini";
    LPCSTR Llujing=lujing.c_str();
	LPCSTR Lfsgid=fsgid.c_str();
	DeleteFile(Llujing);
}

string ˫�����ӿ�::������ֵ(string fsgid)
{
string lujing=".\\"+fsgid+".ini";
LPCSTR Llujing=lujing.c_str();
LPCSTR Lfsgid=fsgid.c_str();
LPSTR retvar=new char[1024];
GetPrivateProfileString(Lfsgid,"����ֵ",NULL,retvar,1024,Llujing);
//���ڿ�ʼߣ����ת��
string Sretvar=(LPSTR)retvar;
delete []retvar;
//ߣ����
return Sretvar;
}

string ˫�����ӿ�::�򵥵���(string fsgid,string ����1,string ����,string Ҫ���õĺ���)
{
˫�����ӿ�::����(fsgid,����1,����,Ҫ���õĺ���);
˫�����ӿ�::����(fsgid);
string ret=˫�����ӿ�::������ֵ(fsgid);
˫�����ӿ�::�������(fsgid);
return ret;
}