/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtwitch <mtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:45:43 by andrey            #+#    #+#             */
/*   Updated: 2021/01/18 17:19:33 by mtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

static char	*ft_insert_prefix(char *str, t_print *s_pr)
{
	char	*buf;

	if (!(buf = ft_strjoin("0x", str)))
		return (NULL);
	if (!buf || !str)
	{
		ft_free_strs(buf, str, s_pr);
		return (NULL);
	}
	free(str);
	if (!buf)
		return (NULL);
	return (buf);
}

static char	*ft_hex_point(unsigned long int nb, char *str, int reg)
{
	unsigned long int	tmp;
	char				*sym;
	char				*buf;

	if (!(sym = ft_calloc(2, sizeof(char))))
		return (NULL);
	if (nb == 0)
		str[0] = '0';
	while (nb)
	{
		tmp = nb % 16;
		*sym = ((tmp < 10) ? (tmp + '0') : ((tmp - 10) + reg));
		buf = str;
		if (!(str = ft_strjoin(sym, str)))
		{
			free(str);
			free(sym);
			free(buf);
			return (NULL);
		}
		free(buf);
		nb = nb / 16;
	}
	free(sym);
	return (str);
}

int			ft_print_p(t_print *s_pr, va_list ap)
{
	unsigned long int	nb;
	char				*str;

	nb = va_arg(ap, unsigned long int);
	if (!(str = (char *)ft_calloc(1, sizeof(char))))
		return (ft_return_error(s_pr));
	if (!(str = ft_hex_point(nb, str, 97)))
		return (ft_return_error(s_pr));
	if (nb == 0 && s_pr->perc == 0)
		*str = '\0';
	if (!(str = ft_insert_prefix(str, s_pr)))
		return (ft_return_error(s_pr));
	if (s_pr->width > (int)ft_strlen(str))
	{
		if (s_pr->alignment == 0)
			str = ft_ins_sep_l(str, s_pr->width - (int)ft_strlen(str), ' ');
		else
			str = ft_ins_sep_r(str, s_pr->width - (int)ft_strlen(str), ' ');
	}
	if (!str)
		return (ft_return_error(s_pr));
	return (ft_put_free_str(str));
}
