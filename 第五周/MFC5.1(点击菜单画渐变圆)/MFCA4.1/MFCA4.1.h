
// MFCA4.1.h : MFCA4.1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCA41App:
// �йش����ʵ�֣������ MFCA4.1.cpp
//

class CMFCA41App : public CWinApp
{
public:
	CMFCA41App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCA41App theApp;
