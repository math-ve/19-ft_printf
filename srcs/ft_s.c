/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-eyn <mvan-eyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 13:56:15 by mvan-eyn          #+#    #+#             */
/*   Updated: 2020/01/31 08:57:38 by mvan-eyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_is_preci_s(char *temp, char *str, t_st *tab)
{
	temp = ft_preci_s(tab, str, temp);
	if (tab->width > ft_strlen(temp) && tab->is_width == 1)
		str = ft_is_width_s(tab, temp, str);
	else
		str = ft_no_width_s(temp, str);
	free(temp);
	return (str);
}

char	*ft_s(t_st *tab, va_list args)
{
	char *str;
	char *temp;

	temp = NULL;
	str = va_arg(args, char*);
	if (str == NULL)
		str = "(null)";
	if (tab->precision < 0)
		tab->is_preci = 0;
	if ((tab->is_preci == 1) && (tab->precision < ft_strlen(str)))
		return (ft_is_preci_s(temp, str, tab));
	else
	{
		if (tab->width > ft_strlen(str) && tab->is_width == 1)
			temp = ft_is_width_s(tab, str, temp);
		else
			temp = ft_no_width_s(str, temp);
		return (temp);
	}
}
