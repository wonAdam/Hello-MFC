
// ModalDialog3View.cpp : implementation of the CModalDialog3View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ModalDialog3.h"
#endif

#include "ModalDialog3Doc.h"
#include "ModalDialog3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "CMyDialog.h"

// CModalDialog3View

IMPLEMENT_DYNCREATE(CModalDialog3View, CView)

BEGIN_MESSAGE_MAP(CModalDialog3View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CModalDialog3View construction/destruction

CModalDialog3View::CModalDialog3View() noexcept
{
	// TODO: add construction code here
	m_str = _T("");
	m_font = 0;
}

CModalDialog3View::~CModalDialog3View()
{
}

BOOL CModalDialog3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CModalDialog3View drawing

void CModalDialog3View::OnDraw(CDC* pDC)
{
	CModalDialog3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CFont font;
	CString fontname;

	if (m_font == 0) fontname = _T("±¼¸²");
	else if (m_font == 1) fontname = _T("±Ã¼­");
	else if (m_font == 2) fontname = _T("¹ÙÅÁ");
	font.CreatePointFont(400, fontname);

	pDC->SelectObject(&font);
	pDC->TextOut(10, 10, m_str);
}


// CModalDialog3View printing

BOOL CModalDialog3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CModalDialog3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CModalDialog3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CModalDialog3View diagnostics

#ifdef _DEBUG
void CModalDialog3View::AssertValid() const
{
	CView::AssertValid();
}

void CModalDialog3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CModalDialog3Doc* CModalDialog3View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CModalDialog3Doc)));
	return (CModalDialog3Doc*)m_pDocument;
}
#endif //_DEBUG


// CModalDialog3View message handlers


void CModalDialog3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	CMyDialog dlg;
	dlg.m_str = m_str;
	dlg.m_font = m_font;

	int result = dlg.DoModal();
	if (result == IDOK)
	{
		m_str = dlg.m_str;
		m_font = dlg.m_font;
		Invalidate();
	}
	else if (result == IDC_CLEAR)
	{
		m_str = _T("");
		Invalidate();
	}

	CView::OnLButtonDown(nFlags, point);
}
