/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minus_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-eyn <mvan-eyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 13:42:53 by mvan-eyn          #+#    #+#             */
/*   Updated: 2020/01/30 15:06:39 by mvan-eyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_left_c(int width, char c, char *temp)
{
	int i;

	i = 0;
	temp[i] = c;
	i++;
	while (i < width)
	{
		temp[i] = ' ';
		i++;
	}
}

void	ft_right_c(int width, char c, char *temp)
{
	int	i;

	i = width;
	temp[--i] = c;
	while (i > 0)
	{
		temp[--i] = ' ';
	}
}

void	ft_left_s(t_st *tab, char *src, char *dest)
{
	int i;

	i = 0;
	if (tab->minus == '-')
	{
		while (src[i])
		{
			dest[i] = src[i];
			i++;
		}
		while (i < tab->width)
			dest[i++] = ' ';
		dest[i] = '\0';
	}
}

void	ft_right_s(t_st *tab, char *src, char *dest)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (i < tab->width - ft_strlen(src))
		dest[i++] = ' ';
	while (src[k])
	{
		dest[i] = src[k];
		k++;
		i++;
	}
	dest[i] = '\0';
}
