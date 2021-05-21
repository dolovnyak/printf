#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ft_printf.h"

#define POZ(val) (val < 0 ? -val : val)

typedef struct	s_proc_sym
{
	int		spase_zero_minus_plus_hash[5];
	int		width;
	int		precision;
	int		modifier;
	int		count;
	int		len_width;
	int		len_precision;
	int		type;
}				t_procent_syms;

static int  count_digits_u(unsigned long value, int base)
{
	int     res;

	res = 0;
	if (value == 0)
		return (1);
	while (value)
	{
		value /= base;
		res++;
	}
	return (res);
}

char        *ft_utoa_base(unsigned long nb, int base)
{
	int     i;
	char    *str;
	int     len;
	char    *main;

	if (!nb && !base && !(base >= 2 && base <= 16))
		return (NULL);
	i = 0;
	main = "0123456789ABCDEF";
	len = count_digits_u(nb, base);
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (nb == 0)
		str[0] = 0 + '0';
	while (nb)
	{
		str[len - ++i] = main[nb % base];
		nb /= base;
	}
	return (str);
}

int             ft_atoi(const char *str)
{
	int                     sign;
	long long       num;
	long long       check;

	num = 0;
	check = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		num = num * 10 + (*str - '0');
		if (num < 0 || num / 10 != check)
			return (sign == 1 ? -1 : 0);
		check = num;
		str++;
	}
	return ((int)num * sign);
}

char    *ft_strcpy(char *dst, const char *src)
{
	int i;

	if (dst == src)
		return (dst);
	i = -1;
	while (src[++i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}

size_t  ft_numlen(int num)
{
	size_t  i;

	i = 1;
	if (num < 0)
		i++;
	while (num /= 10)
		i++;
	return (i);
}

void	get_data(t_procent_syms *test_params)
{
	register int i;

	test_params->count = 2;
	i = -1;
	while (++i < 5)
		if (rand() % 2 == 0)
		{
			test_params->spase_zero_minus_plus_hash[i] = 1;
			test_params->count++;
		}
		else
			test_params->spase_zero_minus_plus_hash[i] = 0;
	test_params->width = rand() % 1000;
	test_params->precision = 0;
	if (rand() % 3 == 0)
		test_params->precision = rand() % 1000;
	test_params->modifier = rand() % 5;
	test_params->len_width = test_params->width == 0 ? 0 : ft_numlen(test_params->width);
	test_params->len_precision = test_params->precision == 0 ? 0 : ft_numlen(test_params->precision);
	test_params->count += test_params->len_width + test_params->len_precision;
	if (test_params->modifier != 0)
		test_params->count++;
	if (test_params->precision != 0)
		test_params->count++;
	if (test_params->modifier == 2 || test_params->modifier >= 4)
		test_params->count++;
	test_params->type = rand() % 6;
}

char	*get_params(t_procent_syms *test_params, int flag)
{
	register int	i;
	int				tmp_count;
	char			*tmp;

	tmp = malloc(test_params->count + 5);
	tmp[0] = '%';
	tmp_count = 1;
	i = -1;
	while (++i < 5)
		if (test_params->spase_zero_minus_plus_hash[i] == 1)
		{
			if (i == 0)
				tmp[tmp_count] = ' ';
			else if (i == 1)
				tmp[tmp_count] = '0';
			else if (i == 2)
				tmp[tmp_count] = '-';
			else if (i == 3)
				tmp[tmp_count] = '+';
			else
				tmp[tmp_count] = '#';
			tmp_count++;
		}
	char *s_width = ft_utoa_base(test_params->width, 10);
	ft_strcpy(&tmp[tmp_count], s_width);
	tmp_count += test_params->len_width;
	char *s_precision = ft_utoa_base(test_params->precision, 10);
	if (test_params->precision != 0)
		tmp[tmp_count++] = '.';
	ft_strcpy(&tmp[tmp_count], s_precision);
	tmp_count += test_params->len_precision;
	if (test_params->modifier != 0)
	{
		if (test_params->modifier == 1)
			tmp[tmp_count] = 'h';
		else if (test_params->modifier == 2)
		{
			tmp[tmp_count] = 'h';
			tmp[++tmp_count] = 'h';
		}
		else if (test_params->modifier == 3)
			tmp[tmp_count] = 'l';
		else
		{
			tmp[tmp_count] = 'l';
			tmp[++tmp_count] = 'l';
		}
		tmp_count++;
	}
	if (flag == 0)
	{
		if (test_params->type == 0)
			tmp[tmp_count] = 'd';
		else if (test_params->type == 1)
			tmp[tmp_count] = 'i';
		else if (test_params->type == 2)
			tmp[tmp_count] = 'o';
		else if (test_params->type == 3)
			tmp[tmp_count] = 'u';
		else if (test_params->type == 4)
			tmp[tmp_count] = 'x';
		else if (test_params->type == 5)
			tmp[tmp_count] = 'X';
	}
	else
		tmp[tmp_count] = 'f';
	tmp[++tmp_count] = 'A';	
	tmp[++tmp_count] = 'A';	
	tmp[++tmp_count] = 'A';	
	tmp[++tmp_count] = '\0';	
	free(s_precision);
	free(s_width);
	return (tmp);
}

int		main(int argc, char **argv)
{
	char			*s;
	int				param_num;
	t_procent_syms	test_params;
	long			num;
	double			a;
	register int	i;

	if (argc != 3)
	{
		printf ("Tbl ||oMu_/\\_opKa\n");
		return (0);
	}
	setbuf(stdout, NULL);
	srand(time(0));
	param_num = ft_atoi(argv[2]);
	if (argv[1][0] != 'f')
	{
		while (param_num--)
		{
			num = rand() % 9223372036854775807;
			num = (rand() % 2) ? -num : num;
			get_data(&test_params);
			s = get_params(&test_params, 0);
			printf (s, num);
			printf ("\n");
			ft_printf (s, num);
			printf ("\nstring: %s; ", s);
			printf ("num: %ld\n", num);
			printf ("\n");
			free (s);
		}
	}
	else
		while (param_num--)
		{
			num = 0;
			i = 64;
			while (--i >= 0)
				num |= (rand() % 2 == 1) ? 1l << i : 0l;
			a = *((double*)&num);
			get_data(&test_params);
			s = get_params(&test_params, 1);
			printf (s, a);
			printf ("\n");
			ft_printf (s, a);
			printf ("\nstring: %s; ", s);
			printf ("num: %.400f\n", a);
			printf ("\n");
			free (s);
		}
	return (0);
}
