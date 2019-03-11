/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:43:46 by sbecker           #+#    #+#             */
/*   Updated: 2019/03/11 13:47:37 by sschmele         ###   ########.fr       */
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
	if (all->precision < len && all->width < len)
		str = flags_ps_or_signs(all, str, len);
	if (all->precision >= len)
		str = int_precision_processing(all, str, &len);
	if (all->width >= len)
		str = int_w_mz_processing(all, str, len);
	write(1, str, ft_strlen(str));
}

void		do_uint(t_all *all, va_list *ap, char *str)
{
	long	num;
	int		len;

	if (all->modifier == 0)
		str = ft_itoa_base(va_arg(*ap, unsigned int), 10);
	else if (all->modifier == 1)
		str = ft_itoa_base((unsigned short)va_arg(*ap, int), 10);
	else if (all->modifier == 2)
		str = ft_itoa_base((unsigned char)va_arg(*ap, int), 10);
	else
		str = ft_itoa_base((unsigned long long)va_arg(*ap, long), 10);
	len = ft_strlen(str);
	if (all->precision >= len)
		str = intu82_p_processing(all, str, &len);
	if (all->width >= len)
		str = intu82_w_mz_processing(all, str, len);
	write(1, str, ft_strlen(str));
}

void		do_int8(t_all *all, va_list *ap, char *str)
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
		str = intu82_p_processing(all, str, &len);
	if (all->flag_hash == 1 && all->precision < 0)
		str = int8_h_processing(all, str, &len);
	if (all->width >= len)
		str = intu82_w_mz_processing(all, str, len);
	write(1, str, ft_strlen(str));
}

void		do_int16x(t_all *all, va_list *ap, char *str)
{
	int		len;

	if (all->modifier == 0)
		str = ft_itoa_base(va_arg(*ap, int), 16);
	else if (all->modifier == 1)
		str = ft_itoa_base((short int)va_arg(*ap, int), 16);
	else if (all->modifier == 2)
		str = ft_itoa_base((unsigned char)va_arg(*ap, int), 16);
	else
		str = ft_itoa_base((long long)va_arg(*ap, long), 16);
	len = ft_strlen(str);
	if (all->flag_hash == 1 && all->precision < 0 && all->width == 0)
		str = int16x_h_processing(all, str, &len);
	if (all->precision >= len)
		str = int16_p_processing(all, str, &len);
	if (all->width >= len)
		str = int16_w_mz_processing(all, str, len);
	do_lower(str);
	write(1, str, ft_strlen(str));
}

void		do_int16xupper(t_all *all, va_list *ap, char *str)
{
	int		len;

	if (all->modifier == 0)
		str = ft_itoa_base(va_arg(*ap, int), 16);
	else if (all->modifier == 1)
		str = ft_itoa_base((short int)va_arg(*ap, int), 16);
	else if (all->modifier == 2)
		str = ft_itoa_base((unsigned char)va_arg(*ap, int), 16);
	else
		str = ft_itoa_base((long long)va_arg(*ap, long), 16);
	len = ft_strlen(str);
	if (all->flag_hash == 1 && all->precision < 0 && all->width == 0)
		str = int16x_h_processing(all, str, &len);
	if (all->precision >= len)
		str = int16_p_processing(all, str, &len);
	if (all->width >= len)
		str = int16_w_mz_processing(all, str, len);
	write(1, str, ft_strlen(str));
}
