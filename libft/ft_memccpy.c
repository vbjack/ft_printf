/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtwitch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 12:45:51 by mtwitch           #+#    #+#             */
/*   Updated: 2020/11/03 12:29:46 by mtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*d;

	ch = (unsigned char)c;
	d = (unsigned char *)dst;
	while (n--)
	{
		*d++ = *(unsigned char *)src++;
		if (*(d - 1) == ch)
			return (d);
	}
	return (NULL);
}
