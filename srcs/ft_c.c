/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-eyn <mvan-eyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 13:31:45 by mvan-eyn          #+#    #+#             */
/*   Updated: 2020/01/30 15:05:56 by mvan-eyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_c(t_st *tab, va_list args)
{
	char	c;
	char	*temp;
	int		i;

	i = 0;
	temp = NULL;
	c = va_arg(args, int);
	if (!(temp = (char*)malloc(sizeof(char*) * tab->width + 1)))
		return (NULL);
	if (tab->width == 0)
		tab->width = 1;
	temp[tab->width] = '\0';
	if (tab->minus == '-')
		ft_left_c(tab->width, c, temp);
	else
		ft_right_c(tab->width, c, temp);
	return (temp);
}
