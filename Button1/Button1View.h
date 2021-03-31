
// Button1View.h : interface of the CButton1View class
//

#pragma once


class CButton1View : public CView
{
protected: // create from serialization only
	CButton1View() noexcept;
	DECLARE_DYNCREATE(CButton1View)

// Attributes
public:
	CButton1Doc* GetDocument() const;
	CButton m_pushbutton;
	CButton m_checkbox;
	CButton m_3state;
	CButton m_radio1;
	CButton m_radio2;
	CButton m_groupbox;

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
	virtual ~CButton1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	void OnButtonClicked();
};

#ifndef _DEBUG  // debug version in Button1View.cpp
inline CButton1Doc* CButton1View::GetDocument() const
   { return reinterpret_cast<CButton1Doc*>(m_pDocument); }
#endif

