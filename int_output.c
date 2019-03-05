/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:43:46 by sbecker           #+#    #+#             */
/*   Updated: 2019/03/05 11:55:01 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	do_int(t_all *all, va_list *ap, char *str)
{
	if (all->modifier == 1)
		str = ft_itoa_base((short int)va_arg(*ap, int), 10);
	else if (all->modifier == 2)
		str = ft_itoa_base((unsigned char)va_arg(*ap, int), 10);
	else if (all->modifier == 3)
		str = ft_itoa_base((long int)va_arg(*ap, int), 10);
	else if (all->modifier == 4)
		str = ft_itoa_base((long long int)va_arg(*ap, int), 10);
	write(1, str, ft_strlen(str));
}

void	do_uint(t_all *all, va_list *ap, char *str)
{

}

void	do_int8(t_all *all, va_list *ap, char *str)
{

}

void	do_int16x(t_all *all, va_list *ap, char *str)
{

}

void	do_int16X(t_all *all, va_list *ap, char *str)
{

}
