#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"

int					get_int_len(int len)
{
	int				res;

	res = 1; //если даже длина = 0, то длина получившейся строки будет 1

	if (len < 20) //после 20 идет немного другой подсчет
	{
		if (len % 
	}




	return (res);
}

int		main(void)
{
	int	len;
	int	len_s;
	
	char *s = "11111000000101110110000000000000000000000";
	len_s = ft_strlen(s);
	printf("%d\n", len_s);
	len = get_int_len(len_s);
	printf("%d\n", len);
	return (0);
}
