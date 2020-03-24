
// MFC3.4View.cpp : CMFC34View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC3.4.h"
#endif

#include "MFC3.4Doc.h"
#include "MFC3.4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC34View

IMPLEMENT_DYNCREATE(CMFC34View, CView)

BEGIN_MESSAGE_MAP(CMFC34View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFC34View ����/����

CMFC34View::CMFC34View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC34View::~CMFC34View()
{
}

BOOL CMFC34View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC34View ����

void CMFC34View::OnDraw(CDC* pDC)
{
	CMFC34Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString s;
	s.Format(_T("(%d,%d)"), pDoc->pointx3,pDoc-> pointy3);
	pDC->TextOutW(pDoc->pointx3, pDoc->pointy3, s);
	
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC34View ���

#ifdef _DEBUG
void CMFC34View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC34View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC34Doc* CMFC34View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC34Doc)));
	return (CMFC34Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC34View ��Ϣ�������


void CMFC34View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC34Doc* pDoc = GetDocument();
	
	
	pDoc->pointx1 = point.x;
	pDoc->pointy1 = point.y;
	
	CView::OnLButtonDown(nFlags, point);
}


void CMFC34View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CMFC34Doc* pDoc = GetDocument();
	CClientDC dc(this);
	pDoc->pointx2 = point.x;
	pDoc->pointy2 = point.y;
	//if (pDoc->pointx1 != 0 && pDoc->pointy1 != 0 && pDoc->pointx2 != 0 && pDoc->pointy2 != 0)
		dc.Rectangle(pDoc->pointx1, pDoc->pointy1, pDoc->pointx2, pDoc->pointy2);
		this->InvalidateRect(NULL, false);
	CView::OnLButtonUp(nFlags, point);
}


void CMFC34View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC34Doc* pDoc = GetDocument();

	if (nFlags&MK_LBUTTON)
	{
		pDoc->pointx3 = point.x;
		pDoc->pointy3 = point.y;
		Invalidate();
	}

	
	CView::OnMouseMove(nFlags, point);
}
