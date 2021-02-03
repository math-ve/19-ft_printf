/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-eyn <mvan-eyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:59:51 by mvan-eyn          #+#    #+#             */
/*   Updated: 2020/01/31 09:37:49 by mvan-eyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_t_struct
{
	int			precision;
	int			is_preci;
	int			width;
	int			is_width;
	char		convert;
	char		zero;
	char		minus;
}				t_st;

int				ft_printf(const char *format, ...);
void			ft_putchar(char c);
void			initialize(t_st *tab);
void			ft_checker_all(const char *format,
				int *i, t_st *tab, va_list args);
char			is_conversion(const char c);
int				is_number(const char *format, int *i);
void			ft_check_flag(const char *format,
				int *i, t_st *tab, va_list args);
void			ft_check_number(const char *format, int *i, t_st *tab);
int				parse_format(va_list args, const char *format);
int				ft_dispatch(t_st *tab, va_list args);
char			*ft_mod(t_st *tab);
char			*ft_c(t_st *tab, va_list args);
char			*ft_d(t_st *tab, va_list args);
char			*ft_p(t_st *tab, va_list args);
char			*ft_s(t_st *tab, va_list args);
char			*ft_u(t_st *tab, va_list args);
char			*ft_x(t_st *tab, va_list args);
char			*ft_xx(t_st *tab, va_list args);
char			*ft_c(t_st *tab, va_list args);
void			ft_right_c(int width, char c, char *temp);
void			ft_left_c(int width, char c, char *temp);
void			ft_right_s(t_st *tab, char *src, char *dest);
void			ft_left_s(t_st *tab, char *src, char *dest);
void			ft_right_d(t_st *tab, char *src, char *dest, int negative);
void			ft_left_d(t_st *tab, char *src, char *dest);
char			*ft_preci_s(t_st *tab, char *src, char *dest);
char			*ft_preci_d(t_st *tab, char *src, char *dest, int negative);
char			*ft_is_preci_d(t_st *tab, char *src, char *dest, int negative);
char			*ft_no_preci_d(t_st *tab, char *src, int negative);
char			*ft_is_width_s(t_st *tab, char *src, char *dest);
char			*ft_no_width_s(char *src, char *dest);
char			*ft_is_width_d(t_st *tab, char *src, char *dest, int negative);
char			*ft_no_width_d(char *src, char *dest);
char			*ft_is_negative(char *src);
char			*ft_negative(char *src);
int				ft_write(char *str);
int				ft_write_c(char *str, t_st *tab);
char			*ft_itoa_base(unsigned int value, int base);
char			*ft_itoa_base2(unsigned long int value, unsigned int base);
char			*ft_substr(char const *s, int start, int len);
int				ft_atoi(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strlen(const char *s);
char			*ft_itoa(long int n);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);

#endif
