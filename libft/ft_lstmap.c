/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtwitch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 15:39:17 by mtwitch           #+#    #+#             */
/*   Updated: 2020/11/18 15:55:14 by mtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*buf;
	t_list	*ret;

	if (!(res = ft_lstnew(f(lst->content))))
		return (NULL);
	ret = res;
	lst = lst->next;
	while (lst)
	{
		if (!(buf = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&ret, del);
			return (NULL);
		}
		ft_lstadd_back(&res, buf);
		lst = lst->next;
	}
	return (ret);
}
