
// MFCA4.1View.cpp : CMFCA41View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCA4.1.h"
#endif

#include "MFCA4.1Doc.h"
#include "MFCA4.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCA41View

IMPLEMENT_DYNCREATE(CMFCA41View, CView)

BEGIN_MESSAGE_MAP(CMFCA41View, CView)
	ON_COMMAND(ID_32771, &CMFCA41View::On32771)
END_MESSAGE_MAP()

// CMFCA41View ����/����

CMFCA41View::CMFCA41View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCA41View::~CMFCA41View()
{
}

BOOL CMFCA41View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCA41View ����

void CMFCA41View::OnDraw(CDC* pDC)
{
	CMFCA41Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	

		//this->InvalidateRect(NULL, false);
	
}


// CMFCA41View ���

#ifdef _DEBUG
void CMFCA41View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCA41View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCA41Doc* CMFCA41View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCA41Doc)));
	return (CMFCA41Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCA41View ��Ϣ�������


void CMFCA41View::On32771()
{
	CClientDC dc(this);
	CRect crect;
	for (int i = 30; i>1; i--)
	{
		color = RGB(red, green, blue);
		CPen newPen(PS_DOT, width, color);
		CPen *oldPen = dc.SelectObject(&newPen);
		t = i*10;
		//width += 1;
		red +=15;
		green += 10;
		blue +=5;
		dc.Ellipse(px - t, py - t, px + t, py + t);

	}
	

}
