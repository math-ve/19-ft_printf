/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-eyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:34:40 by mvan-eyn          #+#    #+#             */
/*   Updated: 2019/10/08 10:34:42 by mvan-eyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long int n)
{
	long int		len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(long int n)
{
	long int	i;
	size_t		len;
	char		*s;

	i = (long)n;
	if (i == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_intlen(i);
	if (!(s = malloc((len + 1) * sizeof(*s))))
		return (NULL);
	if (i == 0)
		s[len - 1] = 0 + '0';
	if (i < 0)
	{
		s[0] = '-';
		i = -i;
	}
	s[len] = '\0';
	while (i > 0)
	{
		len--;
		s[len] = (i % 10) + '0';
		i /= 10;
	}
	return (s);
}
