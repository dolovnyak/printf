/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_processing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:05:26 by sschmele          #+#    #+#             */
/*   Updated: 2019/03/11 16:51:05 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*int16_p_processing(t_all *all, char *str, int *len)
{
	char	*new;

	new = ft_strnew(all->precision);
	ft_memset((void*)new, '0', (all->precision - *len));
	ft_strcpy(&new[all->precision - *len], str);
	*len = all->precision;
	ft_strdel(&str);
	if (all->flag_hash == 1)
		new = int16x_h_processing(new, len);
	return (new);
}

char		*int16_w_mz_processing(t_all *all, char *str, int len)
{
	char	*new;

	if (all->flag_hash == 1 && all->flag_zero == 0 && all->precision < 0)
		str = int16x_h_processing(str, &len);
	new = ft_strnew(all->width);
	if (all->flag_minus == 1)
	{
		ft_memcpy((void*)new, (const void*)str, len);
		ft_memset((void*)&new[len], ' ', (all->width - len));
	}
	else if (all->flag_zero == 1 && all->precision < 0)
	{
		ft_memset((void*)new, '0', (all->width - len));
		ft_strcpy(&new[all->width - len], str);
		if (all->flag_hash == 1)
			new[1] = 'X';
	}
	else
	{
		ft_memset((void*)new, ' ', (all->width - len));
		ft_strcpy(&new[all->width - len], str);
	}
	ft_strdel(&str);
	return (new);
}

char		*int16x_h_processing(char *str, int *len)
{
	char	*new;

	new = ft_strnew((size_t)(*len + 2));
	new[0] = '0';
	new[1] = 'X';
	ft_strcpy(&new[2], str);
	*len += 2;
	ft_strdel(&str);
	return (new);
}

void		do_lower(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
}
