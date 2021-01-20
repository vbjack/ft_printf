/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtwitch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:23:08 by mtwitch           #+#    #+#             */
/*   Updated: 2020/11/12 11:52:11 by mtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_powerten(int n)
{
	int	r;

	r = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		r *= 10;
	}
	return (r);
}

void		ft_putnbr_fd(int n, int fd)
{
	int		p;
	int		m;
	char	c;

	m = 1;
	if (n < 0)
	{
		m = -1;
		write(fd, "-", 1);
	}
	p = ft_powerten(n);
	while (p != 0)
	{
		c = n / (p * m) + '0';
		write(fd, &c, 1);
		n = n % p;
		p /= 10;
	}
}
