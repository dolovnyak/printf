/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_rounding.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 04:10:34 by sbecker           #+#    #+#             */
/*   Updated: 2019/03/26 11:48:35 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	processing_overflow_integerpart(t_fcomp *fcomp)
{
	register int	i;

	i = -1;
	while (++i < fcomp->len_integer && fcomp->integer[i] == 10)
	{
		fcomp->integer[i + 1]++;
		fcomp->integer[i] = 0;
	}
	if (i == fcomp->len_integer - 1)
		fcomp->len_integer++;
}

int		check_5(t_fcomp *fcomp, int count)
{
	register int	i;

	i = fcomp->len_fraction - count - 1;
//	printf ("CHECK: %d\n", fcomp->fraction[i]);
//	printf ("CHECK: %d\n", fcomp->fraction[--i]);
//	printf ("CHECK: %d\n", fcomp->fraction[--i]);
	while (--i >= 0)
		if (fcomp->fraction[i] != 0)
			return (1);
//	printf ("CHECK\n");
	return (0);
}

char	*get_string_integer(t_fcomp *fcomp)
{
	char            *s;
	register int    i;
	register int    j;

	if (fcomp->fraction[fcomp->len_fraction - 1] == 5 && fcomp->integer[0] % 2 == 0)
		check_5(fcomp, 1) == 1 ? fcomp->integer[0]++ : fcomp->integer[0];
	else if (fcomp->fraction[fcomp->len_fraction - 1] >= 5)
		fcomp->integer[0]++;
	if (fcomp->integer[0] == 10)
		processing_overflow_integerpart(fcomp);
	s = ft_memalloc(fcomp->len_integer + 1);
	i = fcomp->len_integer - 1;
	j = -1;
	while (--i >= 0)
		s[++j] = fcomp->integer[i] + '0';
	return (s);
}
