/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtwitch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 10:18:39 by mtwitch           #+#    #+#             */
/*   Updated: 2020/11/06 12:05:15 by mtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	i1;
	size_t	j;

	j = ft_strlen(needle);
	if (j == 0)
		return ((char *)haystack);
	if (j > ft_strlen(haystack) || j > len)
		return (NULL);
	i1 = 0;
	while (haystack[i1] && i1 < len)
	{
		i = 0;
		while (needle[i] && haystack[i1 + i] && i1 + i < len)
		{
			if (needle[i] != haystack[i1 + i])
				break ;
			i++;
		}
		if (i == j)
			return (&((char *)haystack)[i1]);
		i1++;
	}
	return (NULL);
}
