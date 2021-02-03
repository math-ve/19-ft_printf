/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-eyn <mvan-eyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:17:32 by mvan-eyn          #+#    #+#             */
/*   Updated: 2020/01/30 15:07:40 by mvan-eyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_write(char *str)
{
	int count;

	count = ft_strlen(str);
	write(1, str, ft_strlen(str));
	return (count);
}

int		ft_write_c(char *str, t_st *tab)
{
	int i;

	i = 0;
	while (i < tab->width)
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
