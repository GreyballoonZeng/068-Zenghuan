
// MFC2.3View.h : CMFC23View ��Ľӿ�
//

#pragma once


class CMFC23View : public CView
{
protected: // �������л�����
	CMFC23View();
	DECLARE_DYNCREATE(CMFC23View)

// ����
public:
	CMFC23Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC23View();
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
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC2.3View.cpp �еĵ��԰汾
inline CMFC23Doc* CMFC23View::GetDocument() const
   { return reinterpret_cast<CMFC23Doc*>(m_pDocument); }
#endif

