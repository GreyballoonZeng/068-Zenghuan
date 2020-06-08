// Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC7.2.h"
#include "Dlg.h"
#include "afxdialogex.h"


// Dlg 对话框

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


// Dlg 消息处理程序





BOOL Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	s.AddString(str);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
