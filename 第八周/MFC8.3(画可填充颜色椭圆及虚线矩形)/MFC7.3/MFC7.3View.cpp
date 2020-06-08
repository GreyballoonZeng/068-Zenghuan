
// MFC7.3View.cpp : CMFC73View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC7.3.h"
#endif

#include "MFC7.3Doc.h"
#include "MFC7.3View.h"
#include "Dlg.h"
#include "Dlg2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC73View

IMPLEMENT_DYNCREATE(CMFC73View, CView)

BEGIN_MESSAGE_MAP(CMFC73View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()

	ON_COMMAND(ID_32771, &CMFC73View::OnDrawEllipse)

	ON_COMMAND(ID_32772, &CMFC73View::OnEllipseColor)
END_MESSAGE_MAP()

// CMFC73View 构造/析构

CMFC73View::CMFC73View()
{
	// TODO: 在此处添加构造代码


}

CMFC73View::~CMFC73View()
{
}

BOOL CMFC73View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC73View 绘制

void CMFC73View::OnDraw(CDC* pDC)
{
	CMFC73Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	pDC->Ellipse(cr);
	cr1 = cr;
	set = 1;
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC73View 诊断

#ifdef _DEBUG
void CMFC73View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC73View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC73Doc* CMFC73View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC73Doc)));
	return (CMFC73Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC73View 消息处理程序


void CMFC73View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	
		cr.left = point.x;
		cr.top = point.y;
	
		if (set==1) {
			CClientDC dc(this);
			int width = 1, color = RGB(10, 0, 0);
			CPen newPen(PS_DOT, width, color);
			CBrush br;
			br.CreateStockObject(NULL_BRUSH);
			CPen *oldPen = dc.SelectObject(&newPen);
			dc.SelectObject(&br);
			dc.Rectangle(&cr1);
			dc.SelectObject(oldPen);
			br.DeleteObject();
		}
	CView::OnLButtonDown(nFlags, point);
}


void CMFC73View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	if (nFlags&MK_LBUTTON) 
	{ 
		px2 = point.x;
		py2 = point.y;
		cr.right = px2;
		cr.bottom = py2;	
		Invalidate();
	}
	CView::OnMouseMove(nFlags, point);
}




void CMFC73View::OnDrawEllipse()
{
	Dlg dlg;	
	int r = dlg.DoModal();	
	if (r == IDOK) {
		cr.left = dlg.left;
		cr.right = dlg.right;
		cr.top = dlg.top;
		cr.bottom = dlg.bottom;
		Invalidate(); 
	}
	
}




void CMFC73View::OnEllipseColor()
{
	Dlg2 dlg;
	int r = dlg.DoModal();
	if (r == IDOK) {
		CClientDC dc(this);
		CBrush  newBrush(RGB(dlg.red,dlg.green,dlg.blue));
		CBrush *oldBrush = dc.SelectObject(&newBrush);
		dc.Ellipse(cr1);
			dc.SelectObject(oldBrush);
	}
}
