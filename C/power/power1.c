int power(int a, unsigned int n)
{
	int remain = 1;
	
	if (n == 0)
	{
		return 1;
	}
	else
	{
		while (n >= 2)
		{
			remain *= ( (n&1)==1 ? a : 1 );
			a      *= a;
			n = n >> 1;
		}
		return a * remain;
	}
}