/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 12:50:06 by sbecker           #+#    #+#             */
/*   Updated: 2019/03/04 14:25:57 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	do_16x(t_all *all, va_list *ap, char *s)
{

}

void	do_n(t_all *all, va_list *ap)
{
	int *ptr;

	ptr = va_arg(*ap, int*);
	*ptr = all->symbol_num;
}

void	do_percent(t_all *all, va_list *ap, char *s)
{

}
