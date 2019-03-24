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
	
	printf("original: %.0f\n", a);
	ft_printf("our     : %.0f\n\n", b);
	
	//width
	printf("WIDTH\n");
	printf("original: %12f\n", a);
	ft_printf("our     : %19f\n\n", b);
	
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
	
	printf("original: %#.7f\n", a);
	ft_printf("our     : %#.7f\n\n", b);
	
	//width and flags
	printf("WIDTH AND FLAGS\n");
	printf("original: %-12fAA\n", a);
	ft_printf("our     : %-12fAA\n\n", b);

	printf("original: %+20f\n", a);
	ft_printf("our     : %+20f\n\n", b);

	printf("original: %025f\n", a);
	ft_printf("our     : %025f\n\n", b);

	printf("original: % 16f\n", a);
	ft_printf("our     : % 16f\n\n", b);
	
	printf("original: %#18f\n", a);
	ft_printf("our     : %#18f\n\n", b);

	//precision, width and flags
	printf("PRECISION, WIDTH AND FLAGS\n");
	printf("original: %-10.5fA\n", a);
	ft_printf("our     : %-10.5fA\n\n", b);

	printf("original: %-14.7fA\n", a);
	ft_printf("our     : %-14.5fA\n\n", b);

	printf("original: %+18.6f\n", a);
	ft_printf("our     : %+18.6f\n\n", b);

	printf("original: %+7.6f\n", a);
	ft_printf("our     : %+7.6f\n\n", b);

	printf("original: % 20.7f\n", a);
	ft_printf("our     : % 20.7f\n\n", b);

	printf("original: % 18.10f\n", a);
	ft_printf("our     : % 18.10f\n\n", b);
	
	printf("original: %018.12f\n", a);
	ft_printf("our     : %018.12f\n\n", b);

	printf("original: %012.12f\n", a);
	ft_printf("our     : %012.12f\n\n", b);

	//precision, width and double flags
	printf("PRECISION, WIDTH AND DOUBLE FLAGS\n");
	printf("original: % 019.8f\n", a);
	ft_printf("our     : % 019.8f\n\n", b);

	printf("original: %+026.12f\n", a);
	ft_printf("our     : %+026.12f\n\n", b);

	printf("original: %-+30.12fAA\n", a);
	ft_printf("our     : %-+30.12fAA\n\n", b);

	printf("original: %- 27.13fAA\n", a);
	ft_printf("our     : %- 27.13fAA\n\n", b);

	//width and double flags
	printf("WIDTH AND DOUBLE FLAGS\n");
	printf("original: %0#15f\n", a);
	ft_printf("our     : %0#15f\n\n", b);
	
	printf("original: %0+20f\n", a);
	ft_printf("our     : %0+20f\n\n", b);
	
	printf("original: %0 25f\n", a);
	ft_printf("our     : %0 25f\n\n", b);
	
	printf("original: %+-25fAA\n", a);
	ft_printf("our     : %+-25fAA\n\n", b);

	printf("original: %0#4f\n", a);
	ft_printf("our     : %0#4f\n\n", b);
	return (0);
}
