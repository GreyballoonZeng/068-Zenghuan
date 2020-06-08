
// MFC1.3View.cpp : CMFC13View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC1.3.h"
#endif

#include "MFC1.3Doc.h"
#include "MFC1.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC13View

IMPLEMENT_DYNCREATE(CMFC13View, CView)

BEGIN_MESSAGE_MAP(CMFC13View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFC13View 构造/析构

CMFC13View::CMFC13View()
{
	// TODO: 在此处添加构造代码

}

CMFC13View::~CMFC13View()
{
}

BOOL CMFC13View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC13View 绘制

void CMFC13View::OnDraw(CDC* /*pDC*/)
{
	CMFC13Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC13View 诊断

#ifdef _DEBUG
void CMFC13View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC13View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC13Doc* CMFC13View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC13Doc)));
	return (CMFC13Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC13View 消息处理程序


void CMFC13View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonDown(nFlags, point);
	CMFC13Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if(set==1)
	pDoc->count++;
	set = 0;
    
}


void CMFC13View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CView::OnLButtonDown(nFlags, point);
	CMFC13Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString s;
	s.Format(_T("鼠标左键共按下%d次"), pDoc->count);
	CClientDC dc(this);
	dc.TextOutW(200, 200, s);
}


void CMFC13View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	set = 1;
	CView::OnLButtonUp(nFlags, point);
}
