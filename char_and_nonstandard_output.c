/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 12:50:06 by sbecker           #+#    #+#             */
/*   Updated: 2019/03/04 19:33:26 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	do_n(t_all *all, va_list *ap)
{
	int *ptr;

	ptr = va_arg(*ap, int*);
	*ptr = all->symbol_num;
}

void	do_percent(t_all *all, va_list *ap, char *s)
{
	s = ft_memalloc(all->width);
	if (all->flag_minus == 1)
	{
		ft_memset((void*)s, ' ', all->width);
		s[0] = '%';
	}
	else if (all->flag_zero == 1)
	{
		ft_memset((void*)s, '0', all->width);
		s[all->width - 1] = '%';
	}
	else
	{
		ft_memset((void*)s, ' ', all->width);
		s[all->width -1] = '%';
	}
	write (1, s, all->width);
	free (s);
}

void	do_uchar(t_all *all, va_list *ap, char *s)
{
	s = ft_memalloc(all->width);
	if (all->flag_minus == 1)
	{
		ft_memset((void*)s, ' ', all->width);
		s[0] = (unsigned char)va_arg(*ap, int);
	}
	else if (all->flag_zero == 1)
	{
		ft_memset((void*)s, '0', all->width);
		s[all->width - 1] = (unsigned char)va_arg(*ap, int);
	}
	else
	{
		ft_memset((void*)s, ' ', all->width);
		s[all->width -1] = (unsigned char)va_arg(*ap, int);
	}
	write (1, s, all->width);
	free (s);
}

void	do_string(t_all *all, va_list *ap, char *str)
{

}
