#include "stdafx.h"
#include <fstream>//�ļ���д
using namespace std;//��������֧��
#include <io.h>
#include <Windows.h>
#include <string>

#define FSG ˫�����ӿ�
#define Call ����
#define ClearCache �������
#define ReadingValues ������ֵ
#define EasyCall �򵥵���

class ˫�����ӿ�
{
public:
	    static void ����(CString fsgid,CString ����1,CString ����,CString Ҫ���õĺ���);
	    static bool ����(CString fsgid);
        static void �������(CString fsgid);
        static CString ������ֵ(CString fsgid);
        static CString �򵥵���(CString fsgid,CString ����1,CString ����,CString Ҫ���õĺ���);
};


