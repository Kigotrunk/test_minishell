/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallegre <kallegre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:58:03 by kallegre          #+#    #+#             */
/*   Updated: 2023/06/19 18:29:42 by kallegre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pipex(char **argv, char **envp)
{
	t_vars	va;
	int		i;

	/*if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		return (here_doc(argc, argv, envp));
	if (access(argv[1], F_OK) == -1)
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
	return (exec_cmd(argv, envp, va));
}

int	exec_cmd(char *argv[], char *envp[], t_vars va)
{
	int	i;

	i = 0;
	while (i < va.n)
	{
		va.pid[i] = fork();
		if (va.pid[i] < 0)
			return (1);
		if (va.pid[i] == 0)
			cmd(argv, envp, va, i);
		i++;
	}
	close_all(va.n, va.fd);
	free_fd(va.fd, va.n);
	return (check_errors(va.pid, va.n));
}

void	cmd(char **argv, char **envp, t_vars va, int k)
{
	int		filein;
	int		fileout;
	char	*path;
	char	**split;

	split = ft_split(argv[k + 3], ' ');
	path = pathfinder(split[0], envp);
	if (k == 0 && argv[0][0])
	{
		filein = open(end_ope(argv[0]), O_RDONLY);
		dup2(filein, 0);
	}
	if (k != 0)
		dup2(va.fd[k - 1][0], 0);
	if (k == va.n - 1 && argv[1][0])
	{
		unlink(end_ope(argv[1]));
		fileout = open(end_ope(argv[1]), O_WRONLY | O_CREAT, 0666);
		dup2(fileout, 1);
	}
	if (k != va.n - 1)
		dup2(va.fd[k][1], 1);
	close_all(va.n, va.fd);
	execve(path, split, envp);
	free_tab(split);
	free(path);
}