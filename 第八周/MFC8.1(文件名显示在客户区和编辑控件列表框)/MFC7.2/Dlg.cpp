// Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC7.2.h"
#include "Dlg.h"
#include "afxdialogex.h"


// Dlg �Ի���

IMPLEMENT_DYNAMIC(Dlg, CDialogEx)

Dlg::Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	
	, str(_T(""))
{

}

Dlg::~Dlg()
{
}

void Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT3, str);
	DDX_Control(pDX, IDC_LIST1, s);
}


BEGIN_MESSAGE_MAP(Dlg, CDialogEx)

END_MESSAGE_MAP()


// Dlg ��Ϣ�������





BOOL Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	s.AddString(str);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
