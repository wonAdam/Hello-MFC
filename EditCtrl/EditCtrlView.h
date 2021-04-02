
// EditCtrlView.h : interface of the CEditCtrlView class
//

#pragma once


class CEditCtrlView : public CFormView
{
protected: // create from serialization only
	CEditCtrlView() noexcept;
	DECLARE_DYNCREATE(CEditCtrlView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_EDITCTRL_FORM };
#endif

// Attributes
public:
	CEditCtrlDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CEditCtrlView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit;
	CStatic m_static;
	afx_msg void OnEnChangeMyedit();
	afx_msg void OnEnMaxtextMyedit();
};

#ifndef _DEBUG  // debug version in EditCtrlView.cpp
inline CEditCtrlDoc* CEditCtrlView::GetDocument() const
   { return reinterpret_cast<CEditCtrlDoc*>(m_pDocument); }
#endif

