/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:24:39 by jincpark          #+#    #+#             */
/*   Updated: 2022/12/07 19:10:28 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(philo->mutex_philo);
	pthread_mutex_unlock(philo->mutex_philo);
	if (philo->id % 2 == 0)
		usleep(500);
	while (1)
	{
		philo_think_and_get_forks(philo);
		philo_eat(philo);
		philo_sleep(philo);
	}
	return (NULL);
}

int	start_philo(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->n)
	{
		pthread_mutex_lock(&info->mutex_philo[i]);
		if (pthread_create(&info->philo[i].thread, NULL,
				routine, &info->philo[i]) != 0)
		{
			error_msg(5, NULL);
			return (0);
		}
		i++;
	}
	return (1);
}

int	end_philo(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->n)
	{
		if (pthread_detach(info->philo[i++].thread) != 0)
		{
			error_msg(6, NULL);
			return (0);
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_info	*info;

	if (!arg_check(argc, argv))
		return (1);
	info = init_info(argv);
	if (!info)
		return (1);
	if (!start_philo(info))
		return (1);
	monitor_state(info);
	if (!end_philo(info))
		return (1);
	return (0);
}
