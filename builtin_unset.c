/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kortolan <kortolan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:13:04 by kortolan          #+#    #+#             */
/*   Updated: 2023/06/27 17:50:02 by kortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*void	builtin_unset(t_env **env, char **argv)
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
	 		if(!strncmp(env[i], tmp, ft_strlen(tmp)))
			{
	 			ft_unset_utils(env, argv[j], i);
			}
	 		j++;
	 	}
		
	 	i++;
	}
	free(tmp);
}

void	ft_unset_utils(t_env **env, char	*var, int index)
{
	char **new_env;
	int	i;
	int	x;

	i = 0;
	x = 0;
	(void)var;
	ft_printf("in_builtin\n");
	while((env)[i])
		i++;
	new_env = malloc(i * sizeof(char *));
	i = 0;
	while ((env)[i])
	{
		if (i != index)
			new_env[x++] = (env[i]);
		i++;
	}
	new_env[x] = NULL;
	int o = 0;
	while (new_env[o])
		ft_printf("%s\n", new_env[o++]);
	//env = NULL;
	//env = new_env;
	env[0] = "yorifgne";
	//free(env);
}*/