#include "stdafx.h"
#include "˫�����ӿ�file.h"
#include "˫�����ӿ�fileDlg.h"
#include "afxdialogex.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//�궨����
#define REFIRST GetPrivateProfileString(CString(fsgname),CString
#define RELAST ,1024,CString(".\\"+fsgname+".ini"))
#define PDFIRST if (getfunname==
//ȫ�ֱ�����
CString mima="741852";
CString fsgname="chelp";
//����ǰ��������
void exitexe();
//ͷ�ļ�������
#include <iostream>
using namespace std;
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <cstdlib>//�����
#include <io.h>//�Ƿ����
#include <fstream>//�ļ���д

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// C˫�����ӿ�fileDlg �Ի���




C˫�����ӿ�fileDlg::C˫�����ӿ�fileDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C˫�����ӿ�fileDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C˫�����ӿ�fileDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C˫�����ӿ�fileDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// C˫�����ӿ�fileDlg ��Ϣ�������

BOOL C˫�����ӿ�fileDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

//��ʼ���¼�
CString yhmima;//�����û����������

REFIRST ("����"),CString(""),yhmima.GetBuffer(1024) RELAST;

if (yhmima!=mima)
{
	::MessageBox(NULL,"������Ч��Win32Ӧ�ó���","����",MB_ICONHAND);
    exitexe();
}

CString getfunname;
//���������õ��Ĳ���-������
CString canshu1;
CString canshu2;
//����-�������
REFIRST ("Ҫ���õĺ���"),CString(""),getfunname.GetBuffer(1024) RELAST;
PDFIRST "����Ϣ��")
{
	REFIRST ("����1"),CString(""),canshu1.GetBuffer(1024) RELAST;
	REFIRST ("����2"),CString(""),canshu2.GetBuffer(1024) RELAST;
	MessageBox(canshu1,canshu2);
	exitexe();
}
else
{
	PDFIRST "CMD����")
	{
		REFIRST ("����1"),CString(""),canshu1.GetBuffer(1024) RELAST;
		system("canshu1");
		exitexe();
	}
	else
	{
		PDFIRST "�Ƿ����")
		{
			REFIRST ("����1"),CString(""),canshu1.GetBuffer(1024) RELAST;
			int jieguo=_access(canshu1,0);
			if(jieguo==-1) //����ļ��Ƿ���ڣ�����-1������
			{
				WritePrivateProfileString(fsgname,"����ֵ","������",CString(".\\"+fsgname+".ini"));
			}
			else
			{
				WritePrivateProfileString(fsgname,"����ֵ","����",CString(".\\"+fsgname+".ini"));
			}
			exitexe();
		}
		else
		{
			PDFIRST "�����")
			{
            int jieguo=rand()%2;//0-1֮�����������
			CString rejieguo;
            rejieguo.Format("%d", jieguo);
            WritePrivateProfileString(fsgname,"����ֵ",rejieguo,CString(".\\"+fsgname+".ini"));
			exitexe();
			}
			PDFIRST "д�ı��ļ�")
			{
				REFIRST ("����1"),CString(""),canshu1.GetBuffer(1024) RELAST;
				REFIRST ("����2"),CString(""),canshu2.GetBuffer(1024) RELAST;
				fstream file(canshu1);
                file<<canshu2;	
                file.close();//�ر��ļ����
				exitexe();
			}
			else
			{
				PDFIRST "���ı��ļ�")
			   {
				REFIRST ("����1"),CString(""),canshu1.GetBuffer(1024) RELAST;
				char op[225]; //װ���ļ����ݵı���
                fstream file(canshu1);
                file>>op;	
                file.close();//�ر��ļ����
				WritePrivateProfileString(fsgname,"����ֵ",op,CString(".\\"+fsgname+".ini"));
				exitexe();
				}
				else
				{
                PDFIRST "���ļ�")
				REFIRST ("����1"),CString(""),canshu1.GetBuffer(1024) RELAST;
				ShellExecute(NULL,"open",canshu1,NULL,NULL,SW_SHOWNORMAL);
				exitexe();
				}
			}
		}

	}
}
exitexe();
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void exitexe()
{
	DeleteFile(fsgname+".ssg");
	exit(0);
}

void C˫�����ӿ�fileDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void C˫�����ӿ�fileDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR C˫�����ӿ�fileDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

