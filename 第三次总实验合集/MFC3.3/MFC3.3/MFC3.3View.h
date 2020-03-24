
// MFC3.3View.h : CMFC33View 类的接口
//

#pragma once


class CMFC33View : public CView
{
protected: // 仅从序列化创建
	CMFC33View();
	DECLARE_DYNCREATE(CMFC33View)

// 特性
public:
	CMFC33Doc* GetDocument() const;

// 操作
public:
	int N;
	CArray<CRect, CRect> cr;
	CArray<int,int> flag;
	bool set;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC33View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // MFC3.3View.cpp 中的调试版本
inline CMFC33Doc* CMFC33View::GetDocument() const
   { return reinterpret_cast<CMFC33Doc*>(m_pDocument); }
#endif

