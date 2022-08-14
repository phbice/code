/****************************
    infix to postfix
****************************/
#include <stdio.h>

#define PL_HIGH  1
#define PL_LOW   -1

int stack[256];
int top = -1;

void push(int x)
{
	top++;
	stack[top]=x;
}

int pop()
{
	top--;
	return stack[top+1];
}

int stacktop()
{
	return stack[top];
}

int isempty()
{
	return top==-1;
}

void infix2postfix(char input[]);
int MatchChar(char cData, char * szList);
int pl(int a, int b);

int main(int argc, char **argv)
{
	char s[256];
	gets(s);
	infix2postfix(s);
	return 0;
}

void infix2postfix(char input[])
{
	int i;
	for (i=0; input[i]!=0; i++)
	{
		if (MatchChar(input[i], "0123456789."))
			putchar(input[i]);
		else
		{
			putchar(' ');
			if (input[i] == ')')
			{
				while (stacktop()!='(')
				{
					putchar(pop());
					if (isempty())
					{
						printf("syntax error!");
						return;
					}
				}
				pop();
			}
			else if ( isempty() || (input[i]=='(') || (pl(input[i], stacktop())==PL_HIGH))
			{
				push(input[i]);
			}
			else
			{
				while (!isempty() && (stacktop()!='(') && (pl(input[i], stacktop())==PL_LOW))
				{
					putchar(pop());
				}
				push(input[i]);
			}
		}
	}
	while (!isempty())
	{
		if (stacktop()=='(')
		{
			printf("syntax error!");
			return;
		}
		putchar(pop());
	}
}

int MatchChar(char cData, char * szList)
{
	int i;
	for (i=0; (szList[i]!=0) && (szList[i]!=cData); i++);
	
	if (szList[i]==cData)
	{
		return i+1;
	}
	else
	{
		return 0;
	}
}

int o2i(int o)
{
	int i;
	switch (o)
	{
	case '+':
	case '-':
		i=1;
		break;
	case '*':
	case '/':
		i=2;
		break;
	case '^':
		i=3;
		break;
	}
	return i;
}

int pl(int a, int b)
{
	int a1, b1;
	a1 = o2i(a);
	b1 = o2i(b);
	
	if (a1>b1)
		return PL_HIGH;
	else if (a1<b1)
		return PL_LOW;
	else if (a == '^')
		return PL_HIGH;
	else
		return PL_LOW;
}