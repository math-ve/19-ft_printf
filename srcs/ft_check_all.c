/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-eyn <mvan-eyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 08:19:35 by mvan-eyn          #+#    #+#             */
/*   Updated: 2020/01/31 08:20:43 by mvan-eyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_checker_all(const char *format, int *i, t_st *tab, va_list args)
{
	while (is_conversion(format[*i]) == 0 && format[*i])
	{
		ft_check_flag(format, i, tab, args);
		ft_check_number(format, i, tab);
		if (format[*i] == '.')
		{
			(*i)++;
			tab->is_preci = 1;
		}
		if (format[*i] != '-' && format[*i] != '0' && format[*i] != '.' &&
		format[*i] != '*' && (!(format[*i] >= '0' && format[*i] <= '9') &&
		is_conversion(format[*i]) == 0))
			break ;
	}
	tab->convert = is_conversion(format[*i]);
	if (tab->convert != 0)
		(*i)++;
	if (tab->width < 0)
	{
		tab->minus = '-';
		tab->width *= -1;
	}
}
