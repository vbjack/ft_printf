/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtwitch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 11:52:39 by mtwitch           #+#    #+#             */
/*   Updated: 2020/11/17 17:44:47 by mtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_number_chars(const char *s, char c)
{
	int	res;

	if (ft_strlen(s) == 0)
		return (0);
	res = 0;
	while (*s == c && *s)
		s++;
	while (*s)
	{
		if (*s == c)
		{
			res++;
			while (*s == c)
				s++;
		}
		else
			s++;
	}
	if (*(s - 1) == c)
		res--;
	return (res + 1);
}

static int	ft_fchr(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

static void	ft_freematr(char **res, int count)
{
	count--;
	while (count >= 0)
	{
		free(res[count]);
		count--;
	}
	free(res);
}

char		**ft_split(char const *s, char c)
{
	char	**res;
	int		count;

	if (!(res = (char **)malloc(sizeof(char *) * (ft_number_chars(s, c) + 1))))
		return (NULL);
	count = 0;
	while (*s == c && *s)
		s++;
	while (*s)
	{
		if (!(res[count] = (char *)malloc(sizeof(char) * (ft_fchr(s, c) + 1))))
		{
			ft_freematr(res, count);
			return (NULL);
		}
		ft_strlcpy(res[count], s, ft_fchr(s, c) + 1);
		res[count][ft_fchr(s, c)] = '\0';
		s += ft_fchr(s, c);
		count++;
		while (*s == c && *s)
			s++;
	}
	res[count] = NULL;
	return (res);
}
