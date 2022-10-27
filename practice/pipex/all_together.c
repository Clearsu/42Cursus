/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_together.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:36:20 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/27 17:45:41 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

// ./a.out infile /bin/cat /usr/bin/wc outfile

int	main(int argc, char *argv[], char *envp[])
{
	pid_t	pid;
	int		fd_pipe[2];
	int		fd_infile;
	int		fd_outfile;
	char	*argv1[] = {argv[2], "-e", NULL};
	char	*argv2[] = {argv[3], "-l", NULL};
	
	(void)argc;
	pipe(fd_pipe);
	pid = fork();
	if (pid == 0)
	{
		close(fd_pipe[0]);
		fd_infile = open(argv[1], O_RDONLY);
		dup2(fd_infile, 0);
		dup2(fd_pipe[1], 1);
		execve(argv[2], argv1, envp);
	}
	fd_outfile = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0666);
	dup2(fd_pipe[0], 0);
	dup2(fd_outfile, 1);
	close(fd_pipe[1]);
	sleep(1);
	execve(argv[3], argv2, envp);
}
