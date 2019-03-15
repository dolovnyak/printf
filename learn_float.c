/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   learn_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 22:14:10 by sbecker           #+#    #+#             */
/*   Updated: 2019/03/15 06:30:33 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <stdint.h>

int main()
{
	int		sign;
	long	exponent;
	double	a = -185.4375;
	long b;
	int i = 64;
	char *mantissa;

	mantissa = malloc(53);
	b = *((long*)&a);
	long c = b;

	printf ("b = %ld\n", b);
	printf ("original float, sign is first bit:\n");
	i = 64;
	while (--i >= 0)
		printf ("%d ", ((1l << i) & b) ? 1 : 0);
	sign = ((1lu << 63) & b) ? -1 : 1;
	printf ("\nsign: %d\n", sign);

	printf ("\ntake modul float:\n");
	b &= ~(1lu << 63);
	i = 64;
	while (--i >= 0)
		printf ("%d ", ((1l << i) & b) ? 1 : 0);

	printf ("\n\ntake exponent:\n");
	b = b >> 52;
	exponent = b;
	i = 64;
	while (--i >= 0)
		printf ("%d ", ((1l << i) & b) ? 1 : 0);
	printf ("\nexponent: %ld\n", exponent);

	printf ("\ntake mantissa:\n");
	c = c << 11;
	c &= ~(1l << 63);
	i = 64;
	while (--i >= 0)
	{
		mantissa[63 - i] = ((1l << i) & c) ? '1' : '0';
		printf ("%d ", ((1l << i) & c) ? 1 : 0);
	}
	mantissa[0] = '1';
	printf ("\nmantissa: %s", mantissa);



	/*int sign;
	long mantissa;
	long exponent;
	float	a = -185.4375;
	int b = *((int*)&a);
	int c = b;

	printf ("original float, sign is first bit:\n");
	int i = 32;
	while (--i >= 0)
		printf ("%d ", ((1 << i) & b) ? 1 : 0);

	sign = ((1 << 31) & b) ? -1 : 1;
	printf ("\nsign: %d\n", sign);


	printf ("\ntake modul float:\n");
	b &= ~(1 << 31);
	i = 32;
	while (--i >= 0)
		printf ("%d ", ((1 << i) & b) ? 1 : 0);

	printf ("\n\ntake exponent:\n");
	b = b >> 23;
	exponent = b;
	i = 32;
	while (--i >= 0)
		printf ("%d ", ((1 << i) & b) ? 1 : 0);
	printf ("\nexponent: %d\n", exponent);

	printf ("\ntake mantissa:\n");
	c = c << 1;
	c &= ~(1 << 31);
	c = c >> 8;
	c |= 1 << 23;
	mantissa = c;
	i = 32;
	while (--i >= 0)
		printf ("%d ", ((1 << i) & c) ? 1  :0);*/
	return (0);
}
