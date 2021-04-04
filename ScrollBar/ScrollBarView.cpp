
// ScrollBarView.cpp : implementation of the CScrollBarView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ScrollBar.h"
#endif

#include "ScrollBarDoc.h"
#include "ScrollBarView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CScrollBarView

IMPLEMENT_DYNCREATE(CScrollBarView, CFormView)

BEGIN_MESSAGE_MAP(CScrollBarView, CFormView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
END_MESSAGE_MAP()

// CScrollBarView construction/destruction

CScrollBarView::CScrollBarView() noexcept
	: CFormView(IDD_SCROLLBAR_FORM)
{
	// TODO: add construction code here

}

CScrollBarView::~CScrollBarView()
{
}

void CScrollBarView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATUS, m_status);
	DDX_Control(pDX, IDC_SCROLLBAR2, m_hsb);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_vsb);
}

BOOL CScrollBarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CScrollBarView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_hsb.SetScrollRange(0, 360, FALSE);
	m_hsb.SetScrollPos(0, FALSE);
	m_vsb.SetScrollRange(0, 255, FALSE);
	m_vsb.SetScrollPos(128);
}


// CScrollBarView printing

BOOL CScrollBarView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CScrollBarView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CScrollBarView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CScrollBarView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}


// CScrollBarView diagnostics

#ifdef _DEBUG
void CScrollBarView::AssertValid() const
{
	CFormView::AssertValid();
}

void CScrollBarView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CScrollBarDoc* CScrollBarView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CScrollBarDoc)));
	return (CScrollBarDoc*)m_pDocument;
}
#endif //_DEBUG


// CScrollBarView message handlers


void CScrollBarView::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	if (pScrollBar != NULL) // 스크롤바 컨트롤에서 발생한 메세지라면
	{
		if (pScrollBar->GetSafeHwnd() == m_hsb.GetSafeHwnd())
		{
			switch(nSBCode)
			{
			case SB_THUMBTRACK:
				pScrollBar->SetScrollPos(nPos);
				break;
			}
			Invalidate();
		}
	}
	else { // 윈도우 스크롤바에서 발생한 메세지라면
		CFormView::OnHScroll(nSBCode, nPos, pScrollBar);
	}
}


void CScrollBarView::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	int delta = 0;
	if (pScrollBar != NULL)
	{
		if (pScrollBar->GetSafeHwnd() == m_vsb.GetSafeHwnd())
		{
			switch (nSBCode)
			{
			case SB_THUMBTRACK:
				pScrollBar->SetScrollPos(nPos);
				break;
			case SB_LINEUP:
				delta = -4;
				break;
			case SB_LINEDOWN:
				delta = 4;
				break;
			case SB_PAGEUP:
				delta = -20;
				break;
			case SB_PAGEDOWN:
				delta = 20;
				break;
			}
			if (delta != 0)
			{
				int pos = pScrollBar->GetScrollPos();
				pScrollBar->SetScrollPos(pos + delta);
			}
			Invalidate();
		}
	}
	else {
		CFormView::OnVScroll(nSBCode, nPos, pScrollBar);
	}
}


void CScrollBarView::OnDraw(CDC* pDC)
{
	int hpos = m_hsb.GetScrollPos();
	int vpos = m_vsb.GetScrollPos();

	CFont font;
	LOGFONT lf = { 0 }; // 구조체를 0으로 초기화
	lf.lfHeight = vpos / 3 + 1; // 폰트 크기 설정, vpos가 0이면 폰트크기는 1
	lf.lfEscapement = 10 * hpos; // 폰트의 회전각
	font.CreateFontIndirect(&lf); // 폰트 생성

	pDC->SelectObject(&font);
	pDC->SetTextColor(RGB(0, vpos, 0));
	pDC->TextOut(50, 100, CString("안녕하세요"));

	CString str;
	str.Format(_T("글자 크기: %d, 회전각: %d, 초록색 농도: %d"), lf.lfHeight, hpos, vpos);
	m_status.SetWindowText(str);
}
