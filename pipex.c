/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kortolan <kortolan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:58:03 by kallegre          #+#    #+#             */
/*   Updated: 2023/07/03 12:28:42 by kortolan         ###   ########.fr       */
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
	va.envp = get_tab_env(*env);
	va.argv = argv;
	//va.io_lst = io_list;
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
	return (exec_cmd(env, va));
}

int	exec_cmd(t_env **env, t_vars va)
{
	int		i;

	i = 0;
	while (i < va.n)
	{
		va.pid[i] = fork();
		if (va.pid[i] < 0)
			return (1);
		if (va.pid[i] == 0)
			cmd(env, va, i);
		i++;
	}
	close_all(va.n, va.fd);
	free_fd(va.fd, va.n);
	return (check_errors(va.pid, va.n));
}

void	cmd(t_env **env, t_vars va, int k)
{
	int		filein;
	int		fileout;
	char	*path;
	char	**split;

	split = ft_split(va.argv[k + 3], ' ');
	if (is_builtin(split[0]))
	{
		do_builtin(ft_split(va.argv[k + 3], ' '), env, va.envp);
		return ;
	}
	path = pathfinder(split[0], va.envp);
	if (k == 0 && va.argv[0][0])
	{
		filein = open(end_ope(va.argv[0]), O_RDONLY);
		dup2(filein, 0);
	}
	if (k != 0)
		dup2(va.fd[k - 1][0], 0);
	if (k == va.n - 1 && va.argv[1][0])
	{
		unlink(end_ope(va.argv[1]));
		fileout = open(end_ope(va.argv[1]), O_WRONLY | O_CREAT, 0666);
		dup2(fileout, 1);
	}
	if (k != va.n - 1)
		dup2(va.fd[k][1], 1);
	close_all(va.n, va.fd);
	execve(path, split, va.envp);
	free_tab(split);
	free(path);
}