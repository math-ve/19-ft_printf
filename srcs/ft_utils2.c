/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-eyn <mvan-eyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:25:37 by mvan-eyn          #+#    #+#             */
/*   Updated: 2020/02/04 16:14:09 by mvan-eyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

char		*ft_strdup(const char *s1)
{
	unsigned long int	i;
	char				*tab;

	i = 0;
	while (s1[i])
		i++;
	tab = malloc(sizeof(*tab) * (i + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char		*ft_substr(char const *s, int start, int len)
{
	int		i;
	char	*src;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
		len = 0;
	else if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	src = malloc((len + 1) * sizeof(*src));
	if (src == NULL)
		return (NULL);
	while (len > i)
	{
		src[i] = s[start];
		i++;
		start++;
	}
	src[i] = '\0';
	return (src);
}

int			ft_atoi(const char *str)
{
	int					i;
	int					signe;
	unsigned long long	prev;
	unsigned long long	digit;

	i = 0;
	prev = 0;
	digit = 0;
	signe = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\r' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
		signe = (str[i++] == '-') ? -1 : 1;
	while (str[i] > 47 && str[i] < 58)
	{
		digit = digit * 10 + (str[i++] - '0');
		if (digit < prev || digit >= 9223372036854775807)
			return ((signe == -1) ? 0 : -1);
		prev = digit;
	}
	return (digit * signe);
}
