
// ChildView.h : interface of the CChildView class
//


#pragma once


// CChildView window

class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
public:

// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);

	// 03
	CArray<CPoint, CPoint&> rectangles;
	CArray<CPoint, CPoint&> ellipses;
	// 04
	CList<CPoint, CPoint&> rectanglesList;
	CList<CPoint, CPoint&> ellipsesList;
	// 05
	CArray<CPoint, CPoint&> yellowBoxes;
	CArray<CPoint, CPoint&> textPoses;

};

