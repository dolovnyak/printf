/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <sbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 10:48:53 by sbecker           #+#    #+#             */
/*   Updated: 2019/03/09 18:35:17 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  Проверить строку check_type, перенести инициализацию, переделать вывод не по символам */

#include "ft_printf.h"

void		initialization(t_all *all)
{
	all->flag_sign_minus = 0;
	all->symbol_num = 0;
	all->flag_minus = 0;
	all->flag_plus = 0;
	all->flag_space = 0;
	all->flag_zero = 0;
	all->flag_hash = 0;
	all->width = 0;
	all->precision = -1;
	all->modifier = 0;
}

char    	*check_more_type(t_all *all, va_list *ap, char *s)
{
	char	*str;
	
	str = NULL;
	if (*s == 's')
		do_string(all, ap, str);
	else if (*s == 'c')
		do_percent_or_uchar(all, ap, str, 1);
	else if (*s == 'p')
	{
		all->flag_hash = 1;
		all->modifier = 3;
		do_int16x(all, ap, str);
	}
	else if (*s == 'n')
		do_n(all, ap);
	else if (*s == '%')
		do_percent_or_uchar(all, ap, str, 0);
	else
		s--;
	return (s);
}

char    	*check_type_and_output(t_all *all, va_list *ap, char *s)
{
	char	*str;
	
	str = NULL;
	if (*s == 'd' || *s == 'i')
		do_int(all, ap, str);
	else if (*s == 'u')
		do_uint(all, ap, str);
	else if (*s == 'o')
		do_int8(all, ap, str);
	else if (*s == 'x')
		do_int16x(all, ap, str);
	else if (*s == 'X')
		do_int16X(all, ap, str);
	else if (*s == 'f' || *s == 'F')
		do_float(all, ap, str);
	else if (*s == 'e' || *s == 'E')
		do_efloat(all, ap, str);
	else if (*s == 'g' || *s == 'G')
		do_gfloat(all, ap, str);
	else if (*s == 'a' || *s == 'A')
		do_afloat(all, ap, str);
	else
		s = check_more_type(all, ap, s);
	s++;
	return (s);
}

char		*processing_and_output(t_all *all, char *s, va_list *ap)
{
	s = check_flags(all, ++s);
	s = check_width_or_precision(all, s, ap, 0);
	if (*s == '.')
	{
		all->precision = 0;
		s = check_width_or_precision(all, ++s, ap, 1);
	}
	s = check_modifier(all, s);
	s = check_type_and_output(all, ap,  s);
	return (s);
}

char		*output_nonpercent_symbs(t_all *all, char *s)
{
	register int i;

	i = 0;
	while (s[i] != '%' && s[i])
		i++;
	write (1, s, i);
	all->symbol_num += i;
	return (s + i);
}

int			ft_printf(const char *str, ...)
{
	t_all	all;
	va_list	ap;
	char	*tmp_s;
	char	*s;

	s = ft_strdup(str);
	tmp_s = s;
	va_start(ap, str);
	while (*s)
	{
		if (*s == '%')
		{
			initialization(&all);
			s = processing_and_output(&all, s, &ap);
		}
		else
			s = output_nonpercent_symbs(&all, s);
	}
	va_end(ap);
	free(tmp_s);
	return (1);
}
