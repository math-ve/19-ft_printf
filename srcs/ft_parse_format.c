/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-eyn <mvan-eyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 13:04:28 by mvan-eyn          #+#    #+#             */
/*   Updated: 2020/02/04 09:08:03 by mvan-eyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		parse_format(va_list args, const char *format)
{
	int			i;
	int			count;
	t_st		tab;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			initialize(&tab);
			ft_checker_all(format, &i, &tab, args);
			count += ft_dispatch(&tab, args);
		}
		else
			while (format[i] && format[i] != '%')
			{
				ft_putchar(format[i]);
				i++;
				count += 1;
			}
	}
	return (count);
}
