/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 06:08:36 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/31 23:00:12 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	multiple_pipes(t_vars *vars, size_t i)
{
	pid_t		pid;
	int			fd_pipe[2];
	static int	prev_read_end;
	
	if (i < vars->cmd_num - 1)
		pipe(fd_pipe);
	pid = fork();
	if (pid > 0) // parent process
	{
		prev_read_end = fd_pipe[0];
		close(fd_pipe[1]);
		printf("waiting child process %lu...\n", i + 1);
		waitpid(0, NULL, 0);
		return ;
	}
	// input
	if (i == 0)	
	{
		dup2(vars->fd_in, 0);
		close(vars->fd_in);
	}
	else
	{
		dup2(prev_read_end, 0);
		close(prev_read_end);
	}
	close(fd_pipe[0]);
	// output
	if (i == vars->cmd_num - 1)
	{
		dup2(vars->fd_out, 1);
		close(vars->fd_out);
	}
	else
	{
		dup2(fd_pipe[1], 1);
		close(fd_pipe[1]);
	}
	execve(vars->cmd_path[i], vars->argv[i], vars->envp);
}

void	pipex(t_vars *vars)
{
	size_t	i;

	vars->fd_in = open(vars->infile, O_RDONLY);
	vars->fd_out = open(vars->outfile, O_WRONLY | O_TRUNC | O_CREAT, 0666);
	i = 0;
	while (i < vars->cmd_num)
		multiple_pipes(vars, i++);
}
