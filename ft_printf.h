/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 14:17:26 by sbecker           #+#    #+#             */
/*   Updated: 2019/03/04 12:17:57 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"
# include <stdio.h>

typedef struct	s_all
{
	char	flag_minus;
	char	flag_plus;
	char	flag_space;
	char	flag_zero;
	char	flag_hash;
	int		width;
	int		precision;
	int		modifier;
	int		type;

//	int		modifier_h = 1;
//	int		modifier_hh = 2;
//	int		modifier_l = 3;
//	int		modifier_ll = 4;
//	int		modifier_L = 5; //заменить 5 модификаторов на 1

//	int		type_int = 1;
//	int		type_uint = 2;
//	int		type_int8 = 3;
//	int		type_int16x = 4;
//	int		type_int16X = 5;
//	int		type_float = 6;
//	int		type_efloat = 7;
//	int		type_gfloat = 8;
//	int		type_afloat = 9;
//	int		type_uchar = 10;
//	int		type_string = 11;
//	int		type_ptr = 12;
//	int		ebanina_type = 13;
//	int		percent_type = 14; //заменить все типы на 1
}				t_all;

char			*check_flags(t_all *all, char *s);
char			*check_width_or_precision(t_all *all, char *s, va_list *ap, int flag);
char			*check_modifier(t_all *all, char *s);
char			*check_type(t_all *all, char *s, va_list *ap);

#endif
