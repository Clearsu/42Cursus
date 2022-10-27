/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_fork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:47:08 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/27 17:56:25 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main()
{
	pid_t	pid;

	pid = fork();
	if (pid > 0)
	{
		printf("parent1 pid = %d\n", pid);
		pid = fork();
		if (pid > 0)
		{
			printf("parent2 pid = %d\n", pid);
			pid = fork();
			if (pid > 0)
			{
				printf("parent3 pid = %d\n", pid);
				return (0);
			}
			printf("child3 pid = %d\n", pid);
			return (0);
		}
		printf("child2 pid = %d\n", pid);
		return (0);
	}
	printf("child1 pid = %d\n", pid);
	return (0);
}
