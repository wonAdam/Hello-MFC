
// ModelessDialogView.cpp : implementation of the CModelessDialogView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ModelessDialog.h"
#endif

#include "ModelessDialogDoc.h"
#include "ModelessDialogView.h"
#include "CMyDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CModelessDialogView

IMPLEMENT_DYNCREATE(CModelessDialogView, CView)

BEGIN_MESSAGE_MAP(CModelessDialogView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CModelessDialogView construction/destruction

CModelessDialogView::CModelessDialogView() noexcept
{
	m_pDlg = NULL;
	m_str = _T("");
	m_font = 0;
}

CModelessDialogView::~CModelessDialogView()
{
}

BOOL CModelessDialogView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CModelessDialogView drawing

void CModelessDialogView::OnDraw(CDC* pDC)
{
	CModelessDialogDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	CFont font;
	CString fontname;

	if (m_font == 0) fontname = _T("±¼¸²");
	else if (m_font == 1) fontname = _T("±Ã¼­");
	else if (m_font == 2) fontname = _T("¹ÙÅÁ");
	font.CreatePointFont(400, fontname);

	pDC->SelectObject(&font);
	pDC->TextOut(10, 10, m_str);
}


// CModelessDialogView printing

BOOL CModelessDialogView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CModelessDialogView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CModelessDialogView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CModelessDialogView diagnostics

#ifdef _DEBUG
void CModelessDialogView::AssertValid() const
{
	CView::AssertValid();
}

void CModelessDialogView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CModelessDialogDoc* CModelessDialogView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CModelessDialogDoc)));
	return (CModelessDialogDoc*)m_pDocument;
}
#endif //_DEBUG


// CModelessDialogView message handlers


void CModelessDialogView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (m_pDlg != NULL)
	{
		m_pDlg->SetFocus();
	}
	else 
	{
		m_pDlg = new CMyDialog();
		m_pDlg->m_pView = this;
		m_pDlg->m_str = m_str;
		m_pDlg->m_font = m_font;
		m_pDlg->Create(IDD_DIALOG1);
		m_pDlg->ShowWindow(SW_SHOW);
	}

	CView::OnLButtonDown(nFlags, point);
}
