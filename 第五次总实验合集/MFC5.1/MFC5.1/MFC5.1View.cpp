
// MFC5.1View.cpp : CMFC51View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC5.1.h"
#endif

#include "MFC5.1Doc.h"
#include "MFC5.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC51View

IMPLEMENT_DYNCREATE(CMFC51View, CView)

BEGIN_MESSAGE_MAP(CMFC51View, CView)
	ON_COMMAND(ID_FILE_OPEN, &CMFC51View::OnFileOpen)
END_MESSAGE_MAP()

// CMFC51View 构造/析构

CMFC51View::CMFC51View()
{
	// TODO: 在此处添加构造代码

}

CMFC51View::~CMFC51View()
{
}

BOOL CMFC51View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC51View 绘制

void CMFC51View::OnDraw(CDC* /*pDC*/)
{
	CMFC51Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC51View 诊断

#ifdef _DEBUG
void CMFC51View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC51View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC51Doc* CMFC51View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC51Doc)));
	return (CMFC51Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC51View 消息处理程序


void CMFC51View::OnFileOpen()
{
	CClientDC dc(this);
	CFileDialog cfd(true);//true为打开，false为另存为
	int r = cfd.DoModal();
	if (r == IDOK) {
    CString filename = cfd.GetPathName();
	CImage img;
	img.Load(filename);
	img.Draw(dc.m_hDC, 0, 0,img.GetWidth(),img.GetHeight());
	dc.TextOutW(500, 300, filename);
	}
	
	
}
