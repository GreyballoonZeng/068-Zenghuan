
// MFC6.1View.h : CMFC61View 类的接口
//

#pragma once


class CMFC61View : public CView
{
protected: // 仅从序列化创建
	CMFC61View();
	DECLARE_DYNCREATE(CMFC61View)

// 特性
public:
	CMFC61Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC61View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On32771();
};

#ifndef _DEBUG  // MFC6.1View.cpp 中的调试版本
inline CMFC61Doc* CMFC61View::GetDocument() const
   { return reinterpret_cast<CMFC61Doc*>(m_pDocument); }
#endif

