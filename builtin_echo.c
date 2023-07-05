/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kortolan <kortolan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 01:34:54 by marvin            #+#    #+#             */
/*   Updated: 2023/07/03 18:20:01 by kortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_echo(char **argv)
{
	int	i;
	//int	j;

	i = 1;
	if (!argv[1])
		return ;
	ft_print_echo(argv, i);
	if (!n_option(argv[1]))
		ft_printf("%c", '\n');
}


void	ft_print_echo(char **argv, int index)
{
	while (argv[index])
    {
        ft_printf("%s ", argv[index]);
        index++;
    }	
}

int	n_option(char *arg)
{
	int	i;

	i = 1;
	if(arg[0] != '-')
		return (0);
	while(arg[i])
	{
		if(arg[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}