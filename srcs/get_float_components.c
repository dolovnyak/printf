/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_float_components.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 17:49:23 by sbecker           #+#    #+#             */
/*   Updated: 2019/03/25 16:33:08 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int find_len_integer(int len_s)
{
	int res = 0;
	if (len_s < 10)
	{
		if (len_s % 3 == 0)
			res = len_s / 3;
		else
			res = len_s / 3 + 1;
	}
	else
	{
		if (len_s % 10 >= 0 && len_s % 10 <= 3)
			res = len_s / 10 + len_s / 5 + 1;
		else
			res = (len_s - (len_s / 10) * 10) / 7 + (len_s / 10) * 3 + 2;
	}
	return (res + 5);
}

int		exception_handling(t_fcomp *fcomp, long b, long exponent)
{
	fcomp->inf_check = 0;
	fcomp->nan_check = 0;
	if (exponent == 2047)
	{
		printf ("CHECK3\n");
		b = b << 12;
		if (b == 0)
			return (fcomp->inf_check = 1);
		else
			return (fcomp->nan_check = 1);
	}
	b = b << 11;
	b &= ~(1l << 63);
	if (exponent == 0 && b == 0)
	{
		fcomp->len_integer = 2;
		fcomp->integer = (int*)ft_memalloc(sizeof(int));
		fcomp->fraction = (int*)ft_memalloc(sizeof(int));
		return (1);
	}
	return (0);
}

void	get_components(va_list *ap, t_fcomp *fcomp, t_all *all)
{
	long	exponent;
	long	b;
	double	a;
	char	*b_fraction;
	char	*b_integer;

	a = va_arg(*ap, double);
	b = *((long*)&a);
	int i = 64;
	printf ("AAAA: ");
	while (--i >= 0)
		printf ("%d ", ((1l << i) & b) ? 1 : 0);
	printf ("\n");
	fcomp->sign = ((1lu << 63) & b) ? -1 : 1;
	b &= ~(1l << 63);
	exponent = b >> 52;
	fcomp->len_fraction = 1;
	if (exception_handling(fcomp, b, exponent))
		return ;
	exponent -= 1023;
	b_fraction = bit_fraction(exponent, b, &fcomp->len_fraction);
	get_fraction(b_fraction, fcomp);
	b_integer = bit_integer(exponent, b, &fcomp->len_integer);
//	fcomp->len_integer = find_len_integer(fcomp->len_integer);
	get_integer(b_integer, fcomp);
	norm_integer(fcomp);
//	printf("bit fract: %s\n", b_fraction); //del
//	printf("bit integ: %s\n", b_integer);	//del
	free(b_fraction);
	free(b_integer);
}
