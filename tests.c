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

char    *ft_itoa(int n)
{
	char                    *s;
	size_t                  len;

	len = ft_numlen(n);
	printf ("CHECK1\n");
	printf ("%s\n", s);
	s = (char*)malloc(len + 1);
	printf ("CHECK2\n");
	if (n == -2147483648)
		return (ft_strcpy(s, "-2147483648"));
	n = POZ(n);
	if (!s)
		return (0);
	s[--len] = n % 10 + '0';
	while (n /= 10)
		s[--len] = n % 10 + '0';
	if (&s[--len])
		s[len] = '-';
	return (s);
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
	test_params->width = rand() % 200;
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

char	*get_params(t_procent_syms *test_params)
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
	tmp[++tmp_count] = 'A';	
	tmp[++tmp_count] = 'A';	
	tmp[++tmp_count] = 'A';	
	tmp[++tmp_count] = '\0';	
	free(s_precision);
	free(s_width);
	return (tmp);
}

int		main()
{
	char	*s;
	int		param_num;
	t_procent_syms	test_params;
	register int i;
	long	num;

//	setbuf(stdout, NULL);
	srand(time(0));
	param_num = 10000000;
	while (param_num-- >= 0)
	{
		num = rand() % 9223372036854775807;
		num = (rand() % 2) ? -num : num;
		get_data(&test_params);
		s = get_params(&test_params);
		printf (s, num);
		fflush(stdout);
		printf ("\n");
		fflush(stdout);
		ft_printf (s, num);
		printf ("\nstring: %s; ", s);
		fflush(stdout);
		printf ("num: %ld\n", num);
		fflush(stdout);
		printf ("\n");
		fflush(stdout);
		free (s);
	}
	return (0);
}
