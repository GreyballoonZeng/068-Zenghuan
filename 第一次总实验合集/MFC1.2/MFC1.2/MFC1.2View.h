
// MFC1.2View.h : CMFC12View ��Ľӿ�
//

#pragma once


class CMFC12View : public CView
{
protected: // �������л�����
	CMFC12View();
	DECLARE_DYNCREATE(CMFC12View)

// ����
public:
	CMFC12Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC12View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC1.2View.cpp �еĵ��԰汾
inline CMFC12Doc* CMFC12View::GetDocument() const
   { return reinterpret_cast<CMFC12Doc*>(m_pDocument); }
#endif

