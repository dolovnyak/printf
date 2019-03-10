#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	long long int a;
	long long int b;
	
	a = 7777777777777777777;
	b = 7777777777777777777;

	/*All with long long ints: 77..(19)*/
	
	printf("original: %lld\n", a);
	ft_printf("our     : %lld\n\n", b);

	//flags
	printf("FLAGS\n");
	printf("original: %0lld\n", a);
	ft_printf("our     : %0lld\n\n", b);


	printf("original: %-lldA\n", a);
	ft_printf("our     : %-lldA\n\n", b);

	printf("original: %+lld\n", a);
	ft_printf("our     : %+lld\n\n", b);

	printf("original: % lld\n", a);
	ft_printf("our     : % lld\n\n", b);
	
	//precision
	printf("PRECISION\n");
	printf("original: %.26lld\n", a);
	ft_printf("our     : %.26lld\n\n", b);
	
	printf("original: %.3lld\n", a);
	ft_printf("our     : %.3lld\n\n", b);
	
	//width
	printf("WIDTH\n");
	printf("original: %25ld\n", a);
	ft_printf("our     : %25ld\n\n", b);
	
	printf("original: %1ld\n", a);
	ft_printf("our     : %1ld\n\n", b);
	
	//precision and flags
	printf("PRECISION AND FLAGS\n");
	printf("original: %0.28lld\n", a);
	ft_printf("our     : %0.28lld\n\n", b);
	
	printf("original: %-.21lldA\n", a);
	ft_printf("our     : %-.21lldA\n\n", b);
	
	printf("original: %+.22lld\n", a);
	ft_printf("our     : %+.22lld\n\n", b);

	printf("original: % .23lld\n", a);
	ft_printf("our     : % .23lld\n\n", b);
	
	//width and flags
	printf("WIDTH AND FLAGS\n");
	printf("original: %-27lldAA\n", a);
	ft_printf("our     : %-27lldAA\n\n", b);
//
	printf("original: %+29lld\n", a);
	ft_printf("our     : %+29lld\n\n", b);

	printf("original: %030lld\n", a);
	ft_printf("our     : %030lld\n\n", b);
//
	printf("original: % 34lld\n", a);
	ft_printf("our     : % 34lld\n\n", b);

	//precision, width and flags
	printf("PRECISION, WIDTH AND FLAGS\n");
	printf("original: %-25.27lldA\n", a);
	ft_printf("our     : %-25.27lldA\n\n", b);

	printf("original: %-19.25lldA\n", a);
	ft_printf("our     : %-19.25lldA\n\n", b);

	printf("original: %+30.19lld\n", a);
	ft_printf("our     : %+30.19lld\n\n", b); //если число лонг-лонг, а тип инт, ошибка

	printf("original: %+15.28lld\n", a);
	ft_printf("our     : %+15.28lld\n\n", b);

	printf("original: % 30.30lld\n", a);
	ft_printf("our     : % 30.30lld\n\n", b);

	printf("original: % 24.31ld\n", a);
	ft_printf("our     : % 24.31ld\n\n", b);
	
	printf("original: %023.20lld\n", a);
	ft_printf("our     : %023.20lld\n\n", b);

	printf("original: %021.21lld\n", a);
	ft_printf("our     : %021.21lld\n\n", b);

	//precision, width and double flags
	printf("PRECISION, WIDTH AND DOUBLE FLAGS\n");
	printf("original: % 019.8lld\n", a);
	ft_printf("our     : % 019.8lld\n\n", b); //mistake

	printf("original: %+019.8lld\n", a);
	ft_printf("our     : %+019.8lld\n\n", b); //mistake

	printf("original: %+029.21lld\n", a);
	ft_printf("our     : %+029.21lld\n\n", b);

	printf("original: %-+29.30lld\n", a);
	ft_printf("our     : %-+29.30lld\n\n", b);

	printf("original: %- 23.23lld\n", a);
	ft_printf("our     : %- 23.23lld\n\n", b);
	return (0);
}
