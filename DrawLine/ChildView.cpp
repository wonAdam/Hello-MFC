
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "DrawLine.h"
#include "ChildView.h"

#define _USE_MATH_DEFINES
#include <math.h>

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
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); 

	//// 클라이언트 영역의 좌표를 얻습니다.
	//CRect rect;
	//GetClientRect(&rect);

	//// 수평선과 수직선을 그립니다.
	//dc.MoveTo(0, rect.bottom / 2);
	//dc.LineTo(rect.right, rect.bottom / 2);
	//dc.MoveTo(rect.right / 2, 0);
	//dc.LineTo(rect.right / 2, rect.bottom);

	//// 마름모꼴을 그립니다.
	//POINT points[] = { {rect.right / 2, 0}, {rect.right, rect.bottom / 2},
	//	{rect.right / 2, rect.bottom }, {0, rect.bottom / 2 }, {rect.right / 2, 0} };
	//dc.Polyline(points, 5);

	// 11
	CRect rect;
	GetClientRect(&rect);

	POINT points[100];
	for (int i = 0; i < 100; i++)
	{
		float x, y;
		x = (M_PI / 20.0f) * i;
		y = cos(x);
		y *= (rect.bottom / 4) + rect.bottom;
		x *= rect.right / 20;

		POINT pt;
		pt.x = x;
		pt.y = y;

		points[i] = pt;
	}
	
	dc.Polyline(points, 100);
	
	dc.MoveTo(0, rect.bottom / 2);
	dc.LineTo(rect.right, rect.bottom / 2);
}

