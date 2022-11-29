/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think_eat_sleep.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:39:12 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/30 00:56:09 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "philo.h"

int	dead_check(t_philo *philo)
{
	if (get_time_in_mili() >= philo->limit)
	{
		*philo->alive = 0;
		pthread_mutex_lock(philo->print);
		printf("%ld %d died\n", get_timestamp(philo), philo->id);
		return (1);
	}
	return (0);
}

int	philo_think(t_philo *philo)
{
	if (!*philo->alive)
		return (0);
	print_in_mutex(philo, "is thinking");
	while (!get_right_fork(philo))
	{
		if (!*philo->alive || dead_check(philo))
			return (0);
		usleep(200);
	}
	while (!get_left_fork(philo))
	{
		if (!*philo->alive || dead_check(philo))
			return (0);
		usleep(200);
	}
	return (1);
}

int	philo_eat(t_philo *philo)
{
	time_t	eat_limit;
	time_t	now;

	if (!*philo->alive)
		return (0);
	pthread_mutex_lock(philo->print);
	printf("%ld %d %s\n", get_timestamp(philo), philo->id, "is eating");
	now = get_time_in_mili();
	philo->eat_reps--;
	if (!philo->eat_reps)
		*philo->eat_left = *philo->eat_left - 1;
	if (*philo->eat_left)
		pthread_mutex_unlock(philo->print);
	eat_limit = now + philo->time->to_eat;
	lengthen_life(philo, now);
	while (get_time_in_mili() < eat_limit)
	{
		if (!*philo->alive || dead_check(philo))
			return (0);
		usleep(200);
	}
	put_forks_down(philo);
	return (1);
}

int	philo_sleep(t_philo *philo)
{
	time_t	sleep_limit;

	if (!*philo->alive)
		return (0);
	sleep_limit = get_time_in_mili() + philo->time->to_sleep;
	print_in_mutex(philo, "is sleeping");
	while (get_time_in_mili() < sleep_limit)
	{
		if (!*philo->alive || dead_check(philo))
			return (0);
		usleep(200);
	}
	return (1);
}

void	philo_think_exception(t_philo *philo)
{
	printf("%ld %d is thinking\n", get_timestamp(philo), philo->id);
	get_right_fork(philo);
	get_left_fork(philo);
	while (1)
	{
		if (!*philo->alive || dead_check(philo))
			return ;
		usleep(200);
	}
}
