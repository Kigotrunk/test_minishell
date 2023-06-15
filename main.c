/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallegre <kallegre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:04:14 by kallegre          #+#    #+#             */
/*   Updated: 2023/06/15 23:00:36 by kallegre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    free_tab(char **tab)
{
        int     i;

        i = 0;
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

char	*eoa_quote(char *str, char c)
{
    str++;
	while (*str != c && *str != '\0')
		str++;
	while (*str != ' ' && *str != '\0')
		str++;
	return (str);
}

char    *eoa_str(char *str)
{
    while (*str != ' ' && *str != '\'' && *str != '\"' && *str)
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
        if (*str == '\n')
            return (n);
		if (*str == '\"' || *str == '\'')
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
    char    c;

    i = 0;
    if(str[i] != '\'' && str[i] != '\"')
    {
        while (str[i] != ' ' && str[i] != '\'' && str[i] != '\"' && str[i])
            i++;
    }
    if(str[i] == '\'' || str[i] == '\"')
    {
        c = str[i];
        while(str[i] != c && str[i] != '\0')
		    i++;
	    while (str[i] != ' ' && str[i] != '\0')
            i++;
    }
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
    //int i;

    (void)argc;
    (void)argv;
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
        minishell(args, envp);
        /*if (argv)
        {
            i = 0;
            while (argv[i])
            {
                ft_printf("%s\n", argv[i]);
                i++;
            }
        }*/
        free(input);
        input = NULL;
        free_tab(args);
        args = NULL;
        ft_printf("minishell$ ");
    }
    return (0);
}

void    minishell(char **argv, char **envp)
{
    (void)argv;
    (void)envp;
}