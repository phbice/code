#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "PreProcess.h"

LIST * PreProcess(char * szInput)
{
	int i, tempflag;
	ITEM tempitem = (ITEM){0,0};
	LIST * formular = createlist();
	
	for (i=0; szInput[i]!=0;)
	{
		    // number detected
		if ( MatchChar(szInput[i], "0123456789.") )
		{
			i = i + getnum(&szInput[i], &tempitem);
			append(formular, &tempitem);
		}   // bracket detected
		else if ((tempflag = MatchChar(szInput[i], "()")) != 0)
		{
			tempitem.flag = BRACKET | tempflag;
			append(formular, &tempitem);
			i++;
		}   //operator detected
		else if ( (tempflag = MatchChar(szInput[i], "+-*/^"))!=0 )
		{
			if (szInput[i]=='-' && tempitem.flag!=NUMBER)
			{
				tempitem.flag = NEG; //distinguish negtive sign with subtraction sign
			}
			else
			{
				tempitem.flag = tempflag;
			}
			tempitem.flag |= OPERATOR;

			append(formular, &tempitem);
			i++;
		}	//blank character detected
		else if ( MatchChar(szInput[i], " \t") )
		{
			i++;
		}
		else
		{
			emptylist(formular);
			tempitem.flag = CAL_ERROR | UNKNOWN_EXPRESSION;
			tempitem.num = (double)i;
			append(formular, &tempitem);
			break;
		}
	}

	return formular;
}

int getnum(char string[], ITEM * output)
{
	char cTemp;
	int  i, iDotCount;
	for (i=0, iDotCount=0; (string[i]!=0) && MatchChar(string[i],"0123456789.") && (iDotCount<=1); i++)
	{
		if (string[i] == '.')
		{
			iDotCount++;
		}
	}
	
	cTemp = string[i];
	string[i] = 0;

	output->flag = NUMBER;
	output->num  = atof(string);

	string[i] = cTemp;
	
	return i;
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

void printitem(ITEM * item)
{
	static char optable[16] = "@+-*/^_";
	switch (item->flag & FLAG_MASK)
	{
	case NUMBER:
		printf("%lf", item->num);
		break;
	case OPERATOR:
		putchar(optable[item->flag & (~FLAG_MASK)]);
		break;
	case BRACKET:
		putchar(item->flag==BRACKET_L ? '(' : ')');
		break;
	}
}