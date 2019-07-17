#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	void *a;
	int	b[2];

	a = "ghggggg";
	b[0] = 5;
	b[1] = 456;

	printf("%d		", -8574332);
	ft_printf("%d\n", -8574332);

	printf("%i		", 433322211);
	ft_printf("%i\n", 433322211);
	printf("%u		", -8574332);
	ft_printf("%u\n", -8574332);

	printf("%o		", 5647);
	ft_printf("%o\n", 5647);

	printf("%x		", -8574332);
	ft_printf("%x\n", -8574332);

	printf("%X		", -8574332);
	ft_printf("%X\n", -8574332);

	ft_printf("%b\n", -8574332);
	ft_printf("%B\n", -8574332);

	printf("%n		", b);
	ft_printf("%n\n", b);
	
	printf("%p		", a);
	ft_printf("%p\n", a);

	printf("%c		", 'G');
	ft_printf("%c\n", 'G');

	printf("%C		", 'g');
	ft_printf("%C\n", 'g');
	
	printf("%s		", "hello");
	ft_printf("%s\n", "hello");	
	
	//printf("%f		", 675833.77777);
	//ft_printf("%f\n", 675833.77777);
	
	//printf("%F		", -546.22222222223445);
	//ft_printf("%F\n", -546.22222222223445);
	
	printf("%%		");
	ft_printf("%%\n");
	
	printf("%U		", -546);
	ft_printf("%U\n", -546);

	//b-type
	ft_printf("B-TYPE\n\n");
	ft_printf("%0b\n", 56444);
	ft_printf("%-.30BAA\n", 546);
	ft_printf("%050b\n", -546);
	ft_printf("%040.20B\n", -546);
	ft_printf("%-40bAA\n", -546);
	ft_printf("%llb\n", -546);
	ft_printf("%hhB\n", -546);
	ft_printf("%hB\n", -546);
	ft_printf("%lB\n", -546);
	ft_printf("%0-30.13bAA\n", -546);

	return (0);
}
