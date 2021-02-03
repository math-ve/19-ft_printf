/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-eyn <mvan-eyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 13:33:23 by mvan-eyn          #+#    #+#             */
/*   Updated: 2020/01/30 15:06:12 by mvan-eyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ft_is_negative(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	if (!(dest = malloc(sizeof(char*) * ft_strlen(src))))
		return (NULL);
	while (src[i + 1])
	{
		dest[i] = src[i + 1];
		i++;
	}
	dest[i] = '\0';
	free(src);
	return (dest);
}

char		*ft_negative(char *src)
{
	int		i;
	char	*dest;

	i = 1;
	if (!(dest = malloc(sizeof(char*) * ft_strlen(src) + 1)))
		return (NULL);
	dest[0] = '-';
	while (src[i - 1])
	{
		dest[i] = src[i - 1];
		i++;
	}
	dest[i] = '\0';
	free(src);
	return (dest);
}

char		*ft_d(t_st *tab, va_list args)
{
	char	*nbr;
	char	*temp;
	int		is_negative;

	temp = NULL;
	is_negative = 0;
	nbr = ft_itoa(va_arg(args, int));
	if (tab->is_preci == 1 && tab->precision == 0 &&
	ft_strncmp(nbr, "0", ft_strlen(nbr)) != 0)
		tab->precision = 1;
	if (nbr[0] == '-')
	{
		nbr = ft_is_negative(nbr);
		is_negative = 1;
	}
	if ((ft_strncmp(nbr, "0", ft_strlen(nbr)) == 0) &&
	tab->is_preci == 1 && tab->precision == 0)
	{
		free(nbr);
		nbr = "";
	}
	if ((tab->is_preci == 1) && (tab->precision > ft_strlen(nbr)))
		return (ft_is_preci_d(tab, temp, nbr, is_negative));
	else
		return (ft_no_preci_d(tab, nbr, is_negative));
}
