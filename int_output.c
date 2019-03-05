/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:43:46 by sbecker           #+#    #+#             */
/*   Updated: 2019/03/05 19:32:07 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		do_int(t_all *all, va_list *ap, char *str)
{
	int		len;
	char	*fin;
	int		flag;

	flag = 0;
	if (all->modifier == 0)
		str = ft_itoa_base(va_arg(*ap, int), 10);
	else if (all->modifier == 1)
		str = ft_itoa_base((short int)va_arg(*ap, int), 10);
	else if (all->modifier == 2)
		str = ft_itoa_base((unsigned char)va_arg(*ap, int), 10);
	else
		str = ft_itoa_base(va_arg(*ap, long), 10);
	len = ft_strlen(str);
	if (all->precision > (len - 1))
	{
		fin = int_p_processing(all, str, len);
		str = ft_strdup(fin);
		flag = 1;
	}
	if (all->flag_plus != 0 && !(str[0] == '-'))
	{
		if (flag == 1)
		{
			free(fin);
			len = ft_strlen(str);
		}
		fin = int_f_processing(all, str, len);
		str = ft_strdup(fin);
	}
	if (all->flag_space != 0 && !(str[0] == '-'))
	{
		if (flag == 1)
		{
			free(fin);
			len = ft_strlen(str);
		}
		fin = int_f_processing(all, str, len);
		str = ft_strdup(fin);
	}
	if (all->width > len || all->width > all->precision)
	{
		if (flag == 1)
		{
			free(fin);
			len = ft_strlen(str);
		}
		fin = int_w_processing(all, str, len);
		str = ft_strdup(fin);
		flag = 2;
	}
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
