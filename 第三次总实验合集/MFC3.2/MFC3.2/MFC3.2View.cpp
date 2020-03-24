
// MFC3.2View.cpp : CMFC32View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3.2.h"
#endif

#include "MFC3.2Doc.h"
#include "MFC3.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC32View

IMPLEMENT_DYNCREATE(CMFC32View, CView)

BEGIN_MESSAGE_MAP(CMFC32View, CView)
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC32View 构造/析构

CMFC32View::CMFC32View()
{
	// TODO: 在此处添加构造代码

}

CMFC32View::~CMFC32View()
{
}

BOOL CMFC32View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC32View 绘制

void CMFC32View::OnDraw(CDC* pDC)
{
	CMFC32Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString s = _T("由于按键冲突，现WSAD为上下左右，左箭头键为使矩形向左上角增大，右箭头键为使矩形向右下角缩小，单击鼠标左键时，矩形恢复到原来大小");
	pDC->TextOutW(10, 10, s);

	pDC->Rectangle(pDoc->cr1 );

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC32View 诊断

#ifdef _DEBUG
void CMFC32View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC32View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC32Doc* CMFC32View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC32Doc)));
	return (CMFC32Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC32View 消息处理程序


void CMFC32View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{	
	CMFC32Doc* pDoc = GetDocument();

	// TODO: 在此添加消息处理程序代码和/或调用默认值
	GetClientRect(pDoc->cr2);
	switch (nChar) {
		
	case 'W':
		if(pDoc->cr1.top>=5)
		{
			pDoc->cr1.top -= 5;
			pDoc->cr1.bottom -= 5;
		}
		break;
	case 'S':
		if (pDoc->cr1.bottom  <= pDoc->cr2.bottom - 5)
		{
			pDoc->cr1.top += 5;
			pDoc->cr1.bottom += 5;
		}break;
	case 'A':
		if (pDoc->cr1.left >=5 )
		{
			pDoc->cr1.left -= 5;
			pDoc->cr1.right -= 5;
		}break;
	case 'D':
		if (pDoc->cr1.right < pDoc->cr2.right - 5)
		{
			pDoc->cr1.left += 5;
			pDoc->cr1.right += 5;
		}break;
	case VK_LEFT:
		if (pDoc->cr1.left >= 5 && pDoc->cr1.top >= 5)
		{
			pDoc->cr1.left -= 5;
			pDoc->cr1.top -= 5;
		}break;
	case VK_RIGHT:
		
	    {
			pDoc->cr1.left += 5;
			pDoc->cr1.top += 5;
	}break;

	}
	this->InvalidateRect(NULL,true);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMFC32View::OnLButtonDown(UINT nFlags, CPoint point)
{
	CMFC32Doc* pDoc = GetDocument();
	pDoc->cr1.left = 400;
	pDoc->cr1.right = 600;
	pDoc->cr1.top = 200;
	pDoc->cr1.bottom = 400;
	this->InvalidateRect(NULL,true);
	CView::OnLButtonDown(nFlags, point);
}
