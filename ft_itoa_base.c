/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 08:33:26 by sschmele          #+#    #+#             */
/*   Updated: 2019/03/05 12:40:45 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdlib.h>
#define MALLOC(x) if (x == NULL) return (NULL)

int			count_digits(int value, int base)
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

char		*ft_itoa_base(int value, int base)
{
	int		i;
	char	*str;
	int		len;
	char	*main;
	long	nb;

	if (!value && !base && !(base >= 2 && base <= 16))
		return (NULL);
	i = 0;
	main = "0123456789ABCDEF";
	len = count_digits(value, base);
	nb = value;
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
