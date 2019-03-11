/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 14:17:26 by sbecker           #+#    #+#             */
/*   Updated: 2019/03/11 14:47:24 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"
# include <stdio.h>			//DELETE

typedef struct	s_all
{
	int		symbol_num;
	char	flag_minus;
	char	flag_plus;
	char	flag_space;
	char	flag_zero;
	char	flag_hash;
	char	flag_sign_minus;
	int		width;
	int		precision;
	int		modifier;
	int		type;
}				t_all;

int				ft_printf(const char *str, ...);
char			*check_flags(t_all *all, char *s);
char			*check_width_or_precision(t_all *all, char *s,
		va_list *ap, char flag);
char			*check_modifier(t_all *all, char *s);
char			*check_type(t_all *all, char *s);
char			*check_type_and_output(t_all *all, va_list *ap, char *s);
void			do_n(t_all *all, va_list *ap);
void			do_int(t_all *all, va_list *ap, char *str);
void			do_uint(t_all *all, va_list *ap, char *str);
void			do_int8(t_all *all, va_list *ap, char *str);
void			do_int16x(t_all *all, va_list *ap, char *str);
void			do_int16xupper(t_all *all, va_list *ap, char *str);
void			do_float(t_all *all, va_list *ap, char *str);
void			do_efloat(t_all *all, va_list *ap, char *str);
void			do_gfloat(t_all *all, va_list *ap, char *str);
void			do_afloat(t_all *all, va_list *ap, char *str);
void			do_string(t_all *all, va_list *ap, char *str);
char			*ft_itoa_base(long value, int base);
void			do_percent_or_uchar(t_all *all, va_list *ap, char *str, char f);
char			*int_precision_processing(t_all *all, char *str, int *len);
char			*int_w_mz_processing(t_all *all, char *str, int len);
char			*flags_ps_or_signs(t_all *all, char *str, int len);
char			*intu82_p_processing(t_all *all, char *str, int *len);
char			*intu82_w_mz_processing(t_all *all, char *str, int len);
char			*int8_h_processing(t_all *all, char *str, int *len);
char			*int16x_h_processing(t_all *all, char *str, int *len);
char			*int16_p_processing(t_all *all, char *str, int *len);
char			*int16_w_mz_processing(t_all *all, char *str, int len);
void			do_lower(char *str);
#endif
