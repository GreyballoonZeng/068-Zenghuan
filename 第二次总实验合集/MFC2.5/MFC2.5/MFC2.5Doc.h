
// MFC2.5Doc.h : CMFC25Doc ��Ľӿ�
//


#pragma once


class CMFC25Doc : public CDocument
{
protected: // �������л�����
	CMFC25Doc();
	DECLARE_DYNCREATE(CMFC25Doc)

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
	virtual ~CMFC25Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	int A;int B;int C;//����A��B��C�е�ֵ
	CString D;//�洢����+ - * /
	CRect crA, crB, crC, crD;//����A��B��C��D
	CString s1, s2, s3, s4;//�洢��������
	int count;//�洢D�е������
	CString str1 = _T("����ֵ"), str2 = _T("����ֵ"), str3 = _T("����ֵ"),str4 = _T("����ֵ");
protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
