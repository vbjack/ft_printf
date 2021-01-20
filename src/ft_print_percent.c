/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtwitch <mtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:46:00 by andrey            #+#    #+#             */
/*   Updated: 2021/01/18 16:04:32 by mtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

int	ft_print_percent(t_print *s_pr)
{
	int r;

	r = 1;
	if (s_pr->zer_percent == 1)
		s_pr->filling = '0';
	if (s_pr->alignment == 0)
	{
		while (r < s_pr->width)
		{
			ft_putchar_fd(s_pr->filling, 1);
			r++;
		}
		ft_putchar_fd('%', 1);
	}
	else
	{
		ft_putchar_fd('%', 1);
		while (r < s_pr->width)
		{
			ft_putchar_fd(' ', 1);
			r++;
		}
	}
	return (r);
}
