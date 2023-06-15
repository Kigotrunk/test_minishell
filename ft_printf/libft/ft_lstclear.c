/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallegre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:23:10 by kallegre          #+#    #+#             */
/*   Updated: 2022/12/03 14:41:19 by kallegre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*end;
	t_list	*a_lst;
	t_list	*n_lst;

	a_lst = *lst;
	end = ft_lstlast(a_lst);
	while (a_lst != end)
	{
		n_lst = a_lst->next;
		ft_lstdelone(a_lst, del);
		a_lst = n_lst;
	}
	ft_lstdelone(a_lst, del);
	*lst = NULL;
}
