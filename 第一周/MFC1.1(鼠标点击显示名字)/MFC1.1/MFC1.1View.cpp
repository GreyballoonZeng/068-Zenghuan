
// MFC1.1View.cpp : CMFC11View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC1.1.h"
#endif

#include "MFC1.1Doc.h"
#include "MFC1.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC11View

IMPLEMENT_DYNCREATE(CMFC11View, CView)

BEGIN_MESSAGE_MAP(CMFC11View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC11View ����/����

CMFC11View::CMFC11View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC11View::~CMFC11View()
{
}

BOOL CMFC11View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC11View ����

void CMFC11View::OnDraw(CDC* pDC)
{
	CMFC11Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC11View ���

#ifdef _DEBUG
void CMFC11View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC11View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC11Doc* CMFC11View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC11Doc)));
	return (CMFC11Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC11View ��Ϣ�������


void CMFC11View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC11Doc* pDoc = GetDocument();
	
	
	CClientDC dc(this);
	dc.TextOutW(200, 200,pDoc->stuname);

	CView::OnLButtonDown(nFlags, point);
}
