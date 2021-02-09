#include <afxwin.h>

//---------- 클래스 선언부 ----------//
// 응용프로그램 클래스를 선언합니다.
class CHelloApp : public CWinApp
{
public:
	virtual BOOL InitInstance();
};

// 메인 윈도우 클래스를 선언합니다.
class CMainFrame : public CFrameWnd
{
public: 
	CMainFrame();

protected:
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP();
};

//---------- 응용 프로그램 객체 ----------//
// 응용 프로그램 객체를 선언합니다.
CHelloApp theApp;

//---------- 클래스 정의부 ----------//
// 응용 프로그램 클래스를 정의합니다.
BOOL CHelloApp::InitInstance()
{
	m_pMainWnd = new CMainFrame;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	return TRUE;
}


// 메인 윈도우 클래스를 정의합니다.
CMainFrame::CMainFrame()
{
	Create(NULL, _T("Hello World"), WS_CAPTION | WS_POPUPWINDOW | WS_MINIMIZE, CRect(0, 0, 500, 200));
}

void CMainFrame::OnPaint()
{
	CPaintDC dc(this);
	const TCHAR* msg = _T("Hello, MFC");
	dc.TextOut(100, 100, msg, lstrlen(msg));
}

void CMainFrame::OnLButtonDown(UINT nFlags, CPoint point)
{
	theApp.m_pMainWnd->ShowWindow(SW_SHOWMAXIMIZED);
	if (MessageBox(_T("종료하시겠습니까?"), _T("마우스 메세지"), MB_YESNOCANCEL | MB_ICONQUESTION) == IDYES)
	{
		DestroyWindow();
	}
}

//---------- 메세지 맵 ----------//
// 메세지 맵을 선언합니다.
BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()