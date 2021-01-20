/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtwitch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:45:40 by mtwitch           #+#    #+#             */
/*   Updated: 2020/11/03 13:18:21 by mtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s1;
	int		i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	s1 = (char *)s;
	if (*s1 == c)
		return (s1);
	while (i--)
		if (*--s1 == c)
			return (s1);
	return (NULL);
}
