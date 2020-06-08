
// MFC3.3View.cpp : CMFC33View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3.3.h"
#endif

#include "MFC3.3Doc.h"
#include "MFC3.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC33View

IMPLEMENT_DYNCREATE(CMFC33View, CView)

BEGIN_MESSAGE_MAP(CMFC33View, CView)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFC33View 构造/析构

CMFC33View::CMFC33View()
{
	// TODO: 在此处添加构造代码
	set = true;
	N = 5;
	
	for (int i = 0; i < N; i++)
	{ 
		flag.Add(-1);
		int t = (i + 1) * 200;
		CRect rect (t, 0, t + 30, 30);
			cr.Add(rect);

	}
}

CMFC33View::~CMFC33View()
{
}

BOOL CMFC33View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC33View 绘制

void CMFC33View::OnDraw(CDC* pDC)
{
	CMFC33Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (set)
	{
		for (int i = 0; i < N; i++)
		{
			SetTimer(i, rand() %45+ 10, NULL);
			
		}
	  set = false;

	}


	for (int i = 0; i < N; i++)
	{
		pDC->Ellipse(cr[i]);
	}
}


// CMFC33View 诊断

#ifdef _DEBUG
void CMFC33View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC33View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC33Doc* CMFC33View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC33Doc)));
	return (CMFC33Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC33View 消息处理程序


void CMFC33View::OnTimer(UINT_PTR nIDEvent)
{
	CRect cr1;
	GetClientRect(cr1);
	int i = nIDEvent;
	
		cr[i].top += 4;
		cr[i].bottom +=4;
		if (cr[i].bottom >cr1.bottom)flag[i] = 1;
	
	if (cr[i].top!=0&&flag[i]==1)
	{
			cr[i].top = cr[i].top - 8;
			cr[i].bottom = cr[i].bottom -8;
	}
	if (cr[i].top == 0)
		flag[i] = -1;
	this->InvalidateRect(NULL, true);
	
	CView::OnTimer(nIDEvent);
}
