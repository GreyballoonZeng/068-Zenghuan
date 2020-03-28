
// MFC4.3View.h : CMFC43View ��Ľӿ�
//

#pragma once


class CMFC43View : public CView
{
protected: // �������л�����
	CMFC43View();
	DECLARE_DYNCREATE(CMFC43View)

// ����
public:
	CMFC43Doc* GetDocument() const;

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
	virtual ~CMFC43View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	CBitmap m_Bitmap;
	int m_nWidth;
	int m_nHeight;
protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC4.3View.cpp �еĵ��԰汾
inline CMFC43Doc* CMFC43View::GetDocument() const
   { return reinterpret_cast<CMFC43Doc*>(m_pDocument); }
#endif

