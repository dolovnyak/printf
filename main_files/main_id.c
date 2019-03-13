#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	int a;
	int b;
	
	//a = -6789;
	//b = -6789;
	
	a = 7777777777777777777;
	b = 7777777777777777777;
	
	//a = 0;
	//b = 0;

	//a = 4356;
	//b = 4356;

	/*All with ints: -6789, 0 and 4356*/
	
	printf("original: %d\n", a);
	ft_printf("our     : %d\n\n", b);

	//flags
	printf("FLAGS\n");
	printf("original: %0d\n", a);
	ft_printf("our     : %0d\n\n", b);


	printf("original: %-dA\n", a);
	ft_printf("our     : %-dA\n\n", b);

	printf("original: %+d\n", a);
	ft_printf("our     : %+d\n\n", b);

	printf("original: % d\n", a);
	ft_printf("our     : % d\n\n", b);
	
	//precision
	printf("PRECISION\n");
	printf("original: %.6d\n", a);
	ft_printf("our     : %.6d\n\n", b);
	
	printf("original: %.3d\n", a);
	ft_printf("our     : %.3d\n\n", b);
	
	//width
	printf("WIDTH\n");
	printf("original: %8d\n", a);
	ft_printf("our     : %8d\n\n", b);
	
	printf("original: %1d\n", a);
	ft_printf("our     : %1d\n\n", b);
	
	//precision and flags
	printf("PRECISION AND FLAGS\n");
	printf("original: %0.16d\n", a);
	ft_printf("our     : %0.16d\n\n", b);
	
	printf("original: %-.5dA\n", a);
	ft_printf("our     : %-.5dA\n\n", b);
	
	printf("original: %+.10d\n", a);
	ft_printf("our     : %+.10d\n\n", b);

	printf("original: % .4d\n", a);
	ft_printf("our     : % .4d\n\n", b);
	
	//width and flags
	printf("WIDTH AND FLAGS\n");
	printf("original: %-5dAA\n", a);
	ft_printf("our     : %-5dAA\n\n", b);

	printf("original: %+10d\n", a);
	ft_printf("our     : %+10d\n\n", b);

	printf("original: %010d\n", a);
	ft_printf("our     : %010d\n\n", b);

	printf("original: % 7d\n", a);
	ft_printf("our     : % 7d\n\n", b);

	//precision, width and flags
	printf("PRECISION, WIDTH AND FLAGS\n");
	printf("original: %-10.5dA\n", a);
	ft_printf("our     : %-10.5dA\n\n", b);

	printf("original: %-4.5dA\n", a);
	ft_printf("our     : %-4.5dA\n\n", b);

	printf("original: %+9.6d\n", a);
	ft_printf("our     : %+9.6d\n\n", b); //если число лонг-лонг, а тип инт, ошибка

	printf("original: %+4.6d\n", a);
	ft_printf("our     : %+4.6d\n\n", b);

	printf("original: % 11.7d\n", a);
	ft_printf("our     : % 11.7d\n\n", b);

	printf("original: % 5.7d\n", a);
	ft_printf("our     : % 5.7d\n\n", b);
	
	printf("original: %018.12d\n", a);
	ft_printf("our     : %018.12d\n\n", b);

	printf("original: %011.12d\n", a);
	ft_printf("our     : %011.12d\n\n", b);

	//precision, width and double flags
	printf("PRECISION, WIDTH AND DOUBLE FLAGS\n");
	printf("original: % 019.8d\n", a);
	ft_printf("our     : % 019.8d\n\n", b);

	printf("original: %+017.12d\n", a);
	ft_printf("our     : %+017.12d\n\n", b);

	printf("original: %-+19.12d\n", a);
	ft_printf("our     : %-+19.12d\n\n", b);

	printf("original: %- 15.13d\n", a);
	ft_printf("our     : %- 15.13d\n\n", b);
	return (0);
}
