/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kortolan <kortolan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:53:46 by kortolan          #+#    #+#             */
/*   Updated: 2023/06/29 16:11:18 by kortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strlen_env(char *env)
{
	int	i;
	
	i = 0;
	while (env[i] != '=')
		i++;
	return (i - 1);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_putstr_echo(char *str, int i)
{
	int	j;
	
	j = 0;
	while (str[j + i])
	{
		printf("%c", str[j + i]);
		j++;
	}
}

t_env	*lstnew(char *content, t_env *next)
{
	t_env	*lst;

	lst = malloc(sizeof(t_env));
	if (!lst)
		return (NULL);
	lst->str = content;
	lst->next = next;
	return (lst);
}

t_env	*ft_lstlast1(t_env *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}


int	ft_lst_size(t_env *lst)
{
	int	size;

	if (!lst)
		return(0);
	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
