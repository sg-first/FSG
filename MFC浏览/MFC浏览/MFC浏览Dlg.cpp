
// MFC���Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC���.h"
#include "MFC���Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//ȫ�ֱ�����
CString mima="741852";
CString fsgname="MFC���";
//�궨����
#define REFIRST GetPrivateProfileString(CString(fsgname),CString
#define RELAST ,1024,CString(".\\"+fsgname+".ini"))
#define PDFIRST if (getfunname==
//����ǰ��������
void exitexe();
void brofile(CString houzhui,CString miaoshu);

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


// CMFC���Dlg �Ի���




CMFC���Dlg::CMFC���Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC���Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC���Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFC���Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CMFC���Dlg ��Ϣ�������

BOOL CMFC���Dlg::OnInitDialog()
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
REFIRST ("Ҫ���õĺ���"),CString(""),getfunname.GetBuffer(1024) RELAST;
PDFIRST "����ļ�")
{
	CString canshu1;
    CString canshu2;
	REFIRST ("����1"),CString(""),canshu1.GetBuffer(1024) RELAST;
	REFIRST ("����2"),CString(""),canshu2.GetBuffer(1024) RELAST;
    brofile(canshu1,canshu2);//��������ļ�
}
PDFIRST "����ļ���")
{
    CString ret=brofol();//��������ļ��У�������ֵ
	WritePrivateProfileString(fsgname,"����ֵ",ret,CString(".\\"+fsgname+".ini"));
}
exitexe();
return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void exitexe()
{
	DeleteFile(fsgname+".ssg");
	exit(0);
}

CString CMFC���Dlg::brofol()
{
	   UpdateData(true);
       char szDir[MAX_PATH];//����һ���ַ������������ļ���
       BROWSEINFO bi;
       ITEMIDLIST*pidl;//����һ���ṹָ��
       memset(&bi,0,sizeof   BROWSEINFO);  
       bi.hwndOwner=m_hWnd;
       bi.hwndOwner=this->m_hWnd; // ָ�������ڣ��ڶԻ�����ʾ�ڼ䣬�����ڽ�������
      bi.pidlRoot=NULL;
       bi.pszDisplayName=szDir;//pszDisplayName�����������û�ѡ�е�Ŀ¼�ַ������ڴ��ַ(������)
       bi.lpszTitle="��ѡ��һ���ؿ����ļ���"; // ��һ�н���ʾ�ڶԻ���Ķ���
       //�������ڵ�ѡ�����״̬�ı�����ʾĿ¼���ļ���ֻ�����ļ�ϵͳĿ¼���������أ�������ϵͳһ���ڵ㡢
       bi.ulFlags=BIF_STATUSTEXT|BIF_BROWSEINCLUDEFILES|BIF_RETURNONLYFSDIRS|BIF_RETURNFSANCESTORS       ;
       bi.lpfn=NULL;//lpfn��Ӧ�ó����������Ի���ص������ĵ�ַ�����Ի����е��¼�����ʱ���öԻ��򽫵��ûص��������ò�������ΪNULL��
       bi.lParam=0;//lParam���Ի��򴫵ݸ��ص�������һ������ָ�롣
       bi.iImage=0;//iImage����ѡ��Ŀ¼��ص�ͼ�񡣸�ͼ�񽫱�ָ��Ϊϵͳͼ���б��е�����ֵ��
       pidl=SHBrowseForFolder(&bi);
       if(pidl==NULL)
	   {return NULL;}
       else
	   {SHGetPathFromIDList(pidl,szDir);}   //��ʾ�ļ�·������ȻszDir ֻ����һ���ļ���
       CString m_strFileName=szDir;
       UpdateData(false);
	   return m_strFileName;
}

void brofile(CString houzhui,CString miaoshu)
{
	miaoshu=miaoshu+"|*."+houzhui;
	CString lujing;
	CString name;
	CFileDialog dlg(true,houzhui,NULL, OFN_FILEMUSTEXIST, _T(miaoshu) );//ѡ���ļ��࣬��ѡ��ͼ
    if ( dlg.DoModal() == IDOK ) 
    {
    lujing=dlg.GetPathName();
    name=dlg.GetFileName();
    }
	WritePrivateProfileString(fsgname,"����ֵ",lujing,CString(".\\"+fsgname+".ini"));
	WritePrivateProfileString(fsgname,"����ֵ2",name,CString(".\\"+fsgname+".ini"));
}

void CMFC���Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC���Dlg::OnPaint()
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
HCURSOR CMFC���Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

