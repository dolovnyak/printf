/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_processing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:05:26 by sschmele          #+#    #+#             */
/*   Updated: 2019/03/09 10:14:46 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*int_precision_processing(t_all *all, char *str, int *len)
{
	char	*new;

	if ((all->flag_sign_minus == 1 || all->flag_plus == 1 || all->flag_space == 1) && all->precision > *len)
		all->precision++;
	if (all->precision > *len)
	{
		new = malloc(all->precision);
		ft_strcpy(&new[all->precision - *len], str);
		ft_memset((void*)new, '0', (all->precision - *len));
		if (all->flag_sign_minus == 1)
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

char        *int_w_processing(t_all *all, char *str, int len)
{
	char 	*new;

	new = ft_strnew(all->width);
	if (all->flag_minus == 1)
	{
		ft_strcpy(new + 1, str);
		ft_memset((void*)&new[len + 1], ' ', (all->width - len));
		if (all->flag_sign_minus == 1)
			new[0] = '-';
		else if (all->flag_plus == 1)
			new[0] = '+';
		else
			new[0] = ' ';
	}
	else if (all->flag_zero == 1 && all->precision < 0)
	{
		ft_strcpy(&new[all->width - len], str);
		ft_memset((void*)new, '0', (all->width - len));
		if (all->flag_sign_minus == 1)
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
		if (all->flag_sign_minus == 1)
			new[all->width - len - 1] = '-';
		else if (all->flag_plus == 1)
			new[all->width - len - 1] = '+';
		else
			new[all->width - len - 1] = ' ';
	}
	free(str);
	return (new);
}
