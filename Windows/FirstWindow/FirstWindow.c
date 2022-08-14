#define UNICODE
#include <Windows.h>

LRESULT CALLBACK MainWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevINstance,
	PSTR szCmdLine, int iCmdShow)
{
	static TCHAR szAppName[] = TEXT("HelloWindows");
	static TCHAR szWindowName[] = TEXT("Main window");
	HWND hwndMain;
	WNDCLASSEX wcx;
	MSG msg;

	    //Fill the WNDCLASSEX structure
	wcx.cbSize        = sizeof(wcx);                         //Size of the structure
	wcx.style         = CS_HREDRAW | CS_VREDRAW;             //Redraw if size changes
	wcx.lpfnWndProc   = MainWndProc;                         //Points to window procedure
	wcx.cbClsExtra    = 0;                                   //No extra class memory
	wcx.cbWndExtra    = 0;                                   //No extra window memory
	wcx.hInstance     = hInstance;                           //Handle to instance
	wcx.hIcon         = LoadIcon(NULL, IDI_APPLICATION);     //Use default icon
	wcx.hCursor       = LoadCursor(NULL, IDC_ARROW);         //Use default cursor
	wcx.hbrBackground = GetStockObject(WHITE_BRUSH);         //White background brush
	wcx.lpszMenuName  = NULL;                                //Menu resouce name, NULL means no menu
	wcx.lpszClassName = szAppName;                           //Name of window class
	wcx.hIconSm       = NULL;                                //Small class icon
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
		500,           500,
		(HWND)NULL,                       //No parent window
		(HMENU)NULL,                      //No menu
		hInstance,                        //instance handle
		NULL                              //No window creation data
	);
	if (!hwndMain)
		return FALSE;
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

	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return 0;
}