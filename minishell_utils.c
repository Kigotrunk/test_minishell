/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kortolan <kortolan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:53:46 by kortolan          #+#    #+#             */
/*   Updated: 2023/06/17 21:11:05 by kortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char **ft_unset_utils(char **env, char	*var, int index)
{
	char **new_env;
	int	i;
	int	x;

	i = 0;
	x = 0;
	(void)var;
	while(env[i])
		i++;
	new_env = malloc(i * sizeof(char *));
	i = 0;
	while (env[i])
	{
		if (i != index)
			new_env[x++] = ft_strdup(env[i]);
		i++;
	}
	new_env[x] = NULL;
	//ft_free_tab(env);
	return (new_env);
}

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