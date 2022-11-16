#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>

void	*thread_func(void *arg)
{
	printf("thread %d entered with argument '%d'\n", *(int *)arg, *(int *)arg);
	printf("thread %d is ended\n", *(int *)arg);
	return (NULL);
}

int	main(void)
{
	pthread_t	thread[3];
	void		*ret;

	for (int i = 0; i < 3; i++)
		pthread_create(&thread[i], NULL, thread_func, &i);
	sleep(1000);
	return (0);
}

