
// MFC4.4View.h : CMFC44View 类的接口
//

#pragma once


class CMFC44View : public CView
{
protected: // 仅从序列化创建
	CMFC44View();
	DECLARE_DYNCREATE(CMFC44View)

// 特性
public:
	CMFC44Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC44View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	int px, py, px1, py1,flag;
protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On1();
	afx_msg void On2();

	afx_msg void On3();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC4.4View.cpp 中的调试版本
inline CMFC44Doc* CMFC44View::GetDocument() const
   { return reinterpret_cast<CMFC44Doc*>(m_pDocument); }
#endif

