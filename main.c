/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kortolan <kortolan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:04:14 by kallegre          #+#    #+#             */
/*   Updated: 2023/07/03 19:24:02 by kortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int err_code = 0;

int main(int argc, char **argv, char **envp)
{
    char    *input;
    char    **args;
    t_env   *env;

    (void)argc;
    (void)argv;
    signal(SIGINT, ft_sig);
    signal(SIGQUIT, ft_sig)
    env = cpy_env(envp);
    while ((input = readline("minishell$ ")))
    {
        if (input == NULL)
            exit(1);
        add_history(input);
        if (quote_check(input) != 0)
        {
            free(input);
            input = NULL;
            ft_printf("Error\n");
            continue ;
        }
        args = split_args(input);
        minishell(args, &env);
        free(input);
        input = NULL;
        free_tab(args);
        args = NULL;
    }
    ft_lstclear(&env, &free);
    env = NULL;
    //system("leaks minishell");
    return (0);
}

int    minishell(char **argv, t_env **env)
{
    char ***cmd_tab;
    char **io_tab;

    if (argv == NULL)
        return (0);
    if (syntax_error(argv))
    {
        ft_printf("Syntax error\n");
        return (258);
    }
    cmd_tab = get_cmd_tab(argv);
    if (cmd_tab == NULL)
    {
        ft_printf("Format error\n");
        return (1);
    }
    cmd_tab = ft_fix_args(cmd_tab, env); //leak
    io_tab = get_io(argv);
    pipex(cmd_tab, io_tab, env);
    free_tab_tab(cmd_tab);
    free_tab(io_tab);
    return (0);
}