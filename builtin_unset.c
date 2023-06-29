/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallegre <kallegre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:13:04 by kortolan          #+#    #+#             */
/*   Updated: 2023/06/29 18:01:30 by kallegre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_unset(t_env **env, char **argv)
{
	t_env	*previous;
	t_env	*tmp_l;
	int		j;
	char	*tmp;
	
	if(!env)
		return (0);
	tmp_l = *env;
	if (!strncmp(tmp_l->content, tmp, ft_strlen(tmp)))
	while ((*env))
	{
	 	j = 2;
	 	while (argv[j])
	 	{
			tmp = ft_strjoin(argv[j], "=");
	 		if(!strncmp((*env)->content, tmp, ft_strlen(tmp)))
			{
				
			}
	 		j++;
	 	}
		(*env) = (*env)->next;
	}
	free(tmp);
}

void	ft_unset_utils(t_env **env, char	*var, int index)
{
	
}