#define LIST_START 0
#define LIST_END   -1
#define LIST_NOW   1

typedef struct item
{
	int           degree;
	double        coef;
}ITEM;

typedef struct node
{
	ITEM item;
	struct node * pNext;
}NODE;

typedef struct list{
	NODE * header;
	int iEnd;
	NODE * pEnd;
}LIST;

LIST * createlist(void);     //create an empty list with header node
int emptylist(LIST * list);  //delete all the nodes except the header node
int destroylist(LIST * list); //destroy the whole list and free the memary
int copylist(LIST * dest, LIST * src);
LIST * splitlist(LIST * scrList, NODE * pSplitNode);
int catlist(LIST * base, LIST * ext);

int listlen(LIST * list);

//int setlistpos(LIST * list, int pos, int offset);
//int getitem(LIST * list, ITEM * item);
//ITEM * getitempos(LIST * list);

NODE * getkth(LIST * list, int k);
ITEM * retrieve(NODE * pNode);
NODE * first(LIST * list);
NODE * last(LIST * list);
NODE * previous(LIST * list, NODE * pNode);
NODE * advance(NODE * pNode);
int append(LIST * list, ITEM * item);

int push(LIST * list, ITEM * item);
int pop (LIST * list, ITEM * item);
int top (LIST * list, ITEM * item);
int isempty(LIST * list);

//void printitem(ITEM * item);
void printlist(LIST * list);
