
// MFC3.4Doc.h : CMFC34Doc 类的接口
//


#pragma once


class CMFC34Doc : public CDocument
{
protected: // 仅从序列化创建
	CMFC34Doc();
	DECLARE_DYNCREATE(CMFC34Doc)

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CMFC34Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	int pointx1, pointy1, pointx2, pointy2,pointx3,pointy3;
	//x1,y1,x2,y2存储矩形坐标，x3,y3存储鼠标滑动即时的坐标
	CRect cr;
protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
