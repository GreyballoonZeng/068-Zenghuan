
// MFC4.4.h : MFC4.4 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFC44App:
// �йش����ʵ�֣������ MFC4.4.cpp
//

class CMFC44App : public CWinAppEx
{
public:
	CMFC44App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC44App theApp;
