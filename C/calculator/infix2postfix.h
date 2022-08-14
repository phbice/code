#define PL_HIGH 1
#define PL_LOW  -1

LIST * infix2postfix(LIST * infix);
int priority(int latter, int former);
