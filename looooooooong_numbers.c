#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n[100] = {5};
	int base = 10;
	int i, j, flag;
	setbuf(stdout, NULL);
	for (i = 0; i < 100; i++)
	{
		for (j = 0; j < 100; j++)
			n[j] *= 10;
		for (j = 0; j < 100 - 1; j++)
			if (n[j] >= base)
			{
				n[j + 1] += n[j] / base;
				n[j] %= base;
			}
	}
	flag = 1;
	for (i = 99; i >= 0; i--)
	{
/*		if (flag == 1)
		{
			if (n[i] == 0)
				continue;
			else
				flag = 0;
		}*/
		printf ("%d", n[i]);
	}
	return (0);
}
