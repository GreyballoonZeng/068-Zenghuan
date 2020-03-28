
// MFC4.3View.cpp : CMFC43View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC4.3.h"
#endif

#include "MFC4.3Doc.h"
#include "MFC4.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC43View

IMPLEMENT_DYNCREATE(CMFC43View, CView)

BEGIN_MESSAGE_MAP(CMFC43View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFC43View ����/����

CMFC43View::CMFC43View()
{
	BITMAP BM;
	m_Bitmap.LoadBitmap(IDB_BITMAP1);
	m_Bitmap.GetBitmap(&BM);
	m_nWidth = BM.bmWidth;
	m_nHeight = BM.bmHeight;


}

CMFC43View::~CMFC43View()
{
}

BOOL CMFC43View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC43View ����

void CMFC43View::OnDraw(CDC* pDC)
{
	CMFC43Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(m_Bitmap);
	pDC->BitBlt(0, 0, m_nWidth, m_nHeight, &MemDC, 0, 0, SRCCOPY);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC43View ��ӡ

BOOL CMFC43View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC43View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC43View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMFC43View ���

#ifdef _DEBUG
void CMFC43View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC43View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC43Doc* CMFC43View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC43Doc)));
	return (CMFC43Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC43View ��Ϣ�������
