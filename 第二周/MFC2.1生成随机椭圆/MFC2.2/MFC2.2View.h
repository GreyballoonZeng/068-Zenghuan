
// MFC2.2View.h : CMFC22View ��Ľӿ�
//

#pragma once


class CMFC22View : public CView
{
protected: // �������л�����
	CMFC22View();
	DECLARE_DYNCREATE(CMFC22View)

// ����
public:
	CMFC22Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC22View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC2.2View.cpp �еĵ��԰汾
inline CMFC22Doc* CMFC22View::GetDocument() const
   { return reinterpret_cast<CMFC22Doc*>(m_pDocument); }
#endif

