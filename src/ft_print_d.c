/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtwitch <mtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:34:18 by andrey            #+#    #+#             */
/*   Updated: 2021/01/18 17:38:22 by mtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

static char	*ft_insert_c(int l, char c)
{
	char	*buf;
	char	*tmp;
	char	*c1;

	if (!(c1 = (char *)ft_calloc(2, sizeof(char))))
		return (NULL);
	*c1 = c;
	if (!(tmp = ft_calloc(1, sizeof(char))))
		return (NULL);
	while (l > 0)
	{
		if (!(buf = ft_strjoin(tmp, c1)))
		{
			free(tmp);
			free(c1);
			return (NULL);
		}
		free(tmp);
		tmp = buf;
		l--;
	}
	free(c1);
	return (tmp);
}

static char	*ft_fill_perc(char *str, int len, int perc)
{
	int		i;
	char	*str_perc;
	char	*buf;

	i = 0;
	if (str[i] == '-')
		i++;
	if (!(str_perc = ft_insert_c(perc - len + i, '0')))
		return (NULL);
	buf = ft_strjoin(str_perc, &str[i]);
	free(str_perc);
	free(str);
	if (!buf)
		return (NULL);
	str_perc = buf;
	if (i > 0)
	{
		if (!(buf = ft_strjoin("-", str_perc)))
			return (NULL);
		free(str_perc);
		str_perc = buf;
	}
	return (str_perc);
}

static char	*ft_fill_right(char *str, int len, int width)
{
	char	*buf;

	while (len < width)
	{
		if (!(buf = ft_strjoin(str, " ")))
			return (NULL);
		free(str);
		str = buf;
		width--;
	}
	return (str);
}

static char	*ft_fill_left(char *str, int len, t_print *s_pr)
{
	int		i;
	char	*str_perc;
	char	*buf;

	i = 0;
	if (str[i] == '-' && s_pr->perc == -1)
		i++;
	if (s_pr->perc > 0)
		str_perc = ft_insert_c(s_pr->width - len, ' ');
	else
		str_perc = ft_insert_c(s_pr->width - len, s_pr->filling);
	if (!str_perc || !(buf = ft_strjoin(str_perc, &str[i])))
		return (NULL);
	free(str_perc);
	str_perc = buf;
	free(str);
	if (i > 0)
	{
		if (!(buf = ft_strjoin("-", str_perc)))
			return (NULL);
		free(str_perc);
		str_perc = buf;
	}
	return (str_perc);
}

int			ft_print_d(t_print *s_pr, va_list ap)
{
	int		r;
	char	*str;

	str = ft_itoa(va_arg(ap, int));
	if (*str == '0' && str[1] == '\0' && s_pr->perc == 0)
		*str = '\0';
	else if (s_pr->perc >= (int)ft_strlen(str))
		if (!(str = ft_fill_perc(str, ft_strlen(str), s_pr->perc)))
			return (ft_return_error(s_pr));
	r = ft_strlen(str);
	if (s_pr->width > r)
	{
		if (s_pr->alignment == 0 && s_pr->filling == '0')
			str = ft_fill_left(str, r, s_pr);
		else if (s_pr->alignment == 0 && s_pr->filling == ' ')
			str = ft_ins_sep_l(str, s_pr->width - r, ' ');
		else if (s_pr->alignment == 1)
			str = ft_fill_right(str, r, s_pr->width);
	}
	if (!str)
		return (ft_return_error(s_pr));
	return (ft_put_free_str(str));
}
