#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//static table[95] = {
//	' ',  '!', '"', '#', '$', '%', '&', '\'', '(', ')',
//	'*',  '+', ',', '-', '.', '/', '0', '1',  '2', '3',
//	'4',  '5', '6', '7', '8', '9', ':', ';',  '<', '=',
//	'>',  '?', '@', 'A', 'B', 'C', 'D', 'E',  'F', 'G',
//	'H',  'I', 'J', 'K', 'L', 'M', 'N', 'O',  'P', 'Q',
//	'R',  'S', 'T', 'U', 'V', 'W', 'X', 'Y',  'Z', '[',
//	'\\', ']', '^', '_', '`', 'a', 'b', 'c',  'd', 'e',
//	'f',  'g', 'h', 'i', 'j', 'k', 'l', 'm',  'n', 'o',
//	'p',  'q', 'r', 's', 't', 'u', 'v', 'w', 'x',  'y',
//	'z',  '{', '|', '}', '~'
//};

typedef unsigned long long int QWORD;

QWORD StringToBin(char string[])
{
	int i;
	QWORD result = 0;
	for (i = 0; string[i] != 0 && i < 21; i++)
		result = result * 95 + string[i] - ' ';
	return result;
}

int main(void)
{
	char string[21];
	QWORD bin;

	do
	{
		printf("Input string >");
		gets_s(string, 21);

		bin = StringToBin(string);
		printf("%016llX\n", bin);
	} while (strcmp(string, "q") != 0);
	system("pause");
	return 0;
}