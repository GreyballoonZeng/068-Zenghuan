
// MFC5.2View.cpp : CMFC52View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC5.2.h"
#endif

#include "MFC5.2Doc.h"
#include "MFC5.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC52View

IMPLEMENT_DYNCREATE(CMFC52View, CView)

BEGIN_MESSAGE_MAP(CMFC52View, CView)
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC52View ����/����

CMFC52View::CMFC52View()
{
	// TODO: �ڴ˴���ӹ������
	cr.left = 250;
	cr.top = 250;
	cr.right = 350;
	cr.bottom = 400; 
}

CMFC52View::~CMFC52View()
{
}

BOOL CMFC52View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC52View ����

void CMFC52View::OnDraw(CDC* pDC)
{
	CMFC52Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CBrush *newBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	CBrush *pOldBrush = pDC->SelectObject(newBrush);
	pDC->Rectangle(&cr);
	pDC->SelectObject(pOldBrush);  
	   if (x > 340)
	   {
		   y += 20;
		   x = 250;
	   }
	pDC->TextOutW(x+300,y+200, s2);
	pDC->TextOutW(x+320, y+210, s1);
      x+= 20;
	
		// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC52View ���

#ifdef _DEBUG
void CMFC52View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC52View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC52Doc* CMFC52View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC52Doc)));
	return (CMFC52Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC52View ��Ϣ�������


void CMFC52View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//CClientDC dc(this);
  	 
		s1.Format(_T("%c"), nChar);	
		s2 = s1 + s2;
		s2.Format(_T("%c"), nChar);

		this->InvalidateRect(NULL, false);
	
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CMFC52View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	if (point.x < 350 && point.x>250 && point.y < 400 && point.y>250)
	{
		x = point.x;
		y = point.y;
	}
	this->InvalidateRect(NULL, false);
	CView::OnLButtonDown(nFlags, point);
}
