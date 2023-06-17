/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kortolan <kortolan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 01:34:54 by marvin            #+#    #+#             */
/*   Updated: 2023/06/17 23:30:50 by kortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_echo(char **argv)
{
	int	i;
	//int	j;
    int option_n;

	i = 1;
    option_n = 0;
	if (!argv[1])
		return ;
    if (argv[1][0] == '-' && argv[1][1] == 'n' && argv[1][2] == '\0')
        option_n = 1;
    if (option_n == 1)
        i++;
	ft_print_echo(argv, i);
    if (option_n == 0)
        printf("\n");
}


void	ft_print_echo(char **argv, int index)
{
	while (argv[index])
    {
        ft_printf("%s ", argv[index]);
        index++;
    }	
}