/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallegre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:47:04 by kallegre          #+#    #+#             */
/*   Updated: 2022/12/05 18:26:24 by kallegre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*a_lst;

	if (!lst || !f)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	a_lst = new;
	while (lst->next)
	{
		lst = lst->next;
		ft_lstadd_back(&new, ft_lstnew(f(lst->content)));
		a_lst = a_lst->next;
		if (a_lst->content == NULL)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
	}
	return (new);
}
