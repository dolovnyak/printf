/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:47:27 by sbecker           #+#    #+#             */
/*   Updated: 2019/03/26 12:04:02 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_string_big_precision(t_fcomp *fcomp, int precision)
{
	char			*s;
	register int	i;
	register int	j;

	s = ft_strnewsetchar(fcomp->len_integer + precision, '0');
	i = fcomp->len_integer - 1;
	j = -1;
	while (--i >= 0)
		s[++j] = fcomp->integer[i] + '0';
	s[++j] = '.';
	i = fcomp->len_fraction;
	while (--i >= 0)
		s[++j] = fcomp->fraction[i] + '0';
	return (s);
}

void	processing_overflow_fractionpart(t_fcomp *fcomp, int precision)
{
	register int	i;
	register int	flag_int_overflow;

	flag_int_overflow = 0;
	i = fcomp->len_fraction - precision - 1;
	while (++i < fcomp->len_fraction && fcomp->fraction[i] == 10)
	{
		if (i == fcomp->len_fraction - 1)
		{
			flag_int_overflow = 1;
			fcomp->fraction[i] = 0;
		}
		fcomp->fraction[i + 1]++;
		fcomp->fraction[i] = 0;
	}
	if (flag_int_overflow == 1)
	{
		fcomp->integer[0]++;
		processing_overflow_integerpart(fcomp);
	}
}

char	*get_string_int_fract(t_fcomp *fcomp, int precision)
{
	char			*s;
	register int	len;
	register int	i;
	register int	j;

	len = fcomp->len_fraction;
	if (fcomp->fraction[-(precision - len) - 1] == 5 && fcomp->fraction[-(precision - len)] % 2 == 0)
	{
		if (check_5(fcomp, precision) == 1)
			fcomp->fraction[-(precision - len)]++;
	}
	else if (fcomp->fraction[-(precision - len) - 1] >= 5)
		fcomp->fraction[-(precision - len)]++;
	processing_overflow_fractionpart(fcomp, precision);
	s = ft_strnewsetchar(fcomp->len_integer + precision, '0');
	i = fcomp->len_integer - 1;
	j = -1;
	while (--i >= 0)
		s[++j] = fcomp->integer[i] + '0';
	s[++j] = '.';
	i = fcomp->len_fraction;
	while (--i >= fcomp->len_fraction - precision)
		s[++j] = fcomp->fraction[i] + '0';
	return (s);
}

char	*get_string_with_precision(t_fcomp *fcomp, t_all *all)
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
		return (get_string_integer(fcomp));
	else if (all->precision >= fcomp->len_fraction)
		return (get_string_big_precision(fcomp, all->precision));
	else
		return (get_string_int_fract(fcomp, all->precision));
	return (s);
}

void	do_float(t_all *all, va_list *ap, char *str)
{
	t_fcomp			fcomp;
	int				len;
	int				count; //del

	get_components(ap, &fcomp, all);
	str = get_string_with_precision(&fcomp, all);
	len = ft_strlen(str);
	if (fcomp.sign == -1 && fcomp.nan_check != 1)
		all->flag_sign_minus = 1;
	if (all->width < len && fcomp.nan_check != 1)
		str = flags_f_ps_or_signs(all, str, &len);
	else if (all->width >= len)
		str = float_w_mz_processing(all, str, &len, fcomp.nan_check);
	all->fin_str = merge_strings(all->fin_str, all->symbol_num, str, len);
	all->symbol_num += len;
	free(str);
	if (fcomp.nan_check != 1)
	{
		free(fcomp.fraction);
		free(fcomp.integer);
	}
}
/*	printf ("fraction:   ");
	count = fcomp.len_fraction;
	while (--count >= 0)
		printf ("%d", fcomp.fraction[count]);
	printf ("\n");
	printf ("integer: ");
	count = fcomp.len_integer - 1;
	while (--count >= 0)
		printf ("%d", fcomp.integer[count]);
	printf ("\n");*/
	//	printf ("string: %s\n", str);
