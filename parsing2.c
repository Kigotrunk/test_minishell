/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kortolan <kortolan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 21:45:07 by kortolan          #+#    #+#             */
/*   Updated: 2023/06/17 23:14:47 by kortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_size_var(int j, int *n, char **env)
{
	char	*new_str;
	int	i;
	
	i = 0;
	while (env[j][i] != '=')
		i++;
	while (env[j][i])
	{
		i++;
		new_str = ft_str_add(new_str, env[j][i]);
		*n += 1;
	}
	return (new_str);
}