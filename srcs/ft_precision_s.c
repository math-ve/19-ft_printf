/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-eyn <mvan-eyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 09:09:39 by mvan-eyn          #+#    #+#             */
/*   Updated: 2020/01/31 09:09:56 by mvan-eyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_preci_s(t_st *tab, char *src, char *dest)
{
	int i;

	i = 0;
	if (!(dest = malloc(sizeof(char*) * tab->precision + 1)))
		return (NULL);
	while (i < tab->precision)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
