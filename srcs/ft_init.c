/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-eyn <mvan-eyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 13:07:15 by mvan-eyn          #+#    #+#             */
/*   Updated: 2020/01/30 15:06:26 by mvan-eyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	initialize(t_st *tab)
{
	tab->precision = 0;
	tab->is_preci = 0;
	tab->width = 1;
	tab->is_width = 0;
	tab->convert = 0;
	tab->zero = 1;
	tab->minus = 0;
}
