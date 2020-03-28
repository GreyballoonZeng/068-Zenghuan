
// MFC4.4View.cpp : CMFC44View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC4.4.h"
#endif

#include "MFC4.4Doc.h"
#include "MFC4.4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC44View

IMPLEMENT_DYNCREATE(CMFC44View, CView)

BEGIN_MESSAGE_MAP(CMFC44View, CView)
	ON_COMMAND(ID_32771, &CMFC44View::On1)
	ON_COMMAND(ID_32772, &CMFC44View::On2)
	ON_COMMAND(ID_32773, &CMFC44View::On3)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFC44View ����/����

CMFC44View::CMFC44View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC44View::~CMFC44View()
{
}

BOOL CMFC44View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC44View ����

void CMFC44View::OnDraw(CDC* pDC)
{
	CMFC44Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	if (flag == 1) {
		pDC->MoveTo(px, py);
		pDC->LineTo(px1, py1);
		px = 0; py = 0;
		px1 = 0; py1 = 0;
	}
	else if (flag == 2) {
		CRect cr(px, py, px1, py1);
		pDC->Rectangle(cr);
		px = 0; py = 0;
		px1 = 0; py1 = 0;
	}
	else if (flag == 3) {
		CRect cr1(px, py, px1, py1);
		pDC->Ellipse(cr1);
		px = 0; py = 0;
		px1 = 0; py1 = 0;

	}
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC44View ���

#ifdef _DEBUG
void CMFC44View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC44View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC44Doc* CMFC44View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC44Doc)));
	return (CMFC44Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC44View ��Ϣ�������


void CMFC44View::On1()
{
	flag = 1;
	//Invalidate();
}


void CMFC44View::On2()
{
	flag = 2;
	//Invalidate();
}




void CMFC44View::On3()
{
	flag = 3;
	//Invalidate();
}


void CMFC44View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	px = point.x;
	py = point.y;
	//Invalidate();
	CView::OnLButtonDown(nFlags, point);
}


void CMFC44View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	px1 = point.x;
	py1 = point.y;
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}
