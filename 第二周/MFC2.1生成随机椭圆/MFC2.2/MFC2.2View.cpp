
// MFC2.2View.cpp : CMFC22View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC2.2.h"
#endif

#include "MFC2.2Doc.h"
#include "MFC2.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC22View

IMPLEMENT_DYNCREATE(CMFC22View, CView)

BEGIN_MESSAGE_MAP(CMFC22View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC22View 构造/析构

CMFC22View::CMFC22View()
{
	// TODO: 在此处添加构造代码

}

CMFC22View::~CMFC22View()
{
}

BOOL CMFC22View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC22View 绘制

void CMFC22View::OnDraw(CDC* pDC)
{
	CMFC22Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString s = _T("请左键点击客户区以生成随机椭圆：");
	pDC->TextOutW(20, 20, s);
	pDC->Ellipse(pDoc->cr);
}


// CMFC22View 诊断

#ifdef _DEBUG
void CMFC22View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC22View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC22Doc* CMFC22View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC22Doc)));
	return (CMFC22Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC22View 消息处理程序


void CMFC22View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC22Doc* pDoc = GetDocument();
	CClientDC dc(this);
	int r1 = rand() % 100 + 30;
	int r2 = rand() % 100 + 30;
	
	pDoc->cr.left = point.x + r1;
	pDoc->cr.top=point.y + r2;
	pDoc->cr.right = point.x - r1;
	pDoc->cr.bottom= point.y - r2;
	this->Invalidate();
	
	CView::OnLButtonDown(nFlags, point);
}
