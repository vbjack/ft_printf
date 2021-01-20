/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtwitch <mtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 11:22:23 by andrey            #+#    #+#             */
/*   Updated: 2021/01/18 16:02:08 by mtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_print
{
	int			alignment;
	char		filling;
	int			width;
	int			perc;
	int			error;
	int			zer_percent;
}				t_print;

int				ft_printf(const char *str, ...);
int				ft_parce_arg(t_print *s_pr, const char *s, va_list ap, int *i);
int				ft_print_c(t_print *s_pr, va_list ap);
int				ft_print_d(t_print *s_pr, va_list ap);
int				ft_print_p(t_print *s_pr, va_list ap);
int				ft_print_x(t_print *s_pr, va_list ap);
int				ft_print_xx(t_print *s_pr, va_list ap);
int				ft_print_u(t_print *s_pr, va_list ap);
int				ft_print_percent(t_print *s_pr);
int				ft_print_s(t_print *s_pr, va_list ap);
char			*ft_ins_sep_l(char *str, int len, char c);
char			*ft_ins_sep_r(char *str, int len, char c);
char			*ft_hex_line(unsigned int nb, char *str, int reg);
int				ft_free_strs(char *str1, char *str2, t_print *s_pr);
int				ft_put_free_str(char *str);
char			*ft_itoa_unsigned(unsigned int n);
int				ft_return_error(t_print *s_pr);
int				ft_power_ten(int l);

#endif
