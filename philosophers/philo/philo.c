/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:24:39 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/29 19:07:41 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(philo->before_start);
	pthread_mutex_unlock(philo->before_start);
	philo->limit = philo->time->start + philo->time->to_die;
	if (philo->id % 2 == 0)
		usleep(200);
	if (philo->n == 1 || !philo->eat_reps)
	{
		philo->eat_reps = 1;
		philo_think_exception(philo);
		return (NULL);
	}
	while (1)
	{
		if (!philo_think(philo) || !philo_eat(philo) || !philo_sleep(philo))
			return (NULL);
	}
	return (NULL);
}

int	start_philo(t_info *info)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&info->before_start);
	while (i < info->n)
	{
		if (pthread_create(&(info->philo[i].thread), NULL,
				routine, &(info->philo[i])) != 0)
		{
			error_msg(5, NULL);
			return (0);
		}
		i++;
	}
	info->time.start = get_time_in_mili();
	pthread_mutex_unlock(&info->before_start);
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
	detect_dead_and_quit(info);
	if (!end_philo(info))
		return (1);
	return (0);
}
