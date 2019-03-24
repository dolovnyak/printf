#include "ft_printf.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdint.h>

typedef __int128 int128_t;

int main()
{
	double a = 3.900000000000000049992919432599999;
	double c = 0.49992919432599999;
	double k = 3.999999999;
	long b = *((long*)&a);
	printf ("original: %.0f\n", a);	
	ft_printf ("%.0f\n", a);
	printf ("original: %.70f\n", a);	
	ft_printf ("%.70f\n", a);	
	printf ("original: %.10f", a);
	ft_printf ("\n%.10f", a);
	printf ("original: %.11f", c);
	ft_printf ("\n%.11f", c);
	printf ("original: %.12f", c);
	ft_printf ("\n%.12f", c);
	printf ("original: %.15f", c);
	ft_printf ("\n%.15f", c);
	printf ("original: %.12f", k);
	ft_printf ("\n%.12f", k);
	printf ("original: %.16f", k);
	ft_printf ("\n%.16f", k);
	printf ("original: %.15f", k);
	ft_printf ("\n%.15f", k);

	printf ("%.0f\n", (double)2.5);
	printf ("%.100f\n", (double)2.5);
	ft_printf ("%.0f\n", (double)2.5);
	printf ("%.0f\n", (double)1.5);
	printf ("%.100f\n", (double)1.5);
	ft_printf ("%.0f\n", (double)1.5);
	printf ("%.0f\n", (double)4.5);
	printf ("%.100f\n", (double)4.5);
	ft_printf ("%.0f\n", (double)4.5);
	printf ("%.0f\n", (double)3.5);
	printf ("%.100f\n", (double)3.5);
	ft_printf ("%.0f\n", (double)3.5);
	printf ("%.0f\n", (double)0.5);
	printf ("%.100f\n", (double)0.5);
	ft_printf ("%.0f\n", (double)0.5);
	printf ("%.1f\n", 0.05);
	printf ("%.2f\n", 4.565335);
	printf ("%.1f\n", 1.15);
	printf ("%.1f\n", 1.25);
	ft_printf ("%.1f\n", 1.25);
	printf ("%.1f\n", 1.35);
	ft_printf ("%.1f\n", 1.35);
	printf ("%.1f\n", 1.45);
	ft_printf ("%.1f\n", 1.45);
	printf ("%.15f\n", c);
	ft_printf ("%.15f\n", c);
	c = 99223372036854775807.3125;
	b = *((long*)&c);
	int i;
	b |= (1l << 1);
//	i = 64 - 19;
//	while (--i >= 0)
//		b &= ~(1l << i);
//	i = 64;
//	while (--i >= 0)
//		printf ("%d ", ((1l << i) & b) ? 1 : 0);
//	printf ("\n");
//	c = *((double*)&b);
	printf ("%.10f\n", c);
	ft_printf ("%.3f\n", c);
	return (0);
}
