/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:43:46 by sbecker           #+#    #+#             */
/*   Updated: 2019/03/13 18:01:30 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		do_int(t_all *all, va_list *ap, char *str)
{
	int			len;

	str = get_str(ap, str, all, 10);
	len = ft_strlen(str);
	if (str[0] == '0')
		zero_p(all, str, &len, 0);
	if (str[0] == '-')
	{
		all->flag_sign_minus = 1;
		str = ft_restrsub(str, 1, --len);
	}
	if (all->precision < len && all->width < len)
		str = flags_ps_or_signs(all, str, &len);
	else
	{
		if (all->precision >= len)
			str = int_precision_processing(all, str, &len);
		if (all->width >= len)
			str = int_w_mz_processing(all, str, &len);
	}
	all->symbol_num += len;
	write(1, str, len);
}

void		do_uint(t_all *all, va_list *ap, char *str)
{
	int				len;

	str = get_str(ap, str, all, 1);
	len = ft_strlen(str);
	if (str[0] == '0')
		zero_p(all, str, &len, 0);
	if (all->precision >= len)
		str = intu82_p_processing(all, str, &len);
	if (all->width >= len)
		str = intu82_w_mz_processing(all, str, &len);
	all->symbol_num += len;
	write(1, str, len);
}

void		do_int8(t_all *all, va_list *ap, char *str)
{
	int				len;

	str = get_str(ap, str, all, 8);
	len = ft_strlen(str);
	if (str[0] == '0')
		zero_p(all, str, &len, 1);
	if (all->precision >= len)
		str = intu82_p_processing(all, str, &len);
	if (all->flag_hash == 1 && (all->precision < 0 || len == 0))
		str = int8_h_processing(str, &len);
	if (all->width >= len)
		str = intu82_w_mz_processing(all, str, &len);
	all->symbol_num += len;
	write(1, str, len);
}

void		do_int16x(t_all *all, va_list *ap, char *str)
{
	int				len;

	str = get_str(ap, str, all, 16);
	len = ft_strlen(str);
	if (str[0] == '0')
		zero_p(all, str, &len, 0);
	if (all->flag_hash == 1 && all->precision < 0 && all->width == 0)
		str = int16x_h_processing(str, &len);
	if (all->precision >= len)
		str = int16_p_processing(all, str, &len);
	if (all->width >= len)
		str = int16_w_mz_processing(all, str, &len);
	do_lower(str);
	all->symbol_num += len;
	write(1, str, len);
}

void		do_int16xupper(t_all *all, va_list *ap, char *str)
{
	int				len;

	str = get_str(ap, str, all, 16);
	len = ft_strlen(str);
	if (str[0] == '0')
		zero_p(all, str, &len, 0);
	if (all->flag_hash == 1 && all->precision < 0 && all->width == 0)
		str = int16x_h_processing(str, &len);
	if (all->precision >= len)
		str = int16_p_processing(all, str, &len);
	if (all->width >= len)
		str = int16_w_mz_processing(all, str, &len);
	all->symbol_num += len;
	write(1, str, len);
}
