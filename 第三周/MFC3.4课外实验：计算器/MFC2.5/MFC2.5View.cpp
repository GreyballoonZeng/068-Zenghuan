
// MFC2.5View.cpp : CMFC25View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC2.5.h"
#endif

#include "MFC2.5Doc.h"
#include "MFC2.5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC25View

IMPLEMENT_DYNCREATE(CMFC25View, CView)

BEGIN_MESSAGE_MAP(CMFC25View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC25View 构造/析构

CMFC25View::CMFC25View()
{
	// TODO: 在此处添加构造代码

}

CMFC25View::~CMFC25View()
{
}

BOOL CMFC25View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC25View 绘制

void CMFC25View::OnDraw(CDC* pDC)
{
	CMFC25Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->crA.left = 100; pDoc->crA.top = 100; pDoc->crA.right = 300; pDoc->crA.bottom = 300;//定义矩形位置
	pDoc->crB.left = 350; pDoc->crB.top = 100; pDoc->crB.right = 550; pDoc->crB.bottom = 300;
	pDoc->crC.left = 600; pDoc->crC.top = 100; pDoc->crC.right =800; pDoc->crC.bottom = 300;
	pDoc->crD.left = 850; pDoc->crD.top = 100; pDoc->crD.right = 1050; pDoc->crD.bottom = 300;

	pDC->Rectangle(pDoc->crA); pDC->TextOutW(140, 70, pDoc->s1);//输出矩形名称
	pDC->Rectangle(pDoc->crB); pDC->TextOutW(390, 70, pDoc->s2);
	pDC->Rectangle(pDoc->crC); pDC->TextOutW(640, 70, pDoc->s3);
	pDC->Rectangle(pDoc->crD); pDC->TextOutW(890, 70, pDoc->s4);

	pDC->TextOutW(200, 200, pDoc->str1);  //输出矩形中的数值、结果、符号
	pDC->TextOutW(450, 200, pDoc->str2);
	pDC->TextOutW(900, 200, pDoc->D);
	pDC->TextOutW(650, 200, pDoc->str3);
	
	//if (pDoc->count == 2)pDC->TextOutW(950, 200, pDoc->str3);
	//if (pDoc->count == 3)pDC->TextOutW(950, 200, pDoc->str3);
	//if (pDoc->count == 4)pDC->TextOutW(950, 200, pDoc->str3);


	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC25View 诊断

#ifdef _DEBUG
void CMFC25View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC25View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC25Doc* CMFC25View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC25Doc)));
	return (CMFC25Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC25View 消息处理程序


void CMFC25View::OnLButtonDown(UINT nFlags, CPoint point)
{
	

	

	
	CMFC25Doc* pDoc = GetDocument();
	CClientDC dc(this);
	if (point.x > pDoc->crA.left&&point.x<pDoc->crA.right&&point.y>pDoc->crA.top&&point.y < pDoc->crA.bottom){
		pDoc->A = rand() % 50 + 20;
		pDoc->str1.Format(_T("%d"), pDoc->A);
	}
	 if (point.x > pDoc->crB.left&&point.x<pDoc->crB.right&&point.y>pDoc->crB.top&&point.y < pDoc->crB.bottom){
			 pDoc->B = rand() % 50 + 20;
			 pDoc->str2.Format(_T("%d"), pDoc->B);
	}
	
	 if (point.x > pDoc->crD.left&&point.x<pDoc->crD.right&&point.y>pDoc->crD.top&&point.y < pDoc->crD.bottom) {
		 pDoc->count=pDoc->count++ % 4;
		if (pDoc->count == 1) { pDoc->D = _T("＋");  }
		if (pDoc->count == 2) { pDoc->D = _T("－ "); }
		if (pDoc->count == 3) { pDoc->D = _T("×"); }
		if (pDoc->count == 4){pDoc->D = _T("÷");}
		pDoc->count=pDoc->count % 4;
	
		
    }
   if (point.x > pDoc->crC.left&&point.x<pDoc->crC.right&&point.y>pDoc->crC.top&&point.y < pDoc->crC.bottom){
		
		if(pDoc->count%4==1)pDoc->C = pDoc->A + pDoc->B;
		if (pDoc->count%4 ==2)pDoc->C = pDoc->A - pDoc->B;
		if (pDoc->count%4 == 3)pDoc->C = pDoc->A * pDoc->B;
		if (pDoc->count %4==0)pDoc->C = pDoc->A / pDoc->B;
		pDoc->str3.Format(_T("%d"), pDoc->C);
	}

	this->InvalidateRect(NULL,false);
		CView::OnLButtonDown(nFlags, point);
	

}
