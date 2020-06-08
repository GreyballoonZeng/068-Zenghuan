
// MFC5.2View.h : CMFC52View 类的接口
//

#pragma once


class CMFC52View : public CView
{
protected: // 仅从序列化创建
	CMFC52View();
	DECLARE_DYNCREATE(CMFC52View)

// 特性
public:
	CMFC52Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC52View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	CString s1, s2, s3;
	int x=250, y=300;
	CRect cr;
protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC5.2View.cpp 中的调试版本
inline CMFC52Doc* CMFC52View::GetDocument() const
   { return reinterpret_cast<CMFC52Doc*>(m_pDocument); }
#endif

