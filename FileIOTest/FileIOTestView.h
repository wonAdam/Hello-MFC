
// FileIOTestView.h : interface of the CFileIOTestView class
//

#pragma once


class CFileIOTestView : public CView
{
protected: // create from serialization only
	CFileIOTestView() noexcept;
	DECLARE_DYNCREATE(CFileIOTestView)

// Attributes
public:
	CFileIOTestDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CFileIOTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in FileIOTestView.cpp
inline CFileIOTestDoc* CFileIOTestView::GetDocument() const
   { return reinterpret_cast<CFileIOTestDoc*>(m_pDocument); }
#endif

