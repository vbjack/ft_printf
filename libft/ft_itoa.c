/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtwitch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 12:42:20 by mtwitch           #+#    #+#             */
/*   Updated: 2020/11/12 11:49:15 by mtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countdigits(int n)
{
	int	r;

	r = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		r++;
	}
	return (r);
}

static int	ft_powerten(int k)
{
	int	r;

	r = 1;
	while (k > 1)
	{
		r *= 10;
		k--;
	}
	return (r);
}

static char	*ft_itoa_algoritm(char *res, int n, int p, int m)
{
	while (p != 0)
	{
		*res = (n / (p * m)) + '0';
		n = n % p;
		p /= 10;
		res++;
	}
	return (res);
}

char		*ft_itoa(int n)
{
	char	*res;
	int		m;
	int		k;
	int		p;

	k = ft_countdigits(n);
	m = 0;
	if (n < 0)
		m = -1;
	if (!(res = (char *)malloc(sizeof(char) * (k + (m * -1) + 1))))
		return (NULL);
	p = ft_powerten(k);
	*res = '0';
	res[1] = '\0';
	if (n == 0)
		return (res);
	*res = '-';
	k += (m * -1);
	if (m == (-1))
		res++;
	else
		m = 1;
	res = ft_itoa_algoritm(res, n, p, m);
	*res = '\0';
	return (res - k);
}
