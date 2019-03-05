/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_processing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:05:26 by sschmele          #+#    #+#             */
/*   Updated: 2019/03/05 23:07:22 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*After type (int) and modifier processing we deal with precision, width and flags*/

char		*int_precision_processing(t_all *all, char *str, int *len, char check_minus)
{
	char	*new;

	if ((check_minus == 1 || all->flag_plus == 1 || all->flag_space == 1) && all->precision > *len)
		all->precision++;
	else if (check_minus == 1 || all->flag_plus == 1 || all->flag_space == 1)
		all->precision = *len + 1;
	if (all->precision > *len)
	{
		new = malloc(all->precision);
		ft_memset((void*)new, '0', (all->precision - *len));
		if (check_minus == 1)
			new[0] = '-';
		else if (all->flag_plus == 1)
			new[0] = '+';
		else if (all->flag_space == 1)
			new[0] = ' ';
		ft_strcpy(&new[all->precision - *len], str);
		*len = all->precision;
		free(str);
		return (new);
	}
	else
		return (str);
}

char        *int_w_processing(t_all *all, char *str, int len)
{
	char 	*fin;

	fin = ft_strnew(all->width);
	if (all->flag_minus == 1)
	{
		ft_strcpy(fin, str);
		ft_memset((void*)&fin[len], ' ', (all->width - len));
	}
	else if (all->flag_zero == 1 && str[1] != '0')
	{
		ft_strcpy(&fin[all->width - len], str);
		ft_memset((void*)fin, '0', (all->width - len));
	}
	else
	{
		ft_memset((void*)fin, ' ', (all->width - len));
		ft_strcpy(&fin[all->width - len], str);
	}
	free(str);
	return (fin);
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
