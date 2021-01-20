/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtwitch <mtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:46:05 by andrey            #+#    #+#             */
/*   Updated: 2021/01/17 19:08:12 by mtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

static char	*ft_cut_str_perc(char *str, int l, int len)
{
	char	*res;
	char	*buf;
	int		i;

	i = len - l;
	if (!(buf = ft_strdup(str)))
		return (NULL);
	buf[i] = '\0';
	res = ft_strdup(buf);
	free(buf);
	if (!res)
		return (NULL);
	return (res);
}

int			ft_print_s(t_print *s_pr, va_list ap)
{
	char	*str;
	char	*res;
	int		len;
	int		r;

	r = 0;
	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (s_pr->perc < len && s_pr->perc >= 0)
		res = ft_cut_str_perc(str, len - s_pr->perc, len);
	else
		res = ft_strdup(str);
	if (!res)
		return (ft_return_error(s_pr));
	len = ft_strlen(res);
	if (s_pr->alignment == 0 && s_pr->width > len)
		res = ft_ins_sep_l(res, s_pr->width - len, ' ');
	else if (s_pr->width > len)
		res = ft_ins_sep_r(res, s_pr->width - len, ' ');
	if (!res)
		return (ft_return_error(s_pr));
	return (ft_put_free_str(res));
}
