
// MFC3.3View.h : CMFC33View ��Ľӿ�
//

#pragma once


class CMFC33View : public CView
{
protected: // �������л�����
	CMFC33View();
	DECLARE_DYNCREATE(CMFC33View)

// ����
public:
	CMFC33Doc* GetDocument() const;

// ����
public:
	int N;
	CArray<CRect, CRect> cr;
	CArray<int,int> flag;
	bool set;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC33View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // MFC3.3View.cpp �еĵ��԰汾
inline CMFC33Doc* CMFC33View::GetDocument() const
   { return reinterpret_cast<CMFC33Doc*>(m_pDocument); }
#endif

