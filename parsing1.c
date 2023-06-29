/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kortolan <kortolan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:19:33 by kortolan          #+#    #+#             */
/*   Updated: 2023/06/29 16:06:58 by kortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_fix_args(char **args, t_env **env)
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

char	*ft_str_replace(char *arg, int *in_quote, t_env **env)
{
	char	*other;
	
	if (!arg)
		return (NULL);
	other = ft_size(arg, in_quote, env);
	return (other);
}

char	*ft_size(char *arg, int	*in_quote, t_env **env)
{
	int	n;
	int	i;
	char	*new_str;
	if(!*env)
		return NULL;

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

char	*ft_is_dollars(char *arg, int in_quote, int i, t_env **env)
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

char	*ft_dollars(int *n, char *arg, int i, t_env **env)
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
	while ((*env)->str)
	{
		if(strncmp(tmp, (*env)->str, ft_strlen(tmp)) == 0)
		{
			new_str = ft_strdup(ft_size_var(n, env));
			return (new_str);
		}
		*env = (*env)->next;
	}
	if (tmp)
		free(tmp);
	return ("");	
}

char	*ft_size_var(int *n, t_env **env)
{
	char	*new_str;
	int	i;

	new_str = ft_strdup("");
	i = 0;
	while ((*env)->str[i] != '=')
		i++;
	while ((*env)->str[i])
	{
		i++;
		new_str = ft_str_add(new_str, (*env)->str[i]);
		*n += 1;
	}
	return (new_str);
}