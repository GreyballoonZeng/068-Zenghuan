// Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC7.3.h"
#include "Dlg.h"
#include "afxdialogex.h"


// Dlg �Ի���

IMPLEMENT_DYNAMIC(Dlg, CDialogEx)

Dlg::Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, left(0)
	, right(0)
	, top(0)
	, bottom(0)
{

}

Dlg::~Dlg()
{
}

void Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, left);
	DDX_Text(pDX, IDC_EDIT2, right);
	DDX_Text(pDX, IDC_EDIT3, top);
	DDX_Text(pDX, IDC_EDIT4, bottom);
}


BEGIN_MESSAGE_MAP(Dlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &Dlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDOK, &Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// Dlg ��Ϣ�������


void Dlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void Dlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}
