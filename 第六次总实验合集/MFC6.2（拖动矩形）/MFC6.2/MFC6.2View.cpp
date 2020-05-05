
// MFC6.2View.cpp : CMFC62View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC6.2.h"
#endif

#include "MFC6.2Doc.h"
#include "MFC6.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC62View

IMPLEMENT_DYNCREATE(CMFC62View, CView)

BEGIN_MESSAGE_MAP(CMFC62View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFC62View 构造/析构

CMFC62View::CMFC62View()
{
	int c = rand() % 200;
	cr.left = c;
	cr.right = c + 150;
	cr.top = c + 50;
	cr.bottom = c + 250;

}

CMFC62View::~CMFC62View()
{
}

BOOL CMFC62View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC62View 绘制

void CMFC62View::OnDraw(CDC* pDC)
{
	CMFC62Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDC->Rectangle(cr);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC62View 诊断

#ifdef _DEBUG
void CMFC62View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC62View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC62Doc* CMFC62View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC62Doc)));
	return (CMFC62Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC62View 消息处理程序


void CMFC62View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (point.x<cr.right&&point.x>cr.left&&point.y<cr.bottom&&point.y>cr.top)
	{
		flag = 1;
	}
	a = point.x - cr.left;
	b = cr.right - point.x;
	c = point.y - cr.top;
	d = cr.bottom - point.y;
	CView::OnLButtonDown(nFlags, point);
}


void CMFC62View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (flag == 1) {
		cr.left = point.x - a;
		cr.right = point.x + b;
		cr.top = point.y - c;
		cr.bottom = point.y + d;
		Invalidate();
	}
	CView::OnMouseMove(nFlags, point);
}


void CMFC62View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (flag == 1)
		flag = 0;
	CView::OnLButtonUp(nFlags, point);
}
