/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:10:49 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/19 18:38:37 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdlib.h>

int	init_mutex(t_info *info)
{
	int	i;

	info->pork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->n);
	if (!info->pork)
	{
		free(info);
		error_msg(2, NULL);
		return (0);
	}
	i = 0;
	while (i < info->n)
	{
		if (pthread_mutex_init(&(info->pork[i++]), NULL))
		{
			free(info);
			error_msg(3, NULL);
			return (0);
		}
	}
	return (1);
}

int	init_philo(t_info *info)
{
	info->philo = (t_philo *)malloc(sizeof(t_philo) * info->n);
	if (!info->philo)
	{
		free(info->pork);
		free(info);
		error_msg(2, NULL);
		return (0);
	}
	return (1);
}

void	set_time(char **argv, t_info *info)
{
	info->time.time_to_die = ft_atoi(argv[2]);
	info->time.time_to_eat = ft_atoi(argv[3]);
	info->time.time_to_sleep = ft_atoi(argv[4]);
}

t_info	*init_info(char **argv)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
	{
		error_msg(2, NULL);
		return (NULL);
	}
	info->n = ft_atoi(argv[1]);
	if (!init_mutex(info))
		return (NULL);
	if (!init_philo(info))
		return (NULL);
	set_time(argv, info);	
	if (argv[5])
		info->num_of_times_must_eat = ft_atoi(argv[5]);
	return (info);
}
