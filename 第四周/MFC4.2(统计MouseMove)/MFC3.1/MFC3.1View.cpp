
// MFC3.1View.cpp : CMFC31View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3.1.h"
#endif

#include "MFC3.1Doc.h"
#include "MFC3.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC31View

IMPLEMENT_DYNCREATE(CMFC31View, CView)

BEGIN_MESSAGE_MAP(CMFC31View, CView)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC31View 构造/析构

CMFC31View::CMFC31View()
{
	// TODO: 在此处添加构造代码

}

CMFC31View::~CMFC31View()
{
}

BOOL CMFC31View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC31View 绘制

void CMFC31View::OnDraw(CDC* pDC)
{
	CMFC31Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString s1;
	CString s = _T("请按下左键并拖动后释放");
	pDC->TextOutW(100, 100, s);
	pDC->MoveTo(pDoc->countPX1, pDoc->countPY1);
	pDC->LineTo(pDoc->countPX2, pDoc->countPY2);
	s1.Format(_T("MouseMove发生了%d次移动,横向移动%d个像素点发生一次MouseMove事件。"), pDoc->count, pDoc->countPX2 - pDoc->countPX1);

}


// CMFC31View 诊断

#ifdef _DEBUG
void CMFC31View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC31View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC31Doc* CMFC31View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC31Doc)));
	return (CMFC31Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC31View 消息处理程序


void CMFC31View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/
	
	CMFC31Doc* pDoc = GetDocument();
	if (nFlags&MK_LBUTTON) {
		(pDoc->count)++;
	}
	
	CView::OnMouseMove(nFlags, point);
}


void CMFC31View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC31Doc* pDoc = GetDocument();
	CString s;
	pDoc->countPX2 = point.x;
	pDoc->countPY2 = point.y;
	s.Format(_T("MouseMove发生了%d次移动,横向移动%d个像素点发生一次MouseMove事件。"), pDoc->count,pDoc->countPX2-pDoc->countPX1);
	CClientDC dc(this);
	dc.TextOutW(400, 400, s);
	pDoc->count = 0;
	InvalidateRect(NULL, false);
	CView::OnLButtonUp(nFlags, point);
}


void CMFC31View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC31Doc* pDoc = GetDocument();
	pDoc->countPX1 = point.x;
	pDoc->countPY1 = point.y;
	CView::OnLButtonDown(nFlags, point);
}
