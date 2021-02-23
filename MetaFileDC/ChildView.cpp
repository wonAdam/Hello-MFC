
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "MetaFileDC.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	// 확장 메타파일 객체를 생성하고 초기화합니다.
	CMetaFileDC dc;
	dc.CreateEnhanced(NULL, NULL, NULL, NULL);
	// 08
	dc.CreateEnhanced(NULL, _T("Output.emf"), NULL, NULL);

	// 멤버 함수를 호출하여 출력합니다.
	dc.Rectangle(0, 0, 10, 10);
	dc.Ellipse(1, 1, 9, 9);

	// 확장 메타파일 핸들을 얻습니다.
	m_hmf = dc.CloseEnhanced();
}

CChildView::~CChildView()
{
	// 확장 메타파일을 삭제합니다.
	::DeleteEnhMetaFile(m_hmf);
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_RBUTTONDOWN()
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

	// 06
	/*POSITION pos = left.GetHeadPosition();
	while (pos != NULL)
	{
		CPoint point = left.GetNext(pos);
		CRect rect(point.x - 20, point.y - 20, point.x + 20, point.y + 20);
		dc.PlayMetaFile(m_hmf, &rect);
	}
	pos = right.GetHeadPosition();
	while (pos != NULL)
	{
		CPoint point = right.GetNext(pos);
		CRect rect(point.x - 50, point.y - 20, point.x + 50, point.y + 20);
		dc.PlayMetaFile(m_hmf, &rect);
	}*/


	// 07
	POSITION pos = clicks.GetHeadPosition();
	while (pos != NULL)
	{
		CRect clickRect = clicks.GetNext(pos);
		CPoint point(clickRect.left, clickRect.top);
		int width = clickRect.right;
		int height = clickRect.bottom;
		CRect rect(point.x - width, point.y - height, point.x + width, point.y + height);
		dc.PlayMetaFile(m_hmf, &rect);
	}

}

void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	CRect rect(point.x - 20, point.y - 20, point.x + 20, point.y + 20);
	dc.PlayMetaFile(m_hmf, &rect);

	// 06
	//left.AddTail(point);

	// 07
	CRect clickRect(point.x, point.y, 20, 20);
	clicks.AddTail(clickRect);

	CWnd::OnLButtonDown(nFlags, point);
}

void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	CRect rect(point.x - 50, point.y - 20, point.x + 50, point.y + 20);
	dc.PlayMetaFile(m_hmf, &rect);

	// 06
	//right.AddTail(point);

	// 07
	CRect clickRect(point.x, point.y, 50, 20);
	clicks.AddTail(clickRect);

	CWnd::OnRButtonDown(nFlags, point);
}



