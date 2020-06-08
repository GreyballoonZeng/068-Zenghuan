
// MFC7.2Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC7.2.h"
#include "MFC7.2Dlg.h"
#include "afxdialogex.h"
#include "dlg2.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFC72Dlg �Ի���



CMFC72Dlg::CMFC72Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFC72_DIALOG, pParent)
	, x(0)
	, y(0)
	, z(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC72Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, x);
	DDX_Text(pDX, IDC_EDIT3, y);
	DDX_Text(pDX, IDC_EDIT2, z);
}

BEGIN_MESSAGE_MAP(CMFC72Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CMFC72Dlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT3, &CMFC72Dlg::OnEnChangeEdit3)


	ON_BN_CLICKED(IDC_BUTTON4, &CMFC72Dlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFC72Dlg::OnBnClickedButtonSubtract)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFC72Dlg::OnBnClickedButtonMultiply)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC72Dlg::OnBnClickedButtonDivide)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFC72Dlg::OnBnClickedButtonSqrt)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFC72Dlg::OnBnClickedButtonBackWord)
END_MESSAGE_MAP()


// CMFC72Dlg ��Ϣ�������

BOOL CMFC72Dlg::OnInitDialog()
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFC72Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFC72Dlg::OnPaint()
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
HCURSOR CMFC72Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC72Dlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CMFC72Dlg::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}





void CMFC72Dlg::OnBnClickedButtonAdd()
{
	this->UpdateData(true);
	z = x + y;
	this->UpdateData(false);
}


void CMFC72Dlg::OnBnClickedButtonSubtract()
{
	this->UpdateData(true);
	z = x - y;
	this->UpdateData(false);
}


void CMFC72Dlg::OnBnClickedButtonMultiply()
{
	this->UpdateData(true);
	z = x * y;
	this->UpdateData(false);
}


void CMFC72Dlg::OnBnClickedButtonDivide()
{
	this->UpdateData(true);
	if(y!=0)
	z = x / y;
	else{
		dlg2 dlg;
	int r = dlg.DoModal();
	}
	this->UpdateData(false);
}


void CMFC72Dlg::OnBnClickedButtonSqrt()
{   
	this->UpdateData(true);
	if(x>=0)
	z =sqrt(x);
	else {
		dlg2 dlg;
		int r = dlg.DoModal();
	}
	this->UpdateData(false);
}


void CMFC72Dlg::OnBnClickedButtonBackWord()
{
	this->UpdateData(true);
	if(x!=0)
	z = 1 / x;
	else {
		dlg2 dlg;
		int r = dlg.DoModal();
	}
	this->UpdateData(false);
}
