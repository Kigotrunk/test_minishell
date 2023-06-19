/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallegre <kallegre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:01:12 by kallegre          #+#    #+#             */
/*   Updated: 2023/06/19 16:37:16 by kallegre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     syntax_error(char **argv)
{
    int i;

    i = 0;
    if (argv[0][0] == '|')
        return (1);
    while(argv[i + 1])
    {
        if (is_ope(argv[i]) && is_ope(argv[i + 1]))
            return (1);
        i++;
    }
    if (argv[i][0] == '|')
        return (1);
    return (0);
}

int     pipe_count(char **argv)
{
    int n;
    int i;

    n = 0;
    i = 0;
    while (argv[i])
    {
        if (argv[i][0] == '|')
            n++;
        i++;
    }
    return (n);
}

char    **get_cmd_tab(char **argv)
{
    char    **cmd_tab;
    int     i;
    int     k;

    cmd_tab = cmd_tab_init(pipe_count(argv) + 4);
    i = 0;
    k = 3;
    while (argv[i])
    {
        if (argv[i][0] == '|')
            i++;
        else if (is_ope(argv[i]))
        {
            if (!argv[i + 1])
                return (NULL);
            if (argv[i][0] == '<')
                cmd_tab[0] = ft_strjoin(argv[i], argv[i + 1]);
            if (argv[i][0] == '>')
                cmd_tab[1] = ft_strjoin(argv[i], argv[i + 1]);
            if (argv[i][0] == '2' && argv[i][1] == '>')
                cmd_tab[2] = ft_strjoin(argv[i], argv[i + 1]);
            i += 2;
        }
        else
        {
            while (argv[i] && !is_ope(argv[i]))
            {
                if (cmd_tab[k] == NULL)
                    cmd_tab[k] = argv[i];
                else
                    cmd_tab[k] = ft_stradd(cmd_tab[k], argv[i]);
                i++;
            }
            k++;
        }
    }
    cmd_tab[k] = NULL;
    return (cmd_tab);
}

char    **cmd_tab_init(int n)
{
    char    **cmd_tab;
    int     i;

    cmd_tab = (char **)malloc(n * sizeof(char *));
    i = 0;
    while (i < 3)
    {
        cmd_tab[i] = malloc(1);
        cmd_tab[i][0] = '\0';
        i++;
    }
    while(i < n)
    {
        cmd_tab[i] = NULL;
        i++;
    }
    return (cmd_tab);
}

char    *ft_stradd(char *s1, char *s2)
{
    char    *s;
    int     i;

    s = malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
    if (s == NULL)
        return (NULL);
    i = 0;
    while (*s1)
    {
        s[i] = *s1;
        s1++;
        i++;
    }
    s[i] = ' ';
    i++;
    while (*s2)
    {
        s[i] = *s2;
        s2++;
        i++;
    }
    s[i] = '\0';
    return (s);
}