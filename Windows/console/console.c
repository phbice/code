#include <Windows.h>

int main(void)
{
	HANDLE hStdin, hStdout; //Standard input and output handle
	int iCharWrittenCount, iEvensReadCount;
	char cCharBuffer[128] = "Hello world";
	INPUT_RECORD sInputBuffer[8];

	SetConsoleTitle(cCharBuffer);
	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_INTENSITY); //text is red and intensified
	WriteConsole(hStdout, cCharBuffer, wsprintf(cCharBuffer, "Hello world!\n"), &iCharWrittenCount, NULL);

	SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
	WriteConsole(hStdout, cCharBuffer, wsprintf(cCharBuffer, "Press any key to quit..."), &iCharWrittenCount, NULL);
	
	FlushConsoleInputBuffer(hStdin);
	ReadConsoleInput(hStdin, sInputBuffer, 8, &iEvensReadCount);
	return 0;
}