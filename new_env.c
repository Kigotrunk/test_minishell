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

t_env   **cpy_env(t_env **env, char **envp)
{
    t_env   **cpy;
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (envp[j])
        j++;
    while (i < j)
    {
        *cpy = lstnew(env[i], *cpy);
        i++;
    }
    if (!cpy)
    {
        perror("malloc env : ");
        exit(-1);
    }
}