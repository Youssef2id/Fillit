/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 00:39:26 by yidabdes          #+#    #+#             */
/*   Updated: 2018/12/06 22:07:39 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*newlst;
	t_list		*list;

	if (!lst || !f)
		return (NULL);
	list = f(lst);
	newlst = list;
	while (lst->next)
	{
		lst = lst->next;
		list->next = f(lst);
		if (!(list->next))
			return (NULL);
		list = list->next;
	}
	return (newlst);
}
