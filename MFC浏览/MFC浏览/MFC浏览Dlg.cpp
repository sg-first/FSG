
// MFC浏览Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC浏览.h"
#include "MFC浏览Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//全局变量区
CString mima="741852";
CString fsgname="MFC浏览";
//宏定义区
#define REFIRST GetPrivateProfileString(CString(fsgname),CString
#define RELAST ,1024,CString(".\\"+fsgname+".ini"))
#define PDFIRST if (getfunname==
//函数前置声明区
void exitexe();
void brofile(CString houzhui,CString miaoshu);

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


// CMFC浏览Dlg 对话框




CMFC浏览Dlg::CMFC浏览Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC浏览Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC浏览Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFC浏览Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CMFC浏览Dlg 消息处理程序

BOOL CMFC浏览Dlg::OnInitDialog()
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
REFIRST ("要调用的函数"),CString(""),getfunname.GetBuffer(1024) RELAST;
PDFIRST "浏览文件")
{
	CString canshu1;
    CString canshu2;
	REFIRST ("参数1"),CString(""),canshu1.GetBuffer(1024) RELAST;
	REFIRST ("参数2"),CString(""),canshu2.GetBuffer(1024) RELAST;
    brofile(canshu1,canshu2);//调用浏览文件
}
PDFIRST "浏览文件夹")
{
    CString ret=brofol();//调用浏览文件夹，读返回值
	WritePrivateProfileString(fsgname,"返回值",ret,CString(".\\"+fsgname+".ini"));
}
exitexe();
return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void exitexe()
{
	DeleteFile(fsgname+".ssg");
	exit(0);
}

CString CMFC浏览Dlg::brofol()
{
	   UpdateData(true);
       char szDir[MAX_PATH];//定义一个字符串用来接收文件名
       BROWSEINFO bi;
       ITEMIDLIST*pidl;//创建一个结构指针
       memset(&bi,0,sizeof   BROWSEINFO);  
       bi.hwndOwner=m_hWnd;
       bi.hwndOwner=this->m_hWnd; // 指定父窗口，在对话框显示期间，父窗口将被禁用
      bi.pidlRoot=NULL;
       bi.pszDisplayName=szDir;//pszDisplayName：用来保存用户选中的目录字符串的内存地址(缓冲区)
       bi.lpszTitle="请选择一个关卡集文件夹"; // 这一行将显示在对话框的顶端
       //描述窗口的选项：包含状态文本、显示目录和文件、只返回文件系统目录（不好用呢）、返回系统一个节点、
       bi.ulFlags=BIF_STATUSTEXT|BIF_BROWSEINCLUDEFILES|BIF_RETURNONLYFSDIRS|BIF_RETURNFSANCESTORS       ;
       bi.lpfn=NULL;//lpfn：应用程序定义的浏览对话框回调函数的地址。当对话框中的事件发生时，该对话框将调用回调函数。该参数可用为NULL。
       bi.lParam=0;//lParam：对话框传递给回调函数的一个参数指针。
       bi.iImage=0;//iImage：与选中目录相关的图像。该图像将被指定为系统图像列表中的索引值。
       pidl=SHBrowseForFolder(&bi);
       if(pidl==NULL)
	   {return NULL;}
       else
	   {SHGetPathFromIDList(pidl,szDir);}   //显示文件路径，不然szDir 只保存一个文件名
       CString m_strFileName=szDir;
       UpdateData(false);
	   return m_strFileName;
}

void brofile(CString houzhui,CString miaoshu)
{
	miaoshu=miaoshu+"|*."+houzhui;
	CString lujing;
	CString name;
	CFileDialog dlg(true,houzhui,NULL, OFN_FILEMUSTEXIST, _T(miaoshu) );//选定文件类，让选地图
    if ( dlg.DoModal() == IDOK ) 
    {
    lujing=dlg.GetPathName();
    name=dlg.GetFileName();
    }
	WritePrivateProfileString(fsgname,"返回值",lujing,CString(".\\"+fsgname+".ini"));
	WritePrivateProfileString(fsgname,"返回值2",name,CString(".\\"+fsgname+".ini"));
}

void CMFC浏览Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC浏览Dlg::OnPaint()
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
HCURSOR CMFC浏览Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

