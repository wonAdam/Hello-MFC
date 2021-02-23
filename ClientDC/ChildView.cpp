
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "ClientDC.h"
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
	ON_WM_RBUTTONDOWN()
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
	CClientDC cdc(this);


	//// 03 
	//for (int i = 0; i < rectangles.GetCount(); i++)
	//{
	//	dc.Rectangle(rectangles[i].x - 20, rectangles[i].y - 20, rectangles[i].x + 20, rectangles[i].y + 20);
	//}

	//for (int i = 0; i < ellipses.GetCount(); i++)
	//{
	//	dc.Ellipse(ellipses[i].x - 20, ellipses[i].y - 20, ellipses[i].x + 20, ellipses[i].y + 20);
	//}

	//// 04
	//POSITION pos1 = rectanglesList.GetHeadPosition();
	//while (pos1 != NULL)
	//{
	//	CPoint pt = rectanglesList.GetNext(pos1);

	//	dc.Rectangle(pt.x - 20, pt.y - 20, pt.x + 20, pt.y + 20);
	//}

	//POSITION pos2 = ellipsesList.GetHeadPosition();
	//while (pos2 != NULL)
	//{
	//	CPoint pt = ellipsesList.GetNext(pos2);

	//	dc.Ellipse(pt.x - 20, pt.y - 20, pt.x + 20, pt.y + 20);
	//}

	// 05
	for (int i = 0; i < yellowBoxes.GetCount(); i++)
	{
		dc.FillSolidRect(yellowBoxes[i].x - 10, yellowBoxes[i].y - 10, 20, 20, RGB(255, 255, 0));
	}

	dc.SetBkMode(TRANSPARENT);
	for (int i = 0; i < textPoses.GetCount(); i++)
	{
		CString str;
		str.Format(_T("(%d, %d)"), textPoses[i].x, textPoses[i].y);
		dc.TextOut(textPoses[i].x, textPoses[i].y, str);
	}

}

void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	//dc.Rectangle(point.x - 20, point.y - 20, point.x + 20, point.y + 20);

	// 05
	dc.FillSolidRect(point.x - 10, point.y - 10, 20, 20, RGB(255, 255, 0));

	// 03 
	//rectangles.Add(point);
	// 04
	//rectanglesList.AddHead(point);
	// 05
	yellowBoxes.Add(point);

	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	//dc.Ellipse(point.x - 20, point.y - 20, point.x + 20, point.y + 20);

	// 05 
	dc.SetBkMode(TRANSPARENT);
	CString str;
	str.Format(_T("(%d, %d)"), point.x, point.y);
	dc.TextOut(point.x, point.y, str);

	// 03 
	//ellipses.Add(point);
	// 04
	//ellipsesList.AddHead(point);
	// 05
	textPoses.Add(point);

	CWnd::OnRButtonDown(nFlags, point);
}
