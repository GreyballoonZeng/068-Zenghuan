
// MFC3.1View.cpp : CMFC31View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC3.1.h"
#endif

#include "MFC3.1Doc.h"
#include "MFC3.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC31View

IMPLEMENT_DYNCREATE(CMFC31View, CView)

BEGIN_MESSAGE_MAP(CMFC31View, CView)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC31View ����/����

CMFC31View::CMFC31View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC31View::~CMFC31View()
{
}

BOOL CMFC31View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC31View ����

void CMFC31View::OnDraw(CDC* pDC)
{
	CMFC31Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString s1;
	CString s = _T("�밴��������϶����ͷ�");
	pDC->TextOutW(100, 100, s);
	pDC->MoveTo(pDoc->countPX1, pDoc->countPY1);
	pDC->LineTo(pDoc->countPX2, pDoc->countPY2);
	s1.Format(_T("MouseMove������%d���ƶ�,�����ƶ�%d�����ص㷢��һ��MouseMove�¼���"), pDoc->count, pDoc->countPX2 - pDoc->countPX1);

}


// CMFC31View ���

#ifdef _DEBUG
void CMFC31View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC31View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC31Doc* CMFC31View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC31Doc)));
	return (CMFC31Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC31View ��Ϣ�������


void CMFC31View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/
	
	CMFC31Doc* pDoc = GetDocument();
	if (nFlags&MK_LBUTTON) {
		(pDoc->count)++;
	}
	
	CView::OnMouseMove(nFlags, point);
}


void CMFC31View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC31Doc* pDoc = GetDocument();
	CString s;
	pDoc->countPX2 = point.x;
	pDoc->countPY2 = point.y;
	s.Format(_T("MouseMove������%d���ƶ�,�����ƶ�%d�����ص㷢��һ��MouseMove�¼���"), pDoc->count,pDoc->countPX2-pDoc->countPX1);
	CClientDC dc(this);
	dc.TextOutW(400, 400, s);
	pDoc->count = 0;
	InvalidateRect(NULL, false);
	CView::OnLButtonUp(nFlags, point);
}


void CMFC31View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC31Doc* pDoc = GetDocument();
	pDoc->countPX1 = point.x;
	pDoc->countPY1 = point.y;
	CView::OnLButtonDown(nFlags, point);
}
