
// MFC2.1View.h : CMFC21View ��Ľӿ�
//

#pragma once


class CMFC21View : public CView
{
protected: // �������л�����
	CMFC21View();
	DECLARE_DYNCREATE(CMFC21View)

// ����
public:
	CMFC21Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC21View();
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

#ifndef _DEBUG  // MFC2.1View.cpp �еĵ��԰汾
inline CMFC21Doc* CMFC21View::GetDocument() const
   { return reinterpret_cast<CMFC21Doc*>(m_pDocument); }
#endif

