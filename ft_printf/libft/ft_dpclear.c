/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dpclear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:20:53 by sbecker           #+#    #+#             */
/*   Updated: 2018/12/06 12:30:31 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_dpclear(char **arr)
{
	int i;

	i = 0;
	while (arr)
	{
		ft_strdel(&*arr);
		arr++;
	}
	free(arr);
	return (NULL);
}