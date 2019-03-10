#include "ft_printf.h"

int     main(void)
{
	long long int   a;
	long long int   b;

	a = 120;
	b = 120;

	ft_printf ("\123\n");
	printf	  ("%0+10d\n", 666);	
	ft_printf ("%0+10d\n", 666);	
	printf	  ("%0 10d\n", 666);	
	ft_printf ("%0 10d\n", 666);	
	printf	  ("%0+10d\n", -666);	
	ft_printf ("%0+10d\n", -666);	
	printf	  ("\n%+10d\n", 666);	
	ft_printf ("%+10d\n", 666);	
	printf	  ("% 10d\n", 666);	
	ft_printf ("% 10d\n", 666);	
	printf	  ("%+10d\n", -666);	
	ft_printf ("%+10d\n", -666);	
	printf	  ("\n%-+10d\n", 666);	
	ft_printf ("%+-10d\n", 666);	
	printf	  ("%- 10d\n", 666);	
	ft_printf ("%- 10d\n", 666);	
	printf	  ("%-+10d\n", -666);	
	ft_printf ("%-+10d\n", -666);	
	printf	  ("% 010.20u\n", 1256);
	ft_printf ("% 010.20u\n", 1256); //здесь непредсказуемое поведение, поэтому пусть выводит то, что выводит
	printf    ("% u\n", 133);
	ft_printf ("% u\n", 133);
	printf	  ("% 10d\n", 143);
	ft_printf ("% 10d\n", 143);
	printf	  ("%010.2d\n", -255);
	ft_printf ("%010.2d\n", -255);
	printf	  ("%010.d\n", -255);
	ft_printf ("%010.d\n", -255);
	printf	  ("%010d\n", -255);
	ft_printf ("%010d\n", -255);
	printf ("%.5d\n", -255);
	ft_printf ("%.5d\n", -255);
	printf ("%+.5d\n", 255);
	ft_printf ("%+.5d\n", 255);
	printf ("%d\n", 255);
	ft_printf ("%d\n", 255);
	printf ("%d\n", -255);
	ft_printf ("%d\n", -255);
	printf ("%.4d\n", 255);
	ft_printf ("%.4d\n", 255);
	printf ("ori%+010.4d\n", 255);
	ft_printf ("our%+010.4d\n", 255);
	printf	  ("ori%010.5d\n", 255);
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
	printf("MISTAKE\n");
	printf ("%0cO\n", 'A');
	ft_printf ("%0cO\n", 'A');
	printf("bla%hhd\n", a);
	ft_printf("bla%hhd\n", b);
	printf ("\n%d\n", a);
	printf ("%d\n", b);
	printf("MISTAKE\n");
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
