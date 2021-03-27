
// FileIOTestView.cpp : implementation of the CFileIOTestView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "FileIOTest.h"
#endif

#include "FileIOTestDoc.h"
#include "FileIOTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFileIOTestView

IMPLEMENT_DYNCREATE(CFileIOTestView, CView)

BEGIN_MESSAGE_MAP(CFileIOTestView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CFileIOTestView construction/destruction

CFileIOTestView::CFileIOTestView() noexcept
{
	// TODO: add construction code here

}

CFileIOTestView::~CFileIOTestView()
{
}

BOOL CFileIOTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CFileIOTestView drawing

void CFileIOTestView::OnDraw(CDC* pDC)
{
	CFileIOTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	pDC->SetMapMode(MM_LOMETRIC);
	pDC->Rectangle(50, -50, 350, -350);
	pDC->Ellipse(500, -50, 800, -350);
}


// CFileIOTestView printing

BOOL CFileIOTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CFileIOTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CFileIOTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CFileIOTestView diagnostics

#ifdef _DEBUG
void CFileIOTestView::AssertValid() const
{
	CView::AssertValid();
}

void CFileIOTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFileIOTestDoc* CFileIOTestView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFileIOTestDoc)));
	return (CFileIOTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CFileIOTestView message handlers
