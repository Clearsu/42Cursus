#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_struct
{
	int fork1;
	int fork2;
}	t_struct;

t_struct test;

int	arr[3] = {0, 0, 0};

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void	*start_func1(void *i)
{
	int	n = *(int *)i;
	pthread_mutex_lock(&mutex);
	for (int j = 0; j < 100; j++)
	{
		test.fork1++;
		printf("fork1 : %d\n", test.fork1);
	}
	pthread_mutex_unlock(&mutex);
	printf("thread %d done\n", n);
	return (NULL);
}

void	*start_func2(void *i)
{
	int	n = *(int *)i;
	pthread_mutex_lock(&mutex);
	for (int j = 0; j < 100; j++)
	{
		test.fork2++;
		printf("fork2 : %d\n", test.fork2);
	}
	pthread_mutex_unlock(&mutex);
	printf("thread %d done\n", n);
	return (NULL);
}

int main()
{
	pthread_t	thread[2];
	int	n1;
	int n2;
	test.fork1 = 0;
	test.fork2 = 0;


	n1 = 1;
	n2 = 2;

		pthread_create(&thread[0], NULL, start_func1, (void *)&n1);
		pthread_create(&thread[1], NULL, start_func2, (void *)&n2);
		pthread_join(thread[0], NULL);
		pthread_join(thread[1], NULL);
}
