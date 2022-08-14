#define UNICODE
#define _UNICODE

#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include <Windows.h>

LRESULT CALLBACK MainWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevINstance,
	PSTR szCmdLine, int iCmdShow)
{
	static TCHAR szAppName[] = TEXT("HelloWindows");
	static TCHAR szWindowName[] = TEXT("Main window");
	HWND hwndMain;
	HWND hwndButton;
	WNDCLASSEX wcx;
	MSG msg;

	//Fill the WNDCLASSEX structure
	wcx.cbSize = sizeof(wcx);                         //Size of the structure
	wcx.style = CS_HREDRAW | CS_VREDRAW;             //Redraw if size changes
	wcx.lpfnWndProc = MainWndProc;                         //Points to window procedure
	wcx.cbClsExtra = 0;                                   //No extra class memory
	wcx.cbWndExtra = 0;                                   //No extra window memory
	wcx.hInstance = hInstance;                           //Handle to instance
	wcx.hIcon = LoadIcon(NULL, IDI_APPLICATION);     //Use default icon
	wcx.hCursor = LoadCursor(NULL, IDC_ARROW);         //Use default cursor
	wcx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);         //White background brush
	wcx.lpszMenuName = NULL;                                //Menu resouce name, NULL means no menu
	wcx.lpszClassName = szAppName;                           //Name of window class
	wcx.hIconSm = NULL;                                //Small class icon
		//Register window class
	if (!RegisterClassEx(&wcx))
		return FALSE;

	//Create main window
	hwndMain = CreateWindowEx(
		0,                                //No extension style
		szAppName,                        //Class name
		szWindowName,                     //Window name, shown on the title bar
		WS_OVERLAPPEDWINDOW,              //overlapped window
		CW_USEDEFAULT, CW_USEDEFAULT,     //Default position
		500, 500,
		(HWND)NULL,                       //No parent window
		(HMENU)NULL,                      //No menu
		hInstance,                        //instance handle
		NULL                              //No window creation data
	);
	if (!hwndMain)
		return FALSE;

	//Create a button
	hwndButton = CreateWindowEx(0, L"BUTTON", L"Hello!",
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
		10, 30, 100, 30,
		hwndMain, NULL, hInstance,
		NULL);

	//Show window
	//This will send a WM_PAINT message to window
	ShowWindow(hwndMain, SW_SHOWDEFAULT);
	UpdateWindow(hwndMain);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

LRESULT CALLBACK MainWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	switch (uMsg)
	{
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		TextOut(hdc, 0, 0, TEXT("Hello Windows!"), 14);
		EndPaint(hwnd, &ps);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	case WM_COMMAND:
		if (HIWORD(wParam) == BN_CLICKED)
			MessageBox(hwnd, L"Hello world!", L"Button Clicked", MB_OK);
		return 0;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return 0;
}
