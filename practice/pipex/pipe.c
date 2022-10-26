/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:02:38 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/26 14:54:44 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	pid_t	pid;
	int		fd[2];
	char	buff[50];

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		dup2(fd[1], 1);
		close(fd[0]);
		printf("This message is sent from child process\n");
		return (0);
	}
	close(fd[1]);
	read(fd[0], buff, 50);
	printf("Parent process : %s", buff);
	return (0);
}
