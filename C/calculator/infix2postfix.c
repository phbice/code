#include "list.h"
#include "PreProcess.h"
#include "infix2postfix.h"

LIST * infix2postfix(LIST * infix)
{
	ITEM inputitem, tempitem, topitem;
	LIST * postfix = createlist();
	LIST * stack   = createlist();

	setlistpos(infix, LIST_START, 0);
	while (!getitem(infix, &inputitem))
	{
		switch (inputitem.flag & FLAG_MASK)
		{
		case NUMBER:
			append(postfix, &inputitem);
			break;

		case OPERATOR:
			while (!isempty(stack))
			{
				top(stack, &topitem);
				if ((topitem.flag == BRACKET_L) || priority(inputitem.flag&(~FLAG_MASK), topitem.flag&(~FLAG_MASK)) == PL_HIGH)
				{
					break;
				}
				else
				{
					pop(stack, &tempitem);
					append(postfix, &tempitem);
				}
			}
			push(stack, &inputitem);
			break;

		case BRACKET:
			if (inputitem.flag == BRACKET_L)
			{
				push(stack, &inputitem);
			}
			else
			{
				while (top(stack, &topitem), topitem.flag != BRACKET_L)
				{
					if (isempty(stack))
					{
						emptylist(postfix);
						tempitem.flag = CAL_ERROR | UNBALENCED_BRACKET;
						append(postfix, &tempitem);
						return postfix;
					}
					pop(stack, &tempitem);
					append(postfix, &tempitem);
				}
				pop(stack, &tempitem);
			}
			break;
		}
	}
	
	while (!isempty(stack))
	{
		top(stack, &topitem);
		if (topitem.flag == BRACKET_L)
		{
			emptylist(postfix);
			tempitem.flag = CAL_ERROR | UNBALENCED_BRACKET;
			append(postfix, &tempitem);
			return postfix;
		}
		pop(stack, &tempitem);
		append(postfix, &tempitem);
	}

	destroylist(stack);
	return postfix;
}

int priority(int latter, int former)
{
	static int pltable[] = {0, 1,  1,  2,  2,  3,  1};
	               //         ADD SUB MUL DIV POW NEG
	if (pltable[latter] < pltable[former])
		return PL_LOW;
	else if (pltable[latter] > pltable[former])
		return PL_HIGH;
	else if (latter == POW)
		return PL_HIGH;
	else
		return PL_LOW;
}