#include "stdafx.h"
#include <io.h>
#include <Windows.h>
#include <string>
#include <fstream>//�ļ���д
using namespace std;//��������֧��

#define FSG ˫�����ӿ�
#define Call ����
#define ClearCache �������
#define ReadingValues ������ֵ
#define EasyCall �򵥵���

class ˫�����ӿ�
{
public:
    static void ����(string fsgid,string ����1,string ����,string Ҫ���õĺ���);
    static bool ����(string fsgid);
    static void �������(string fsgid);
    static string ������ֵ(string fsgid);
    static string �򵥵���(string fsgid,string ����1,string ����,string Ҫ���õĺ���);
};


