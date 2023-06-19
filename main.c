/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallegre <kallegre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:04:14 by kallegre          #+#    #+#             */
/*   Updated: 2023/06/19 13:21:43 by kallegre         ###   ########.fr       */
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

int quote_check(char *str)
{
    int b;

    b = 0;
    while(*str)
    {
        if (*str == '\"' && b == 0)
            b = 1;
        else if (*str == '\'' && b == 0)
            b = -1;
        else if (*str == '\"' && b == 1)
            b = 0;
        else if (*str == '\'' && b == -1)
            b = 0;
        str++;
    }
    return (b);
}

int is_ope(char *str)
{
    if (*str == '|' || *str == '<' || *str=='>')
        return (1);
    else 
    {
        while (ft_isdigit(*str))
            str++;
        if (*str == '<' || *str == '>')
            return (1);
    }
    return (0);
}

char    *end_ope(char *str)
{
    if (str[0] == '|')
        return (str + 1);
    else if (str[0] == '<' || str[0] == '>')
    {
        if (str[0] == str[1] || str[1] == '|')
            return (str + 2);
        else
            return (str + 1);
    }
    else
        while (ft_isdigit(*str))
            str++;
        return (str + 1);
}

char	*eoa_quote(char *str, char c)
{
    str++;
	while (*str != c && *str != '\0')
		str++;
    if (*str == c)
        str++;
	if (*str != ' ' && *str != '\0' && !is_ope(str))
		str = eoa_str(str);
	return (str);
}

char    *eoa_str(char *str)
{
    while (*str != ' ' && *str != '\'' && *str != '\"' && *str && !is_ope(str))
		str++;
    if (*str == '\'' || *str == '\"')
        str = eoa_quote(str, *str);
    return (str);
}

int	arg_c(char *str)
{
	int	n;

	n = 0;
	while (*str)
	{
		while (*str == ' ')
			str++;
        if (*str == '\n' || *str == '\0')
            return (n);
        else if (is_ope(str))
        {
            n++;
            str = end_ope(str);
        }
		else if (*str == '\"' || *str == '\'')
		{
			n++;
			str = eoa_quote(str, *str);
		}
		else
		{
			n++;
			str = eoa_str(str);
		}
	}
	return (n);
}

int arg_len(char *str)
{
    int     i;

    i = 0;
    if (*str == '\'' || *str == '\"')
        i = eoa_quote(str, *str) - str;
    else if (is_ope(str))
        i = end_ope(str) - str;
    else
        i = eoa_str(str) - str;
    //readline?
    if (str[i - 1] == '\n')
        i--;
    return (i);
}

char	*get_arg(char *str)
{
	int		i;
	int		len;
	char	*arg;

	i = 0;
	len = arg_len(str);
	arg = (char *)malloc((len + 1) * sizeof(char));
	if (arg == NULL)
		return (NULL);
	while (i < len)
	{
		arg[i] = str[i];
		i++;
	}
	arg[i] = '\0';
	return (arg);
}

char	**split_args(char *str)
{
	char	**tab;
	int		ac;
	int		i;

	ac = arg_c(str);
    if (ac == 0)
        return (NULL);
	tab = (char **)malloc((ac + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (*str && i < ac)
	{
		while (*str == ' ')
			str++;
		if(*str == '\"' || *str == '\'')
		{
			tab[i] = get_arg(str);
			str = eoa_quote(str, *str);
			i++;
		}
        else if (is_ope(str))
        {
            tab[i] = get_arg(str);
            str = end_ope(str);
            i++;
        }
		else
		{
			tab[i] = get_arg(str);
			str = eoa_str(str);
			i++;
		}
	}
	tab[i] = NULL;
	return (tab);
}

int main(int argc, char **argv, char **envp)
{
    char *input;
    char **args;
    char **env;

    (void)argc;
    (void)argv;
    env = cpy_env(envp);
    ft_printf("minishell$ ");
    while ((input = get_next_line(0)))
    {
        if (quote_check(input) != 0)
        {
            free(input);
            input = NULL;
            ft_printf("Error\nminishell$ ");
            continue ;
        }
        args = split_args(input);
        //print_tab(args);
        minishell(args, env);
        free(input);
        input = NULL;
        free_tab(args);
        args = NULL;
        ft_printf("minishell$ ");
    }
    free_tab(env);
    env = NULL;
    return (0);
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
    print_tab(argv);

    cmd_tab = get_cmd_tab(argv);
    if (cmd_tab == NULL)
    {
        ft_printf("Format error");
        return (1);
    }
    print_tab(cmd_tab);

    if (is_builtin(argv[0]))
        do_builtin(argv, env);
    //else
        //pipex(argv, env);
    return (0);
}