/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-eyn <mvan-eyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 13:51:42 by mvan-eyn          #+#    #+#             */
/*   Updated: 2020/01/31 09:10:51 by mvan-eyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_norm2(char *src, char *dest, int *i, int *k)
{
	while (src[*k])
		dest[(*i)++] = src[(*k)++];
	dest[*i] = '\0';
}

void	ft_norm3(char *src, char *dest, int *i, t_st *tab)
{
	while (*i < tab->precision - ft_strlen(src))
		dest[(*i)++] = '0';
}

char	*ft_preci_d(t_st *tab, char *src, char *dest, int negative)
{
	int i;
	int k;

	i = 1;
	k = 0;
	if (negative > 0)
	{
		if (!(dest = malloc(sizeof(char*) * tab->precision + 2)))
			return (NULL);
		dest[0] = '-';
		while (i < (tab->precision + 1) - ft_strlen(src))
			dest[i++] = '0';
		ft_norm2(src, dest, &i, &k);
	}
	else if (ft_strncmp(src, "", ft_strlen(src)) != 0)
	{
		i = 0;
		if (!(dest = malloc(sizeof(char*) * tab->precision + 1)))
			return (NULL);
		ft_norm3(src, dest, &i, tab);
		ft_norm2(src, dest, &i, &k);
	}
	else
		dest = src;
	return (dest);
}

char	*ft_is_preci_d(t_st *tab, char *src, char *dest, int negative)
{
	char *ret;

	ret = NULL;
	src = ft_preci_d(tab, dest, src, negative);
	if (tab->convert != 'p')
		free(dest);
	if (tab->width > tab->precision)
		ret = ft_is_width_d(tab, src, ret, negative);
	else
		ret = ft_no_width_d(src, ret);
	free(src);
	if (tab->convert == 'p')
		free(dest);
	return (ret);
}

char	*ft_no_preci_d(t_st *tab, char *src, int negative)
{
	char *ret;

	ret = NULL;
	if (negative == 1)
		src = ft_negative(src);
	if (((tab->width > ft_strlen(src))))
		ret = ft_is_width_d(tab, src, ret, negative);
	else
		ret = ft_no_width_d(src, ret);
	if (tab->convert != '%' && (ft_strncmp(src, "", ft_strlen(src)) != 0))
		free(src);
	return (ret);
}
