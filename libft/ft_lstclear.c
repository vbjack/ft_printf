/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtwitch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 15:17:41 by mtwitch           #+#    #+#             */
/*   Updated: 2020/11/18 15:55:28 by mtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*buf;

	buf = *lst;
	while (*lst)
	{
		buf = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		*lst = buf;
	}
}
