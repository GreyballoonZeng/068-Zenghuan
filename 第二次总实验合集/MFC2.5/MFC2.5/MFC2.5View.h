
// MFC2.5View.h : CMFC25View ��Ľӿ�
//

#pragma once


class CMFC25View : public CView
{
protected: // �������л�����
	CMFC25View();
	DECLARE_DYNCREATE(CMFC25View)

// ����
public:
	CMFC25Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC25View();
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

#ifndef _DEBUG  // MFC2.5View.cpp �еĵ��԰汾
inline CMFC25Doc* CMFC25View::GetDocument() const
   { return reinterpret_cast<CMFC25Doc*>(m_pDocument); }
#endif

