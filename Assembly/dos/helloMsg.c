#include <Windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
				   PSTR szCmdLine, int iCmdShow)
{
	MessageBox(NULL, TEXT("Hello,Windows!"),TEXT("HelloMsg"),MB_OKCANCEL);
	return 0;
}