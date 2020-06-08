
// MFC3.3View.cpp : CMFC33View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC3.3.h"
#endif

#include "MFC3.3Doc.h"
#include "MFC3.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC33View

IMPLEMENT_DYNCREATE(CMFC33View, CView)

BEGIN_MESSAGE_MAP(CMFC33View, CView)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFC33View ����/����

CMFC33View::CMFC33View()
{
	// TODO: �ڴ˴���ӹ������
	set = true;
	N = 5;
	
	for (int i = 0; i < N; i++)
	{ 
		flag.Add(-1);
		int t = (i + 1) * 200;
		CRect rect (t, 0, t + 30, 30);
			cr.Add(rect);

	}
}

CMFC33View::~CMFC33View()
{
}

BOOL CMFC33View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC33View ����

void CMFC33View::OnDraw(CDC* pDC)
{
	CMFC33Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (set)
	{
		for (int i = 0; i < N; i++)
		{
			SetTimer(i, rand() %45+ 10, NULL);
			
		}
	  set = false;

	}


	for (int i = 0; i < N; i++)
	{
		pDC->Ellipse(cr[i]);
	}
}


// CMFC33View ���

#ifdef _DEBUG
void CMFC33View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC33View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC33Doc* CMFC33View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC33Doc)));
	return (CMFC33Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC33View ��Ϣ�������


void CMFC33View::OnTimer(UINT_PTR nIDEvent)
{
	CRect cr1;
	GetClientRect(cr1);
	int i = nIDEvent;
	
		cr[i].top += 4;
		cr[i].bottom +=4;
		if (cr[i].bottom >cr1.bottom)flag[i] = 1;
	
	if (cr[i].top!=0&&flag[i]==1)
	{
			cr[i].top = cr[i].top - 8;
			cr[i].bottom = cr[i].bottom -8;
	}
	if (cr[i].top == 0)
		flag[i] = -1;
	this->InvalidateRect(NULL, true);
	
	CView::OnTimer(nIDEvent);
}
