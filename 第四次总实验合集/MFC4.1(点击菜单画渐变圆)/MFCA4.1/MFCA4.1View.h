
// MFCA4.1View.h : CMFCA41View ��Ľӿ�
//

#pragma once


class CMFCA41View : public CView
{
protected: // �������л�����
	CMFCA41View();
	DECLARE_DYNCREATE(CMFCA41View)

// ����
public:
	CMFCA41Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCA41View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	int px=500 , py=300;
	int t;
	int red = 25, green = 25, blue = 25, width =5;
	int color = RGB(red, green, blue);
protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On32771();
};

#ifndef _DEBUG  // MFCA4.1View.cpp �еĵ��԰汾
inline CMFCA41Doc* CMFCA41View::GetDocument() const
   { return reinterpret_cast<CMFCA41Doc*>(m_pDocument); }
#endif

