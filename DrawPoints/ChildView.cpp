
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "DrawPoints.h"
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
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this);

	// 10
	CDC m_dcMem;
	CBitmap m_bitmap;

	m_dcMem.CreateCompatibleDC(&dc); // 메모리 DC 생성
	m_bitmap.CreateCompatibleBitmap(&dc, 256, 256); // 메모리 비트맵 생성
	m_dcMem.SelectObject(&m_bitmap); // 비트맵 선택

	for (int x = 0; x < 256; x++)
		for (int y = 0; y < 256; y++)
			m_dcMem.SetPixelV(x, y, RGB(x, y, 0));
	
	dc.BitBlt(350, 10, 256, 256,
		&m_dcMem, 0, 0, SRCCOPY);
}


// 09
void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CDC *dc = GetDC();
	COLORREF ref = GetPixel(*dc, point.x, point.y);
	CString str;
	str.Format(_T("R=%d, G=%d, B=%d"), GetRValue(ref), GetGValue(ref), GetBValue(ref));
	MessageBox(str, _T("DrawPoints"), MB_OK);

	CWnd::OnLButtonDown(nFlags, point);
}
