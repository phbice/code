/*Game of life : Calculating module
*/
/*
typedef struct canvas
{
	int width;
	int height;
	char pix[];
}CANVAS;
*/

#include "life.h"

//void UpdataLife(char canvas[][WIDTH]);

void generate(char parent[][WIDTH], char child[][WIDTH], char changed[][WIDTH])
{
	int i,j;
	int iNumNeighbors;

	for (i=0; i<HEIGHT; i++)
	{
		for (j=0; j<WIDTH; j++)
		{
			iNumNeighbors = CountNeighbors(parent, i, j);
			switch (iNumNeighbors)
			{
			case 2:
				child[i][j] = parent[i][j];
				break;
			case 3:
				child[i][j] = LIVE;
				break;
			default:
				child[i][j] = DIE;
			}

			if (parent[i][j] != child[i][j])
				changed[i][j] = LIFE_CHANGED;
			else
				changed[i][j] = LIFE_UNCHANGED;
		}
	}

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
