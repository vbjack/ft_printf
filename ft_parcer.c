/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtwitch <mtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:17:23 by andrey            #+#    #+#             */
/*   Updated: 2021/01/18 16:57:39 by mtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"
#include "./libft/libft.h"

static int	ft_find_width(t_print *s_pr, const char *s, int i, va_list ap)
{
	int	w;

	s_pr->width = 0;
	if (s[i] == '*')
	{
		w = va_arg(ap, int);
		if (w >= 0)
			s_pr->width = w;
		else
		{
			s_pr->width = w * (-1);
			s_pr->alignment = 1;
		}
		i++;
	}
	else
		while (ft_isdigit(s[i]))
		{
			s_pr->width = s_pr->width * 10 + (s[i] - '0');
			i++;
		}
	return (i);
}

static int	ft_find_perc(t_print *s_pr, const char *s, int i, va_list ap)
{
	int	p;

	s_pr->perc = 0;
	s_pr->filling = ' ';
	if (s[i] == '*')
	{
		p = va_arg(ap, int);
		if (p >= 0)
			s_pr->perc = p;
		else
			s_pr->perc = -1;
		i++;
	}
	else
	{
		while (ft_isdigit(s[i]))
		{
			s_pr->perc = s_pr->perc * 10 + (s[i] - '0');
			i++;
		}
	}
	return (i);
}

static int	ft_parce_option(t_print *s_pr, char opt, va_list ap)
{
	int	r;

	r = -1;
	if (opt == 'c')
		r = ft_print_c(s_pr, ap);
	if (opt == 'd' || opt == 'i')
		r = ft_print_d(s_pr, ap);
	if (opt == 'p')
		r = ft_print_p(s_pr, ap);
	if (opt == '%')
		r = ft_print_percent(s_pr);
	if (opt == 's')
		r = ft_print_s(s_pr, ap);
	if (opt == 'u')
		r = ft_print_u(s_pr, ap);
	if (opt == 'x')
		r = ft_print_x(s_pr, ap);
	if (opt == 'X')
		r = ft_print_xx(s_pr, ap);
	if (r < 0)
		s_pr->error = -1;
	return (r);
}

int			ft_parce_arg(t_print *s_pr, const char *s, va_list ap, int *i)
{
	int	r;

	r = 0;
	while (s[*i] == '-' || s[*i] == '0')
	{
		if (s[*i] == '0' && s_pr->alignment == 0)
			s_pr->zer_percent = 1;
		if (s[*i] == '-')
			s_pr->alignment = 1;
		(*i)++;
	}
	*i = ft_find_width(s_pr, s, *i, ap);
	if (s[*i] == '.')
		*i = ft_find_perc(s_pr, s, ++(*i), ap);
	if (s_pr->alignment > 0 || s_pr->perc != (-1))
		s_pr->filling = ' ';
	else if (s_pr->zer_percent == 1)
		s_pr->filling = '0';
	r = ft_parce_option(s_pr, s[*i], ap);
	if (r >= 0)
		(*i)++;
	else
		r++;
	return (r);
}
