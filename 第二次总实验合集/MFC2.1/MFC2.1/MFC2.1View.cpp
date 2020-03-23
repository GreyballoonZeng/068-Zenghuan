
// MFC2.1View.cpp : CMFC21View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC2.1.h"
#endif

#include "MFC2.1Doc.h"
#include "MFC2.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC21View

IMPLEMENT_DYNCREATE(CMFC21View, CView)

BEGIN_MESSAGE_MAP(CMFC21View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC21View ����/����

CMFC21View::CMFC21View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC21View::~CMFC21View()
{
}

BOOL CMFC21View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC21View ����

void CMFC21View::OnDraw(CDC* pDC)
{
	CMFC21Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Ellipse(pDoc->cr);

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC21View ���

#ifdef _DEBUG
void CMFC21View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC21View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC21Doc* CMFC21View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC21Doc)));
	return (CMFC21Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC21View ��Ϣ�������


void CMFC21View::OnLButtonDown(UINT nFlags, CPoint point)
{
	CMFC21Doc* pDoc = GetDocument();
	CRect rect;
	GetClientRect(&rect);
	int minr;//���Ϳ�֮��ľ���ֵ
	if ((rect.bottom - rect.top) >( rect.right - rect.left)){
		minr = (rect.bottom - rect.top) - (rect.right - rect.left);
	pDoc->cr.left = rect.left; pDoc->cr.right = rect.right;
	pDoc->cr.top = rect.top +minr / 2; pDoc->cr.bottom = rect.bottom - minr / 2;
	}
	else {
		minr = (rect.right - rect.left) - (rect.bottom - rect.top);
		pDoc->cr.left = rect.left + minr / 2; pDoc->cr.right = rect.right - minr / 2;
		pDoc->cr.top = rect.top; pDoc->cr.bottom = rect.bottom;
	}
	this->InvalidateRect(NULL,true);

	CView::OnLButtonDown(nFlags, point);
}
