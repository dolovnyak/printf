/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:43:46 by sbecker           #+#    #+#             */
/*   Updated: 2019/03/05 23:13:16 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*re_strsub(char *s, int start, int len)
{
	char	*a;
	int		i;

	i = 0;
	if (!s)
		return (0);
	if ((a = (char*)ft_memalloc(len + 1)))
	{
		while (i < len)
		{
			a[i] = s[start];
			start++;
			i++;
		}
		a[i] = '\0';
	}
	free (s);
	return (a);
}

void		do_int(t_all *all, va_list *ap, char *str)
{
	int		len;
	char	*fin;
	char	check_minus;

	check_minus = 0;
	if (all->modifier == 0)
		str = ft_itoa_base(va_arg(*ap, int), 10);
	else if (all->modifier == 1)
		str = ft_itoa_base((short int)va_arg(*ap, int), 10);
	else if (all->modifier == 2)
		str = ft_itoa_base((unsigned char)va_arg(*ap, int), 10);
	else
		str = ft_itoa_base(va_arg(*ap, long), 10);
	len = ft_strlen(str);
	if (str[0] == '-')
	{
		len--;
		check_minus = 1;
		str = re_strsub(str, 1, len);
	}
	str = int_precision_processing(all, str, &len, check_minus);
	if (all->width > len)
		str = int_w_processing(all, str, len);
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
