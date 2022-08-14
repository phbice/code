#include <Windows.h>

int main(void)
{
	HANDLE hStdin, hStdout;
	int i, iCharWrittenCount, iEventReadCount;
	INPUT_RECORD sInputRecord[8];
	CONSOLE_SCREEN_BUFFER_INFO sScreenBufferInfo;
	char szOutputBuffer[128] = "Process bar";
	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTitle(szOutputBuffer);

	WriteConsole(hStdout, szOutputBuffer, wsprintf(szOutputBuffer, "Processing... "), &iCharWrittenCount, NULL);
	GetConsoleScreenBufferInfo(hStdout, &sScreenBufferInfo);
	WriteConsole(hStdout, szOutputBuffer, wsprintf(szOutputBuffer, "    \n"), &iCharWrittenCount, NULL);
	for (i = 0; i <= 100; i++)
	{
		WriteConsoleOutputCharacter(hStdout, szOutputBuffer, wsprintf(szOutputBuffer, "%3d%%", i), sScreenBufferInfo.dwCursorPosition, &iCharWrittenCount);
		Sleep(100);
	}
	WriteConsole(hStdout, szOutputBuffer, wsprintf(szOutputBuffer, "Complete!\n"), &iCharWrittenCount, NULL);

	FlushConsoleInputBuffer(hStdin);
	ReadConsoleInput(hStdin, sInputRecord, 8, &iEventReadCount);
	return 0;
}

//int processBar(int percent)
//{
//
//}