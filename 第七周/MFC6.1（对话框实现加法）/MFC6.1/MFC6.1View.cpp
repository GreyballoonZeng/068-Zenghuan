
// MFC6.1View.cpp : CMFC61View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC6.1.h"
#endif

#include "MFC6.1Doc.h"
#include "MFC6.1View.h"
#include "Dlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC61View

IMPLEMENT_DYNCREATE(CMFC61View, CView)

BEGIN_MESSAGE_MAP(CMFC61View, CView)
	ON_COMMAND(ID_32771, &CMFC61View::On32771)
END_MESSAGE_MAP()

// CMFC61View ����/����

CMFC61View::CMFC61View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC61View::~CMFC61View()
{
}

BOOL CMFC61View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC61View ����

void CMFC61View::OnDraw(CDC* /*pDC*/)
{
	CMFC61Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC61View ���

#ifdef _DEBUG
void CMFC61View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC61View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC61Doc* CMFC61View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC61Doc)));
	return (CMFC61Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC61View ��Ϣ�������


void CMFC61View::On32771()
{
	Dlg dlg;
		int t = dlg.DoModal();

}
