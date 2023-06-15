/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallegre <kallegre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:58:04 by kortolan          #+#    #+#             */
/*   Updated: 2023/06/15 23:23:50 by kallegre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line_bonus.h"

void    free_tab(char **tab);
int     quote_check(char *str);
int	    arg_c(char *str);
char	*eoa_quote(char *str, char c);
char    *eoa_str(char *str);
int     arg_len(char *str);
char	*get_arg(char *str);
char	**split_args(char *str);
void    minishell(char **argv, char **envp);

//is_builtin && called ft_builtins
int     is_builtin(char *cmd);
void    do_builtin(char **cmd, char **env);

//ft_builtin
void    builtin_cd(const char *path);
void    builtin_pwd(char **cmd);
void    builtin_env(char **envp);
void	builtin_unset(char **env, char **argv);
void	builtin_echo();

//ft_utils
char    **cpy_env(char **envp);
char	**ft_unset_utils(char **env, char	*var, int index);
int		ft_strlen_env(char *env);
void	ft_free_tab(char **tab);

#endif
