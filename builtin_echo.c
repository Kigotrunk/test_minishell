/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 01:34:54 by marvin            #+#    #+#             */
/*   Updated: 2023/06/16 01:34:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_echo(char **argv)
{
	int	i;
    int option_n;

	i = 1;
    option_n = 0;
    if (argv[1][0] == '-' && argv[1][1] == 'n' && argv[1][2] == '\0')
        option_n = 1;
    if (option_n == 1)
        i++;
    while (argv[i])
    {
        ft_print_echo(argv, i);
        i++;
    }
    
}

void    ft_print_echo(char **argv, int index)
{
    int first_quote;
    int last_quote;

    first_quote = ft_is_quote(argv[index][0]);
    last_quote = ft_is_quote(argv[index][ft_strlen(argv[index] - 1)]);
    if (first_quote == 1 && last_quote == 1)
        ft_putstr_echo(argv[index] + 1, -1);

}

int ft_is_quote(char *str)
{
    int i;

    i = 0;
    if (str == '\'')
        i = 1;
    if (str == '"')
        i = 2;
    return (i);
}