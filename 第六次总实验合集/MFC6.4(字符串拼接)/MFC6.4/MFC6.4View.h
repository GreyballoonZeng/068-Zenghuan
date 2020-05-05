
// MFC6.4View.h : CMFC64View ��Ľӿ�
//

#pragma once


class CMFC64View : public CView
{
protected: // �������л�����
	CMFC64View();
	DECLARE_DYNCREATE(CMFC64View)

// ����
public:
	CMFC64Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMFC64View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC6.4View.cpp �еĵ��԰汾
inline CMFC64Doc* CMFC64View::GetDocument() const
   { return reinterpret_cast<CMFC64Doc*>(m_pDocument); }
#endif

