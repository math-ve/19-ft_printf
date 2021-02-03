/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-eyn <mvan-eyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:14:47 by mvan-eyn          #+#    #+#             */
/*   Updated: 2020/01/30 15:07:35 by mvan-eyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_is_width_s(t_st *tab, char *src, char *dest)
{
	int i;

	i = tab->width - ft_strlen(src);
	if (!(dest = malloc(sizeof(char*) * i + tab->width + 1)))
		return (NULL);
	if (tab->minus == '-')
		ft_left_s(tab, src, dest);
	else
		ft_right_s(tab, src, dest);
	return (dest);
}

char	*ft_no_width_s(char *src, char *dest)
{
	int i;

	i = 0;
	if (!(dest = malloc(sizeof(char*) * ft_strlen(src) + 1)))
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	if (src == NULL)
		return (NULL);
	return (dest);
}

char	*ft_is_width_d(t_st *tab, char *src, char *dest, int negative)
{
	if (!(dest = malloc(sizeof(char*) * tab->width + 1)))
		return (NULL);
	if (tab->minus == '-')
		ft_left_d(tab, src, dest);
	else
		ft_right_d(tab, src, dest, negative);
	return (dest);
}

char	*ft_no_width_d(char *src, char *dest)
{
	int i;

	i = 0;
	if (!(dest = malloc(sizeof(char*) * ft_strlen(src) + 1)))
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
