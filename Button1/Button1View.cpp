
// Button1View.cpp : implementation of the CButton1View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Button1.h"
#endif

#include "Button1Doc.h"
#include "Button1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CButton1View

IMPLEMENT_DYNCREATE(CButton1View, CView)

BEGIN_MESSAGE_MAP(CButton1View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_BN_CLICKED(101, OnButtonClicked)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CButton1View construction/destruction

CButton1View::CButton1View() noexcept
{
	// TODO: add construction code here

}

CButton1View::~CButton1View()
{
}

BOOL CButton1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CButton1View drawing

void CButton1View::OnDraw(CDC* /*pDC*/)
{
	CButton1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CButton1View printing

BOOL CButton1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CButton1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CButton1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CButton1View diagnostics

#ifdef _DEBUG
void CButton1View::AssertValid() const
{
	CView::AssertValid();
}

void CButton1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CButton1Doc* CButton1View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CButton1Doc)));
	return (CButton1Doc*)m_pDocument;
}
#endif //_DEBUG


// CButton1View message handlers


int CButton1View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	m_pushbutton.Create(_T("푸시 버튼"), 
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 
		CRect(20, 20, 160, 50), this, 101);

	m_checkbox.Create(_T("체크 박스"),
		WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
		CRect(20, 60, 160, 90), this, 102);

	m_3state.Create(_T("3상태 체크 박스"),
		WS_CHILD | WS_VISIBLE | BS_AUTO3STATE,
		CRect(20, 100, 160, 130), this, 103);

	m_radio1.Create(_T("라디오 버튼 1"),
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		CRect(20, 170, 160, 200), this, 104);

	m_radio2.Create(_T("라디오 버튼 2"),
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		CRect(20, 210, 160, 240), this, 105);

	m_groupbox.Create(_T("그룹 박스"),
		WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
		CRect(10, 140, 170, 250), this, 106);

	m_checkbox.SetCheck(BST_CHECKED);
	m_3state.SetState(BST_INDETERMINATE);
	m_radio2.SetCheck(BST_CHECKED);

	return 0;
}


void CButton1View::OnButtonClicked()
{
	// TODO: Add your implementation code here.
	int state_checkbox = m_checkbox.GetState();
	int state_3state = m_3state.GetState();
	int state_radio1 = m_radio1.GetState();
	int state_radio2 = m_radio2.GetState();

	CString str;
	str.Format(_T("버튼 상태: %d, %d, %d, %d"),
		state_checkbox, state_3state, state_radio1, state_radio2);
	MessageBox(str, _T("Button1 실습"), MB_ICONINFORMATION);
}
