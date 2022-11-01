/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:44:10 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/01 19:46:02 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parse_heredoc(t_vars *vars, char **argv, char **envp)
{
	vars->limiter = argv[2];
	vars->argv = (char ***)malloc(sizeof(char **) * 3);
	if (!vars->argv)
		ft_error(2, NULL);
	vars->argv[0] = ft_split(argv[3], ' ');
	vars->argv[1] = ft_split(argv[4], ' ');
	if (!vars->argv[0] || !vars->argv[1])
		ft_error(2, NULL);
	vars->argv[2] = NULL;
	vars->outfile = argv[5];
	vars->envp = envp;
	vars->limiter_len = ft_strlen(vars->limiter);
}

void	heredoc_single_pipe(t_vars *vars, int read_end, pid_t pid)
{
	int	fd_pipe[2];
	int	fd_out;

	pipe(fd_pipe);
	pid = fork();
	if (pid == 0)
	{
		close(fd_pipe[0]);
		dup2(read_end, 0);
		close(read_end);
		dup2(fd_pipe[1], 1);
		close(fd_pipe[1]);
		execve(vars->cmd_path[0], vars->argv[0], vars->envp);
	}
	close(read_end);
	fd_out = open(vars->outfile, O_WRONLY | O_CREAT | O_APPEND, 0666);
	dup2(fd_pipe[0], 0);
	close(fd_pipe[0]);
	dup2(fd_out, 1);
	close(fd_out);
	execve(vars->cmd_path[1], vars->argv[1], vars->envp);
}

void	pipe_heredoc(t_vars *vars)
{
	pid_t	pid;
	char	*str;
	int		fd_pipe[2];

	pipe(fd_pipe);
	pid = fork();
	if (pid == 0)
	{
		close(fd_pipe[0]);
		while (1)
		{
			ft_printf("pipe heredoc> ");
			str = get_next_line(0);
			if (ft_strncmp(str, vars->limiter, vars->limiter_len) == 0)
			{
				close(fd_pipe[1]);
				exit(0);
			}
			write(fd_pipe[1], str, ft_strlen(str));
			free(str);
		}
	}
	close(fd_pipe[1]);
	waitpid(0, NULL, 0);
	heredoc_single_pipe(vars, fd_pipe[0], pid);
}

void	here_doc(t_vars *vars, int argc, char **argv, char **envp)
{
	(void)argc;

	parse_heredoc(vars, argv, envp);
	parse_path(vars, envp);
	search_path(vars);
	pipe_heredoc(vars);
}
