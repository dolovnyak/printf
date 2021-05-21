#include "ft_printf.h"
#include <stdio.h>

int main()
{
	printf	 ("%#.xA\n", 0);
	ft_printf("%#.xA\n\n", 0);

	printf	 ("%.xA\n", 0);
	ft_printf("%.xA\n\n", 0);

	printf	 ("%#.oA\n", 0);
	ft_printf("%#.oA\n\n", 0);

	printf	 ("%.oA\n", 0);
	ft_printf("%.oA\n\n", 0);

	printf	 ("@moulitest: %.o %.0o\n", 0, 0);
	ft_printf("@moulitest: %.o %.0o\n\n", 0, 0);

	printf	 ("@moulitest: %.u %.0u\n", 0, 0);
	ft_printf("@moulitest: %.u %.0u\n\n", 0, 0);
	return (0);
}
