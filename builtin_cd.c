/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 00:23:47 by marvin            #+#    #+#             */
/*   Updated: 2023/07/03 00:23:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    builtin_cd(char **argv)
{
    char    *path;

    if (!argv[1])
    {
        ft_printf("cd : need path\n");
        return ;
    }
    path = argv[1];
    if (chdir(path) != 0)
    {
        perror("path");
        return ;
    }
}
