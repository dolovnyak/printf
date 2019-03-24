/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_float_components.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 17:49:23 by sbecker           #+#    #+#             */
/*   Updated: 2019/03/25 01:15:26 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		exception_handling(t_fcomp *fcomp, long b, long exponent)
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
	fcomp->sign = ((1lu << 63) & b) ? -1 : 1;
	b &= ~(1l << 63);
	exponent = b >> 52;
	if (exception_handling(fcomp, b, exponent))
		return ;
	exponent -= 1023;
	fcomp->len_fraction = 1; //нужнa из-за нехватки строк в bit_fraction (когда exponent >= 52 длина должна быть 1)
	b_fraction = bit_fraction(exponent, b, &fcomp->len_fraction);
	get_fraction(b_fraction, fcomp);
	b_integer = bit_integer(exponent, b, &fcomp->len_integer);
	printf("bit fract: %s\n", b_fraction); //del
	printf("bit integ: %s\n", b_integer);	//del
	get_integer(b_integer, fcomp);
//	norm_integer(fcomp);
	free(b_fraction);
	free(b_integer);
}
