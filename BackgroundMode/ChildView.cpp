
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "BackgroundMode.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(GetStockObject(GRAY_BRUSH)), nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); 

	dc.SetBkMode(OPAQUE);
	dc.SetBkColor(RGB(0, 0, 255));
	dc.TextOut(100, 50, CString("OPAQUE MODE [1]"));

	dc.SetBkMode(TRANSPARENT);
	dc.TextOut(100, 100, CString("TRANSPARENT MODE"));

	dc.SetBkMode(OPAQUE);
	dc.SetBkColor(RGB(0, 255, 0));
	dc.TextOut(100, 150, CString("OPAQUE MODE [2]"));
}

