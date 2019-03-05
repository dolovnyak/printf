/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 12:50:06 by sbecker           #+#    #+#             */
/*   Updated: 2019/03/05 11:58:39 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	do_n(t_all *all, va_list *ap)
{
	int *ptr;

	ptr = va_arg(*ap, int*);
	*ptr = all->symbol_num;
}

void	do_percent(t_all *all, va_list *ap, char *str)
{
	str = ft_memalloc(all->width);
	if (all->flag_minus == 1)
	{
		ft_memset((void*)str, ' ', all->width);
		str[0] = '%';
	}
	else if (all->flag_zero == 1)
	{
		ft_memset((void*)str, '0', all->width);
		str[all->width - 1] = '%';
	}
	else
	{
		ft_memset((void*)str, ' ', all->width);
		str[all->width -1] = '%';
	}
	write (1, str, all->width);
	free (str);
}

void	do_uchar(t_all *all, va_list *ap, char *str)
{
	str = ft_memalloc(all->width);
	if (all->flag_minus == 1)
	{
		ft_memset((void*)str, ' ', all->width);
		str[0] = (unsigned char)va_arg(*ap, int);
	}
	else if (all->flag_zero == 1)
	{
		ft_memset((void*)str, '0', all->width);
		str[all->width - 1] = (unsigned char)va_arg(*ap, int);
	}
	else
	{
		ft_memset((void*)str, ' ', all->width);
		str[all->width -1] = (unsigned char)va_arg(*ap, int);
	}
	write (1, str, all->width);
	free (str);
}

void	do_string(t_all *all, va_list *ap, char *str)
{

}
