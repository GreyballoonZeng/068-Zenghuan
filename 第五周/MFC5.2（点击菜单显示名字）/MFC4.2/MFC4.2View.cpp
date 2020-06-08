
// MFC4.2View.cpp : CMFC42View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC4.2.h"
#endif

#include "MFC4.2Doc.h"
#include "MFC4.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC42View

IMPLEMENT_DYNCREATE(CMFC42View, CView)

BEGIN_MESSAGE_MAP(CMFC42View, CView)
	ON_COMMAND(ID_32771, &CMFC42View::On32771)
END_MESSAGE_MAP()

// CMFC42View 构造/析构

CMFC42View::CMFC42View()
{
	// TODO: 在此处添加构造代码

}

CMFC42View::~CMFC42View()
{
}

BOOL CMFC42View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC42View 绘制

void CMFC42View::OnDraw(CDC* /*pDC*/)
{
	CMFC42Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC42View 诊断

#ifdef _DEBUG
void CMFC42View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC42View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC42Doc* CMFC42View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC42Doc)));
	return (CMFC42Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC42View 消息处理程序


void CMFC42View::On32771()
{
	
	CString s=_T("曾欢");
	CClientDC dc(this);
	dc.TextOutW(500, 300, s);
}
