
// MFC3.2View.cpp : CMFC32View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC3.2.h"
#endif

#include "MFC3.2Doc.h"
#include "MFC3.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC32View

IMPLEMENT_DYNCREATE(CMFC32View, CView)

BEGIN_MESSAGE_MAP(CMFC32View, CView)
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC32View ����/����

CMFC32View::CMFC32View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC32View::~CMFC32View()
{
}

BOOL CMFC32View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC32View ����

void CMFC32View::OnDraw(CDC* pDC)
{
	CMFC32Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString s = _T("���ڰ�����ͻ����WSADΪ�������ң����ͷ��Ϊʹ���������Ͻ������Ҽ�ͷ��Ϊʹ���������½���С������������ʱ�����λָ���ԭ����С");
	pDC->TextOutW(10, 10, s);

	pDC->Rectangle(pDoc->cr1 );

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC32View ���

#ifdef _DEBUG
void CMFC32View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC32View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC32Doc* CMFC32View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC32Doc)));
	return (CMFC32Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC32View ��Ϣ�������


void CMFC32View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{	
	CMFC32Doc* pDoc = GetDocument();

	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	GetClientRect(pDoc->cr2);
	switch (nChar) {
		
	case 'W':
		if(pDoc->cr1.top>=5)
		{
			pDoc->cr1.top -= 5;
			pDoc->cr1.bottom -= 5;
		}
		break;
	case 'S':
		if (pDoc->cr1.bottom  <= pDoc->cr2.bottom - 5)
		{
			pDoc->cr1.top += 5;
			pDoc->cr1.bottom += 5;
		}break;
	case 'A':
		if (pDoc->cr1.left >=5 )
		{
			pDoc->cr1.left -= 5;
			pDoc->cr1.right -= 5;
		}break;
	case 'D':
		if (pDoc->cr1.right < pDoc->cr2.right - 5)
		{
			pDoc->cr1.left += 5;
			pDoc->cr1.right += 5;
		}break;
	case VK_LEFT:
		if (pDoc->cr1.left >= 5 && pDoc->cr1.top >= 5)
		{
			pDoc->cr1.left -= 5;
			pDoc->cr1.top -= 5;
		}break;
	case VK_RIGHT:
		
	    {
			pDoc->cr1.left += 5;
			pDoc->cr1.top += 5;
	}break;

	}
	this->InvalidateRect(NULL,true);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMFC32View::OnLButtonDown(UINT nFlags, CPoint point)
{
	CMFC32Doc* pDoc = GetDocument();
	pDoc->cr1.left = 400;
	pDoc->cr1.right = 600;
	pDoc->cr1.top = 200;
	pDoc->cr1.bottom = 400;
	this->InvalidateRect(NULL,true);
	CView::OnLButtonDown(nFlags, point);
}
