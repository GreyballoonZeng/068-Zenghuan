// dlg2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC7.2.h"
#include "dlg2.h"
#include "afxdialogex.h"


// dlg2 �Ի���

IMPLEMENT_DYNAMIC(dlg2, CDialogEx)

dlg2::dlg2(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

dlg2::~dlg2()
{
}

void dlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(dlg2, CDialogEx)
	ON_BN_CLICKED(IDOK, &dlg2::OnBnClickedOk)
END_MESSAGE_MAP()


// dlg2 ��Ϣ�������


void dlg2::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}
