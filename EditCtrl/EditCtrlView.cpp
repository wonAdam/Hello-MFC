
// EditCtrlView.cpp : implementation of the CEditCtrlView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "EditCtrl.h"
#endif

#include "EditCtrlDoc.h"
#include "EditCtrlView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEditCtrlView

IMPLEMENT_DYNCREATE(CEditCtrlView, CFormView)

BEGIN_MESSAGE_MAP(CEditCtrlView, CFormView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_EN_CHANGE(IDC_MYEDIT, &CEditCtrlView::OnEnChangeMyedit)
	ON_EN_MAXTEXT(IDC_MYEDIT, &CEditCtrlView::OnEnMaxtextMyedit)
END_MESSAGE_MAP()

// CEditCtrlView construction/destruction

CEditCtrlView::CEditCtrlView() noexcept
	: CFormView(IDD_EDITCTRL_FORM)
{
	// TODO: add construction code here

}

CEditCtrlView::~CEditCtrlView()
{
}

void CEditCtrlView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MYEDIT, m_edit);
	DDX_Control(pDX, IDC_MYSTATIC, m_static);
}

BOOL CEditCtrlView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CEditCtrlView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	m_edit.SetLimitText(20);
}


// CEditCtrlView printing

BOOL CEditCtrlView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEditCtrlView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEditCtrlView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CEditCtrlView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}


// CEditCtrlView diagnostics

#ifdef _DEBUG
void CEditCtrlView::AssertValid() const
{
	CFormView::AssertValid();
}

void CEditCtrlView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CEditCtrlDoc* CEditCtrlView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEditCtrlDoc)));
	return (CEditCtrlDoc*)m_pDocument;
}
#endif //_DEBUG


// CEditCtrlView message handlers
void CEditCtrlView::OnEnChangeMyedit()
{
	CString str;
	m_edit.GetWindowText(str);
	m_static.SetWindowText(str);
}


void CEditCtrlView::OnEnMaxtextMyedit()
{
	MessageBox(_T("최대 길이 도달!"), _T("오류"), MB_ICONERROR);
}
