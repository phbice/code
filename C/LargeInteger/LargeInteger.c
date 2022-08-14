#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINT_BITS 4096
#define LENGTH    (LINT_BITS / 32)

#define CARRY(x)  (((x) & 0xFFFFFFFF00000000LL) >> 32)
#define RESULT(x) ((x)&0x00000000FFFFFFFFLL)

typedef unsigned int DWORD;
typedef unsigned long long int QWORD;

DWORD * Ladd(DWORD * pNum1, DWORD * pNum2)
{
	static DWORD result[LENGTH];
	int i;
	QWORD temp;

	memset(result, 0, LENGTH * sizeof(DWORD));
	
	for (i = 0, temp = 0; i < LENGTH; i++) {
		temp = (QWORD)pNum1[i] + pNum2[i] + CARRY(temp);
		result[i] = RESULT(temp);
	}

	return result;
}

DWORD * Lmul(DWORD * pNum1, DWORD * pNum2)
{
	static DWORD result[LENGTH];
	static DWORD resultTemp[LENGTH];
	int i, j;
	QWORD reminder;

	//initialize the result array, avoid error when Lnum is called more than one time
	memset(result, 0, LENGTH * sizeof(DWORD));

	for (i = 0; i < LENGTH; i++)
	{
		memset(resultTemp, 0, LENGTH * sizeof(DWORD));
		for (j = 0, reminder = 0; j < LENGTH - i; j++)
		{
			reminder = (QWORD)pNum1[i] * pNum2[j] + CARRY(reminder);
			resultTemp[j + i] = RESULT(reminder);
		}
		memcpy(result, Ladd(result, resultTemp), LENGTH * sizeof(DWORD));
	}

	return result;
}

static DWORD divide_by_10(DWORD * pNum, DWORD * pResult)
{
	static DWORD resultTemp[LENGTH];
	int i;
	DWORD reminder = 0;
	for (i = LENGTH - 1; i >= 0; i--)
	{
		resultTemp[i] = (DWORD)( ( ((QWORD)reminder << 32) | pNum[i] ) / 10 );
		reminder = (DWORD)( ( ((QWORD)reminder << 32) | pNum[i]  ) % 10 );
	}
	memcpy(pResult, resultTemp, LENGTH * sizeof(DWORD));
	
	return reminder;
}

static int zero(DWORD * pNum)
{
	int i;
	for (i = 0; i < LENGTH; i++)
		if (pNum[i] != 0)
			return 0;
	return 1;
}
int  Lprint(DWORD * pNum)
{
//	int i;
//	for (i = LENGTH - 1; i >= 0; i--) {
//		printf("%08X ", pNum[i]);
//		if (i % 8 == 0)
//			putchar('\n');
//	}
	static DWORD result[LENGTH];
	int i;
	char * digital = (char *)malloc(1235);
	DWORD reminder = divide_by_10(pNum, result);
	digital[0] = reminder + '0';

	for (i = 1; !zero(result); i++)
	{
		reminder = divide_by_10(result, result);
		digital[i] = reminder + '0';
	}
	for (i -= 1; i >= 0; i--)
	{
		putchar(digital[i]);
	}

	return 0;
}

int main()
{
	static DWORD a[LENGTH] = { 1 };
	static DWORD b[LENGTH] = { 0 };

//	freopen("log.txt", "w", stdout);
	for (b[0] = 1; b[0] <= 500; b[0]++)
	{
		memcpy(a, Lmul(a, b), LENGTH * sizeof(DWORD));
//		Lprint(a);
//		putchar('\n');
	}
	Lprint(a);
	putchar('\n');

	printf("Press [Enter] to quit");
	getchar();
	return 0;
}
