/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 14:17:26 by sbecker           #+#    #+#             */
/*   Updated: 2019/03/04 14:21:28 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"
# include <stdio.h>

typedef struct	s_all
{
	int		symbol_num;
	char	flag_minus;
	char	flag_plus;
	char	flag_space;
	char	flag_zero;
	char	flag_hash;
	int		width;
	int		precision;
	int		modifier;
	int		type;
}				t_all;

char			*check_flags(t_all *all, char *s);
char			*check_width_or_precision(t_all *all, char *s,
		va_list *ap, char flag);
char			*check_modifier(t_all *all, char *s);
char			*check_type(t_all *all, char *s);
void			do_n(t_all *all, va_list *ap);
void			do_percent(t_all *all, va_list *ap, char *s);
void			do_16x(t_all *all, va_list *ap, char *s);

#endif
