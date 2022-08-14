#include <stdio.h>
#include <stdlib.h>

#define RADIX   9
#define RADIX_N 4782969

typedef unsigned long long int QWORD;
typedef	QWORD NUM;

void FindDivisibility(NUM qwBaseNum);

int main(void)
{
	FindDivisibility(0LL);

	system("pause");
	return 0;
}

void FindDivisibility(NUM qwBaseNum)
{
	int iNumLen; //Length of the given qwBaseNum
	int iAddedDigital; //The Digital to be added at the end of the qwBaseNum
	NUM qwBackup = qwBaseNum;
	char bFlag[RADIX] = { 0 }; //Set 1 to flag the used number
	for (iNumLen = 0; qwBackup != 0; qwBackup /= RADIX, iNumLen++)
	{
		bFlag[qwBackup % RADIX] = 1;
	}

	qwBaseNum *= RADIX;
	if ((qwBaseNum / (RADIX_N)) == 0)
	{
		for (iAddedDigital = 1; iAddedDigital <= RADIX - 1; iAddedDigital++)
		{
			if (bFlag[iAddedDigital] == 0 && ((qwBaseNum + iAddedDigital) % (iNumLen + 1)) == 0)
			{
				FindDivisibility(qwBaseNum + iAddedDigital);
			}
		}
	}
	else
	{
		for (iAddedDigital = 1; iAddedDigital <= RADIX - 1; iAddedDigital++)
		{
			if (bFlag[iAddedDigital] == 0 && ((qwBaseNum + iAddedDigital) % (iNumLen + 1)) == 0)
			{
				printf("%llo\n", qwBaseNum + iAddedDigital);
			}
		}
	}
	
	return;
}