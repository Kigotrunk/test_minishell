/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kortolan <kortolan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:30:05 by kortolan          #+#    #+#             */
/*   Updated: 2023/07/03 16:30:05 by kortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    builtin_cd(char **argv, t_env **env)
{
    char    *path;
    char    *pwd;
    if(!env)
        return ;
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
    pwd = (char *)malloc(2048 * sizeof(char));
    pwd = getcwd(pwd, 2048);
}