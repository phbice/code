/*------------------------------------------------------------
   Game of life : Graphic module
				 PHB 2018/1/12 20:47
  ------------------------------------------------------------*/
#define UNICODE
#define _UNICODE

#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "life.h"

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
					PSTR szCmdLine, int iCmdShow)
{
	static TCHAR    szAppName[] = TEXT ("GameOfLife") ;
	HWND			hwnd ;
	MSG				msg ;
	WNDCLASSEX		wndclass ;
	RECT			rectWindow;
	int ret;
	int errorcode;

	wndclass.cbSize         = sizeof(wndclass);
	wndclass.style          = 0;// CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc    = WndProc ;
	wndclass.cbClsExtra     = 0 ;
	wndclass.cbWndExtra     = 0 ;
	wndclass.hInstance      = hInstance ;
	wndclass.hIcon          = NULL;// LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor        = NULL;// LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground  = (HBRUSH) GetStockObject (BLACK_BRUSH) ;
	wndclass.lpszMenuName   = NULL ;
	wndclass.lpszClassName  = szAppName ;
	wndclass.hIconSm        = NULL;

	ret = RegisterClassEx(&wndclass);
	errorcode = GetLastError();

		//Required client size
	rectWindow.left    = 0;
	rectWindow.top     = 0;
	rectWindow.right   = WIDTH  * (CELL_SIZE+1) + 1;
	rectWindow.bottom  = HEIGHT * (CELL_SIZE+1) + 1;
		//Adjust window size to accommodate the desired client area
	AdjustWindowRectEx(&rectWindow, WS_OVERLAPPEDWINDOW, FALSE, 0);//WS_EX_CLIENTEDGE);

	hwnd = CreateWindowEx(0,//WS_EX_CLIENTEDGE,
		                 szAppName,             // window class name
						 TEXT ("Game of life"), // window caption
						 WS_OVERLAPPEDWINDOW,   // window style
						 100,           // initial x position
						 100,	        // initial y position
						 rectWindow.right - rectWindow.left,         // initial x size
						 rectWindow.bottom - rectWindow.top,         // initial y size
						 NULL,                  // parent window handle
						 NULL,                  // window menu handle
						 hInstance,             // program instance handle
						 NULL) ;                // creation parameters
	 
	 ShowWindow (hwnd, iCmdShow) ;
	 UpdateWindow (hwnd) ;
	 
	 while (GetMessage(&msg, NULL, 0, 0))
	 {
		  TranslateMessage(&msg) ;
		  DispatchMessage(&msg) ;
	 }
	 return (int)msg.wParam ;
}

LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC             hdc ;
	PAINTSTRUCT     ps ;
//	RECT            rect ;

	int             i,j; //Loop counter

	static HPEN     hBoundary;
	static HBRUSH   hLife;

		// Arrays that save the state of life
	static char canvas1[HEIGHT][WIDTH];
	static char canvas2[HEIGHT][WIDTH];
	static char changed[HEIGHT][WIDTH];
	
	static char (* pParent)[WIDTH] = canvas1;
	static char (* pChild)[WIDTH]  = canvas2;
	char (* pTemp)[WIDTH];


	switch (message)
	{
	case WM_CREATE:
		//SetTimer(hwnd, TIMER_INIT_LIFE, INIT_TIME, NULL);

		hBoundary = CreatePen(PS_SOLID, 1, RGB(109,109,109));
		hLife     = CreateSolidBrush(RGB(255,255,198));

			//Use random number to initialize life
		srand((unsigned int)time(NULL));
		for (i=0; i<HEIGHT; i++)
		{
			for (j=0; j<WIDTH; j++)
			{
				canvas1[i][j] =  ( (rand()&0x03)==0 ? 1 : 0);
			}
		}
		return 0 ;

	case WM_PAINT:
		hdc = BeginPaint (hwnd, &ps) ;
		SelectObject(hdc, hBoundary);
		if (ps.fErase == FALSE)
		{
			for (i = ps.rcPaint.top / (CELL_SIZE + 1); i < (ps.rcPaint.bottom + CELL_SIZE) / (CELL_SIZE + 1) && i < HEIGHT; i++)
				for (j = ps.rcPaint.left / (CELL_SIZE + 1); j < (ps.rcPaint.right + CELL_SIZE) / (CELL_SIZE + 1) && j < WIDTH; j++)
				{
					if (pParent[i][j] == LIVE)
						SelectObject(hdc, hLife);
					else
						SelectObject(hdc, GetStockObject(BLACK_BRUSH));

					Rectangle(hdc, j*(CELL_SIZE + 1), i*(CELL_SIZE + 1),
						j*(CELL_SIZE + 1) + CELL_SIZE + 2, i*(CELL_SIZE + 1) + CELL_SIZE + 2);
				}
		}
		else
			for (i = 0; i < HEIGHT; i++)
				for (j = 0; j < WIDTH; j++)
				{
					if (changed[i][j] == LIFE_CHANGED)
					{
						if (pParent[i][j] == LIVE)
							SelectObject(hdc, hLife);
						else
							SelectObject(hdc, GetStockObject(BLACK_BRUSH));

						Rectangle(hdc, j*(CELL_SIZE + 1), i*(CELL_SIZE + 1),
							j*(CELL_SIZE + 1) + CELL_SIZE + 2, i*(CELL_SIZE + 1) + CELL_SIZE + 2);
					}
				}
		
		//SelectObject(hdc, hBoundary);
		//for (i=0; i<HEIGHT; i++)
		//	for (j=0; j<WIDTH; j++)
		//	{
		//		if (pParent[i][j] == LIVE)
		//			SelectObject(hdc, hLife);
		//		else
		//			SelectObject(hdc, GetStockObject(BLACK_BRUSH));

		//		Rectangle(hdc, j*(CELL_SIZE+1), i*(CELL_SIZE+1),
		//				        j*(CELL_SIZE+1) + CELL_SIZE+2, i*(CELL_SIZE+1) + CELL_SIZE+2);
		//	}

		EndPaint (hwnd, &ps) ;
		return 0 ;

	//case WM_TIMER:
	//	if (wParam == TIMER_UPDATE_LIFE)
	//	{
	//		generate(pParent, pChild);
	//		pTemp = pParent;
	//		pParent = pChild;
	//		pChild = pTemp;

	//		rect.left    = 0;
	//		rect.top     = 0;
	//		rect.right   = WIDTH  * (CELL_SIZE+1) + 1;
	//		rect.bottom  = HEIGHT * (CELL_SIZE+1) + 1;
	//		InvalidateRect(hwnd, &rect, FALSE);
	//	}
	//	else
	//	{
	//		KillTimer(hwnd, TIMER_INIT_LIFE);
	//		SetTimer(hwnd, TIMER_UPDATE_LIFE, UPDATE_PERIOD, NULL);
	//	}

	//	return 0;
	case WM_KEYDOWN:
		if (wParam == VK_TAB)
		{
			generate(pParent, pChild, changed);
			pTemp = pParent;
			pParent = pChild;
			pChild = pTemp;

			//rect.left = 0;
			//rect.top = 0;
			//rect.right = WIDTH * (CELL_SIZE + 1) + 1;
			//rect.bottom = HEIGHT * (CELL_SIZE + 1) + 1;
			InvalidateRect(hwnd, NULL, FALSE);
		}

		return 0;

	case WM_DESTROY:
		KillTimer(hwnd, TIMER_UPDATE_LIFE);
		DeleteObject(hBoundary);
		DeleteObject(hLife);
		PostQuitMessage(0);
		return 0;

	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
}
