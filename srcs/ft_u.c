/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-eyn <mvan-eyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 13:57:57 by mvan-eyn          #+#    #+#             */
/*   Updated: 2020/02/04 14:35:05 by mvan-eyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_u(t_st *tab, va_list args)
{
	char	*nbr;
	char	*temp;
	int		is_negative;

	temp = NULL;
	is_negative = 0;
	nbr = ft_itoa(va_arg(args, unsigned int));
	if (tab->is_preci == 1 && tab->precision == 0 &&
	ft_strncmp(nbr, "0", ft_strlen(nbr)) != 0)
		tab->precision = 1;
	if (nbr[0] == '-')
	{
		nbr = ft_is_negative(nbr);
		is_negative = 1;
	}
	if ((ft_strncmp(nbr, "0", ft_strlen(nbr)) == 0) &&
	tab->is_preci == 1 && tab->precision < 1)
		nbr = "";
	if ((tab->is_preci == 1) && (tab->precision > ft_strlen(nbr)))
		return (ft_is_preci_d(tab, temp, nbr, is_negative));
	else
		return (ft_no_preci_d(tab, nbr, is_negative));
}
