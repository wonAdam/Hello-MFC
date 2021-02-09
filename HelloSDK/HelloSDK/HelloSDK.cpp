#include <windows.h>

// WinMain 함수에서 참조하므로 함수 원형을 선언합니다.
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//---------- 메인 함수 ----------//
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	//---------- 윈도우 클래스 초기화 및 등록 ----------//
	WNDCLASS wndclass;
	HWND hwnd;
	MSG msg;

	// 윈도우 클래스를 초기화하고 운영체제를 등록합니다.
	wndclass.style = CS_HREDRAW | CS_VREDRAW | CS_NOCLOSE;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_QUESTION);
	wndclass.hCursor = LoadCursor(NULL, IDC_UPARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = TEXT("HelloClass");

	// 윈도우를 운영체제에 등록합니다.
	if (!RegisterClass(&wndclass)) return 1;

	//---------- 윈도우 생성 ----------//
	// 윈도우를 생성하고 화면에 나타낸다.
	// 첫번째 인자는 등록된 윈도우의 이름으로 찾아가므로 이름을 똑같게 기입해야합니다.
	hwnd = CreateWindow(TEXT("HelloClass"), TEXT("Hello World"),
		WS_POPUPWINDOW | WS_CAPTION,
		0, 0, 500, 200,
		NULL, NULL, hInstance, NULL);

	ShowWindow(hwnd, SW_MAXIMIZE);


	//---------- 메세지 루프 ----------//
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;


}

//---------- 윈도우 프로시저 ----------//
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	const TCHAR* str = TEXT("Hello, SDK");

	// 발생한 메세지의 종류에 따라 적절히 처리합니다
	switch (message)
	{
	case WM_CREATE:
		return 0;

	case WM_LBUTTONDOWN:
		if (MessageBox(hwnd, TEXT("종료하시겠습니까?"), TEXT("마우스 메세지"), MB_OKCANCEL | MB_ICONSTOP) == IDOK)
		{
			PostQuitMessage(0);
		}

		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		TextOut(hdc, 100, 100, str, lstrlen(str));
		EndPaint(hwnd, &ps);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	// 나머지 메세지는 운영체제에게 맡깁니다.
	return DefWindowProc(hwnd, message, wParam, lParam);
}