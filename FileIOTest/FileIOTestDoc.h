
// FileIOTestDoc.h : interface of the CFileIOTestDoc class
//


#pragma once

class CMyData : public CObject
{
	DECLARE_SERIAL(CMyData)
public:
	CString m_str;
	COLORREF m_color;

public:
	CMyData() {}
	CMyData(CString& str, COLORREF& color) { m_str = str; m_color = color; }
	virtual ~CMyData();
	void Serialize(CArchive& ar);
};

CMyData::~CMyData() {}

void CMyData::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);

	if (ar.IsStoring())
	{
		ar << m_str << m_color;
	}
	else {
		ar >> m_str >> m_color;
	}
}

IMPLEMENT_SERIAL(CMyData, CObject, 1);


class CFileIOTestDoc : public CDocument
{
protected: // create from serialization only
	CFileIOTestDoc() noexcept;
	DECLARE_DYNCREATE(CFileIOTestDoc)

// Attributes
public:
	CMyData m_data;

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CFileIOTestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};

