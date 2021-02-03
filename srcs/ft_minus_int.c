/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minus_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-eyn <mvan-eyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 13:45:22 by mvan-eyn          #+#    #+#             */
/*   Updated: 2020/01/31 08:54:32 by mvan-eyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_left_d(t_st *tab, char *src, char *dest)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < tab->width)
		dest[i++] = ' ';
	dest[i] = '\0';
}

void	ft_norm(int *i, int *k, char *src, char *dest)
{
	dest[*i] = src[*k];
	(*i)++;
	(*k)++;
}

void	ft_right_d(t_st *tab, char *src, char *dest, int negative)
{
	int i;
	int k;

	i = 0;
	k = 0;
	if ((tab->zero == '0' && tab->is_preci == 0) || (tab->convert == '%' &&
	tab->zero == '0') || (tab->zero == '0' && tab->precision < 0))
	{
		if (negative == 1 && tab->zero == '0')
		{
			while (i < tab->width - ft_strlen(src) + 1)
				dest[i++] = '0';
			dest[0] = '-';
			k++;
		}
		else
			while (i < tab->width - ft_strlen(src))
				dest[i++] = '0';
	}
	else
		while (i < tab->width - ft_strlen(src) && tab->is_width == 1)
			dest[i++] = ' ';
	while (src[k])
		ft_norm(&i, &k, src, dest);
	dest[i] = '\0';
}
