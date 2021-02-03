/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-eyn <mvan-eyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:19:34 by mvan-eyn          #+#    #+#             */
/*   Updated: 2020/01/30 15:07:49 by mvan-eyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_to_upper(char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		if (src[i] >= 'a' && src[i] <= 'z')
			src[i] -= 32;
		i++;
	}
}

char	*ft_xx(t_st *tab, va_list args)
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
	ft_to_upper(nbr);
	if ((tab->is_preci == 1) && (tab->precision > ft_strlen(nbr)))
		return (ft_is_preci_d(tab, temp, nbr, is_negative));
	else
		return (ft_no_preci_d(tab, nbr, is_negative));
	return (nbr);
}
