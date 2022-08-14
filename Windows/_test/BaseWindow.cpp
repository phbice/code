#include "BaseWindow.h"

BaseWindow::BaseWindow(HINSTANCE hInstance, TCHAR * szAppName, TCHAR * szWindowName)
{
    this->hInstance = hInstance;
    this->szAppName = szAppName;
    this->szWindowName = szWindowName;

    wcx.cbSize = sizeof(this->wcx);  // Size of the structure
    wcx.style  = CS_HREDRAW | CS_VREDRAW;  // REDRAW if size changes
                                           // Horizontally or Vertically
    wcx.lpfnWndProc = this->WndProc;  // Points to window procedure
    wcx.cbClsExtra = 0;  // No Extra class memory
    wcx.cbWndExtra = 0;  // No Extra window memory
    wcx.hInstance = this->hInstance;  // Handle to instance
    wcx.hIcon = LoadIcon(NULL, IDI_APPLICATION);  // Use default icon
    wcx.hCursor = LoadCursor(NULL, IDC_ARROW);  // Use default cursor
    wcx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);  // White background
                                                              // brush
    wcx.lpszMenuName = NULL;  // Name of window class
    wcx.lpszClassName = this->szAppName;  // Small class icon
    wcx.hIconSm = NULL;

    RegisterClassEx(&wcx);
}

int BaseWindow::run()
{
    this->hwnd = CreateWindowEx(
        0,  // No extension style
        this->szAppName,  // Class Name
        this->szWindowName,  // Window name, shown on the title bar
        WS_OVERLAPPEDWINDOW,  // Overlapped window
        CW_USEDEFAULT, CW_USEDEFAULT,  // Default positon
        500, 500,  // Window Size
        (HWND)NULL,  // No parent window
        (HMENU)NULL,  // No menu
        this->hInstance,  // Instance handle
        this  // Window creation data, passed to WndProc as CREATESTRUCT
    );

    TCHAR szBuffer[128];
    wsprintf(szBuffer, TEXT("Error code %d"), GetLastError());
    MessageBox((HWND)NULL, szBuffer, TEXT("Error"), MB_OK);
    
    ShowWindow(this->hwnd, SW_SHOWDEFAULT);
    UpdateWindow(this->hwnd);

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}

LRESULT CALLBACK BaseWindow::WndProc(HWND hwnd, UINT uMsg,
    WPARAM wParam, LPARAM lParam)
{
    BaseWindow * pWnd;

    if (uMsg == WM_CREATE)
    {
        CREATESTRUCT * pCreate = reinterpret_cast<CREATESTRUCT *>(lParam);
        pWnd = reinterpret_cast<BaseWindow *>(pCreate->lpCreateParams);
        SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)pWnd);
    }
    else
        pWnd = reinterpret_cast<BaseWindow *>(GetWindowLongPtr(hwnd, GWLP_USERDATA));

    return pWnd->HandleMessage(uMsg, wParam, lParam);
}

LRESULT BaseWindow::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;

    switch (uMsg)
    {
    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);
        TextOut(hdc, 0, 0, TEXT("你好世界！"), 5);
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

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    PSTR szCmdLine, int iCmdShow)
{
    static TCHAR szAppName[] = TEXT("HelloWindows");
    static TCHAR szWindowName[] = TEXT("Main window");
    static BaseWindow window = BaseWindow(hInstance, szAppName, szWindowName);
    return window.run();
}
