/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-eyn <mvan-eyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:03:17 by mvan-eyn          #+#    #+#             */
/*   Updated: 2020/02/04 15:54:04 by mvan-eyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*src1;
	unsigned char	*src2;

	i = 0;
	src1 = (unsigned char *)s1;
	src2 = (unsigned char *)s2;
	if (((!s1) || (!s2)) && n == 0)
		return (0);
	while (src1[i] && src2[i] && i < n)
	{
		if (src1[i] != src2[i])
			return (src1[i] - src2[i]);
		i++;
	}
	if (i < n && ((src1[i] == '\0' && src2[i] != '\0') ||
				(src2[i] == '\0' && src1[i] != '\0')))
		return (src1[i] - src2[i]);
	return (0);
}

int			ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		i++;
	}
	return (i);
}

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*source;

	dest = (unsigned char*)dst;
	source = (unsigned char*)src;
	if (!n || dst == src)
		return (dst);
	i = 0;
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return (dst);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(str = (char*)malloc((len_s1 + len_s2 + 1) * sizeof(char))))
		return (NULL);
	ft_memcpy(str, s1, len_s1);
	ft_memcpy(str + len_s1, s2, len_s2);
	str[len_s1 + len_s2] = '\0';
	return (str);
}
