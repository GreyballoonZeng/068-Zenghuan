
// MFC6.3View.cpp : CMFC63View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC6.3.h"
#endif

#include "MFC6.3Doc.h"
#include "MFC6.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC63View

IMPLEMENT_DYNCREATE(CMFC63View, CView)

BEGIN_MESSAGE_MAP(CMFC63View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CMFC63View ����/����

CMFC63View::CMFC63View()
{
	// TODO: �ڴ˴���ӹ������
	
}

CMFC63View::~CMFC63View()
{
}

BOOL CMFC63View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC63View ����

void CMFC63View::OnDraw(CDC* pDC)
{
	CMFC63Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	GetClientRect(&cr1);


	if (set1) {
		cr.left = 0;
		cr.right = 100;
		cr.top = cr1.bottom/2-50;
		cr.bottom = cr1.bottom/2+50;
		SetTimer(1, rand() % 45 + 10, NULL);
		set1= false;
	}


	pDC->Ellipse(cr);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC63View ���

#ifdef _DEBUG
void CMFC63View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC63View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC63Doc* CMFC63View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC63Doc)));
	return (CMFC63Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC63View ��Ϣ�������


void CMFC63View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(set2==false)
	    set2 = true;

	CView::OnLButtonDown(nFlags, point);
}


void CMFC63View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	


	if (flag == 1&&set2)
	{
		cr.left += 15;
		cr.right += 15;
		Invalidate();
		if (cr.right >= cr1.right)flag = 2;
	}
	else if(flag == 2 && set2)
	{
		cr.left -= 15; 
		cr.right -= 15;
		Invalidate();
		if (cr.left <= 0)flag = 1;
	}
	CView::OnTimer(nIDEvent);
}


void CMFC63View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	set2 = false;
	CView::OnLButtonDblClk(nFlags, point);
}
