
// MFC2.2View.cpp : CMFC22View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC2.2.h"
#endif

#include "MFC2.2Doc.h"
#include "MFC2.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC22View

IMPLEMENT_DYNCREATE(CMFC22View, CView)

BEGIN_MESSAGE_MAP(CMFC22View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC22View ����/����

CMFC22View::CMFC22View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC22View::~CMFC22View()
{
}

BOOL CMFC22View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC22View ����

void CMFC22View::OnDraw(CDC* pDC)
{
	CMFC22Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString s = _T("���������ͻ��������������Բ��");
	pDC->TextOutW(20, 20, s);
	pDC->Ellipse(pDoc->cr);
}


// CMFC22View ���

#ifdef _DEBUG
void CMFC22View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC22View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC22Doc* CMFC22View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC22Doc)));
	return (CMFC22Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC22View ��Ϣ�������


void CMFC22View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC22Doc* pDoc = GetDocument();
	CClientDC dc(this);
	int r1 = rand() % 100 + 30;
	int r2 = rand() % 100 + 30;
	
	pDoc->cr.left = point.x + r1;
	pDoc->cr.top=point.y + r2;
	pDoc->cr.right = point.x - r1;
	pDoc->cr.bottom= point.y - r2;
	this->Invalidate();
	
	CView::OnLButtonDown(nFlags, point);
}
