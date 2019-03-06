/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_processing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:05:26 by sschmele          #+#    #+#             */
/*   Updated: 2019/03/06 21:09:54 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*int_precision_processing(t_all *all, char *str, int *len, char check_minus)
{
	char	*new;

	if ((check_minus == 1 || all->flag_plus == 1 || all->flag_space == 1) && all->precision > *len)
		all->precision++;
	if (all->precision > *len)
	{
		new = malloc(all->precision);
		ft_strcpy(&new[all->precision - *len], str);
		ft_memset((void*)new, '0', (all->precision - *len));
		if (check_minus == 1)
			new[0] = '-';
		else if (all->flag_plus == 1)
			new[0] = '+';
		else if (all->flag_space == 1)
			new[0] = ' ';
		*len = all->precision;
		free(str);
		return (new);
	}
	else
		return (str);
}

char        *int_w_processing(t_all *all, char *str, int len, char check_minus)
{
	char 	*new;

	new = ft_strnew(all->width);
	if (all->flag_minus == 1)
	{
		ft_strcpy(new, str);
		ft_memset((void*)&new[len], ' ', (all->width - len));
	}
	else if (all->flag_zero == 1 && all->precision < 0)
	{
		ft_strcpy(&new[all->width - len], str);
		ft_memset((void*)new, '0', (all->width - len));
		if (check_minus == 1)
			new[0] = '-';
		else if (all->flag_plus == 1)
			new[0] = '+';
		else
			new[0] = ' ';
	}
	else
	{
		ft_memset((void*)new, ' ', (all->width - len));
		ft_strcpy(&new[all->width - len], str);
	}
	free(str);
	return (new);
}

char		*int_f_processing(t_all *all, char *str, int len)
{
	char    *fin;

	if (all->flag_plus == 1)
	{
		fin = ft_strnew(len + 1);
		fin[0] = '+';
		ft_strcpy(&fin[1], str);
	}
	if (all->flag_space == 1)
	{
		fin = ft_strnew(len + 1);
		fin[0] = ' ';
		ft_strcpy(&fin[1], str);
	}
	free(str);
	return (fin);
}
