#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	unsigned long a;
	unsigned long b;
	
	//a = 5;
	//b = 5;
	
	a = -42;
	b = -42;

	//a = 4294967295;
	//b = 4294967295;
	

	/*All with unsigned ints: 11 symbols and 1*/
	
	printf("original: %u\n", a);
	ft_printf("our     : %u\n\n", b);

	//flags
	printf("FLAGS\n");
	printf("original: %0lu\n", a);
	ft_printf("our     : %0lu\n\n", b);


	printf("original: %-luA\n", a);
	ft_printf("our     : %-luA\n\n", b);
	
	//precision
	printf("PRECISION\n");
	printf("original: %.14u\n", a);
	ft_printf("our     : %.14u\n\n", b);
	
	printf("original: %.1u\n", a);
	ft_printf("our     : %.1u\n\n", b);
	
	//width
	printf("WIDTH\n");
	printf("original: %17u\n", a);
	ft_printf("our     : %17u\n\n", b);
	
	printf("original: %2u\n", a);
	ft_printf("our     : %2u\n\n", b);
	
	//precision and flags
	printf("PRECISION AND FLAGS\n");
	printf("original: %0.16u\n", a);
	ft_printf("our     : %0.16u\n\n", b);
	
	printf("original: %-.20uA\n", a);
	ft_printf("our     : %-.20uA\n\n", b);
	
	//width and flags
	printf("WIDTH AND FLAGS\n");
	printf("original: %-13uAA\n", a);
	ft_printf("our     : %-13uAA\n\n", b);

	printf("original: %025u\n", a);
	ft_printf("our     : %025u\n\n", b);

	printf("original: %01u\n", a);
	ft_printf("our     : %01u\n\n", b);

	//precision, width and flags
	printf("PRECISION, WIDTH AND FLAGS\n");
	printf("original: %-15.17uA\n", a);
	ft_printf("our     : %-15.17uA\n\n", b);

	printf("original: %-20.5uA\n", a);
	ft_printf("our     : %-20.5uA\n\n", b);
	
	printf("original: %018.12u\n", a);
	ft_printf("our     : %018.12u\n\n", b);

	printf("original: %011.12u\n", a);
	ft_printf("our     : %011.12u\n\n", b);

	//precision, width and double flags
	printf("PRECISION, WIDTH AND DOUBLE FLAGS\n");

	printf("original: %-019.12uAA\n", a);
	ft_printf("our     : %-019.12uAA\n\n", b);

	printf("original: %- 15.20uAA\n", a);
	ft_printf("our     : %- 15.20uAA\n\n", b);
	return (0);
}
