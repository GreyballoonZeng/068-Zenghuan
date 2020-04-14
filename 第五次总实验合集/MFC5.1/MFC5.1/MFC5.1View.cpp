
// MFC5.1View.cpp : CMFC51View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC5.1.h"
#endif

#include "MFC5.1Doc.h"
#include "MFC5.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC51View

IMPLEMENT_DYNCREATE(CMFC51View, CView)

BEGIN_MESSAGE_MAP(CMFC51View, CView)
	ON_COMMAND(ID_FILE_OPEN, &CMFC51View::OnFileOpen)
END_MESSAGE_MAP()

// CMFC51View ����/����

CMFC51View::CMFC51View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC51View::~CMFC51View()
{
}

BOOL CMFC51View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC51View ����

void CMFC51View::OnDraw(CDC* /*pDC*/)
{
	CMFC51Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC51View ���

#ifdef _DEBUG
void CMFC51View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC51View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC51Doc* CMFC51View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC51Doc)));
	return (CMFC51Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC51View ��Ϣ�������


void CMFC51View::OnFileOpen()
{
	CClientDC dc(this);
	CFileDialog cfd(true);//trueΪ�򿪣�falseΪ���Ϊ
	int r = cfd.DoModal();
	if (r == IDOK) {
    CString filename = cfd.GetPathName();
	CImage img;
	img.Load(filename);
	img.Draw(dc.m_hDC, 0, 0,img.GetWidth(),img.GetHeight());
	dc.TextOutW(500, 300, filename);
	}
	
	
}
