
// MFCA4.1View.h : CMFCA41View 类的接口
//

#pragma once


class CMFCA41View : public CView
{
protected: // 仅从序列化创建
	CMFCA41View();
	DECLARE_DYNCREATE(CMFCA41View)

// 特性
public:
	CMFCA41Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCA41View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	int px=500 , py=300;
	int t;
	int red = 25, green = 25, blue = 25, width =5;
	int color = RGB(red, green, blue);
protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On32771();
};

#ifndef _DEBUG  // MFCA4.1View.cpp 中的调试版本
inline CMFCA41Doc* CMFCA41View::GetDocument() const
   { return reinterpret_cast<CMFCA41Doc*>(m_pDocument); }
#endif

