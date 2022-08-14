#include <stdio.h>
#include <malloc.h>
#include "list.h"
#include <math.h>

double cal(LIST * pPoly, double x);
LIST * d(LIST * pPoly);
LIST * solve(LIST * pPoly);
double solve_newton(LIST * pPoly, LIST * pPoly1, double x0);
double solve_bisection(LIST * pPoly, double ends_l, double ends_r);

double cal(LIST * pPoly, double x)
{
	int i = pPoly->n-1;
	double result = get(pPoly, i);
	for (; i>=1; i--)
	{
		result = result * x  +  get(pPoly, i-1);
	}
	
	return result;
}

LIST * d(LIST * pPoly)
{
	int i;
	double t;
	LIST * pPoly1 = creat(pPoly->n - 1);
	for (i=1; i<pPoly->n; i++)
	{
		append(pPoly1, i * get(pPoly, i));
	}
	return pPoly1;
}

LIST * solve(LIST * pPoly)
{
	LIST * pSolution = creat(pPoly->n-1);
	LIST * pPoly1;     //Derivative
	LIST * pSolution1; //solution of the derivative
	int i; //loop counter
	double delta;
	double ends_r, ends_l;
	
	if (pPoly->n > 3)
	{
		pPoly1 = d(pPoly);
		pSolution1 = solve(pPoly1);

		//monotonical, only one solution
		if ( (pSolution1 == NULL) || (pSolution1->i == 0))
		{
			append(pSolution, solve_newton(pPoly, pPoly1, 0));
		}
		//more than one solution, calculate the endpoints and isolate the solution
		else if ( ( cal( pPoly, get(pSolution1,0) ) <= 0 )&&( (pPoly->n&0x01) == 0) ||
		          ( cal( pPoly, get(pSolution1,0) ) >= 0 )&&( (pPoly->n&0x01) == 1) )
		{
			ends_l = get(pSolution1,0);
			i=1;
		}
		else
		{
			ends_l = get(pSolution1,0)-1;
			ends_l = ends_l - cal(pPoly, ends_l)/cal(pPoly1, ends_l);
			i=0;
		}

		for (; i < pSolution1->i; i++)
		{
			ends_r = get(pSolution1, i);
			if (cal(pPoly, ends_l) * cal(pPoly, ends_r) <= 0)
			{
				append(pSolution, solve_bisection(pPoly, ends_l, ends_r));
				ends_l = ends_r;
			}
		}
		
		if (cal(pPoly, ends_r)<=0)
		{
			append(pSolution, solve_newton(pPoly, pPoly1, ends_r + 1));
		}

		free(pPoly1);
		free(pSolution1);
		return pSolution;
	}
	else if (pPoly->n == 1)
	{
		return pSolution;
	}
	else if (pPoly->n == 2)
	{
		if (get(pPoly, 1) == 0)
		{
			return pSolution;
		}
		else
		{
			append(pSolution, -get(pPoly, 1)/get(pPoly, 0));
			return pSolution;
		}
	}
	else if (pPoly->n == 3)
	{
		delta = get(pPoly, 1) * get(pPoly, 1) - 4 * get(pPoly, 2) * get(pPoly, 0);

		if (delta == 0)
		{
			append( pSolution, - get(pPoly, 1)/(2 * get(pPoly, 2)) );
		}
		else if (delta > 0)
		{
			append( pSolution, (-get(pPoly,1) - sqrt(delta)) / (2*get(pPoly, 2)) );
			append( pSolution, (-get(pPoly,1) + sqrt(delta)) / (2*get(pPoly, 2)) );
		}
		return pSolution;
	}
}

double solve_newton(LIST * pPoly, LIST * pPoly1, double x0)
{
	static double ACCURACY = 1E-10;
	while(fabs(cal(pPoly, x0))>=ACCURACY)
	{
		x0 = x0 - cal(pPoly, x0)/cal(pPoly1, x0);
	}
	return x0;
}


double solve_bisection(LIST * pPoly, double ends_l, double ends_r)
{
	int i; //times of bisection
	double middle;
	for(i=0; i<=54; i++)
	{
		middle = ( ends_l + ends_r )/2;
		if ( cal(pPoly, ends_l) * cal(pPoly, middle) <= 0)
		{
			ends_r = middle;
		}
		else
		{
			ends_l = middle;
		}
	}
	return (ends_l + ends_r)/2;
}

int main(void)
{
	int i,n;
	double coef;
	LIST * pSolution;
	LIST * pPoly;
	
/*
	append(pPoly, -5);
	append(pPoly, -7);
	append(pPoly, 3);
	append(pPoly, 1);
*/
	
	printf("Input the degree of the polynomial>");
	scanf("%d",&n);
	n++;
	pPoly = creat(n);
	printf("Input coefficients in in ascending order:\n");
	
	printf("Constant term         >");
	scanf("%lf",&coef);
	append(pPoly,coef);
	
	printf("The coefficient of x  >");
	scanf("%lf",&coef);
	append(pPoly,coef);
	
	for (i=2; i<n; i++)
	{
		printf("The coefficient of x^%d>",i);
		scanf("%lf",&coef);
		append(pPoly,coef);
	}
	
	printf("Equation:\n");
	
	printf("%lfx^%d ", get(pPoly,n-1), n-1);
	for (i=n-2; i>=2; i--)
	{
		printf("%+lfx^%d ", get(pPoly,i), i);
	}
	printf("%+lfx %+lf = 0\n", get(pPoly,1), get(pPoly,0));

	pSolution = solve(pPoly);

	printf("Solution:\n");
	printlist(pSolution);

	return 0;
}
