/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kortolan <kortolan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:19:33 by kortolan          #+#    #+#             */
/*   Updated: 2023/06/18 00:22:09 by kortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_fix_args(char **args, char **env)
{
	int	in_quote; 
	int	i;
	ft_printf("in_fix_args\n");
	in_quote = 0;
	i = 0;
	while (args[i])
	{
		args[i] = ft_str_replace(args[i], &in_quote, env);
		i++;
	}
	return (args);
}

char	*ft_str_replace(char *arg, int *in_quote, char **env)
{
	char	*new_str;
	
	ft_printf("in_str_replace\n");
	if (!arg)
		return (NULL);
	new_str = ft_size(arg, in_quote, env);
	return (new_str);
}

char	*ft_size(char *arg, int	*in_quote, char **env)
{
	int	n;
	int	i;
	char	*new_str;

	ft_printf("in_ft_size\n");
	n = 0;
	i = 0;
	while (arg[i])
	{
		if (arg[i] != '\'' && arg[i] != '\"' && arg[i] != '$')
			new_str = ft_str_add(new_str, arg[i]);
		else if (arg[i] == '\'' && *in_quote != 2)
			echo_s_quote(in_quote);
		else if (arg[i] == '\'' && *in_quote == 2)
			new_str = ft_str_add(new_str, arg[i]);
		else if (arg[i] == '\"' && *in_quote != 1)
			echo_d_quote(in_quote);
		else if (arg[i] == '\"' && *in_quote == 1)
			new_str = ft_str_add(new_str, arg[i]);
		else if (arg[i] == '$')
			new_str = ft_strjoin(new_str, ft_is_dollars(arg, *in_quote, i, env));
		i++;
	}
	return (new_str);
}

char	*ft_is_dollars(char *arg, int in_quote, int i, char **env)
{
	char	*new_str;
	int	n;

	ft_printf("in_ft_is_dollars\n");
	n = 0;
	if (in_quote != 1)
	{
		new_str = ft_dollars(&n, arg, i, env);
		return (new_str);
	}
	return ("$");
}

char	*ft_dollars(int *n, char *arg, int i, char **env)
{
	char	*tmp;
	char	*new_str;
	int		j;

	ft_printf("in_ft_dollars\n");
	if (!arg[i + 1] || ft_is_space(arg[i + 1]) == 1)
		return ("$");
	i++;
	j = 0;
	while (arg[i])
	{
		if (!ft_is_space(arg[i]) && !ft_is_quote(arg[i]))
		{
			tmp = ft_str_add(tmp, arg[i]);
			ft_printf("add_PATH\n");
		}
		else
			break;
		i++;	
	}
	ft_printf("test999\n");
		int o = 0;
	while (env[o])
		ft_printf("%s\n", env[o++]);
	while (env[j])
	{
		if(!strncmp(tmp, env[j], ft_strlen(tmp)))
		{
			ft_printf("found_PATH\n");
			new_str = ft_size_var(j, n, env);
			return (new_str);
		}
		j++;	
	}
	ft_printf("end_ft_dollars");
	if (tmp)
		free(tmp);
	return ("");	
}