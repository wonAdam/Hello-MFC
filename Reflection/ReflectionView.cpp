
// ReflectionView.cpp : implementation of the CReflectionView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Reflection.h"
#endif

#include "ReflectionDoc.h"
#include "ReflectionView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CReflectionView

IMPLEMENT_DYNCREATE(CReflectionView, CFormView)

BEGIN_MESSAGE_MAP(CReflectionView, CFormView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CReflectionView construction/destruction

CReflectionView::CReflectionView() noexcept
	: CFormView(IDD_REFLECTION_FORM)
{
	// TODO: add construction code here

}

CReflectionView::~CReflectionView()
{
}

void CReflectionView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}

BOOL CReflectionView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CReflectionView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_list.AddString(_T("사과"));
	m_list.AddString(_T("포도"));
	m_list.AddString(_T("참외"));
	m_list.AddString(_T("수박"));
}


// CReflectionView printing

BOOL CReflectionView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CReflectionView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CReflectionView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CReflectionView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}


// CReflectionView diagnostics

#ifdef _DEBUG
void CReflectionView::AssertValid() const
{
	CFormView::AssertValid();
}

void CReflectionView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CReflectionDoc* CReflectionView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CReflectionDoc)));
	return (CReflectionDoc*)m_pDocument;
}
#endif //_DEBUG


// CReflectionView message handlers
