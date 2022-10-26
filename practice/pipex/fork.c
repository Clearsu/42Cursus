/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:47:24 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/26 13:49:00 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int	main(void)
{
	pid_t	pid;

	printf("before fork\n");
	pid = fork();
	if (pid == 0)
	{
		printf("child process\n");
	}
	else
	{
		waitpid(0, NULL, 0);
		printf("parent process\n");
	}
}
