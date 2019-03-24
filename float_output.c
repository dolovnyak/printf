/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:47:27 by sbecker           #+#    #+#             */
/*   Updated: 2019/03/24 15:22:16 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*char	*rounding_string(t_fcomp *fcomp, int precision)
{
	char			*s;
	register int	round_num;
	register int	i;
	register int	j;
	int				tmp;

	j = -1;
	s = ft_memalloc(-(precision - fcomp->len) + 1);
	printf ("strlen: %zu\n", ft_strlen(s));
	i = fcomp->len;
	round_num = -(precision - fcomp->len) - 1;
	while (--i >= round_num)
		printf ("%d", fcomp->fraction[i]);
	printf ("\n");
	i = round_num;
	if (fcomp->fraction[i - 1] >= 5)
		fcomp->fraction[i] += 1;
	while (++i < fcomp->len)
	{
		if (fcomp->fraction[i - 1] >= 10)
		{
			fcomp->fraction[i] += 1;
			fcomp->fraction[i - 1] %= 10;
		}
		else
			break;
	}
	i = fcomp->len;
	while (--i >= round_num)
		printf ("%d", fcomp->fraction[i]);
	printf ("\n");
	return (s); //added
}*/

int					check_5(int *num)
{
	int				i;

	i = 0;
	while (num[i])
	{
		if (num[i] != 0)
			return (1);
		else
			i++;
	}
	return (0);
}

char				*int_rounded(t_fcomp *fcomp)
{
	char			*s;
	register int	i;
	register int	j;

	s = ft_memalloc(fcomp->len_integer + 1);
	if (fcomp->fraction[fcomp->len_fraction - 1] == 5 &&
			fcomp->integer[0] % 2 == 0)
	{
		check_5(&(fcomp->fraction[fcomp->len_fraction - 1])) == 1 ? 
			fcomp->integer[0]++ : fcomp->integer[0]; //доделать
		i = fcomp->len_integer - 1;
		j = -1;
		while (--i >= 0)
			s[++j] = fcomp->integer[i] + '0';
		}
		return (s);
	}
	/*
	else
	}*/
	return (s);
}

char				*get_string_with_precision(t_fcomp *fcomp, t_all *all)
{
	char			*s;
	int				i;
	int				j;

	all->precision = all->precision < 0 ? 6 : all->precision;
	if (fcomp->inf_check)
		return (ft_strdup("inf"));
	if (fcomp->nan_check)
		return (ft_strdup("nan"));
	if (all->precision == 0)
		return (int_rounded(fcomp));
/*	else if (all->precision >= fcomp->len)
	{
		s = ft_strnewsetchar(all->precision + 2, '0');
		s[0] = fcomp->integer_part + '0';
		s[1] = '.';
		i = fcomp->len;
		j = 1;
		while (--i >= 0)
			s[++j] = fcomp->fraction[i] + '0';
	}
	else
	{
		rounding_string(fcomp, all->precision - 1);
		s = ft_memalloc(all->precision + 2);
		s[0] = fcomp->integer_part + '0';
		s[1] = '.';
		i = fcomp->len;
		j = 1;
		while (--i >= fcomp->len - all->precision)
			s[++j] = fcomp->fraction[i] + '0';
	}*/
	return (s);
}

void				do_float(t_all *all, va_list *ap, char *str)
{
	t_fcomp			fcomp;
	int				len;
	int				count; //del
	int				i; //del

	get_components(ap, &fcomp, all);

	printf ("fraction:   ");
	count = fcomp.len_fraction;
	while (--count >= 0)
		printf ("%d", fcomp.fraction[count]);
	printf ("\n");
	printf ("integer: ");
	i = fcomp.len_integer - 1;
	while (--i >= 0)
		printf ("%d", fcomp.integer[i]);
	printf ("\n");

	str = get_string_with_precision(&fcomp, all);
	len = ft_strlen(str);
	if (fcomp.sign == -1)
		all->flag_sign_minus = 1;
	if (all->width < len)
		str = flags_ps_or_signs(all, str, &len);
	else if (all->width >= len)
		str = float_w_mz_processing(all, str, &len);
	all->fin_str = merge_strings(all->fin_str, all->symbol_num, str, len);
	all->symbol_num += len;

	printf ("string:   %s\n", str);
	free(str);
	free(fcomp.fraction);
	free(fcomp.integer);
}
