/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtwitch <mtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:46:16 by andrey            #+#    #+#             */
/*   Updated: 2021/01/17 19:10:43 by mtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

char		*ft_hex_line(unsigned int nb, char *str, int reg)
{
	unsigned int	tmp;
	char			*sym;
	char			*buf;

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

char		*ft_ins_sep_l(char *str, int len, char c)
{
	char	*buf;
	int		i;
	char	*tmp;

	i = 0;
	if (!(buf = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	buf[len] = '\0';
	while (len > 0)
	{
		buf[i] = c;
		i++;
		len--;
	}
	tmp = str;
	if (!(str = ft_strjoin(buf, str)))
	{
		free(buf);
		if (str)
			free(str);
		str = NULL;
	}
	free(tmp);
	free(buf);
	return (str);
}

char		*ft_ins_sep_r(char *str, int len, char c)
{
	char	*buf;
	int		i;
	char	*tmp;

	i = 0;
	if (!(buf = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	buf[len] = '\0';
	while (len > 0)
	{
		buf[i] = c;
		i++;
		len--;
	}
	tmp = str;
	if (!(str = ft_strjoin(str, buf)))
	{
		free(buf);
		if (str)
			free(str);
		str = NULL;
	}
	free(tmp);
	free(buf);
	return (str);
}

int			ft_print_x(t_print *s_pr, va_list ap)
{
	unsigned int	nb;
	char			*str;
	int				len;

	nb = va_arg(ap, unsigned int);
	if (!(str = (char *)ft_calloc(1, sizeof(char))))
		return (ft_return_error(s_pr));
	if (!(str = ft_hex_line(nb, str, 97)))
		return (ft_free_strs(str, str, s_pr));
	if (s_pr->perc == 0 && *str == '0' && str[1] == '\0')
		*str = '\0';
	if (s_pr->perc > (int)(ft_strlen(str)))
		if (!(str = ft_ins_sep_l(str, s_pr->perc - (int)(ft_strlen(str)), '0')))
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
