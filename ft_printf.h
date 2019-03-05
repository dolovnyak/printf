/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 14:17:26 by sbecker           #+#    #+#             */
/*   Updated: 2019/03/05 16:31:25 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"
# include <stdio.h>			//DELETE

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
char			*check_type_and_output(t_all *all, va_list *ap, char *s);
void			do_n(t_all *all, va_list *ap);
void			do_int(t_all *all, va_list *ap, char *str);
void			do_uint(t_all *all, va_list *ap, char *str);
void            do_int8(t_all *all, va_list *ap, char *str);
void			do_int16x(t_all *all, va_list *ap, char *str);
void            do_int16X(t_all *all, va_list *ap, char *str);
void            do_float(t_all *all, va_list *ap, char *str);
void            do_efloat(t_all *all, va_list *ap, char *str);
void            do_gfloat(t_all *all, va_list *ap, char *str);
void            do_afloat(t_all *all, va_list *ap, char *str);
void            do_string(t_all *all, va_list *ap, char *str);
char			*ft_itoa_base(long value, int base);
void			do_percent_or_uchar(t_all *all, va_list *ap, char *str, char f);

#endif
