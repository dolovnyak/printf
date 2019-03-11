/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:43:46 by sbecker           #+#    #+#             */
/*   Updated: 2019/03/11 19:22:07 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			do_int(t_all *all, va_list *ap, char *str)
{
	long		num;
	int			len;

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
	str = ft_lltoa_base(num, 10);
	len = ft_strlen(str);
	if (all->precision < len && all->width < len)
		str = flags_ps_or_signs(all, str, &len);
	if (all->precision >= len)
		str = int_precision_processing(all, str, &len);
	if (all->width >= len)
		str = int_w_mz_processing(all, str, &len);
	all->symbol_num += len;
	write(1, str, len);
}

void				do_uint(t_all *all, va_list *ap, char *str)
{
	unsigned long   num;
	int				len;

	if (all->modifier == 0)
		num = va_arg(*ap, unsigned int);
	else if (all->modifier == 1)
		num = (unsigned short)va_arg(*ap, unsigned int);
	else if (all->modifier == 2)
		num = (unsigned char)va_arg(*ap, unsigned int);
	else
		num = va_arg(*ap, unsigned long);
	str = ft_utoa_base(num, 10);
	len = ft_strlen(str);
	if (all->precision >= len)
		str = intu82_p_processing(all, str, &len);
	if (all->width >= len)
		str = intu82_w_mz_processing(all, str, &len);
	all->symbol_num += len;
	write(1, str, len);
}

void				do_int8(t_all *all, va_list *ap, char *str)
{
	unsigned long   num;
	int				len;

	if (all->modifier == 0)
		num = va_arg(*ap, unsigned int);
	else if (all->modifier == 1)
		num = (unsigned short)va_arg(*ap, unsigned int);
	else if (all->modifier == 2)
		num = (unsigned char)va_arg(*ap, unsigned int);
	else
		num = va_arg(*ap, unsigned long);
	str = ft_utoa_base(num, 8);
	len = ft_strlen(str);
	if (all->precision >= len)
		str = intu82_p_processing(all, str, &len);
	if (all->flag_hash == 1 && all->precision < 0)
		str = int8_h_processing(str, &len);
	if (all->width >= len)
		str = intu82_w_mz_processing(all, str, &len);
	all->symbol_num += len;
	write(1, str, len);
}

void				do_int16x(t_all *all, va_list *ap, char *str)
{
	unsigned long   num;
	int				len;

	if (all->modifier == 0)
		num = va_arg(*ap, unsigned int);
	else if (all->modifier == 1)
		num = (unsigned short)va_arg(*ap, unsigned int);
	else if (all->modifier == 2)
		num = (unsigned char)va_arg(*ap, unsigned int);
	else
		num = va_arg(*ap, unsigned long);
	str = ft_utoa_base(num, 16);
	len = ft_strlen(str);
	if (all->flag_hash == 1 && all->precision < 0 && all->width == 0)
		str = int16x_h_processing(str, &len);
	if (all->precision >= len)
		str = int16_p_processing(all, str, &len);
	if (all->width >= len)
		str = int16_w_mz_processing(all, str, len);
	do_lower(str);
	len = ft_strlen(str);
	all->symbol_num += len;
	write(1, str, len);
}

void				do_int16xupper(t_all *all, va_list *ap, char *str)
{
	unsigned long   num;
	int				len;

	if (all->modifier == 0)
		num = va_arg(*ap, unsigned int);
	else if (all->modifier == 1)
		num = (unsigned short)va_arg(*ap, unsigned int);
	else if (all->modifier == 2)
		num = (unsigned char)va_arg(*ap, unsigned int);
	else
		num = va_arg(*ap, unsigned long);
	str = ft_utoa_base(num, 16);
	len = ft_strlen(str);
	if (all->flag_hash == 1 && all->precision < 0 && all->width == 0)
		str = int16x_h_processing(str, &len);
	if (all->precision >= len)
		str = int16_p_processing(all, str, &len);
	if (all->width >= len)
		str = int16_w_mz_processing(all, str, len);
	len = ft_strlen(str);
	all->symbol_num += len;
	write(1, str, len);
}
