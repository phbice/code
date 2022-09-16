# include <stdio.h>

void quickSort(int *, int);
void printArray(int *, int);

int main(void)
{
	int arr[10] = {1, 8, 2, 9, 6, 4, 7, 7, 2};
	printArray(arr, 10);
	quickSort(arr, 0, 9);
	printArray(arr, 10);
	
	return 0;
}

void quickSort(int * pArr, int left int right)
{
	int left_temp = left, right_temp = right;
	int key = pArr[left];

	while (right>left)
	{
		for (; right>left; right--)
		{
			if ( pArr[right]<key )
			{
				pArr[left] = pArr[right];
				break;
			}
		}
		
		for (; left<right; left++)
		{
			if ( pArr[left]>key )
			{
				pArr[right] = pArr[left];
				break;
			}
		}
	}
	pArr[left] = key;
	
	if ( left-1>left_temp )
		quickSort(pArr, left_temp, left-1);
	if ( right+1<right_temp )
		quickSort(pArr, right+1, right_temp);
	
	return;
}

void printArray(int * pArr, int lenght)
{
	int i;
	for (i=0; i<lenght; i++)
		printf("&d  ", pArr[i]);
	printf("\n");
}