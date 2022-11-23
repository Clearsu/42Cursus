/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:39:12 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/23 16:37:25 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "philo.h"

int	get_left_idx(t_philo *philo)
{
	int	left;

	if (philo->id == 0)
		left = philo->n - 1;
	else
		left = philo->id - 1;
	return (left);
}

int	is_porks_available(t_philo *philo)
{
	return (philo->table[philo->id] && philo->table[get_left_idx(philo)]);
}

int	dead_check(t_philo *philo)
{
	time_t	now;

	now = get_time_in_mili();
	if (now >= philo->limit)
	{
		printf("%ld %d died\n", get_timestamp(philo), philo->id);
		philo->alive = 0;
		return (1);
	}
	return (0);
}

void	lengthen_life(t_philo *philo)
{
	philo->limit += philo->time->to_die;
}

void	get_porks(t_philo *philo)
{
	philo->table[philo->id] = 0;
	philo->table[get_left_idx(philo)] = 0;
	pthread_mutex_lock(philo->right_hand);
	pthread_mutex_lock(philo->left_hand);
}

void	put_porks_down(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_hand);
	pthread_mutex_unlock(philo->left_hand);
	philo->table[philo->id] = 1;
	philo->table[get_left_idx(philo)] = 1;
}

int	philo_eat(t_philo *philo)
{
	time_t	eat_limit;

	if (!philo->alive)
		return (0);
	if (is_porks_available(philo))
	{
		get_porks(philo);
		printf("%ld %d has taken a fork\n", get_timestamp(philo), philo->id);
		eat_limit = get_time_in_mili() + philo->time->to_eat;
		lengthen_life(philo);
		printf("%ld %d is eating\n", get_timestamp(philo), philo->id);
		while (get_time_in_mili() < eat_limit)
		{
			if (!philo->alive || dead_check(philo))
				return (0);
			usleep(50);
		}
		put_porks_down(philo);
	}
	return (1);
}

int	philo_sleep(t_philo *philo)
{
	time_t	sleep_limit;

	if (!philo->alive)
		return (0);
	printf("%ld %d is sleeping\n", get_timestamp(philo), philo->id);
	sleep_limit = get_time_in_mili() + philo->time->to_sleep;
	while (get_time_in_mili() < sleep_limit)
	{
		if (!philo->alive || dead_check(philo))
			return (0);
		usleep(50);
	}
	return (1);
}

int	philo_think(t_philo *philo)
{
	if (!philo->alive)
		return (0);
	if (is_porks_available(philo))
		return (1);
	printf("%ld %d is thinking\n", get_timestamp(philo), philo->id);
	while (!is_porks_available(philo))
	{
		if (!philo->alive || dead_check(philo))
			return (0);
		usleep(50);
	}
	return (1);
}
