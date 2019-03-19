/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_float_components.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 17:49:23 by sbecker           #+#    #+#             */
/*   Updated: 2019/03/19 18:06:14 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     exception_handling(t_fcomp *fcomp, long b, long exponent)
{
	fcomp->inf_check = 0;
	fcomp->nan_check = 0;
	if (exponent == 2047)
	{
		b = b << 12;
		if (b == 0)
			return (fcomp->inf_check = 1);
		else
			return (fcomp->nan_check = 1);
	}
	if (exponent == 0)
	{
		fcomp->integer_part = 0;
		fcomp->fraction = (int*)ft_memalloc(sizeof(int));
		return (1);
	}
	return (0);
}

char    *bit_fraction(long exponent, long b, int *len)
{
	register int    i;
	char            *b_fraction;

	*len = 53 - exponent;
	b_fraction = ft_memalloc(*len + 1);
	ft_memset((void*)b_fraction, '0', *len);
	if (exponent < 0)
	{
		b_fraction[*len - 54] = '1';
		i = 52;
	}
	else
		i = *len - exponent;
	while (--i >= 0)
		b_fraction[*len - 2 - i] = ((1l << i) & b) ? '1' : '0';
	return (b_fraction);
}

void    countup_fraction(t_fcomp *fcomp, int *num, char bit)
{
	int count;

	count = -1;
	if (bit == '1')
		while (++count < fcomp->len)
		{
			fcomp->fraction[count] += num[count];
			fcomp->fraction[count + 1] += fcomp->fraction[count] / 10;
			fcomp->fraction[count] %= 10;
		}
}

void    take_fraction(char *b_fraction, t_fcomp *fcomp)
{
	register int    i;
	int             count;
	int             *num;

	fcomp->fraction = (int*)ft_memalloc(fcomp->len * sizeof(int));
	num = (int*)ft_memalloc(fcomp->len * sizeof(int));
	num[fcomp->len - 1] = 5;
	i = -1;
	while (b_fraction[++i])
	{
		countup_fraction(fcomp, num, b_fraction[i]);
		count = -1;
		while (++count < fcomp->len - 1)
			num[count] = num[count + 1];
		num[fcomp->len - 1] = 0;
		count = -1;
		while (++count < fcomp->len)
			num[count] *= 5;
		count = -1;
		while (++count < fcomp->len)
		{
			num[count + 1] += num[count] / 10;
			num[count] %= 10;
		}
	}
	free(num);
}

void    get_components(va_list *ap, t_fcomp *fcomp, t_all *all)
{
	long            exponent;
	long            b;
	double          a;
	char            *b_fraction;

	a = va_arg(*ap, double);
	b = *((long*)&a);
	fcomp->sign = ((1lu << 63) & b) ? -1 : 1;
	exponent = b >> 52;
	if (exception_handling(fcomp, b, exponent))
		return ;
	exponent -= 1023;
	b_fraction = bit_fraction(exponent, b, &fcomp->len);
	take_fraction(b_fraction, fcomp);
	fcomp->integer_part = (int)a;
}
