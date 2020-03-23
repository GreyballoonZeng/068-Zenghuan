
// MFC2.4View.cpp : CMFC24View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC2.4.h"
#endif

#include "MFC2.4Doc.h"
#include "MFC2.4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC24View

IMPLEMENT_DYNCREATE(CMFC24View, CView)

BEGIN_MESSAGE_MAP(CMFC24View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC24View ����/����

CMFC24View::CMFC24View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC24View::~CMFC24View()
{
}

BOOL CMFC24View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC24View ����

void CMFC24View::OnDraw(CDC* pDC)
{
	CMFC24Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->TextOutW(10, 10, pDoc->s2);
	pDC->TextOutW(pDoc->pointx - 20, pDoc->pointy - 20, pDoc->s1);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC24View ���

#ifdef _DEBUG
void CMFC24View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC24View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC24Doc* CMFC24View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC24Doc)));
	return (CMFC24Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC24View ��Ϣ�������


void CMFC24View::OnLButtonDown(UINT nFlags, CPoint point)
{

	CMFC24Doc* pDoc = GetDocument();
	CClientDC dc(this);
	pDoc->C = pDoc->A + pDoc->B;
	pDoc->pointx = point.x;
	pDoc->pointy = point.y;
	pDoc->s1.Format(_T("A+B=%d"), pDoc->C);
	this->Invalidate();
	

	CView::OnLButtonDown(nFlags, point);
}
