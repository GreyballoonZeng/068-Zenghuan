
// MFC1.2View.cpp : CMFC12View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC1.2.h"
#endif

#include "MFC1.2Doc.h"
#include "MFC1.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC12View

IMPLEMENT_DYNCREATE(CMFC12View, CView)

BEGIN_MESSAGE_MAP(CMFC12View, CView)
END_MESSAGE_MAP()

// CMFC12View ����/����

CMFC12View::CMFC12View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC12View::~CMFC12View()
{
}

BOOL CMFC12View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC12View ����

void CMFC12View::OnDraw(CDC* pDC)
{
	CMFC12Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDC->TextOutW(200, 200, pDoc->s);
	pDC->TextOutW(400, 200, pDoc->A);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC12View ���

#ifdef _DEBUG
void CMFC12View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC12View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC12Doc* CMFC12View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC12Doc)));
	return (CMFC12Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC12View ��Ϣ�������
