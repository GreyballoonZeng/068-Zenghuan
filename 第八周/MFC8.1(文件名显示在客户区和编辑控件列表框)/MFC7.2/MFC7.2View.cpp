
// MFC7.2View.cpp : CMFC72View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC7.2.h"
#endif

#include "MFC7.2Doc.h"
#include "MFC7.2View.h"
#include "Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC72View

IMPLEMENT_DYNCREATE(CMFC72View, CView)

BEGIN_MESSAGE_MAP(CMFC72View, CView)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_32771, &CMFC72View::OnPrintFileName)
END_MESSAGE_MAP()

// CMFC72View ����/����

CMFC72View::CMFC72View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC72View::~CMFC72View()
{
}

BOOL CMFC72View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC72View ����

void CMFC72View::OnDraw(CDC* /*pDC*/)
{
	CMFC72Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC72View ���

#ifdef _DEBUG
void CMFC72View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC72View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC72Doc* CMFC72View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC72Doc)));
	return (CMFC72Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC72View ��Ϣ�������



void CMFC72View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK) {
		filename= cfd.GetPathName();
		dc.TextOutW(500, 300, filename);
	}
	CView::OnLButtonDblClk(nFlags, point);
}


void CMFC72View::OnPrintFileName()
{   
	
		 Dlg dlg; 
	 dlg.str = filename;
	     int r1 = dlg.DoModal();
         
	}
	

