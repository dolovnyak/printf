#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ft_printf.h"

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

void	get_data(t_procent_syms *all)
{
	register int i;

	all->count = 2;
	i = -1;
	while (++i < 5)
		if (rand() % 2 == 0)
		{
			all->spase_zero_minus_plus_hash[i] = 1;
			all->count++;
		}
		else
			all->spase_zero_minus_plus_hash[i] = 0;
	all->width = rand() % 200;
	if (rand() % 3 == 0)
		all->precision = rand() % 1000;
	all->modifier = rand() % 5;
	all->len_width = all->width == 0 ? 0 : ft_numlen(all->width);
	all->len_precision = all->precision == 0 ? 0 : ft_numlen(all->precision);
	all->count += all->len_width + all->len_precision;
	if (all->modifier != 0)
	   all->count++;
	if (all->precision != 0)
		all->count++;
	if (all->modifier == 2 || all->modifier >= 4)
		all->count++;
	all->type = rand() % 6;
}

char	*get_params(t_procent_syms *all)
{
	register int	i;
	int				tmp_count;
	char			*tmp;

	tmp = ft_memalloc(all->count + 5);
	tmp[0] = '%';
	tmp_count = 1;
	i = -1;
	while (++i < 5)
		if (all->spase_zero_minus_plus_hash[i] == 1)
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
	char *width = ft_itoa(all->width);
	ft_strcpy(&tmp[tmp_count], width);
	free(width);
	tmp_count += all->len_width;
	char *precision = ft_itoa(all->precision);
	free(precision);
	if (all->precision != 0)
		tmp[tmp_count++] = '.';
	ft_strcpy(&tmp[tmp_count], precision);
	tmp_count += all->len_precision;
	if (all->modifier != 0)
	{
		if (all->modifier == 1)
			tmp[tmp_count] = 'h';
		else if (all->modifier == 2)
		{
			tmp[tmp_count] = 'h';
			tmp[++tmp_count] = 'h';
		}
		else if (all->modifier == 3)
			tmp[tmp_count] = 'l';
		else
		{
			tmp[tmp_count] = 'l';
			tmp[++tmp_count] = 'l';
		}
		tmp_count++;
	}
	if (all->type == 0)
		tmp[tmp_count] = 'd';
	else if (all->type == 1)
		tmp[tmp_count] = 'i';
	else if (all->type == 2)
		tmp[tmp_count] = 'o';
	else if (all->type == 3)
		tmp[tmp_count] = 'u';
	else if (all->type == 4)
		tmp[tmp_count] = 'x';
	else if (all->type == 5)
		tmp[tmp_count] = 'X';
	tmp[++tmp_count] = 'A';	
	tmp[++tmp_count] = 'A';	
	tmp[++tmp_count] = 'A';	
	return (tmp);
}

int		main()
{
	char	*s;
	int		param_num;
	t_procent_syms	all;
	register int i;
	long	num;

	setbuf(stdout, NULL);
	srand(time(0));
	param_num = 100000;
	while (param_num-- >= 0)
	{
		num = rand() % 9223372036854775807;
		num = (rand() % 2) ? -num : num;
		get_data(&all);
		s = get_params(&all);
		printf (s, num);
		printf ("\n");
		ft_printf (s, num);
		printf ("\nstring: %s; ", s);
		printf ("num: %ld\n", num);
		printf ("\n");
		free (s);
	}
	return (0);
}
