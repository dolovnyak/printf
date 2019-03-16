#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	double a;
	double b;
	
	//a = -6789;
	//b = -6789;
	
	a = 65.7869;
	b = 65.7869;
	
	//a = 0;
	//b = 0;

	//a = 4356;
	//b = 4356;

	/*All with ints: -6789, 0 and 4356*/

	printf("original: %f\n", a);
	ft_printf("our     : %f\n\n", b);

	//flags
	printf("FLAGS\n");
	printf("original: %0f\n", a);
	ft_printf("our     : %0f\n\n", b);


	printf("original: %-fA\n", a);
	ft_printf("our     : %-fA\n\n", b);

	printf("original: %+f\n", a);
	ft_printf("our     : %+f\n\n", b);

	printf("original: % f\n", a);
	ft_printf("our     : % f\n\n", b);
	
	printf("original: %#f\n", a);
	ft_printf("our     : %#f\n\n", b);
	
	//precision
	printf("PRECISION\n");
	printf("original: %.6f\n", a);
	ft_printf("our     : %.6f\n\n", b);
	
	printf("original: %.3f\n", a);
	ft_printf("our     : %.3f\n\n", b);
	
	//width
	printf("WIDTH\n");
	printf("original: %8f\n", a);
	ft_printf("our     : %8f\n\n", b);
	
	printf("original: %1f\n", a);
	ft_printf("our     : %1f\n\n", b);
	
	//precision and flags
	printf("PRECISION AND FLAGS\n");
	printf("original: %0.16f\n", a);
	ft_printf("our     : %0.16f\n\n", b);
	
	printf("original: %-.5fA\n", a);
	ft_printf("our     : %-.5fA\n\n", b);
	
	printf("original: %+.10f\n", a);
	ft_printf("our     : %+.10f\n\n", b);

	printf("original: % .4f\n", a);
	ft_printf("our     : % .4f\n\n", b);
	
	//width and flags
	printf("WIDTH AND FLAGS\n");
	printf("original: %-5fAA\n", a);
	ft_printf("our     : %-5fAA\n\n", b);

	printf("original: %+10f\n", a);
	ft_printf("our     : %+10f\n\n", b);

	printf("original: %010f\n", a);
	ft_printf("our     : %010f\n\n", b);

	printf("original: % 7f\n", a);
	ft_printf("our     : % 7f\n\n", b);

	//precision, width and flags
	printf("PRECISION, WIDTH AND FLAGS\n");
	printf("original: %-10.5fA\n", a);
	ft_printf("our     : %-10.5fA\n\n", b);

	printf("original: %-4.5fA\n", a);
	ft_printf("our     : %-4.5fA\n\n", b);

	printf("original: %+9.6f\n", a);
	ft_printf("our     : %+9.6f\n\n", b); //если число лонг-лонг, а тип инт, ошибка

	printf("original: %+4.6f\n", a);
	ft_printf("our     : %+4.6f\n\n", b);

	printf("original: % 11.7f\n", a);
	ft_printf("our     : % 11.7f\n\n", b);

	printf("original: % 5.7f\n", a);
	ft_printf("our     : % 5.7f\n\n", b);
	
	printf("original: %018.12f\n", a);
	ft_printf("our     : %018.12f\n\n", b);

	printf("original: %011.12f\n", a);
	ft_printf("our     : %011.12f\n\n", b);

	//precision, width and double flags
	printf("PRECISION, WIDTH AND DOUBLE FLAGS\n");
	printf("original: % 019.8f\n", a);
	ft_printf("our     : % 019.8f\n\n", b);

	printf("original: %+017.12f\n", a);
	ft_printf("our     : %+017.12f\n\n", b);

	printf("original: %-+19.12f\n", a);
	ft_printf("our     : %-+19.12f\n\n", b);

	printf("original: %- 15.13f\n", a);
	ft_printf("our     : %- 15.13f\n\n", b);

	//width and double flags
	printf("WIDTH AND DOUBLE FLAGS\n");
	printf("original: %0#15f\n", a);
	ft_printf("our     : %0#15f\n\n", b);

	printf("original: %0#4f\n", a);
	ft_printf("our     : %0#4f\n\n", b);
	return (0);
}
