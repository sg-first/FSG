#include "stdafx.h"
#include "双锅链接库file.h"
#include "双锅链接库fileDlg.h"
#include "afxdialogex.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//宏定义区
#define REFIRST GetPrivateProfileString(CString(fsgname),CString
#define RELAST ,1024,CString(".\\"+fsgname+".ini"))
#define PDFIRST if (getfunname==
//全局变量区
CString mima="741852";
CString fsgname="chelp";
//函数前置声明区
void exitexe();
//头文件声明区
#include <iostream>
using namespace std;
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <cstdlib>//随机数
#include <io.h>//是否存在
#include <fstream>//文件读写

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// C双锅链接库fileDlg 对话框




C双锅链接库fileDlg::C双锅链接库fileDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C双锅链接库fileDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C双锅链接库fileDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C双锅链接库fileDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// C双锅链接库fileDlg 消息处理程序

BOOL C双锅链接库fileDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

//初始化事件
CString yhmima;//储存用户输入的密码

REFIRST ("密码"),CString(""),yhmima.GetBuffer(1024) RELAST;

if (yhmima!=mima)
{
	::MessageBox(NULL,"不是有效的Win32应用程序","错误",MB_ICONHAND);
    exitexe();
}

CString getfunname;
//函数调用用到的参数-声明区
CString canshu1;
CString canshu2;
//参数-声明完成
REFIRST ("要调用的函数"),CString(""),getfunname.GetBuffer(1024) RELAST;
PDFIRST "简单消息框")
{
	REFIRST ("参数1"),CString(""),canshu1.GetBuffer(1024) RELAST;
	REFIRST ("参数2"),CString(""),canshu2.GetBuffer(1024) RELAST;
	MessageBox(canshu1,canshu2);
	exitexe();
}
else
{
	PDFIRST "CMD命令")
	{
		REFIRST ("参数1"),CString(""),canshu1.GetBuffer(1024) RELAST;
		system("canshu1");
		exitexe();
	}
	else
	{
		PDFIRST "是否存在")
		{
			REFIRST ("参数1"),CString(""),canshu1.GetBuffer(1024) RELAST;
			int jieguo=_access(canshu1,0);
			if(jieguo==-1) //检测文件是否存在，等于-1不存在
			{
				WritePrivateProfileString(fsgname,"返回值","不存在",CString(".\\"+fsgname+".ini"));
			}
			else
			{
				WritePrivateProfileString(fsgname,"返回值","存在",CString(".\\"+fsgname+".ini"));
			}
			exitexe();
		}
		else
		{
			PDFIRST "随机数")
			{
            int jieguo=rand()%2;//0-1之间随机的数字
			CString rejieguo;
            rejieguo.Format("%d", jieguo);
            WritePrivateProfileString(fsgname,"返回值",rejieguo,CString(".\\"+fsgname+".ini"));
			exitexe();
			}
			PDFIRST "写文本文件")
			{
				REFIRST ("参数1"),CString(""),canshu1.GetBuffer(1024) RELAST;
				REFIRST ("参数2"),CString(""),canshu2.GetBuffer(1024) RELAST;
				fstream file(canshu1);
                file<<canshu2;	
                file.close();//关闭文件句柄
				exitexe();
			}
			else
			{
				PDFIRST "读文本文件")
			   {
				REFIRST ("参数1"),CString(""),canshu1.GetBuffer(1024) RELAST;
				char op[225]; //装载文件内容的变量
                fstream file(canshu1);
                file>>op;	
                file.close();//关闭文件句柄
				WritePrivateProfileString(fsgname,"返回值",op,CString(".\\"+fsgname+".ini"));
				exitexe();
				}
				else
				{
                PDFIRST "打开文件")
				REFIRST ("参数1"),CString(""),canshu1.GetBuffer(1024) RELAST;
				ShellExecute(NULL,"open",canshu1,NULL,NULL,SW_SHOWNORMAL);
				exitexe();
				}
			}
		}

	}
}
exitexe();
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void exitexe()
{
	DeleteFile(fsgname+".ssg");
	exit(0);
}

void C双锅链接库fileDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void C双锅链接库fileDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR C双锅链接库fileDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

