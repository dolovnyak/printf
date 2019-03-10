#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	int a;
	int b;
	
	//a = 16798;
	//b = 16798;

	a = 235;
	b = 235;
	

	/*All with ints in 16-system*/
	
	printf("original: %x\n", a);
	ft_printf("our     : %x\n\n", b);
	
	printf("original: %X\n", a);
	ft_printf("our     : %X\n\n", b);

	//flags
	printf("FLAGS\n");
	printf("original: %0x\n", a);
	ft_printf("our     : %0x\n\n", b);
	
	printf("original: %0X\n", a);
	ft_printf("our     : %0X\n\n", b);


	printf("original: %-xA\n", a);
	ft_printf("our     : %-xA\n\n", b);

	printf("original: %-XA\n", a);
	ft_printf("our     : %-XA\n\n", b);


	printf("original: %#xA\n", a);
	ft_printf("our     : %#xA\n\n", b);

	printf("original: %#XA\n", a);
	ft_printf("our     : %#XA\n\n", b);
	
	//precision
	printf("PRECISION\n");
	printf("original: %.14x\n", a);
	ft_printf("our     : %.14x\n\n", b);
	
	printf("original: %.14X\n", a);
	ft_printf("our     : %.14X\n\n", b);
	
	printf("original: %.1x\n", a);
	ft_printf("our     : %.1x\n\n", b);
	
	printf("original: %.1X\n", a);
	ft_printf("our     : %.1X\n\n", b);
	
	//width
	printf("WIDTH\n");
	printf("original: %17x\n", a);
	ft_printf("our     : %17x\n\n", b);
	
	printf("original: %17X\n", a);
	ft_printf("our     : %17X\n\n", b);
	
	printf("original: %2x\n", a);
	ft_printf("our     : %2x\n\n", b);

	printf("original: %2X\n", a);
	ft_printf("our     : %2X\n\n", b);
	
	//precision and flags
	printf("PRECISION AND FLAGS\n");
	printf("original: %0.16x\n", a);
	ft_printf("our     : %0.16x\n\n", b);

	printf("original: %0.16X\n", a);
	ft_printf("our     : %0.16X\n\n", b);
	
	printf("original: %-.20xA\n", a);
	ft_printf("our     : %-.20xA\n\n", b);

	printf("original: %-.20XA\n", a);
	ft_printf("our     : %-.20XA\n\n", b);
	
	printf("original: %#.14xA\n", a);
	ft_printf("our     : %#.14xA\n\n", b);

	printf("original: %#.14XA\n", a);
	ft_printf("our     : %#.14XA\n\n", b);

	//width and flags
	printf("WIDTH AND FLAGS\n");
	printf("original: %-13xAA\n", a);
	ft_printf("our     : %-13xAA\n\n", b);

	printf("original: %-13XAA\n", a);
	ft_printf("our     : %-13XAA\n\n", b);

	printf("original: %025x\n", a);
	ft_printf("our     : %025x\n\n", b);

	printf("original: %025X\n", a);
	ft_printf("our     : %025X\n\n", b);

	printf("original: %01x\n", a);
	ft_printf("our     : %01x\n\n", b);

	printf("original: %#14x\n", a);
	ft_printf("our     : %#14x\n\n", b);

	printf("original: %#14X\n", a);
	ft_printf("our     : %025X\n\n", b);

	//precision, width and flags
	printf("PRECISION, WIDTH AND FLAGS\n");
	printf("original: %-15.17xA\n", a);
	ft_printf("our     : %-15.17xA\n\n", b);

	printf("original: %-20.5xA\n", a);
	ft_printf("our     : %-20.5xA\n\n", b);
	
	printf("original: %018.12x\n", a);
	ft_printf("our     : %018.12x\n\n", b);

	printf("original: %011.12x\n", a);
	ft_printf("our     : %011.12x\n\n", b);

	printf("original: %#18.12x\n", a);
	ft_printf("our     : %#18.12x\n\n", b);

	printf("original: %#11.12x\n", a);
	ft_printf("our     : %#11.12x\n\n", b);

	//precision, width and double flags
	printf("PRECISION, WIDTH AND DOUBLE FLAGS\n");

	printf("original: %-#19.12XAA\n", a);
	ft_printf("our     : %-#19.12XAA\n\n", b);

	printf("original: %-#15.20XAA\n", a);
	ft_printf("our     : %-#15.20XAA\n\n", b);

	printf("original: %0#19.12X\n", a);
	ft_printf("our     : %0#19.12X\n\n", b);

	printf("original: %0#15.20X\n", a);
	ft_printf("our     : %0#15.20X\n\n", b);

	//width and double flags
	printf("WIDTH AND DOUBLE FLAGS\n");
	printf("original: %0#15x\n", a);
	ft_printf("our     : %0#15x\n\n", b);
	
	printf("original: %0#15X\n", a);
	ft_printf("our     : %0#15X\n\n", b);
	return (0);
}
