/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   learn_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 22:14:10 by sbecker           #+#    #+#             */
/*   Updated: 2019/03/16 19:02:49 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "ft_printf.h"

typedef __int128 int128_t;

char		*do_tryfloat(int sign, long exponent, char *m)
{
	double b = -185.4375;
	char	*res;
	char	*before;
	int		precision;

	precision = 20;
	res = ft_strnew(20);
	before = ft_ltoa_base((int)b, 10);
	
	printf("%s\n", before);


	


	

	

	//res = (m[0] - '0') * 128 + (m[1] - '0') * 64 + (m[2] - '0') * 32 + (m[3] - '0') * 16 + (m[4] - '0') * 8 + (m[5] - '0') * 4 + (m[6] - '0') * 2 + m[7] - '0' + (m[8] - '0') * 0.5 + (m[9] - '0') * 0.25 + (m[10] - '0') * 0.125 + (m[11] - '0') * 0.062500 + (m[12] - '0') * 0.031250;
	//printf("%d\n", b);
	return (res);
}

int main()
{
	int		sign;
	long	exponent;
//	long double	a = 0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000099999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999;

	long double a = 185.4375;
	int128_t b;
	int128_t odin = 1;
	int i = 128;
	int m = 112;
	int e = 15;
	int hold_i = i;
	char *mantissa;

	mantissa = malloc(m);
	b = *((int128_t*)&a);
	long c = b;

	//printf ("original float, sign is first bit:\n");
	odin = odin << 127;
	int128_t tmp_odin = 1;
	while (--i >= 0)
		printf ("%d ", ((tmp_odin << i) & odin) ? 1 : 0);
	printf ("\n\n");
	i = 80;
	while (--i >= 0)
		printf ("%d ", ((tmp_odin << i) & b) ? 1 : 0);
	sign = ((odin << (hold_i-1)) & b) ? -1 : 1;
	printf ("\nsign: %d\n", sign);

	//printf ("\ntake modul float:\n");
//	b &= ~(odin << (hold_i-1));
//	i = 128;
//	while (--i >= 0)
//		printf ("%d ", ((odin << i) & b) ? 1 : 0);

	//printf ("\n\ntake exponent:\n");
	b = b >> m;
	exponent = b;
	//i = 64;
	//while (--i >= 0)
	//	printf ("%d ", ((1l << i) & b) ? 1 : 0);
	printf ("\nexponent: %ld\n", exponent);

	//printf ("\ntake mantissa:\n");
	c = c << e;
	c &= ~(odin << (hold_i-1));
	while (--i >= 0)
	{
		mantissa[(hold_i - 1) - i] = ((odin << i) & c) ? '1' : '0';
	//	printf ("%d ", ((1l << i) & c) ? 1 : 0);
	}
	mantissa[0] = '1';
	printf ("\nmantissa: %s\n", mantissa);
	do_tryfloat(sign, exponent, mantissa);
	return (0);
}
