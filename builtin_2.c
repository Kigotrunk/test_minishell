/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 01:35:58 by marvin            #+#    #+#             */
/*   Updated: 2023/06/15 01:35:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    builtin_cd(const char *path)
{
    int i;

    i = chdir(path);
    if (i == -1)
        perror("path");
}

void    builtin_pwd(char **cmd)
{
    char    *pwd;

	(void)cmd;
	if (cmd[1])
	{
		write(1, "too many arguments\n", 19);
		return ;
	}
    	pwd = (char *)malloc(2048 * sizeof(char));
    	pwd = getcwd(pwd, 2048);
    	if (pwd == NULL)
       		perror("path");
    	else
        	printf("%s\n", pwd);
}

void    builtin_env(char **env)
{
	int	x;

	x = 0;
	if (env == NULL)
		perror("env");
	while (env[x])
	{
		printf("%s\n", env[x]);
		x++;
	}
}

void	builtin_unset(char **env, char **argv)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (env[i])
	{
	 	j = 1;
	 	while (argv[j])
	 	{
			tmp = ft_strjoin(argv[j], "=");
	 		if(!strncmp(env[i], argv[j], ft_strlen(tmp)))
	 			env = ft_unset_utils(env, argv[j], i);
	 		j++;
	 	}
	 	i++;
	}
}