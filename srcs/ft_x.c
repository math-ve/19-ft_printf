/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-eyn <mvan-eyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:18:26 by mvan-eyn          #+#    #+#             */
/*   Updated: 2020/01/30 15:07:44 by mvan-eyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_x(t_st *tab, va_list args)
{
	char	*nbr;
	int		is_negative;
	char	*temp;

	temp = NULL;
	is_negative = 0;
	nbr = ft_itoa_base(va_arg(args, int), 16);
	if (tab->is_preci == 1 && tab->precision == 0 &&
	ft_strncmp(nbr, "0", ft_strlen(nbr)) != 0)
		tab->precision = 1;
	if ((ft_strncmp(nbr, "0", ft_strlen(nbr)) == 0) &&
	tab->is_preci == 1 && tab->precision < 1)
		nbr = "";
	if ((tab->is_preci == 1) && (tab->precision > ft_strlen(nbr)))
		return (ft_is_preci_d(tab, temp, nbr, is_negative));
	else
		return (ft_no_preci_d(tab, nbr, is_negative));
	return (nbr);
}
