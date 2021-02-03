/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-eyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:08:23 by mvan-eyn          #+#    #+#             */
/*   Updated: 2019/10/07 15:08:26 by mvan-eyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int		i;
	unsigned char		*sone;
	unsigned char		*stwo;

	sone = (unsigned char *)s1;
	stwo = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (sone[i] != stwo[i])
			return (sone[i] - stwo[i]);
		i++;
	}
	return (0);
}
