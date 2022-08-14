#include <stdio.h>
#include <stdlib.h>

#define FILENAME1 "F:\\expression.rar"
#define FILENAME2 "F:\\t.rar"

int main(void)
{
	int i, c1, c2;
	FILE * pFile1;
	FILE * pFile2;

	fopen_s(&pFile1, FILENAME1, "rb");
	fopen_s(&pFile2, FILENAME2, "rb");

	for (i = 0; (!feof(pFile1)) && (!feof(pFile2)); i++)
		if ( (c1 = getc(pFile1)) != (c2 = getc(pFile2)))
			break;

	printf("Offset: 0x%X\n", i);

	fclose(pFile1);
	fclose(pFile2);
	system("pause");
	return 0;
}