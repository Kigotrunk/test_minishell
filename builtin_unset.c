/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallegre <kallegre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:13:04 by kortolan          #+#    #+#             */
/*   Updated: 2023/06/29 18:24:00 by kallegre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*builtin_unset(t_env **env, char **argv)
{
	//t_env	*previous;
	t_env	*tmp_l;
	int		j;
	char	*tmp;
	
	if(!env)
		return(NULL);
	tmp_l = *env;
	tmp = ft_strjoin(argv[1], "=");
	if (!strncmp(tmp_l->str, tmp, ft_strlen(tmp)))
	{
		tmp_l = (*env)->next;
		free(*env);
		return (tmp_l);
	}
	while ((*env))
	{
	 	j = 2;
	 	while (argv[j])
	 	{
			tmp = ft_strjoin(argv[j], "=");
	 		if(!strncmp((*env)->str, tmp, ft_strlen(tmp)))
			{
				
			}
	 		j++;
	 	}
		(*env) = (*env)->next;
	}
	free(tmp);
	return (tmp_l);
}
