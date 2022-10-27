/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 01:24:17 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/28 02:54:04 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	recur_fork(t_vars *vars, pid_t pid, int *fd_pipe, size_t i)
{
	if (i > 1)
		waitpid(pid, NULL, 0);
	if (i == vars->cmd_num)
		return ;
	pid = fork();
	if (pid > 0)
	{
		waitpid(0, NULL, 0);
		dup2(fd_pipe[0], 0);
		//dup2(fd_pipe[1], 1);
		close(fd_pipe[1]); // for test
		recur_fork(vars, pid, fd_pipe, i++);
		vars->argv[0] = vars->cmd_path[i];
		vars->argv[1] = vars->cmd_flag[i];
		vars->argv[2] = NULL;
		if (i == vars->cmd_num)
		{
			close(fd_pipe[1]);
			dup2(vars->fd_out, 1);
		}
		execve(vars->cmd_path[i], vars->argv, vars->envp);
	}
	else
	{
		//dup2(fd_pipe[0], 0);
		close(fd_pipe[0]); // for test
		dup2(fd_pipe[1], 1);
		vars->argv[0] = vars->cmd_path[i];
		vars->argv[1] = vars->cmd_flag[i];
		vars->argv[2] = NULL;
		if (i == vars->cmd_num - 1)
			close(fd_pipe[0]);
		execve(vars->cmd_path[i], vars->argv, vars->envp);  
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
	dup2(vars->fd_in, 0);
	recur_fork(vars, pid, fd_pipe, 1);
	close(vars->fd_in);
	close(vars->fd_out);
}
