/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 08:33:26 by sschmele          #+#    #+#             */
/*   Updated: 2019/03/05 13:24:23 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#define MALLOC(x) if (x == NULL) return (NULL)

int			count_digits(long value, int base)
{
	int		res;

	res = 0;
	while (value)
	{
		value /= base;
		res++;
	}
	return (res);
}

char		*ft_itoa_base(long nb, int base)
{
	int		i;
	char	*str;
	int		len;
	char	*main;

	if (!nb && !base && !(base >= 2 && base <= 16))
		return (NULL);
	i = 0;
	main = "0123456789ABCDEF";
	len = count_digits(nb, base);
	(nb < 0 && base == 10) ? len++ : len;
	MALLOC((str = ft_strnew(len)));
	if (nb < 0)
	{
		str[i] = '-';
		nb *= -1;
	}
	while (nb)
	{
		str[len - ++i] = main[nb % base];
		nb /= base;
	}
	return (str);
}
