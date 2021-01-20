/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtwitch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 11:20:36 by mtwitch           #+#    #+#             */
/*   Updated: 2020/11/12 10:54:57 by mtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	res;
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	j = ft_strlen(src);
	if (dstsize < i)
		res = dstsize + j;
	else
		res = i + j;
	if (dstsize <= i || j == 0)
		return (res);
	dst += i;
	while ((dstsize - i) > 1 && *src)
	{
		*dst = *src;
		i++;
		dst++;
		src++;
	}
	if (*dst != '\0')
		*dst = '\0';
	return (res);
}
