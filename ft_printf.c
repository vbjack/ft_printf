/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtwitch <mtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 11:25:59 by andrey            #+#    #+#             */
/*   Updated: 2021/01/18 16:09:02 by mtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include "libft/libft.h"

int				ft_return_error(t_print *s_pr)
{
	s_pr->error = -1;
	return (0);
}

static t_print	*ft_fill_struct(void)
{
	t_print	*s_pr;

	if (!(s_pr = (t_print *)malloc(sizeof(t_print))))
		return (NULL);
	s_pr->alignment = 0;
	s_pr->width = 0;
	s_pr->perc = -1;
	s_pr->filling = ' ';
	s_pr->error = 0;
	s_pr->zer_percent = 0;
	return (s_pr);
}

static int		ft_all_string(const char *s, va_list ap, t_print *s_pr, int r)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (!(s_pr = ft_fill_struct()))
				return (i);
			i++;
			r += ft_parce_arg(s_pr, s, ap, &i);
			if (s_pr->error < 0)
				return (++r);
			free(s_pr);
			s_pr = NULL;
		}
		else
		{
			ft_putchar_fd(s[i], 1);
			i++;
			r++;
		}
	}
	return (++r);
}

int				ft_printf(const char *s, ...)
{
	va_list	ap;
	t_print	*s_pr;
	int		r;

	r = -1;
	va_start(ap, s);
	r = ft_all_string(s, ap, s_pr, r);
	if (s_pr)
		free(s_pr);
	va_end(ap);
	return (r);
}
