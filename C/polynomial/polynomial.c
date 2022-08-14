#include <stdio.h>
#include <stdlib.h>
#include "list.h"

LIST * AddPoly(LIST * poly1, LIST * poly2);
LIST * MulPoly(LIST * poly1, LIST * poly2);

LIST * AddPoly(LIST * poly1, LIST * poly2)
{
	LIST * polySum = createlist(); //´¢´æ½á¹û
	NODE * pNode1, * pNode2;
	ITEM temp;

	for (pNode1 = first(poly1), pNode2 = first(poly2); pNode1 != NULL; pNode1 = advance(pNode1))
	{
		//Go through poly1, check items in poly1 one by one
		//during each pass in the loop, all items that have a lower degree than item1 are added up

		while (pNode2 != NULL && retrieve(pNode2)->degree < retrieve(pNode1)->degree)
		{
			//for one item1, go through all the items that has a lower degree in ploy2
			//if a item2 has a higher or the same degree, get the next itme1 and repeat the process
			append(polySum, retrieve(pNode2)); //there are no like item in poly1, so the item2 is directly put into the sum
			pNode2 = advance(pNode2);
		}
		if (pNode2 == NULL)//pNode2 end, quite the loop
			break;

		//all the item2 that have a lower degree is added, then add the item1
		if (retrieve(pNode1)->degree < retrieve(pNode2)->degree)
		{
			append(polySum, retrieve(pNode1));
		}
		else //unit like item
		{
			temp.degree = retrieve(pNode1)->degree;
			temp.coef = retrieve(pNode1)->coef + retrieve(pNode2)->coef;
			append(polySum, &temp);
			pNode2 = advance(pNode2); //the item is added, so it needs to be skipped in next loop
		}
		//all the items whose degree is lower than item1 in both poly were processed
		//then get the next item1 and again process all the items that has a lower degree
	}
	//add up the remained items
	while (pNode1 != NULL)
	{
		append(polySum, retrieve(pNode1));
		pNode1 = advance(pNode1);
	}
	while (pNode2 != NULL)
	{
		append(polySum, retrieve(pNode2));
		pNode2 = advance(pNode2);
	}

	return polySum;
}

LIST * SplitPoly(LIST * poly)
{

	NODE * pNodeMid; //split point 
	int midDegree = ( retrieve(first(poly))->degree + retrieve(last(poly))->degree + 1 ) / 2;
	for (pNodeMid = first(poly);
		advance(pNodeMid) != NULL && retrieve(pNodeMid)->degree <= midDegree;
		pNodeMid = advance(pNodeMid));

	return splitlist(poly, pNodeMid);
}


LIST * MulPoly(LIST * poly1, LIST * poly2)
{
	ITEM * pItem = NULL;
	ITEM   item;
	NODE * travNode = NULL;
	LIST * splitPoly1, *splitPoly2;
	LIST * tempPoly1, * tempPoly2, * tempPoly3, * tempPoly4; //save intermediate result
	LIST * totalResult;

	if ((listlen(poly1) != 1) && (listlen(poly2) != 1))
	{
			//split the polynomials and recursion
		splitPoly1 = SplitPoly(poly1);
		splitPoly2 = SplitPoly(poly2);
			//part1
		tempPoly1 = MulPoly(poly1, poly2);
		catlist(tempPoly1, MulPoly(splitPoly1, splitPoly2));
			//part2
		tempPoly2 = MulPoly(poly1, splitPoly2);
		tempPoly3 = MulPoly(poly2, splitPoly1);
		tempPoly4 = AddPoly(tempPoly2, tempPoly3);
			//add part1 and part2
		totalResult = AddPoly(tempPoly1, tempPoly4);
			//destroy all the intermediate result
		destroylist(tempPoly1);
		destroylist(tempPoly2);
		destroylist(tempPoly3);
		destroylist(tempPoly4);
			//concatenate the splited polynomial
		catlist(poly1, splitPoly1);
		catlist(poly2, splitPoly2);

		return totalResult;
	}
	else if (listlen(poly1) == 1) //end the recursion
	{
		pItem = retrieve(first(poly1));
		travNode = first(poly2);
	}
	else if (listlen(poly2) == 1)
	{
		pItem = retrieve(first(poly2));
		travNode = first(poly1);
	}
	totalResult = createlist();
	for ( ; travNode != NULL; travNode = advance(travNode))
	{
		item.coef = pItem->coef   * retrieve(travNode)->coef;
		item.degree = pItem->degree + retrieve(travNode)->degree;
		append(totalResult, &item);
	}

	return totalResult;
}
/*
LIST * MulPoly(LIST * poly1, LIST * poly2)
{
	LIST * polyProduct = createlist();
	LIST * polyProductTemp;
	LIST * polyTemp = createlist();
	NODE * pNodeTemp, * pNode1, * pNode2;
	copylist(polyTemp, poly1);

	for (pNode2 = first(poly2); pNode2 != NULL; pNode2 = advance(poly2, pNode2))
	{
		for (pNodeTemp = first(polyTemp), pNode1 = first(poly1); pNodeTemp != NULL; pNodeTemp = advance(polyTemp, pNodeTemp), pNode1 = advance(polyTemp, pNode1))
		{
			retrieve(pNodeTemp)->coef = retrieve(pNode1)->coef   * retrieve(pNode2)->coef;
			retrieve(pNodeTemp)->degree = retrieve(pNode1)->degree + retrieve(pNode2)->degree;
		}
		polyProductTemp = AddPoly(polyTemp, polyProduct);
		free(polyProduct);
		polyProduct = polyProductTemp;
	}

	return polyProduct;
}
*/

void testSplitCat(void)
{
	ITEM item0 = (ITEM) { 0, 1 };
	ITEM item1 = (ITEM) { 1, 2 };
	ITEM item2 = (ITEM) { 2, 3 };
	ITEM item3 = (ITEM) { 3, 4 };
	LIST * poly1 = createlist();
	LIST * poly2;
	NODE * pSplitNode;

	append(poly1, &item0);
	append(poly1, &item1);
	append(poly1, &item2);
	append(poly1, &item3);
	pSplitNode = getkth(poly1, 3);
	poly2 = splitlist(poly1, pSplitNode);

	printlist(poly1);
	putchar('\n');
	printlist(poly2);
	putchar('\n');

	catlist(poly2, poly1);
	poly1 = NULL;
	printlist(poly2);
	putchar('\n');
	return;
}

int main(void)
{

	ITEM item0 = (ITEM) { 0, 1 };
	ITEM item1 = (ITEM) { 1, 2 };
	ITEM item2 = (ITEM) { 2, 1 };
	ITEM item3 = (ITEM) { 3, 3 };
	ITEM item4 = (ITEM) { 4, 1 };
	ITEM item6 = (ITEM) { 6, 4 };
	LIST * poly1 = createlist();
	LIST * poly2 = createlist();
	LIST * polyProduct;
	append(poly1, &item0);
	append(poly1, &item1);
	append(poly1, &item2);
	append(poly1, &item4);
//	append(poly1, &item4);

	append(poly2, &item0);
	append(poly2, &item1);
	append(poly2, &item2);
	append(poly2, &item3);
	append(poly2, &item6);
	polyProduct = MulPoly(poly1, poly2);

	printlist(polyProduct);
	putchar('\n');

	system("pause");
	return 0;
}

