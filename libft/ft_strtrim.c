/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtwitch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 17:37:23 by mtwitch           #+#    #+#             */
/*   Updated: 2020/11/12 11:28:30 by mtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nosymbs_begin(const char *s1, const char *set)
{
	size_t	j;
	size_t	i;
	size_t	len;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (j + 1 > ft_strlen(set))
			break ;
		i++;
	}
	if (i == len)
		return (0);
	return (i);
}

static int	ft_nosymbs_end(const char *s1, const char *set)
{
	size_t	i;
	size_t	j;
	size_t	len;

	len = ft_strlen(s1);
	i = len;
	while (i > 0)
	{
		j = 0;
		while (set[j])
		{
			if (s1[i - 1] == set[j])
				break ;
			j++;
		}
		if (j + 1 > ft_strlen(set))
			break ;
		i--;
	}
	return (i);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_nosymbs_begin(s1, set);
	j = ft_nosymbs_end(s1, set);
	res = (char *)malloc(sizeof(char) * (j - i + 1));
	if (!res || ft_strlen(s1) == 0 ||
			(i == 0 && j == ft_strlen(s1) + 1))
		return (res);
	k = 0;
	while (k < (j - i))
	{
		res[k] = s1[i + k];
		k++;
	}
	if (res[k] != '\0')
		res[k] = '\0';
	return (res);
}
