
// StaticView.cpp : implementation of the CStaticView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Static.h"
#endif

#include "StaticDoc.h"
#include "StaticView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CStaticView

IMPLEMENT_DYNCREATE(CStaticView, CFormView)

BEGIN_MESSAGE_MAP(CStaticView, CFormView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_STN_CLICKED(IDC_STATIC_METAFILE, &CStaticView::OnStnClickedStaticMetafile)
END_MESSAGE_MAP()

// CStaticView construction/destruction

CStaticView::CStaticView() noexcept
	: CFormView(IDD_STATIC_FORM)
{
	// TODO: add construction code here

}

CStaticView::~CStaticView()
{
}

void CStaticView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_METAFILE, m_metafile);
}

BOOL CStaticView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CStaticView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_metafile.SetEnhMetaFile(::GetEnhMetaFile(_T("javatwo.emf")));
}


// CStaticView printing

BOOL CStaticView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CStaticView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CStaticView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CStaticView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}


// CStaticView diagnostics

#ifdef _DEBUG
void CStaticView::AssertValid() const
{
	CFormView::AssertValid();
}

void CStaticView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CStaticDoc* CStaticView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStaticDoc)));
	return (CStaticDoc*)m_pDocument;
}
#endif //_DEBUG


// CStaticView message handlers


void CStaticView::OnStnClickedStaticMetafile()
{
	MessageBox(_T("확장 메타파일 그림 클릭!"));
}
