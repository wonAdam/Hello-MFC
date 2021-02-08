#include <windows.h>

// WinMain 함수에서 참조하므로 함수 원형을 선언합니다.
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASS wndclass;
	HWND hwnd;
	MSG msg;

	// 윈도우 클래스를 초기화하고 운영체제를 등록합니다.
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = TEXT("HelloClass");
	if (!RegisterClass(&wndclass)) return 1;

	// 윈도우를 생성하고 화면에 나타낸다.
	hwnd = CreateWindow(TEXT("HelloClass"), TEXT("HelloSDK"), 
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 
		NULL, NULL, hInstance, NULL);

	ShowWindow(hwnd, nCmdShow);
	ShowWindow(hwnd, nCmdShow);

	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;


}

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
		MessageBox(hwnd, TEXT("마우스 클릭"), TEXT("마우스 메세지"), MB_OK);
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