/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallegre <kallegre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:04:14 by kallegre          #+#    #+#             */
/*   Updated: 2023/06/29 15:38:27 by kallegre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
    char    *input;
    char    **args;
    t_env   *env;

    (void)argc;
    (void)argv;
    cpy_env(&env, envp);
    while ((input = readline("minishell$ ")))
    {
        if (input == NULL)
        {
            free_tab(env);
            exit(1);
        }
        add_history(input); 
        if (quote_check(input) != 0)
        {
            free(input);
            input = NULL;
            ft_printf("Error\n");
            continue ;
        }
        if(input[0] != '\0')
        {
            args = split_args(input);
            args = ft_fix_args(args, &env);
            minishell(args, &env);
            free(input);
            input = NULL;
            free_tab(args);
            args = NULL;
        }
    }
    env = NULL;
    return (0);
}

int    minishell(char **argv, t_env **env)
{
    char **cmd_tab;

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
        ft_printf("Format error");
        return (1);
    }
    print_tab(cmd_tab);
    free_tab(cmd_tab);
    //pipex(cmd_tab, env);
    return (0);
}