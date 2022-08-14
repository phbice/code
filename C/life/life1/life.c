/*Game of life
*/
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH		80	
#define HEIGHT		25	
#define GENERATION  200

#define LIVE		1
#define DIE			0

#define NEIGHBOR_RANGE 2

#define OUTPUT_DIR	"F:\\MyFile\\mathematica\\life\\"

HANDLE hStdout;

void create_bitmap(char filename[], unsigned char data[],int width,int height);

void generate(char parent[][WIDTH], char child[][WIDTH]);
int CountNeighbors(char canvas[][WIDTH], int x, int y);
void ShowLife(char canvas[][WIDTH]);

/**Generate next generation of life, "child", according to the current generation, "parent"
*/
void generate(char parent[][WIDTH], char child[][WIDTH])
{
	int i,j;
	int iNumNeighbors;

	for (i=0; i<HEIGHT; i++)
	{
		for (j=0; j<WIDTH; j++)
		{
			iNumNeighbors = CountNeighbors(parent, i, j);
			if (iNumNeighbors == 3)
			{
				child[i][j] = LIVE;
			}
			else if (iNumNeighbors == 2)
			{
				child[i][j] = parent[i][j];
			}
			else
			{
				child[i][j] = DIE;
			}			
		}
	}

}


static int mod(int i, int m)
{
	if (i >= m)
	{
		i = i - m;
	}
	else if (i < 0)
	{
		i = i + m;
	}
	return i;
}

int CountNeighbors(char canvas[][WIDTH], int i, int j)
{
	/*
	  L    j    R
	U *    *    *
	i * center  *
	D *    *    *
	*/
	
	int U = i-1,
	    D = i+1,
		L = j-1,
		R = j+1;
	
	if (U == -1)
		U = HEIGHT - 1;
	if (D == HEIGHT)
		D = 0;
	if (L == -1)
		L = WIDTH - 1;
	if (R == WIDTH)
		R = 0;
	
	return  canvas[U][L] +
			canvas[U][j] +
			canvas[U][R] +
			canvas[i][L] +
			canvas[i][R] +
			canvas[D][L] +
			canvas[D][j] +
			canvas[D][R];

}

void ShowLife(char canvas[][WIDTH])
{
	static CONSOLE_CURSOR_INFO sCursorInfo;
	int i, j;
	GetConsoleCursorInfo(hStdout, &sCursorInfo);
	sCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hStdout, &sCursorInfo);
	SetConsoleCursorPosition(hStdout, (COORD) { 0, 0 });
	for (i=0; i<HEIGHT; i++)
	{
		for (j=0; j<WIDTH; j++)
		{
			if (canvas[i][j] == LIVE)
			{
				putchar('#');
			}
			else
			{
				putchar(' ');
			}
		}
		putchar('\n');
	}
}

int main(void)
{
	static char canvas1[HEIGHT][WIDTH];
	static char canvas2[HEIGHT][WIDTH];
	
	int i, j;
	
	char (* pParent)[WIDTH] = canvas1;
	char (* pChild)[WIDTH]  = canvas2;
	char (* pTemp)[WIDTH];
	
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

		//Random soup
	srand((unsigned int)time(NULL));
	for (i=0; i<HEIGHT; i++)
	{
		for (j=0; j<WIDTH; j++)
		{
			pParent[i][j] = rand()&1;
		}
	}

	while(1)
	{
		generate(pParent, pChild); //generate next gerneration of life
		ShowLife(pChild); //show life

		pTemp = pParent;
		pParent = pChild;
		pChild = pTemp;
		Sleep(20);
	}

	return 0;
}
