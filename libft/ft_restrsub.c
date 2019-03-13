/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_restrsub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 19:57:18 by sbecker           #+#    #+#             */
/*   Updated: 2019/03/12 20:01:08 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_restrsub(char *s, int start, int len)
{
	char	*a;
	int		i;

	i = 0;
	if (!s)
		return (0);
	if ((a = (char*)malloc(len + 1)))
	{
		while (i < len)
		{
			a[i] = s[start];
			start++;
			i++;
		}
		a[i] = '\0';
	}
	free(s);
	return (a);
}
