#include <stdio.h>
#include "ft_printf.h"
#include <stdint.h>

int main()
{
	int		sign;
	long	exponent;
	double	a = -185.4375;
	long b;
	int i = 64;
	char *mantissa;

	mantissa = malloc(53);
	b = *((long*)&a);
	long c = b;

	printf ("b = %ld\n", b);
	printf ("original float, sign is first bit:\n");
	i = 64;
	while (--i >= 0)
		printf ("%d ", ((1l << i) & b) ? 1 : 0);
	sign = ((1lu << 63) & b) ? -1 : 1;
	printf ("\nsign: %d\n", sign);

	printf ("\ntake modul float:\n");
	b &= ~(1lu << 63); //change the first bit to zero, otherwise if we do << there would have been only 1-s
	i = 64;
	while (--i >= 0)
		printf ("%d ", ((1l << i) & b) ? 1 : 0);

	printf ("\n\ntake exponent:\n");
	b = b >> 52;
	exponent = b;
	i = 64;
	while (--i >= 0)
		printf ("%d ", ((1l << i) & b) ? 1 : 0);
	printf ("\nexponent: %ld\n", exponent);

	printf ("\ntake mantissa:\n");
	c = c << 12;
	i = 64;
	while (--i >= 64 - 52)
	{
		mantissa[64 - i] = ((1l << i) & c) ? '1' : '0';
		printf ("%d ", ((1l << i) & c) ? 1 : 0);
	}
	mantissa[0] = '1';
	printf ("\nmantissa: %s", mantissa);

	return (0);
}
