/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_processing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:05:26 by sschmele          #+#    #+#             */
/*   Updated: 2019/03/05 19:09:13 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*After type (int) and modifier processing we deal with precision, width and flags*/

char		*int_p_processing(t_all *all, char *str, int len)
{
	char	*fin;

	if (all->precision > (len - 1) && str[0] == '-')
	{
//		printf("first\n");
		fin = ft_strnew(all->precision + 1);
		fin[0] = '-';
		ft_memset((void*)&fin[1], '0', (all->precision - len + 1));
		ft_strcpy(&fin[all->precision - len + 2], &str[1]);
	}
	else if (all->precision > len)
	{
//		printf("first_a\n");
		fin = ft_strnew(all->precision);
		ft_memset((void*)fin, '0', (all->precision - len));
		ft_strcpy(&fin[all->precision - len], str);
	}
	free(str);
	return (fin);
}

char        *int_w_processing(t_all *all, char *str, int len)
{
	char 	*fin;

	fin = ft_strnew(all->width);
//	printf("second\n");
	if (all->flag_minus == 1)
	{
		ft_strcpy(fin, str);
		ft_memset((void*)&fin[len], ' ', (all->width - len));
	}
	else if (all->flag_zero == 1)
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
//		printf("third\n");
		fin = ft_strnew(len + 1);
		fin[0] = '+';
		ft_strcpy(&fin[1], str);
	}
	if (all->flag_space == 1)
	{
//		printf("fourth\n");
		fin = ft_strnew(len + 1);
		fin[0] = ' ';
		ft_strcpy(&fin[1], str);
	}
	free(str);
	return (fin);
}
