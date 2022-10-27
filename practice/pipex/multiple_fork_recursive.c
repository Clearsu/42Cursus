/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_fork_recursive.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:57:04 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/27 18:24:33 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	recur_mul_fork(pid_t pid, int n)
{
	if (n == 0)
		return ;
	pid = fork();
	if (pid > 0)
	{	
		printf("parent : %d\n", pid);
		recur_mul_fork(pid, n - 1);
	}
	else
		printf("child : %d\n", pid);
}

int	main()
{	
	pid_t	pid;

	pid = 0;
	recur_mul_fork(pid, 5);
	return 0;
}
