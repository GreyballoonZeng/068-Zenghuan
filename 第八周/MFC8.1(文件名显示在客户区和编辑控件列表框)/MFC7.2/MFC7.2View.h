
// MFC7.2View.h : CMFC72View ��Ľӿ�
//

#pragma once


class CMFC72View : public CView
{
protected: // �������л�����
	CMFC72View();
	DECLARE_DYNCREATE(CMFC72View)

// ����
public:
	CMFC72Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC72View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	CString filename;
protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnPrintFileName();
};

#ifndef _DEBUG  // MFC7.2View.cpp �еĵ��԰汾
inline CMFC72Doc* CMFC72View::GetDocument() const
   { return reinterpret_cast<CMFC72Doc*>(m_pDocument); }
#endif

