
// MFC6.2View.h : CMFC62View 类的接口
//

#pragma once


class CMFC62View : public CView
{
protected: // 仅从序列化创建
	CMFC62View();
	DECLARE_DYNCREATE(CMFC62View)

// 特性
public:
	CMFC62Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC62View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	CRect cr;
	int flag = 0;
	int a, b, c, d;

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC6.2View.cpp 中的调试版本
inline CMFC62Doc* CMFC62View::GetDocument() const
   { return reinterpret_cast<CMFC62Doc*>(m_pDocument); }
#endif

