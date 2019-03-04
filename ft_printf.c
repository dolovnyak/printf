/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <sbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 10:48:53 by sbecker           #+#    #+#             */
/*   Updated: 2019/03/04 12:19:17 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  Проверить строку check_type, перенести инициализацию, переделать вывод не по символам */

#include "ft_printf.h"

void	initialization(t_all *all)
{
	all->flag_minus = 0;
	all->flag_plus = 0;
	all->flag_space = 0;
	all->flag_zero = 0;
	all->flag_hash = 0;
	all->width = 0;
	all->precision = 0;
	all->modifier = 0;
}

char	*processing(t_all *all, char *s, va_list *ap)
{
	s = check_flags(all, ++s);
	s = check_width_or_precision(all, s, ap, 0);
	if (*s == '.')
		s = check_width_or_precision(all, ++s, ap, 1);
	s = check_modifier(all, s);
	s = check_type(all, s);
	return (s);
}

int		ft_printf(const char *str, ...)
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
		{
			s = processing(&all, s, &ap);
		//	intput();
		}
		if (!*s)
			break ;
		s++;
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
	ft_printf("ALLAHALAGLALALALALALALA^^666\n % +0-10.*hhll", 20);
	return (0);
}
