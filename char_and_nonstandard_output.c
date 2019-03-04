/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 12:50:06 by sbecker           #+#    #+#             */
/*   Updated: 2019/03/04 17:50:40 by sbecker          ###   ########.fr       */
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
		ft_memset((void*)s, ' ', all->width - 2);
		s[all->width - 1] = '%';
		write (1, s, all->width);
	}
//	else if (all->flag_zero == 1)
}

void	do_uchar(t_all *all, va_list *ap, char *str)
{

}

void	do_string(t_all *all, va_list *ap, char *str)
{

}
