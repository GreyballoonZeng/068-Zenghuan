#pragma once


// dlg2 �Ի���

class dlg2 : public CDialogEx
{
	DECLARE_DYNAMIC(dlg2)

public:
	dlg2(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~dlg2();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
