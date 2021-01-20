/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtwitch <mtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:46:10 by andrey            #+#    #+#             */
/*   Updated: 2021/01/17 19:10:13 by mtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

int	ft_print_u(t_print *s_pr, va_list ap)
{
	unsigned int	nb;
	char			*str;
	int				len;

	nb = va_arg(ap, unsigned int);
	if (!(str = ft_itoa_unsigned(nb)))
		return (ft_return_error(s_pr));
	len = ft_strlen(str);
	if (*str == '0' && str[1] == '\0' && s_pr->perc == 0)
		*str = '\0';
	else if (s_pr->perc > len)
		if (!(str = ft_ins_sep_l(str, s_pr->perc - len, '0')))
			return (ft_return_error(s_pr));
	len = ft_strlen(str);
	if (s_pr->width > len)
	{
		if (s_pr->alignment == 0)
			str = ft_ins_sep_l(str, s_pr->width - len, s_pr->filling);
		else
			str = ft_ins_sep_r(str, s_pr->width - len, s_pr->filling);
	}
	if (!str)
		return (ft_return_error(s_pr));
	return (ft_put_free_str(str));
}
