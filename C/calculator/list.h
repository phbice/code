#define LIST_START 0
#define LIST_END   -1
#define LIST_NOW   1

typedef struct item
{
	int           flag;
	double        num;
}ITEM;

typedef struct node
{
	ITEM item;
	struct node * pNext;
}NODE;

typedef struct list{
	NODE * header;
	int iNow;
	int iEnd;
	NODE * pNow;
	NODE * pEnd;
}LIST;

LIST * createlist(void);
int emptylist(LIST * list);
int destroylist(LIST * list);

int setlistpos(LIST * list, int pos, int offset);
int getitem(LIST * list, ITEM * item);
int append(LIST * list, ITEM * item);

int push(LIST * list, ITEM * item);
int pop (LIST * list, ITEM * item);
int top (LIST * list, ITEM * item);
int isempty(LIST * list);

void printitem(ITEM * item);
void printlist(LIST * list);
