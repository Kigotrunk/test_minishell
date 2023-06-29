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

void   cpy_env(t_list **env, char **envp)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (envp[j])
        j++;
    while (i < j)
    {
        *env = lstnew(envp[i], *env);
        i++;
    }
    if (!env)
    {
        perror("malloc env : ");
        exit(-1);
    }
    return ;
}