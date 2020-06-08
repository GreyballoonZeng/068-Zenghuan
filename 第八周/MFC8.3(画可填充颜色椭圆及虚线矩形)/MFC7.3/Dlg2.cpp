// Dlg2.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC7.3.h"
#include "Dlg2.h"
#include "afxdialogex.h"


// Dlg2 对话框

IMPLEMENT_DYNAMIC(Dlg2, CDialogEx)

Dlg2::Dlg2(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, red(0)
	, green(0)
	, blue(0)
{

}

Dlg2::~Dlg2()
{
}

void Dlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, red);
	DDX_Text(pDX, IDC_EDIT3, green);
	DDX_Text(pDX, IDC_EDIT2, blue);
}


BEGIN_MESSAGE_MAP(Dlg2, CDialogEx)
END_MESSAGE_MAP()


// Dlg2 消息处理程序
