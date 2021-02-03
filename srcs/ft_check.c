/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-eyn <mvan-eyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 13:07:50 by mvan-eyn          #+#    #+#             */
/*   Updated: 2020/01/31 08:20:59 by mvan-eyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		is_conversion(const char c)
{
	int		i;
	char	*conversion;

	i = 0;
	conversion = "cspdiuxX%";
	while (conversion[i])
	{
		if (conversion[i] == c)
			return (conversion[i]);
		i++;
	}
	return (0);
}

int			is_flag_zero(const char *format, int *i)
{
	if (format[*i - 1] == '-' || format[*i - 1] == '%')
	{
		(*i)++;
		return (1);
	}
	(*i)++;
	return (0);
}

int			is_number(const char *format, int *i)
{
	int		start;
	int		k;
	char	*temp;

	start = *i;
	k = 0;
	temp = NULL;
	while (format[*i] >= '0' && format[*i] <= '9')
	{
		k++;
		(*i)++;
	}
	temp = ft_substr(format, start, k);
	k = ft_atoi(temp);
	free(temp);
	return (k);
}

void		ft_check_flag(const char *format, int *i, t_st *tab, va_list args)
{
	if (format[*i] == '-')
	{
		(*i)++;
		tab->minus = '-';
	}
	if (format[*i] == '0' && is_flag_zero(format, i) > 0)
		tab->zero = '0';
	if (format[*i] == '.')
		tab->is_preci = 1;
	if (format[*i] == '*')
	{
		if (tab->is_preci == 0)
		{
			tab->width = va_arg(args, int);
			tab->is_width = 1;
			(*i)++;
		}
		else
		{
			tab->precision = va_arg(args, int);
			(*i)++;
		}
	}
}

void		ft_check_number(const char *format, int *i, t_st *tab)
{
	if (format[*i] > '0' && format[*i] <= '9')
	{
		if (tab->is_preci == 0)
		{
			tab->width = is_number(format, i);
			tab->is_width = 1;
		}
		else
			tab->precision = is_number(format, i);
	}
}
