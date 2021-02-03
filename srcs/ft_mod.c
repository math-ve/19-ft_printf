/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-eyn <mvan-eyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 13:47:59 by mvan-eyn          #+#    #+#             */
/*   Updated: 2020/01/30 15:06:52 by mvan-eyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_mod(t_st *tab)
{
	char	*nbr;
	int		is_negative;

	nbr = "%";
	is_negative = 0;
	return (ft_no_preci_d(tab, nbr, is_negative));
}
