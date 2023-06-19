/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kortolan <kortolan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:04:14 by kallegre          #+#    #+#             */
/*   Updated: 2023/06/19 18:04:09 by kortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
    char *input;
    char **args;
    char **env;

    (void)argc;
    (void)argv;
    env = cpy_env(envp);
    while ((input = readline("minishell$ ")))
    {
        if (input == NULL)
        {
            exit(1);
        }
        if (quote_check(input) != 0)
        {
            free(input);
            input = NULL;
            ft_printf("Error\nminishell$ ");
            continue ;
        }
        args = split_args(input);
        args = ft_fix_args(args, env);
        print_tab(args);
        minishell(args, env);
        free(input);
        input = NULL;
        free_tab(args);
        args = NULL;
    }
    free_tab(env);
    env = NULL;
    return (0);
}

int    minishell(char **argv, char **env)
{
    char **cmd_tab;

    if (argv == NULL)
        return (0);
    if (syntax_error(argv))
    {
        ft_printf("syntax error\n");
        return (258);
    }
    //print_tab(argv);

    cmd_tab = get_cmd_tab(argv);
    if (cmd_tab == NULL)
    {
        ft_printf("Format error");
        return (1);
    }
    //print_tab(cmd_tab);

    if (is_builtin(argv[0]))
        do_builtin(argv, env);
    //else
        //pipex(argv, env);
    return (0);
}