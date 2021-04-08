
// ModalDialog2View.cpp : implementation of the CModalDialog2View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ModalDialog2.h"
#endif

#include "ModalDialog2Doc.h"
#include "ModalDialog2View.h"

#include "CMyDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CModalDialog2View

IMPLEMENT_DYNCREATE(CModalDialog2View, CView)

BEGIN_MESSAGE_MAP(CModalDialog2View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CModalDialog2View construction/destruction

CModalDialog2View::CModalDialog2View() noexcept
{
	m_str = _T("");
	m_font = 0;
}

CModalDialog2View::~CModalDialog2View()
{
}

BOOL CModalDialog2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CModalDialog2View drawing

void CModalDialog2View::OnDraw(CDC* pDC)
{
	CModalDialog2Doc* pDoc = GetDocument();
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


// CModalDialog2View printing

BOOL CModalDialog2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CModalDialog2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CModalDialog2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CModalDialog2View diagnostics

#ifdef _DEBUG
void CModalDialog2View::AssertValid() const
{
	CView::AssertValid();
}

void CModalDialog2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CModalDialog2Doc* CModalDialog2View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CModalDialog2Doc)));
	return (CModalDialog2Doc*)m_pDocument;
}
#endif //_DEBUG


// CModalDialog2View message handlers


void CModalDialog2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
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
	else if(result == IDC_CLEAR)
	{
		m_str = _T("");
		Invalidate();
	}

	CView::OnLButtonDown(nFlags, point);
}
