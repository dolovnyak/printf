/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 18:09:40 by sschmele          #+#    #+#             */
/*   Updated: 2019/03/11 18:36:27 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define MALLOC(x) if (x == NULL) return (NULL)

static int	count_digits_u(unsigned long value, int base)
{
	int		res;

	res = 0;
	if (value == 0)
		return (1);
	while (value)
	{
		value /= base;
		res++;
	}
	return (res);
}

char		*ft_utoa_base(unsigned long nb, int base)
{
	int		i;
	char	*str;
	int		len;
	char	*main;

	if (!nb && !base && !(base >= 2 && base <= 16))
		return (NULL);
	i = 0;
	main = "0123456789ABCDEF";
	len = count_digits_u(nb, base);
	MALLOC((str = ft_strnew(len)));
	if (nb == 0)
		str[0] = 0 + '0';
	while (nb)
	{
		str[len - ++i] = main[nb % base];
		nb /= base;
	}
	return (str);
}
