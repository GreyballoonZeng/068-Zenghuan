
// MFC4.2View.cpp : CMFC42View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC4.2.h"
#endif

#include "MFC4.2Doc.h"
#include "MFC4.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC42View

IMPLEMENT_DYNCREATE(CMFC42View, CView)

BEGIN_MESSAGE_MAP(CMFC42View, CView)
	ON_COMMAND(ID_32771, &CMFC42View::On32771)
END_MESSAGE_MAP()

// CMFC42View ����/����

CMFC42View::CMFC42View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC42View::~CMFC42View()
{
}

BOOL CMFC42View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC42View ����

void CMFC42View::OnDraw(CDC* /*pDC*/)
{
	CMFC42Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC42View ���

#ifdef _DEBUG
void CMFC42View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC42View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC42Doc* CMFC42View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC42Doc)));
	return (CMFC42Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC42View ��Ϣ�������


void CMFC42View::On32771()
{
	
	CString s=_T("����");
	CClientDC dc(this);
	dc.TextOutW(500, 300, s);
}
