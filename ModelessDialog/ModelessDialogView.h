
// ModelessDialogView.h : interface of the CModelessDialogView class
//

#pragma once
class CMyDialog;
#include "ModelessDialogDoc.h"
//#include "CMyDialog.h"

class CModelessDialogView : public CView
{
protected: // create from serialization only
	CModelessDialogView() noexcept;
	DECLARE_DYNCREATE(CModelessDialogView)

// Attributes
public:
	CModelessDialogDoc* GetDocument() const;
	CMyDialog* m_pDlg;
	CString m_str;
	int m_font;

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
	virtual ~CModelessDialogView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in ModelessDialogView.cpp
inline CModelessDialogDoc* CModelessDialogView::GetDocument() const
   { return reinterpret_cast<CModelessDialogDoc*>(m_pDocument); }
#endif

