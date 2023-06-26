/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kortolan <kortolan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:19:33 by kortolan          #+#    #+#             */
/*   Updated: 2023/06/26 08:29:43 by kortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_fix_args(char **args, char **env)
{
	int	in_quote; 
	int	i;
	
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
	char	*autrement;
	
	if (!arg)
		return (NULL);
	autrement = ft_size(arg, in_quote, env);
	return (autrement);
}

char	*ft_size(char *arg, int	*in_quote, char **env)
{
	int	n;
	int	i;
	char	*new_str;

	n = 0;
	i = 0;
	new_str = ft_strdup("");
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
		{
			new_str = ft_strjoin(new_str, ft_is_dollars(arg, *in_quote, i, env));
			while (!ft_is_space(arg[i + 1]) && !ft_is_quote(arg[i + 1]) && *in_quote != 1)
				i++;
		}
		i++;
	}
	return (new_str);
}

char	*ft_is_dollars(char *arg, int in_quote, int i, char **env)
{
	char	*new_str;
	int	n;

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

	tmp = ft_strdup("");
	if (!arg[i + 1] || ft_is_space(arg[i + 1]) == 1 || ft_is_quote(arg[i + 1]))
		return ("$");
	i++;
	j = 0;
	while (arg[i])
	{
		if (!ft_is_space(arg[i]) && !ft_is_quote(arg[i]))
			tmp = ft_str_add(tmp, arg[i]);
		
		else
			break;
		i++;	
	}
	while (env[j])
	{
		if(strncmp(tmp, env[j], ft_strlen(tmp)) == 0)
		{
			new_str = ft_strdup(ft_size_var(j, n, env));
			return (new_str);
		}
		j++;	
	}
	if (tmp)
		free(tmp);
	return ("");	
}