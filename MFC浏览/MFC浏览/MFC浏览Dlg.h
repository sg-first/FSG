
// MFC���Dlg.h : ͷ�ļ�
//

#pragma once


// CMFC���Dlg �Ի���
class CMFC���Dlg : public CDialogEx
{
// ����
public:
	CMFC���Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	CString brofol();
	DECLARE_MESSAGE_MAP()
};
