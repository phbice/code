/*
2021-08-23 18:13
*/

#define UNICODE
#include <windows.h>

class BaseWindow  // Basic window class
{
public:
    TCHAR * szAppName;  // Name of app, used in Window Class
    TCHAR * szWindowName;  // Window Name, shown in title
    HWND hwnd;  // handle of window
    WNDCLASSEX wcx;  // window class EX
    MSG msg;  // message
    HINSTANCE hInstance;  // Instance of app

    // Register window class
    BaseWindow(HINSTANCE hInstance, TCHAR * szAppName, TCHAR * szWindowName);
    // Create window and Enter message loop
    int run();
    // Window Proc
    static LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg,
        WPARAM wParam, LPARAM lParam);
    // Handle Message
    LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
};