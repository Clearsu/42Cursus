/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 06:08:36 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/28 09:46:07 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	**pipe_malloc(size_t n)
{
	size_t	i;
	int		**fd_pipe;
	
	fd_pipe = (int **)malloc(sizeof(int *) * n);
	i = 0;
	while (i < n)
	{
		fd_pipe[i++] = (int *)malloc(sizeof(int) * 2);
	}
	return (fd_pipe);
}

void	make_pipe(int **fd_pipe, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		pipe(fd_pipe[i++]);
}

void	put_argv(t_vars *vars, size_t i)
{
	vars->argv[0] = vars->cmd_path[i];
	vars->argv[1] = vars->cmd_flag[i];
	vars->argv[2] = NULL;
}

void	multiple_pipes(t_vars *vars, int **fd_pipe, size_t i)
{
	pid_t	pid;

	pid = fork();
	if (pid > 0)
		return ;	
	if (i == 0)
		dup2(vars->fd_in, 0);
	else
	{
		dup2(fd_pipe[i - 1][0], 0);
		close(fd_pipe[i - 1][1]);
	}
	if (i == vars->cmd_num - 1)
		dup2(vars->fd_out, 1);
	else
	{
		dup2(fd_pipe[i][1], 1);
		close(fd_pipe[i][0]);
	}
	put_argv(vars, i);
	execve(vars->cmd_path[i], vars->argv, vars->envp);
}

void	pipex(t_vars *vars)
{
	int		**fd_pipe;
	size_t	i;

	fd_pipe = pipe_malloc(vars->cmd_num - 1);
	make_pipe(fd_pipe, vars->cmd_num - 1);
	vars->fd_in = open(vars->infile, O_RDONLY);
	vars->fd_out = open(vars->outfile, O_WRONLY | O_TRUNC | O_CREAT, 0666);
	vars->argv = (char **)malloc(sizeof(char *) * 3);
	i = 0;
	while (i < vars->cmd_num)
	{
		multiple_pipes(vars, fd_pipe, i++);
	}
}
