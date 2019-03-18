/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:47:27 by sbecker           #+#    #+#             */
/*   Updated: 2019/03/18 14:44:50 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef struct	s_float_components
{
	int	sign;
	int	integer_part;
	int	*fraction;
	int	zero_check;
	int	inf_check;
	int	len;
}				t_fcomp;

char	*f_fraction(t_fcomp *fcomp, int exponent, long b)
{
	char			*b_fraction;
	register int	i;

	if (exponent < 0)
	{
		fcomp->len = -exponent + 53;
		b_fraction = ft_memalloc(fcomp->len + 1);
		ft_memset((void*)b_fraction, '0', fcomp->len);
		if (exponent < 0)
		{
			b_fraction[fcomp->len - 54] = '1';
			i = fcomp->len - exponent;
		}
		i = 52;
		while (--i >= 0)
			b_fraction[fcomp->len - 2 - i] = ((1l << i) & b) ? '1' : '0';
	}
/*	else
	{
		fcomp->len = 53 - exponent;
		b_fraction = ft_memalloc(fcomp->len + 1);
		ft_memset((void*)b_fraction, '0', fcomp->len);
		i = fcomp->len - exponent;
		while (--i >= 0)
			b_fraction[fcomp->len - 2 - i] = ((1l << i) & b) ? '1' : '0';
	}*/
	return (b_fraction);
}

void	get_components(va_list *ap, t_fcomp *fcomp)
{
	long			exponent;
	long			bits;
	register int	i;
	double			a;
	char			*b_fraction;

	a = va_arg(*ap, double);
	bits = *((long*)&a);
	fcomp->sign = ((1lu << 63) & bits) ? -1 : 1;
	exponent = bits >> 52;
	fcomp->inf_check = exponent == 2047 ? 1 : 0;
	bits &= ~(1lu << 63);
	fcomp->zero_check = bits == 0 ? 1 : 0;
	exponent -= 1023;
	b_fraction = f_fraction(fcomp, exponent, bits);

	int *res = (int*)ft_memalloc(fcomp->len * sizeof(int));
	int *num = (int*)ft_memalloc(fcomp->len * sizeof(int));
	num[fcomp->len - 1] = 5;
	printf ("num: %d\n", num[fcomp->len - 1]);
	i = -1;
	int count;
	printf ("\n");
	while (b_fraction[++i])
	{
		count = -1;
		if (b_fraction[i] == '1')
			while (++count < fcomp->len)
			{
				res[count] += num[count];
				res[count + 1] += res[count] / 10;
				res[count] %= 10;
			}

		count = fcomp->len;
		printf ("num: ");
		while (--count >= 0)
			printf ("%d", num[count]);
		printf ("\n");
		count = fcomp->len;
		printf ("res: ");
		while (--count >= 0)
			printf ("%d", res[count]);
		printf ("\n");

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
	printf ("\nend res: 0.");
	count = fcomp->len;
	while (--count >= 0)
		printf ("%d", res[count]);
	printf ("\n\n");
	printf ("fcomp->len: %d\n", fcomp->len);

}

void	do_float(t_all *all, va_list *ap, char *str)
{
	t_fcomp			fcomp;
	get_components(ap, &fcomp);
}

void	do_efloat(t_all *all, va_list *ap, char *str)
{

}

void	do_gfloat(t_all *all, va_list *ap, char *str)
{

}

void	do_afloat(t_all *all, va_list *ap, char *str)
{

}
