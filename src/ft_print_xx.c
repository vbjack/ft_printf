/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtwitch <mtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 18:35:52 by mtwitch           #+#    #+#             */
/*   Updated: 2021/01/17 19:10:57 by mtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

int	ft_print_xx(t_print *s_pr, va_list ap)
{
	int		nb;
	char	*str;
	int		len;

	nb = va_arg(ap, unsigned int);
	if (!(str = (char *)ft_calloc(1, sizeof(char))))
		return (ft_return_error(s_pr));
	if (!(str = ft_hex_line(nb, str, 65)))
		return (ft_free_strs(str, str, s_pr));
	if (s_pr->perc == 0 && *str == '0' && str[1] == '\0')
		*str = '\0';
	if (s_pr->perc > (int)ft_strlen(str))
		if (!(str = ft_ins_sep_l(str, s_pr->perc - (int)ft_strlen(str), '0')))
			return (ft_free_strs(str, str, s_pr));
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
