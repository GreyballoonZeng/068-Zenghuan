
// MFC1.2View.cpp : CMFC12View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC1.2.h"
#endif

#include "MFC1.2Doc.h"
#include "MFC1.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC12View

IMPLEMENT_DYNCREATE(CMFC12View, CView)

BEGIN_MESSAGE_MAP(CMFC12View, CView)
END_MESSAGE_MAP()

// CMFC12View 构造/析构

CMFC12View::CMFC12View()
{
	// TODO: 在此处添加构造代码

}

CMFC12View::~CMFC12View()
{
}

BOOL CMFC12View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC12View 绘制

void CMFC12View::OnDraw(CDC* pDC)
{
	CMFC12Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDC->TextOutW(200, 200, pDoc->s);
	pDC->TextOutW(400, 200, pDoc->A);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC12View 诊断

#ifdef _DEBUG
void CMFC12View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC12View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC12Doc* CMFC12View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC12Doc)));
	return (CMFC12Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC12View 消息处理程序
