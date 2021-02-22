
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "StockObject.h"
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
		::LoadCursor(nullptr, IDC_ARROW), nullptr, nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); 

	// 클라이언트 영역을 초록색 해치 브러시로 채웁니다.
	CRect rect;
	GetClientRect(&rect);
	CBrush brush(HS_CROSS, RGB(0, 255, 0));
	dc.SelectObject(&brush);
	dc.Rectangle(&rect);

	// 경계선이 검은색이고 내부가 비어있는 타원을 그립니다.
	dc.SelectStockObject(BLACK_PEN);
	dc.SelectStockObject(NULL_BRUSH);
	dc.Ellipse(100, 50, 200, 200);

	// 경계선이 없고 내부가 밝은 회색으로 채워진 다각형을 그립니다.
	dc.SelectStockObject(NULL_PEN);
	dc.SelectStockObject(LTGRAY_BRUSH);
	POINT points[] = {
		{250, 50},
		{450, 150},
		{300, 200},
		{250, 150}
	};
	dc.Polygon(points, 4);
}

