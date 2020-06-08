// dlg2.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC7.2.h"
#include "dlg2.h"
#include "afxdialogex.h"


// dlg2 对话框

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


// dlg2 消息处理程序


void dlg2::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
