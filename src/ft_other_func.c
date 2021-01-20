/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtwitch <mtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 14:37:28 by mtwitch           #+#    #+#             */
/*   Updated: 2021/01/17 19:02:09 by mtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

int					ft_power_ten(int l)
{
	int	res;

	if (l >= 0)
		res = 1;
	else
		res = 0;
	while (l > 0)
	{
		res *= 10;
		l--;
	}
	return (res);
}

int					ft_free_strs(char *str1, char *str2, t_print *s_pr)
{
	if (str1)
		free(str1);
	if (str2)
		free(str2);
	s_pr->error = -1;
	return (0);
}

int					ft_put_free_str(char *str)
{
	int	len;

	len = 0;
	if (str)
	{
		len = ft_strlen(str);
		ft_putstr_fd(str, 1);
		free(str);
	}
	return (len);
}

static unsigned int	ft_countdigits(unsigned int n)
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

char				*ft_itoa_unsigned(unsigned int n)
{
	char			*res;
	unsigned int	k;

	k = ft_countdigits(n);
	if (!(res = (char *)malloc(sizeof(char) * (k + 1))))
		return (NULL);
	res[k] = '\0';
	if (n == 0)
	{
		res[0] = '0';
		return (res);
	}
	while (k-- > 0)
	{
		res[k] = (n % 10) + '0';
		n /= 10;
	}
	return (res);
}
