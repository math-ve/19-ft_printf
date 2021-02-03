/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-eyn <mvan-eyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 13:50:10 by mvan-eyn          #+#    #+#             */
/*   Updated: 2020/02/04 16:13:57 by mvan-eyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_p(t_st *tab, va_list args)
{
	char	*nbr;
	int		is_negative;
	char	*temp;

	is_negative = 0;
	temp = NULL;
	temp = ft_itoa_base2(va_arg(args, long int), 16);
	if (tab->is_preci == 1 && tab->precision == 0)
		tab->precision = 1;
	if ((ft_strncmp(temp, "0", ft_strlen(temp) != 0) && tab->precision == 0)
	|| tab->is_preci == 0)
		nbr = ft_strjoin("0x", temp);
	else
		nbr = ft_strdup("0x");
	free(temp);
	if ((ft_strncmp(nbr, "0", ft_strlen(nbr)) == 0) &&
	tab->is_preci == 1 && tab->precision <= 1)
		nbr = "";
	if ((tab->is_preci == 1) && (tab->precision > ft_strlen(nbr)))
		return (ft_is_preci_d(tab, temp, nbr, is_negative));
	else
		return (ft_no_preci_d(tab, nbr, is_negative));
	return (nbr);
}
