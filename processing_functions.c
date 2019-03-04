/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 17:05:30 by sbecker           #+#    #+#             */
/*   Updated: 2019/03/04 15:48:47 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_flags(t_all *all, char *s)
{
	while (*s == '-' || *s == '0' || *s == '+' || *s == '#' || *s == ' ')
	{
		if (*s == '-')
			all->flag_minus = 1;
		else if (*s == '+')
			all->flag_plus = 1;
		else if (*s == '0')
			all->flag_zero = 1;
		else if (*s == ' ')
			all->flag_space = 1;
		else if (*s == '#')
			all->flag_hash = 1;
		s++;
	}
	if (all->flag_space == 1 && all->flag_plus == 1)
		all->flag_space = 0;
	if (all->flag_zero == 1 && all->flag_minus == 1)
		all->flag_zero = 0;
	return (s);
}

char	*check_width_or_precision(t_all *all, char *s, va_list *ap, char flag)
{
	if (*s == '*')
	{
		if (flag == 0)
			all->width = va_arg(*ap, int);
		else
			all->precision = va_arg(*ap, int); //тут также, может ли быть инт
		s++;
	}
	else if (*s >= '0' && *s <= '9')
	{
		if (flag == 0)
			all->width = ft_atoi(s);
		else
			all->precision = ft_atoi(s);
		while (*s >= '0' && *s <= '9')
			s++;
	}
	return (s);
}

char	*check_modifier(t_all *all, char *s)
{
	if (*s == 'h')
	{
		if (*(s + 1) == 'h')
			all->modifier = 2;
		else
			all->modifier = 1;
	}
	else if (*s == 'l')
	{
		if (*(s + 1) == 'l')
			all->modifier = 4;
		else
			all->modifier = 3;
	}
	else if (*s == 'L')
		all->modifier = 5;
	while (*s == 'h' || *s == 'l' || *s == 'L')
		s++;
	return (s);
}
