/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-eyn <mvan-eyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 13:27:21 by mvan-eyn          #+#    #+#             */
/*   Updated: 2020/01/31 08:42:11 by mvan-eyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_dispatch_c(char *str, t_st *tab, va_list args)
{
	int count;

	count = 0;
	str = ft_c(tab, args);
	count = ft_write_c(str, tab);
	free(str);
	return (count);
}

int		ft_dipatch_s(char *str, t_st *tab, va_list args)
{
	int count;

	count = 0;
	str = ft_s(tab, args);
	if (ft_strncmp(str, " ", ft_strlen(str)) != 0 ||
	(ft_strncmp(str, " ", ft_strlen(str)) == 0 && tab->width == 1))
		count = ft_write(str);
	free(str);
	return (count);
}

int		ft_dispatch(t_st *tab, va_list args)
{
	char	*str;
	int		count;

	count = 0;
	str = NULL;
	if (tab->convert == 'c')
		return (ft_dispatch_c(str, tab, args));
	if (tab->convert == 's')
		return (ft_dipatch_s(str, tab, args));
	if (tab->convert == 'p')
		str = ft_p(tab, args);
	if (tab->convert == 'd' || tab->convert == 'i')
		str = ft_d(tab, args);
	if (tab->convert == 'u')
		str = ft_u(tab, args);
	if (tab->convert == 'x')
		str = ft_x(tab, args);
	if (tab->convert == 'X')
		str = ft_xx(tab, args);
	if (tab->convert == '%')
		str = ft_mod(tab);
	count = ft_write(str);
	free(str);
	return (count);
}
