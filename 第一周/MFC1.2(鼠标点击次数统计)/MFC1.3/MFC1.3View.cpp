
// MFC1.3View.cpp : CMFC13View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC1.3.h"
#endif

#include "MFC1.3Doc.h"
#include "MFC1.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC13View

IMPLEMENT_DYNCREATE(CMFC13View, CView)

BEGIN_MESSAGE_MAP(CMFC13View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFC13View ����/����

CMFC13View::CMFC13View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC13View::~CMFC13View()
{
}

BOOL CMFC13View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC13View ����

void CMFC13View::OnDraw(CDC* /*pDC*/)
{
	CMFC13Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC13View ���

#ifdef _DEBUG
void CMFC13View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC13View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC13Doc* CMFC13View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC13Doc)));
	return (CMFC13Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC13View ��Ϣ�������


void CMFC13View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnLButtonDown(nFlags, point);
	CMFC13Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if(set==1)
	pDoc->count++;
	set = 0;
    
}


void CMFC13View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CView::OnLButtonDown(nFlags, point);
	CMFC13Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString s;
	s.Format(_T("������������%d��"), pDoc->count);
	CClientDC dc(this);
	dc.TextOutW(200, 200, s);
}


void CMFC13View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	set = 1;
	CView::OnLButtonUp(nFlags, point);
}
