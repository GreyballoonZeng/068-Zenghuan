
// MFC4.4View.h : CMFC44View ��Ľӿ�
//

#pragma once


class CMFC44View : public CView
{
protected: // �������л�����
	CMFC44View();
	DECLARE_DYNCREATE(CMFC44View)

// ����
public:
	CMFC44Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC44View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	int px, py, px1, py1,flag;
protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On1();
	afx_msg void On2();

	afx_msg void On3();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC4.4View.cpp �еĵ��԰汾
inline CMFC44Doc* CMFC44View::GetDocument() const
   { return reinterpret_cast<CMFC44Doc*>(m_pDocument); }
#endif

