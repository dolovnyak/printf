#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	int a;
	int b;
	
	a = 16798;
	b = 16798;

	//a = 255;
	//b = 255;
	

	/*All with ints in 8-system*/
	
	printf("original: %o\n", a);
	ft_printf("our     : %o\n\n", b);

	//flags
	printf("FLAGS\n");
	printf("original: %0o\n", a);
	ft_printf("our     : %0o\n\n", b);


	printf("original: %-oA\n", a);
	ft_printf("our     : %-oA\n\n", b);


	printf("original: %#oA\n", a);
	ft_printf("our     : %#oA\n\n", b);
	
	//precision
	printf("PRECISION\n");
	printf("original: %.14o\n", a);
	ft_printf("our     : %.14o\n\n", b);
	
	printf("original: %.1o\n", a);
	ft_printf("our     : %.1o\n\n", b);
	
	//width
	printf("WIDTH\n");
	printf("original: %17o\n", a);
	ft_printf("our     : %17o\n\n", b);
	
	printf("original: %2o\n", a);
	ft_printf("our     : %2o\n\n", b);
	
	//precision and flags
	printf("PRECISION AND FLAGS\n");
	printf("original: %0.16o\n", a);
	ft_printf("our     : %0.16o\n\n", b);
	
	printf("original: %-.20oA\n", a);
	ft_printf("our     : %-.20oA\n\n", b);
	
	printf("original: %#.14oA\n", a);
	ft_printf("our     : %#.14oA\n\n", b);

	//width and flags
	printf("WIDTH AND FLAGS\n");
	printf("original: %-13oAA\n", a);
	ft_printf("our     : %-13oAA\n\n", b);

	printf("original: %025o\n", a);
	ft_printf("our     : %025o\n\n", b);

	printf("original: %01o\n", a);
	ft_printf("our     : %01o\n\n", b);

	printf("original: %#14o\n", a);
	ft_printf("our     : %#14o\n\n", b);

	//precision, width and flags
	printf("PRECISION, WIDTH AND FLAGS\n");
	printf("original: %-15.17oA\n", a);
	ft_printf("our     : %-15.17oA\n\n", b);

	printf("original: %-20.5oA\n", a);
	ft_printf("our     : %-20.5oA\n\n", b);
	
	printf("original: %018.12o\n", a);
	ft_printf("our     : %018.12o\n\n", b);

	printf("original: %011.12o\n", a);
	ft_printf("our     : %011.12o\n\n", b);

	printf("original: %#18.12o\n", a);
	ft_printf("our     : %#18.12o\n\n", b);

	printf("original: %#11.12o\n", a);
	ft_printf("our     : %#11.12o\n\n", b);

	//precision, width and double flags
	printf("PRECISION, WIDTH AND DOUBLE FLAGS\n");

	printf("original: %-#19.12o\n", a);
	ft_printf("our     : %-#19.12o\n\n", b);

	printf("original: %-#15.20o\n", a);
	ft_printf("our     : %-#15.20o\n\n", b);

	printf("original: %0#19.12o\n", a);
	ft_printf("our     : %0#19.12o\n\n", b);

	printf("original: %0#15.20o\n", a);
	ft_printf("our     : %0#15.20o\n\n", b);
	return (0);
}
