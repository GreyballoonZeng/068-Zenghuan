
// MFC6.3View.h : CMFC63View 类的接口
//

#pragma once


class CMFC63View : public CView
{
protected: // 仅从序列化创建
	CMFC63View();
	DECLARE_DYNCREATE(CMFC63View)

// 特性
public:
	CMFC63Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC63View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	bool set1 = true;
	bool set2 = false;//暂停开关
	int flag = 1;//1为往右走，2为往左走
	CRect cr;
	CRect cr1;

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC6.3View.cpp 中的调试版本
inline CMFC63Doc* CMFC63View::GetDocument() const
   { return reinterpret_cast<CMFC63Doc*>(m_pDocument); }
#endif

