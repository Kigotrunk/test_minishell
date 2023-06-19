/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallegre <kallegre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:58:39 by kallegre          #+#    #+#             */
/*   Updated: 2023/06/19 13:59:20 by kallegre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    free_tab(char **tab)
{
        int     i;

        i = 0;
        if (tab == NULL)
            return ;
        while (tab[i])
        {
                free(tab[i]);
                tab[i] = NULL;
                i++;
        }
        free(tab);
}

void    print_tab(char **argv)
{
    int i;

    i = 0;
    while (argv[i])
    {
        ft_printf("%s\n", argv[i]);
        i++;
    }
}