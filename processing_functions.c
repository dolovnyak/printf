/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 17:05:30 by sbecker           #+#    #+#             */
/*   Updated: 2019/03/03 22:37:53 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *check_flags(t_all *all, char *s)
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

char	*check_width_or_precision(t_all *all, char *s, va_list *ap, int flag)
{
	if (*s == '*')
	{
		if (flag == 0)
			all->width = va_arg(*ap, int); //проверить может ли быть ширина не только int
		else 
			all->precision = va_arg(*ap, int); //тут также
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

/*void	check_type(t_all *all, char c)
{

}

char	*check_type(t_all *all, char c)
{
	if (c == 'd' || c == 'i')
		all->type_int = 1;
	else if (c == 'u')
		all->type_uint = 1;
	else if (c == 'o')
		all->type_int8 = 1;
	else if (c == 'x')
		all->type_int16x = 1;
	else if (c == 'X')
		all->type_int16X = 1;
	else if (c == 'f' || c == 'F')
		all->type_float = 1;
	else if (c == 'e' || c == 'E')
		all->type_efloat = 1;
	else if (c == 'g' || c == 'G')
		all->type_gfloat = 1;
	else if (c == 'a' || c == 'A')
		all->type_afloat = 1;
	else if (c == 'c')
		all->type_uchar = 1;
	else if (c == 's')
		all->type_string = 1;
	else if (c == 'S')
	{
		all->modifier_l = 1;
		all->type_string = 1;
	}
	else if (c == 'p')
		all->type_ptr = 1;
	else if (c == 'n')
		all->ebanina_type = 1;
	else if (c == '%')
		all->percent_type = 1;
}*/
