#define UNICODE
#define _UNICODE

#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// 尝试创建互斥对象
	HANDLE h = CreateMutex(NULL, TRUE, TEXT("No Previous Instance!"));
	if (!h)
	{
		MessageBox(NULL, TEXT("无法创建互斥对象！"), TEXT("NoPrev"), MB_OK | MB_SYSTEMMODAL);
		return 0;
	}

	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		MessageBox(NULL, TEXT("前一个实例正在运行，不能重复创建！"), TEXT("NoPrev"), MB_OK | MB_SYSTEMMODAL);
		return 0;
	}

	// 注册热键
	if (!RegisterHotKey(NULL, 0x0001, MOD_CONTROL | MOD_SHIFT, 'K'))
	{
		MessageBox(NULL, TEXT("不能注册热键 Ctrl+Shift+K ！"), TEXT("NoPrev"), MB_OK | MB_SYSTEMMODAL);
		return 0;
	}

	MessageBox(NULL, TEXT("NoPrev 顺利运行！\n\n按热键 Ctrl+Shift+K 关闭 NoPrev。"), TEXT("NoPrev"), MB_OK | MB_SYSTEMMODAL);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		switch (msg.message)
		{
		case WM_HOTKEY:
			if ((int)msg.wParam == 0x0001)
				if (MessageBox(NULL, TEXT("停止 NoPrev？"), TEXT("NoPrev"), MB_OKCANCEL | MB_SYSTEMMODAL) == IDOK)
					return 0;
		}
	}

	return 0;
}