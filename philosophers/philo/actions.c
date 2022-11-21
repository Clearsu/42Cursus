/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:39:12 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/21 22:02:39 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "philo.h"

int	is_porks_available(t_philo *philo)
{
	int	prev;

	if (philo->id == 0)
		prev = philo->n - 1;
	else
		prev = philo->id - 1;
	if (philo->table[philo->id] && philo->table[prev])
	{
		philo->table[philo->id] = 0;
		philo->table[prev] = 0;
		return (1);
	}
	return (0);
}

int	dead_check(t_philo *philo)
{
	time_t	now;

	now = get_time_in_mili();
	if (now > philo->limit)
	{
		printf("%ld %d died\n", now, philo->id);
		return (1);
	}
	return (0);
}

void	lengthen_life(t_philo *philo)
{
	philo->limit += philo->time->to_die;
}

void	mutex_lock(t_philo *philo)
{
	pthread_mutex_lock(philo->right_hand);
	pthread_mutex_lock(philo->left_hand);
}

void	mutex_unlock(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_hand);
	pthread_mutex_unlock(philo->left_hand);
}

int	philo_think_and_eat(t_philo *philo)
{
	time_t	eat_limit;

	if (is_porks_available(philo) && !dead_check(philo))
	{
		mutex_lock(philo);
		printf("%ld %d has taken a fork\n", get_timestamp(philo), philo->id);
		eat_limit = philo->curr + philo->time->to_eat;
		printf("%ld %d is eating\n", get_timestamp(philo), philo->id);
		while (philo->alive && get_time_in_mili() < eat_limit)
		{
			usleep(100);
			if (!dead_check(philo))
				return (0);
		}
		mutex_unlock(philo);
		lengthen_life(philo);
		return (1);
	}
	return (0);
}

int	philo_sleep(t_philo *philo)
{
	time_t	sleep_limit;

	printf("%ld %d is sleeping\n", get_timestamp(philo), philo->id);
	sleep_limit = curr + philo->time->to_sleep;
	while (philo->alive && get_time_in_mili() < sleep_limit)
	{
		usleep(100);
		if (!dead_check(philo))
			return (0);
	}
	return (1);
}

int	philo_think(t_philo *philo)
{
	printf("%ld %d is thinking\n", get_timestamp(philo), philo->id);
	while (philo->alive && !is_porks_available(philo))
	{
		usleep(100);
		if (!philo->alive)
			return (0);
	}
	return (1);
}
