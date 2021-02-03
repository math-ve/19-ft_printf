/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-eyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:39:32 by mvan-eyn          #+#    #+#             */
/*   Updated: 2019/10/08 12:39:33 by mvan-eyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*n;
	size_t	i;

	i = 0;
	if (!(n = malloc(size * count)))
		return (NULL);
	while (i < (size * count))
	{
		((char*)n)[i] = 0;
		i++;
	}
	return (n);
}
