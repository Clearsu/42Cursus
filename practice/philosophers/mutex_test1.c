/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_test1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 04:09:46 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/18 17:23:31 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>

pthread_mutex_t	pork[2];

void	*func(void *n)
{
	int i = *(int *)n;
	pthread_mutex_lock(&pork[i]);
	printf("pork %d locked\n", i);
	sleep(1);
	pthread_mutex_unlock(&pork[i]);
	printf("pork %d unlocked\n", i);
	return (NULL);
}

int	main(int argc, char **argv)
{

	pthread_mutex_init(&pork[0], NULL);
	pthread_mutex_init(&pork[1], NULL);
	
	pthread_t	thread[2];
	int	n1 = 0;
	int n2 = 1;

	pthread_create(&thread[0], NULL, func, (void *)&n1);
	pthread_create(&thread[1], NULL, func, (void *)&n2);

	pthread_join(thread[0], NULL);
	pthread_join(thread[1], NULL);
}
