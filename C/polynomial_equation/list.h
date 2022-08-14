#define EMPTY -1
#define FULL  1

typedef double ITEM;
typedef struct list
{
	int n;    //the max number of items
	int i;    //the number of items now
	ITEM item[];
}LIST;

LIST * creat(int n);
int append(LIST * list, ITEM item);
ITEM get(LIST * list, int i);
void printlist(LIST * pList);
