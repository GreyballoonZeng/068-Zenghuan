
// MFC2.3View.cpp : CMFC23View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC2.3.h"
#endif

#include "MFC2.3Doc.h"
#include "MFC2.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC23View

IMPLEMENT_DYNCREATE(CMFC23View, CView)

BEGIN_MESSAGE_MAP(CMFC23View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFC23View 构造/析构

CMFC23View::CMFC23View()
{
	// TODO: 在此处添加构造代码

}

CMFC23View::~CMFC23View()
{
}

BOOL CMFC23View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC23View 绘制

void CMFC23View::OnDraw(CDC* pDC)
{
	CMFC23Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->TextOutW(pDoc->pointx, pDoc->pointy, pDoc->s);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC23View 诊断

#ifdef _DEBUG
void CMFC23View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC23View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC23Doc* CMFC23View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC23Doc)));
	return (CMFC23Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC23View 消息处理程序


void CMFC23View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC23Doc* pDoc = GetDocument();
	pDoc->s = _T("鼠标左键正在被按下");
	pDoc->pointx = point.x;
	pDoc->pointy = point.y;
	this->Invalidate();
	CView::OnLButtonDown(nFlags, point);
}


void CMFC23View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC23Doc* pDoc = GetDocument();
	pDoc->s = _T("鼠标左键正在抬起");
	pDoc->pointx = point.x;
	pDoc->pointy = point.y;
	this->Invalidate();
	CView::OnLButtonUp(nFlags, point);
}
