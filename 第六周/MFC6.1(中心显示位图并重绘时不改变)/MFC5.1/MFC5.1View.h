
// MFC5.1View.h : CMFC51View ��Ľӿ�
//

#pragma once


class CMFC51View : public CView
{
protected: // �������л�����
	CMFC51View();
	DECLARE_DYNCREATE(CMFC51View)

// ����
public:
	CMFC51Doc* GetDocument() const;

// ����
public:
	CString filename;
	int set;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC51View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	
protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // MFC5.1View.cpp �еĵ��԰汾
inline CMFC51Doc* CMFC51View::GetDocument() const
   { return reinterpret_cast<CMFC51Doc*>(m_pDocument); }
#endif

