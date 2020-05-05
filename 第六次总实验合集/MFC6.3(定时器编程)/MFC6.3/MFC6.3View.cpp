
// MFC6.3View.cpp : CMFC63View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC6.3.h"
#endif

#include "MFC6.3Doc.h"
#include "MFC6.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC63View

IMPLEMENT_DYNCREATE(CMFC63View, CView)

BEGIN_MESSAGE_MAP(CMFC63View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CMFC63View 构造/析构

CMFC63View::CMFC63View()
{
	// TODO: 在此处添加构造代码
	
}

CMFC63View::~CMFC63View()
{
}

BOOL CMFC63View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC63View 绘制

void CMFC63View::OnDraw(CDC* pDC)
{
	CMFC63Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	GetClientRect(&cr1);


	if (set1) {
		cr.left = 0;
		cr.right = 100;
		cr.top = cr1.bottom/2-50;
		cr.bottom = cr1.bottom/2+50;
		SetTimer(1, rand() % 45 + 10, NULL);
		set1= false;
	}


	pDC->Ellipse(cr);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC63View 诊断

#ifdef _DEBUG
void CMFC63View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC63View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC63Doc* CMFC63View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC63Doc)));
	return (CMFC63Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC63View 消息处理程序


void CMFC63View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(set2==false)
	    set2 = true;

	CView::OnLButtonDown(nFlags, point);
}


void CMFC63View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	


	if (flag == 1&&set2)
	{
		cr.left += 15;
		cr.right += 15;
		Invalidate();
		if (cr.right >= cr1.right)flag = 2;
	}
	else if(flag == 2 && set2)
	{
		cr.left -= 15; 
		cr.right -= 15;
		Invalidate();
		if (cr.left <= 0)flag = 1;
	}
	CView::OnTimer(nIDEvent);
}


void CMFC63View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	set2 = false;
	CView::OnLButtonDblClk(nFlags, point);
}
