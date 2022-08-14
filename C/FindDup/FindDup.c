#include <stdio.h>
#include <string.h>

int main(void)
{
	char szName1[64];
	char szName2[64];
	int  iCount, i;
	FILE * pFile; 

	if ( (pFile = fopen("name.txt", "r")) == NULL)
		return 1;

	fgets(szName1, 64, pFile);
	iCount = 1;
	while (fgets(szName2, 64, pFile) != NULL)
	{
		if (strcmp(szName1, szName2)==0)
		{
			iCount++;
		}
		else
		{
			if (iCount >= 2)
			{
				for (i=0; szName1[i]!='\n'; i++);
				szName1[i] = 0;
				printf("“%s”有 %d 人重名\n", szName1, iCount);
			}
			strcpy(szName1, szName2);
			iCount = 1;
		}
	}
	
	return 0;
}
