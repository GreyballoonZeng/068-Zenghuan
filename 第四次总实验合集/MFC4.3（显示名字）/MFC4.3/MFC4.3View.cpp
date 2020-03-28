
// MFC4.3View.cpp : CMFC43View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFC43View 构造/析构

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
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC43View 绘制

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
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC43View 打印

BOOL CMFC43View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC43View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFC43View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFC43View 诊断

#ifdef _DEBUG
void CMFC43View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC43View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC43Doc* CMFC43View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC43Doc)));
	return (CMFC43Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC43View 消息处理程序
