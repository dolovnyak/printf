/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:43:46 by sbecker           #+#    #+#             */
/*   Updated: 2019/03/10 15:54:54 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		do_int(t_all *all, va_list *ap, char *str)
{
	long	num;
	int		len;

	if (all->modifier == 0)
		num = va_arg(*ap, int);
	else if (all->modifier == 1)
		num = (short int)va_arg(*ap, int);
	else if (all->modifier == 2)
		num = (unsigned char)va_arg(*ap, int);
	else
		num = va_arg(*ap, long);
	all->flag_sign_minus = num < 0 ? 1 : 0;
	num = num < 0 ? -num : num;
	str = ft_itoa_base(num, 10);
	len = ft_strlen(str);
	if (all->precision < len && all->width < len) //то есть либо они не влияют, либо их вообще нет, а есть только флаги или вообще только знак
		str = flags_ps_or_signs(all, str, len);
	if (all->precision >= len) //width должна быть изначально 0, иначе не сработает условие на цифрах
		str = int_precision_processing(all, str, &len);
	if (all->width >= len)
		str = int_w_mz_processing(all, str, len);
	write(1, str, ft_strlen(str));
}

void	do_uint(t_all *all, va_list *ap, char *str)
{
	long	num;
	int		len;

	if (all->modifier == 0)
		num = va_arg(*ap, unsigned int);
	else if (all->modifier == 1)
		num = (unsigned int)va_arg(*ap, int);
	else if (all->modifier == 2)
		num = (unsigned char)va_arg(*ap, int);
	else
		num = (unsigned long long)va_arg(*ap, long);
	str = ft_itoa_base(num, 10);
	len = ft_strlen(str);
	if (all->precision >= len)
		str = int_precision_processing(all, str, &len);
	if (all->width >= len)
		str = int_w_mz_processing(all, str, len);
	write(1, str, ft_strlen(str));
}

void	do_int8(t_all *all, va_list *ap, char *str)
{
	int		len;

	if (all->modifier == 0)
		str = ft_itoa_base(va_arg(*ap, int), 8);
	else if (all->modifier == 1)
		str = ft_itoa_base((short int)va_arg(*ap, int), 8);
	else if (all->modifier == 2)
		str = ft_itoa_base((unsigned char)va_arg(*ap, int), 8);
	else
		str = ft_itoa_base((long long)va_arg(*ap, long), 8);
	len = ft_strlen(str);
	if (all->precision >= len)
		str = int_precision_processing(all, str, &len);
	if (all->width >= len)
		str = int_w_mz_processing(all, str, len);
	write(1, str, ft_strlen(str));
}

void	do_int16x(t_all *all, va_list *ap, char *str)
{

}

void	do_int16X(t_all *all, va_list *ap, char *str)
{

}
