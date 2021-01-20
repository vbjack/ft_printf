/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtwitch <mtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:45:20 by andrey            #+#    #+#             */
/*   Updated: 2021/01/17 19:05:38 by mtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

int	ft_print_c(t_print *s_pr, va_list ap)
{
	int r;

	r = 1;
	if (s_pr->alignment == 0)
	{
		while (r < s_pr->width)
		{
			ft_putchar_fd(' ', 1);
			r++;
		}
		ft_putchar_fd(va_arg(ap, int), 1);
	}
	else
	{
		ft_putchar_fd(va_arg(ap, int), 1);
		while (r < s_pr->width)
		{
			ft_putchar_fd(' ', 1);
			r++;
		}
	}
	return (r);
}
