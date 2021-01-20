/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtwitch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 10:50:25 by mtwitch           #+#    #+#             */
/*   Updated: 2020/11/03 14:40:41 by mtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	i;

	i = 0;
	while (dstsize > 1)
	{
		if (!src[i])
			break ;
		dst[i] = src[i];
		i++;
		dstsize--;
	}
	if (dst[i] != '\0' && dstsize != 0)
		dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}
