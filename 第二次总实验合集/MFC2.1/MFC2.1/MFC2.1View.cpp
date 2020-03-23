
// MFC2.1View.cpp : CMFC21View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC2.1.h"
#endif

#include "MFC2.1Doc.h"
#include "MFC2.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC21View

IMPLEMENT_DYNCREATE(CMFC21View, CView)

BEGIN_MESSAGE_MAP(CMFC21View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC21View 构造/析构

CMFC21View::CMFC21View()
{
	// TODO: 在此处添加构造代码

}

CMFC21View::~CMFC21View()
{
}

BOOL CMFC21View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC21View 绘制

void CMFC21View::OnDraw(CDC* pDC)
{
	CMFC21Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Ellipse(pDoc->cr);

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC21View 诊断

#ifdef _DEBUG
void CMFC21View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC21View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC21Doc* CMFC21View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC21Doc)));
	return (CMFC21Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC21View 消息处理程序


void CMFC21View::OnLButtonDown(UINT nFlags, CPoint point)
{
	CMFC21Doc* pDoc = GetDocument();
	CRect rect;
	GetClientRect(&rect);
	int minr;//长和宽之差的绝对值
	if ((rect.bottom - rect.top) >( rect.right - rect.left)){
		minr = (rect.bottom - rect.top) - (rect.right - rect.left);
	pDoc->cr.left = rect.left; pDoc->cr.right = rect.right;
	pDoc->cr.top = rect.top +minr / 2; pDoc->cr.bottom = rect.bottom - minr / 2;
	}
	else {
		minr = (rect.right - rect.left) - (rect.bottom - rect.top);
		pDoc->cr.left = rect.left + minr / 2; pDoc->cr.right = rect.right - minr / 2;
		pDoc->cr.top = rect.top; pDoc->cr.bottom = rect.bottom;
	}
	this->InvalidateRect(NULL,true);

	CView::OnLButtonDown(nFlags, point);
}
