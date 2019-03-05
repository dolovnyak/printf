#include "ft_printf.h"

int     main(void)
{
	long long int   a;
	long long int   b;

	a = 120;
	b = 120;

	printf ("%d\n", 255);
	ft_printf ("%d\n", 255);
	printf ("%d\n", -255);
	ft_printf ("%d\n", -255);
	printf ("%.4d\n", 255);
	ft_printf ("%.4d\n", 255);
	printf ("ori%+010.4d\n", 255);
	ft_printf ("our%+010.4d\n", 255);
	printf ("ori%010.5d\n", 255);
	ft_printf ("our%010.5d\n", 255);
	printf ("%40.20ld\n", -12512352555);
	ft_printf ("%40.20ld\n", -12512352555);
	
	
	printf ("A%.5sO\n", "123456789");
	ft_printf ("A%.5sO\n", "123456789");
	printf ("A%10.5sO\n", "123456789");
	ft_printf ("A%10.5sO\n", "123456789");
	printf ("A%010.5sO\n", "123456789");
	ft_printf ("A%010.5sO\n", "123456789");
	printf ("A%-10.5sO\n", "123456789");
	ft_printf ("A%-10.5sO\n", "123456789");
	printf ("%0cO\n", 'A');
	ft_printf ("%0cO\n", 'A');
	printf("bla%hhd\n", a);
	ft_printf("bla%hhd\n", b);
	printf ("\n%d\n", a);
	printf ("%d\n", b);
	ft_printf("123%%A");
	printf("\n123%%A\n");
	ft_printf("123%-10%A");
	printf("\n123%-10%A\n");
	ft_printf("123%010%A");
	printf("\n123%010%A\n");
	ft_printf("123%10%A");
	printf("\n123%10%A\n");
	ft_printf("123%-10ca", 'O');
	printf("\n123%-10ca\n", 'O');
	ft_printf("123%010ca", 'O');
	printf("\n123%010ca\n", 'O');
	ft_printf("123%10ca", 'O');
	printf("\n123%10ca\n", 'O');
	return (0);
}
