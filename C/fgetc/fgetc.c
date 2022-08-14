#include <stdio.h>

int main(void)
{
	char c;
	
	getchar();

	while ( (c = getchar()) != '\n');
	
	printf("end");
	
	return 0;
}