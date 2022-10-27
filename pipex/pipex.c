/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 02:54:14 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/28 03:03:55 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	put_argv(t_vars *vars, size_t i)
{
	vars->argv[0] = vars->cmd_path[i];
	vars->argv[1] = vars->cmd_flag[i];
	vars->argv[2] = NULL;	
}

void	single_pipe(t_vars *vars, pid_t pid, int *fd_pipe)
{
	pid = fork();
	if (pid > 0)
	{
		waitpid(0, NULL, 0);
		dup2(fd_pipe[0], 0);
		close(fd_pipe[1]);
		dup2(vars->fd_out, 1);
		put_argv(vars, 1);
		execve(vars->cmd_path[1], vars->argv, vars->envp);
	}
	else
	{
		close(fd_pipe[0]);
		dup2(vars->fd_in, 0);
		dup2(fd_pipe[1], 1);
		put_argv(vars, 0);
		execve(vars->cmd_path[0], vars->argv, vars->envp);
	}
}

void	pipex(t_vars *vars)
{
	pid_t	pid;
	int		fd_pipe[2];

	vars->fd_in = open(vars->infile, O_RDONLY);
	vars->fd_out = open(vars->outfile, O_WRONLY | O_TRUNC | O_CREAT, 0666);
	vars->argv = (char **)malloc(sizeof(char *) * 3);
	pid = 0;
	pipe(fd_pipe);
	single_pipe(vars, pid, fd_pipe);
	close(vars->fd_in);
	close(vars->fd_out);
}
