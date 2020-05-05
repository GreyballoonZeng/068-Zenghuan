
// MFC6.4View.cpp : CMFC64View 类的实现
//

#include "stdafx.h"

// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC6.4.h"
#endif

#include "MFC6.4Doc.h"
#include "MFC6.4View.h"
#include "MyDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC64View

IMPLEMENT_DYNCREATE(CMFC64View, CView)

BEGIN_MESSAGE_MAP(CMFC64View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CMFC64View 构造/析构

CMFC64View::CMFC64View()
{
	// TODO: 在此处添加构造代码

}

CMFC64View::~CMFC64View()
{
}

BOOL CMFC64View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC64View 绘制

void CMFC64View::OnDraw(CDC* /*pDC*/)
{
	CMFC64Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC64View 打印

BOOL CMFC64View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC64View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFC64View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFC64View 诊断

#ifdef _DEBUG
void CMFC64View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC64View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC64Doc* CMFC64View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC64Doc)));
	return (CMFC64Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC64View 消息处理程序


void CMFC64View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	MyDlg *pD = new MyDlg;
	pD->Create(IDD_DIALOG1);
	pD->ShowWindow(1);
	CView::OnLButtonDblClk(nFlags, point);
}
