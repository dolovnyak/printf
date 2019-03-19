#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int	a;

	a = 657;
//	printf("hello %d\v%o\v%i\v%x\v%X\v%u\v%c\n%s\n%p\n", 3, 786, -469, 255, 127, -78, 'a', "how are you?", a);	
	//ft_printf("hello %d\v%o\v%i\v%x\v%X\v%u\v%c\n%s\n%p\n", 3, 786, -469, 255, 127, -78, 'a', "how are you?", a);
	//printf("null %c and text\n", 0);
	//ft_printf("null %c and text", 0);
	//printf("%0", 42);
	//ft_printf("%p\n", 0);

	//printf("%S\n", L"Á±≥");
	//ft_printf("%S\n", L"Á±≥");

	//printf("hello%0-mA\n");
	//ft_printf("hello%0-mA\n");
	//printf("hello%0-joA\n", 58888888888888);
	//ft_printf("hello%0-joA\n", 58888888888888);
	printf("%.0p, %.p\n", 0, 0);
	ft_printf("%.0p, %.p", 0, 0);
	return (0);
}
