
// MFC4.2View.h : CMFC42View ��Ľӿ�
//

#pragma once


class CMFC42View : public CView
{
protected: // �������л�����
	CMFC42View();
	DECLARE_DYNCREATE(CMFC42View)

// ����
public:
	CMFC42Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC42View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On32771();
};

#ifndef _DEBUG  // MFC4.2View.cpp �еĵ��԰汾
inline CMFC42Doc* CMFC42View::GetDocument() const
   { return reinterpret_cast<CMFC42Doc*>(m_pDocument); }
#endif

