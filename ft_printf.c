/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <sbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 10:48:53 by sbecker           #+#    #+#             */
/*   Updated: 2019/03/04 17:53:01 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  Проверить строку check_type, перенести инициализацию, переделать вывод не по символам */

#include "ft_printf.h"

void		initialization(t_all *all)
{
	all->symbol_num = 0;
	all->flag_minus = 0;
	all->flag_plus = 0;
	all->flag_space = 0;
	all->flag_zero = 0;
	all->flag_hash = 0;
	all->width = 0;
	all->precision = 0;
	all->modifier = 0;
}

void    	check_more_type(t_all *all, va_list *ap, char *s)
{
	char	*str;
	
	if (*s == 's')
		do_string(all, ap, str);
	else if (*s == 'c')
		do_uchar(all, ap, str);
	else if (*s == 'p')
	{
		all->flag_hash = 1;
		all->modifier = 3;
		do_int16x(all, ap, str);
	}
	else if (*s == 'n')
		do_n(all, ap);
	else if (*s == '%')
		do_percent(all, ap, str);
	else
		s--;
}

char    	*check_type_and_output(t_all *all, va_list *ap, char *s)
{
	char	*str;
	
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
		check_more_type(all, ap, s);
	s++;
	return (s);
}

char		*processing_and_output(t_all *all, char *s, va_list *ap)
{
	s = check_flags(all, ++s);
	s = check_width_or_precision(all, s, ap, 0);
	if (*s == '.')
	{
		all->precision = -1;
		s = check_width_or_precision(all, ++s, ap, 1);
	}
	s = check_modifier(all, s);
	s = check_type_and_output(all, ap,  s);
	return (s);
}

int			ft_printf(const char *str, ...)
{
	t_all	all;
	va_list	ap;
	char	*tmp_s;
	char	*s;

	s = ft_strdup(str);
	tmp_s = s;
	initialization(&all);
	va_start(ap, str);
	while (*s)
	{
		if (*s != '%')
			write(1, s, 1);
		else
			s = processing_and_output(&all, s, &ap);
		if (!*s)
			break ;
		s++;
		all.symbol_num++;
	}
	va_end(ap);
	free(tmp_s);
	printf("\nminus = %d, plus = %d, space = %d, zero = %d, hash = %d\n",
			all.flag_minus, all.flag_plus, all.flag_space, all.flag_zero, all.flag_hash);
	printf("width = %d, precision = %d\n", all.width, all.precision);
	printf("modifier = %d\n", all.modifier);
	return (1);
}

int		main(void)
{
	int a;

	a = 0;
	//	ft_printf("ALLAHALAGLALALALALALALA^^666\n % +0-10.*hhll", 20);
	ft_printf("ALLAHALAGLALALALALALALA^^666\n % +0-10.*hhlln", 10, &a);
	printf ("%d\n", a);
	return (0);
}
