/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kortolan <kortolan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:58:03 by kallegre          #+#    #+#             */
/*   Updated: 2023/06/29 19:19:40 by kortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pipex(char **argv, t_env **env)
{
	t_vars	va;
	int		i;

	/*if (access(argv[1], F_OK) == -1)
	{
		perror(argv[1]);
		return (1);
	}*/
	va.n = tab_size(argv) - 3;
	va.fd = (int **)malloc(sizeof(int *) * (va.n - 1));
	i = 0;
	while (i < va.n - 1)
	{
		va.fd[i] = (int *)malloc(sizeof(int) * 2);
		if (pipe(va.fd[i]) == -1)
			return (1);
		i++;
	}
	va.pid = (int *)malloc(sizeof(int) * va.n);
	return (exec_cmd(argv, env, va));
}

int	exec_cmd(char *argv[], t_env **env, t_vars va)
{
	char	**envp;

	va.k = 0;
	envp = get_tab_env(*env);
	while (va.k < va.n)
	{
		va.pid[va.k] = fork();
		if (va.pid[va.k] < 0)
			return (1);
		if (va.pid[va.k] == 0)
			cmd(argv, envp, va, env);
		va.k++;
	}
	free_tab(envp);
	close_all(va.n, va.fd);
	free_fd(va.fd, va.n);
	return (check_errors(va.pid, va.n));
}

void	cmd(char **argv, char **env_arr, t_vars va, t_env **env)
{
	int		filein;
	int		fileout;
	char	*path;
	char	**split;

	split = ft_split(argv[va.k + 3], ' ');
	if (is_builtin(split[0]))
	{
		do_builtin(split, env);
		return ;
	}
	path = pathfinder(split[0], env_arr);
	if (va.k == 0 && argv[0][0])
	{
		filein = open(end_ope(argv[0]), O_RDONLY);
		dup2(filein, 0);
	}
	if (va.k != 0)
		dup2(va.fd[va.k - 1][0], 0);
	if (va.k == va.n - 1 && argv[1][0])
	{
		unlink(end_ope(argv[1]));
		fileout = open(end_ope(argv[1]), O_WRONLY | O_CREAT, 0666);
		dup2(fileout, 1);
	}
	if (va.k != va.n - 1)
		dup2(va.fd[va.k][1], 1);
	close_all(va.n, va.fd);
	execve(path, split, env_arr);
	free_tab(split);
	free(path);
}