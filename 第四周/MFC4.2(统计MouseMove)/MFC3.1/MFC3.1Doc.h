
// MFC3.1Doc.h : CMFC31Doc ��Ľӿ�
//


#pragma once


class CMFC31Doc : public CDocument
{
protected: // �������л�����
	CMFC31Doc();
	DECLARE_DYNCREATE(CMFC31Doc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CMFC31Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	int count;
	int countPX1;//��ǳ�ʼ�������x����
	int countPY1;//��ǳ�ʼ�������y����
	int countPX2;//���ĩβ�ɿ����x����
	int countPY2;//���ĩβ�ɿ����y����
protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
