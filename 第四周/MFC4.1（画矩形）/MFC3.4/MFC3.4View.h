
// MFC3.4View.h : CMFC34View ��Ľӿ�
//

#pragma once


class CMFC34View : public CView
{
protected: // �������л�����
	CMFC34View();
	DECLARE_DYNCREATE(CMFC34View)

// ����
public:
	CMFC34Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC34View();
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
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC3.4View.cpp �еĵ��԰汾
inline CMFC34Doc* CMFC34View::GetDocument() const
   { return reinterpret_cast<CMFC34Doc*>(m_pDocument); }
#endif

