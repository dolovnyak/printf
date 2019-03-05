/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <sbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 10:48:53 by sbecker           #+#    #+#             */
/*   Updated: 2019/03/05 11:58:42 by sschmele         ###   ########.fr       */
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

char    	*check_more_type(t_all *all, va_list *ap, char *s)
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
	return (s);
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
		s = check_more_type(all, ap, s);
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
	//char	*buf[BUFF_SIZE + 1];

	s = ft_strdup(str);
	tmp_s = s;
	initialization(&all);
	va_start(ap, str);
	while (*s)
	{
		if (*s != '%')
			//ft_strcpy(buf, &s)
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
//	printf("\nminus = %d, plus = %d, space = %d, zero = %d, hash = %d\n",
//			all.flag_minus, all.flag_plus, all.flag_space, all.flag_zero, all.flag_hash);
//	printf("width = %d, precision = %d\n", all.width, all.precision);
//	printf("modifier = %d\n", all.modifier);
	return (1);
}

int		main(void)
{
	long long int	a;
	long long int	b;

	a = -2147483648;
	b = -2147483648;
	printf("bla%lld\n", a);
	ft_printf("bla%lld\n", b);
	//printf ("\n%d\n", a);
	//printf ("%d\n", b);
	//ft_printf("123%-10%A");
	//printf("\n123%-10%A\n");
	//ft_printf("123%010%A");
	//printf("\n123%010%A\n");
	//ft_printf("123%10%A");
	//printf("\n123%10%A\n");
	//ft_printf("123%-10ca", 'O');
	//printf("\n123%-10ca\n", 'O');
	//ft_printf("123%010ca", 'O');
	//printf("\n123%010ca\n", 'O');
	//ft_printf("123%10ca", 'O');
	//printf("\n123%10ca\n", 'O');
	return (0);
}
