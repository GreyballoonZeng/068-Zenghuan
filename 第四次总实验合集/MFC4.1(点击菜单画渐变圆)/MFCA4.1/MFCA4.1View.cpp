
// MFCA4.1View.cpp : CMFCA41View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCA4.1.h"
#endif

#include "MFCA4.1Doc.h"
#include "MFCA4.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCA41View

IMPLEMENT_DYNCREATE(CMFCA41View, CView)

BEGIN_MESSAGE_MAP(CMFCA41View, CView)
	ON_COMMAND(ID_32771, &CMFCA41View::On32771)
END_MESSAGE_MAP()

// CMFCA41View 构造/析构

CMFCA41View::CMFCA41View()
{
	// TODO: 在此处添加构造代码

}

CMFCA41View::~CMFCA41View()
{
}

BOOL CMFCA41View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCA41View 绘制

void CMFCA41View::OnDraw(CDC* pDC)
{
	CMFCA41Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	

		//this->InvalidateRect(NULL, false);
	
}


// CMFCA41View 诊断

#ifdef _DEBUG
void CMFCA41View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCA41View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCA41Doc* CMFCA41View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCA41Doc)));
	return (CMFCA41Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCA41View 消息处理程序


void CMFCA41View::On32771()
{
	CClientDC dc(this);
	CRect crect;
	for (int i = 30; i>1; i--)
	{
		color = RGB(red, green, blue);
		CPen newPen(PS_DOT, width, color);
		CPen *oldPen = dc.SelectObject(&newPen);
		t = i*10;
		//width += 1;
		red +=15;
		green += 10;
		blue +=5;
		dc.Ellipse(px - t, py - t, px + t, py + t);

	}
	

}
