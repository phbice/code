/*calculator
*/
#include <stdio.h>
#include <math.h>
#include <float.h>

#include "list.h"
#include "PreProcess.h"
#include "infix2postfix.h"

void Calculate(char * szInput, ITEM * result);
void calculate_postfix(LIST * formular, ITEM * result);
int calculate_sub(LIST * stack, int operator, ITEM * result);

void Calculate(char * szInput, ITEM * result)
{
	LIST * infix_formular,  * postfix_formular;

	infix_formular = PreProcess(szInput);

	top(infix_formular, result);
	if ( (result->flag & FLAG_MASK) == CAL_ERROR)
	{
		destroylist(infix_formular);
		return;
	}

	postfix_formular = infix2postfix(infix_formular);
//	printlist(postfix_formular);
	destroylist(infix_formular);

	top(postfix_formular, result);
	if ((result->flag & FLAG_MASK) == CAL_ERROR)
	{
		destroylist(postfix_formular);
		return;
	}

	calculate_postfix(postfix_formular, result);
	destroylist(postfix_formular);

	return;
}

void calculate_postfix(LIST * formular, ITEM * result)
{
	ITEM inputitem, tempitem;
	LIST * stack = createlist();
	setlistpos(formular, LIST_START, 0);
	while (!getitem(formular, &inputitem))
	{
		switch (inputitem.flag & FLAG_MASK)
		{
		case NUMBER:
			push(stack, &inputitem);
			break;
		case OPERATOR:
			if ( calculate_sub(stack, inputitem.flag&(~FLAG_MASK), result) )
			{
				destroylist(stack);
				return;
			}
			break;
		}
	}
	pop(stack, &tempitem);
	if (!isempty(stack))
	{
		result->flag = CAL_ERROR | SYNTAX_ERROR;
	}
	else
	{
		result->flag = tempitem.flag;
		result->num  = tempitem.num;
	}
		destroylist(stack);
	return;
}

int calculate_sub(LIST * stack, int operator, ITEM * result)
{
	ITEM a = (ITEM){0,0},
	     b = (ITEM){0,0},
		 c = (ITEM){NUMBER,0};

	pop(stack, &b);
	if (operator!=NEG)
		pop(stack, &a);

	if ( (operator!=NEG && (a.flag!=NUMBER || b.flag!=NUMBER)) ||
	     (operator==NEG && b.flag!=NUMBER))
	{
		result->flag = CAL_ERROR | SYNTAX_ERROR;
		return 1;
	}

	switch (operator)
	{
	case ADD:
		c.num = a.num + b.num;
		break;
	case SUB:
		c.num = a.num - b.num;
		break;
	case MUL:
		c.num = a.num * b.num;
		break;
	case DIV:
		if (b.num>=-DBL_EPSILON && b.num<=DBL_EPSILON)
		{
			result->flag = CAL_ERROR | DIVIDED_BY_ZERO;
			return 1;
		}
		c.num = a.num / b.num;
		break;
	case  POW:
		c.num = pow(a.num, b.num);
		break;
	case NEG:
		c.num =       - b.num;
	}
	push(stack, &c);
	return 0;
}

int main(void)
{
	char formular[256];
	ITEM result;
	gets(formular);
	Calculate(formular, &result);

	if ( (result.flag & FLAG_MASK) == CAL_ERROR)
	{
		switch (result.flag & (~FLAG_MASK))
		{
		case UNKNOWN_EXPRESSION:
			printf("\nError: Unknown expression\n");
			break;
		case UNBALENCED_BRACKET:
			printf("\nError: Bracket is not balenced\n");
			break;
		case DIVIDED_BY_ZERO:
			printf("\nError: Divided by zero\n");
			break;
		case SYNTAX_ERROR:
			printf("\nError: syntax error");
			break;
		}
	}
	else
	{
		printf("\n%lf\n", result.num);
	}

	getchar();
	return 0;
}