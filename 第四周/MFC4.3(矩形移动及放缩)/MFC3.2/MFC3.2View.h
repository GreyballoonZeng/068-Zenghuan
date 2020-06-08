
// MFC3.2View.h : CMFC32View ��Ľӿ�
//

#pragma once


class CMFC32View : public CView
{
protected: // �������л�����
	CMFC32View();
	DECLARE_DYNCREATE(CMFC32View)

// ����
public:
	CMFC32Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC32View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC3.2View.cpp �еĵ��԰汾
inline CMFC32Doc* CMFC32View::GetDocument() const
   { return reinterpret_cast<CMFC32Doc*>(m_pDocument); }
#endif

