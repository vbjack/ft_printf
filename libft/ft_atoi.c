/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtwitch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:21:44 by mtwitch           #+#    #+#             */
/*   Updated: 2020/11/10 12:01:55 by mtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' ||
			c == '\r' || c == '\f' || c == '\v')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int		m;
	long	res;

	while (ft_isspace(*str))
		str++;
	m = ((*str == '-') ? (-1) : 1);
	if (*str == '-' || *str == '+')
		str++;
	res = 0;
	while (ft_isdigit(*str))
	{
		if ((res == LONG_MAX / 10 && (*str - '0' > 7 && m == 1)) ||
				res > LONG_MAX / 10)
		{
			return (-1);
		}
		else if ((res == LONG_MIN / 10 && (*str - '0' > 8 && m == -1)) ||
				res < LONG_MIN / 10)
		{
			return (0);
		}
		res = res * 10 + m * (*str - '0');
		str++;
	}
	return (res);
}
