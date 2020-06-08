
// MFC7.3View.cpp : CMFC73View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC7.3.h"
#endif

#include "MFC7.3Doc.h"
#include "MFC7.3View.h"
#include "Dlg.h"
#include "Dlg2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC73View

IMPLEMENT_DYNCREATE(CMFC73View, CView)

BEGIN_MESSAGE_MAP(CMFC73View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()

	ON_COMMAND(ID_32771, &CMFC73View::OnDrawEllipse)

	ON_COMMAND(ID_32772, &CMFC73View::OnEllipseColor)
END_MESSAGE_MAP()

// CMFC73View ����/����

CMFC73View::CMFC73View()
{
	// TODO: �ڴ˴���ӹ������


}

CMFC73View::~CMFC73View()
{
}

BOOL CMFC73View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC73View ����

void CMFC73View::OnDraw(CDC* pDC)
{
	CMFC73Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	pDC->Ellipse(cr);
	cr1 = cr;
	set = 1;
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC73View ���

#ifdef _DEBUG
void CMFC73View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC73View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC73Doc* CMFC73View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC73Doc)));
	return (CMFC73Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC73View ��Ϣ�������


void CMFC73View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	
		cr.left = point.x;
		cr.top = point.y;
	
		if (set==1) {
			CClientDC dc(this);
			int width = 1, color = RGB(10, 0, 0);
			CPen newPen(PS_DOT, width, color);
			CBrush br;
			br.CreateStockObject(NULL_BRUSH);
			CPen *oldPen = dc.SelectObject(&newPen);
			dc.SelectObject(&br);
			dc.Rectangle(&cr1);
			dc.SelectObject(oldPen);
			br.DeleteObject();
		}
	CView::OnLButtonDown(nFlags, point);
}


void CMFC73View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	if (nFlags&MK_LBUTTON) 
	{ 
		px2 = point.x;
		py2 = point.y;
		cr.right = px2;
		cr.bottom = py2;	
		Invalidate();
	}
	CView::OnMouseMove(nFlags, point);
}




void CMFC73View::OnDrawEllipse()
{
	Dlg dlg;	
	int r = dlg.DoModal();	
	if (r == IDOK) {
		cr.left = dlg.left;
		cr.right = dlg.right;
		cr.top = dlg.top;
		cr.bottom = dlg.bottom;
		Invalidate(); 
	}
	
}




void CMFC73View::OnEllipseColor()
{
	Dlg2 dlg;
	int r = dlg.DoModal();
	if (r == IDOK) {
		CClientDC dc(this);
		CBrush  newBrush(RGB(dlg.red,dlg.green,dlg.blue));
		CBrush *oldBrush = dc.SelectObject(&newBrush);
		dc.Ellipse(cr1);
			dc.SelectObject(oldBrush);
	}
}
