
// MFC4.4View.cpp : CMFC44View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC4.4.h"
#endif

#include "MFC4.4Doc.h"
#include "MFC4.4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC44View

IMPLEMENT_DYNCREATE(CMFC44View, CView)

BEGIN_MESSAGE_MAP(CMFC44View, CView)
	ON_COMMAND(ID_32771, &CMFC44View::On1)
	ON_COMMAND(ID_32772, &CMFC44View::On2)
	ON_COMMAND(ID_32773, &CMFC44View::On3)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFC44View 构造/析构

CMFC44View::CMFC44View()
{
	// TODO: 在此处添加构造代码

}

CMFC44View::~CMFC44View()
{
}

BOOL CMFC44View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC44View 绘制

void CMFC44View::OnDraw(CDC* pDC)
{
	CMFC44Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	if (flag == 1) {
		pDC->MoveTo(px, py);
		pDC->LineTo(px1, py1);
		px = 0; py = 0;
		px1 = 0; py1 = 0;
	}
	else if (flag == 2) {
		CRect cr(px, py, px1, py1);
		pDC->Rectangle(cr);
		px = 0; py = 0;
		px1 = 0; py1 = 0;
	}
	else if (flag == 3) {
		CRect cr1(px, py, px1, py1);
		pDC->Ellipse(cr1);
		px = 0; py = 0;
		px1 = 0; py1 = 0;

	}
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC44View 诊断

#ifdef _DEBUG
void CMFC44View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC44View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC44Doc* CMFC44View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC44Doc)));
	return (CMFC44Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC44View 消息处理程序


void CMFC44View::On1()
{
	flag = 1;
	//Invalidate();
}


void CMFC44View::On2()
{
	flag = 2;
	//Invalidate();
}




void CMFC44View::On3()
{
	flag = 3;
	//Invalidate();
}


void CMFC44View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	px = point.x;
	py = point.y;
	//Invalidate();
	CView::OnLButtonDown(nFlags, point);
}


void CMFC44View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	px1 = point.x;
	py1 = point.y;
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}
