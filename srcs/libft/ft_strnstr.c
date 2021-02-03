/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-eyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:33:58 by mvan-eyn          #+#    #+#             */
/*   Updated: 2019/10/08 11:34:00 by mvan-eyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	comp;

	i = 0;
	if (*needle == '\0' || needle == NULL)
		return ((char*)haystack);
	while (haystack[i] && i < len)
	{
		comp = 0;
		while (haystack[i + comp] == needle[comp] && i + comp < len)
		{
			if (needle[comp + 1] == '\0')
				return ((char*)haystack + i);
			comp++;
		}
		i++;
	}
	return (NULL);
}
