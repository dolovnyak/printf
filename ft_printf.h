/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 14:17:26 by sbecker           #+#    #+#             */
/*   Updated: 2019/03/19 18:50:35 by sschmele         ###   ########.fr       */
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
	char	flag_sign_minus;
	int		width;
	int		precision;
	int		modifier;
	int		type;
	char	*fin_string;
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
void			do_string(t_all *all, va_list *ap, char *str);
void			do_ptype(t_all *all, va_list *ap, char *str);
char			*ft_utoa_base(unsigned long nb, int base);
char			*ft_ltoa_base(long nb, int base);
void			do_percent_or_uchar(t_all *all, va_list *ap, char *str, char f);
char			*int_precision_processing(t_all *all, char *str, int *len);
char			*int_w_mz_processing(t_all *all, char *str, int *len);
char			*flags_ps_or_signs(t_all *all, char *str, int *len);
char			*intu82_p_processing(t_all *all, char *str, int *len);
char			*intu82_w_mz_processing(t_all *all, char *str, int *len);
char			*int8_h_processing(t_all *all, char *str, int *len);
char			*int16x_h_processing(t_all *all, char *str, int *len);
char			*int16_p_processing(t_all *all, char *str, int *len);
char			*int16_w_hmz_processing(t_all *all, char *str, int *len);
char			*int16_w_hm_processing(t_all *all, char *str, int *len);
void			do_lower(char *str);
char			*get_str(va_list *ap, char *str, t_all *all, int base);
void			zero_p(t_all *all, char *str, int *len, int flag);
char			*check_type_and_output(t_all *all, va_list *ap, char *s);
char			*merge_strings(char *s1, char *s2, size_t n);
void			do_letter_wzm(t_all *all, va_list *ap, char *str, char s);

#endif
