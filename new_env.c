/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 01:24:42 by marvin            #+#    #+#             */
/*   Updated: 2023/06/15 01:24:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list   *cpy_env(char **envp)
{
    t_list   *new_env;
    int     i;

    i = 0;
    new_env = ft_lstnew(envp[i]);
    while (envp[i])
    {
        ft_lstadd_back(&new_env, envp[i]);
        i++;
    }
    return (new_env);
}
/*
t_env  *ft_envnew(void *content)
{
        t_env  *new;

        new = malloc(sizeof(t_env));
        if (new == NULL)
                return (NULL);
        new->content = content;
        new->next = NULL;
        return (new);
}*/