/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:43:46 by sbecker           #+#    #+#             */
/*   Updated: 2019/03/06 21:15:45 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		do_int(t_all *all, va_list *ap, char *str)
{
	long	num;
	int		len;
	char	*fin;
	char	check_minus;

	if (all->modifier == 0)
		num = va_arg(*ap, int);
	else if (all->modifier == 1)
		num = (short int)va_arg(*ap, int);
	else if (all->modifier == 2)
		num = (unsigned char)va_arg(*ap, int);
	else
		num = va_arg(*ap, long);
	check_minus = num < 0 ? 1 : 0;
	num = num < 0 ? -num : num;
	str = ft_itoa_base(num, 10);
	len = ft_strlen(str);
	str = int_precision_processing(all, str, &len, check_minus);
	if (all->width > len)
		str = int_w_processing(all, str, len, check_minus);
	write(1, str, ft_strlen(str));
}

void	do_uint(t_all *all, va_list *ap, char *str)
{
	if (all->modifier == 0)
		str = ft_itoa_base((unsigned int)va_arg(*ap, int), 10);
	else if (all->modifier == 1)
		str = ft_itoa_base((unsigned short)va_arg(*ap, int), 10);
	else if (all->modifier == 2)
		str = ft_itoa_base((unsigned char)va_arg(*ap, int), 10);
	else
		str = ft_itoa_base((unsigned long long)va_arg(*ap, long), 10);
	write(1, str, ft_strlen(str));
}

void	do_int8(t_all *all, va_list *ap, char *str)
{
	if (all->modifier == 0)
		str = ft_itoa_base(va_arg(*ap, int), 8);
	else if (all->modifier == 1)
		str = ft_itoa_base((short int)va_arg(*ap, int), 8);
	else if (all->modifier == 2)
		str = ft_itoa_base((unsigned char)va_arg(*ap, int), 8);
	else
		str = ft_itoa_base((long long)va_arg(*ap, long), 8);
	write(1, str, ft_strlen(str));
}

void	do_int16x(t_all *all, va_list *ap, char *str)
{

}

void	do_int16X(t_all *all, va_list *ap, char *str)
{

}
