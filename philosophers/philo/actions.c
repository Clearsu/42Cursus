/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:39:12 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/24 00:00:37 by jincpark         ###   ########.fr       */
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

void	print_in_mutex(t_philo *philo, char *str)
{
	if (philo->alive)
	{
		pthread_mutex_lock(philo->print);
		printf("%ld %d %s\n", get_timestamp(philo), philo->id, str);
		pthread_mutex_unlock(philo->print);
	}
}

int	dead_check(t_philo *philo)
{
	if (get_time_in_mili() >= philo->limit)
	{
		philo->alive = 0;
		pthread_mutex_lock(philo->print);
		printf("%ld %d died\n", get_timestamp(philo), philo->id);
		pthread_mutex_unlock(philo->print);
		return (1);
	}
	return (0);
}

void	lengthen_life(t_philo *philo)
{
	philo->limit += philo->time->to_die;
}

int	get_right_pork(t_philo *philo)
{
	if (philo->table[philo->id] == 1)
	{
		philo->table[philo->id] = 0;
		pthread_mutex_lock(philo->right_hand);
		print_in_mutex(philo, "has taken a fork");
		return (1);
	}
	return (0);
}

int	get_left_pork(t_philo *philo)
{
	if (philo->table[get_left_idx(philo)] == 1)
	{
		philo->table[get_left_idx(philo)] = 0;
		pthread_mutex_lock(philo->left_hand);
		print_in_mutex(philo, "has taken a fork");
		return (1);
	}
	return (0);
}

void	put_porks_down(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_hand);
	pthread_mutex_unlock(philo->left_hand);
	philo->table[philo->id] = 1;
	philo->table[get_left_idx(philo)] = 1;
}

int	philo_think(t_philo *philo)
{
	if (!philo->alive)
		return (0);
	if (is_porks_available(philo))
	{
		get_right_pork(philo);
		get_left_pork(philo);
		return (1);
	}
	print_in_mutex(philo, "is thinking");
	while (!get_right_pork(philo))
	{
		if (!philo->alive || dead_check(philo))
			return (0);
		usleep(50);
	}
	while (!get_left_pork(philo) || !philo->eat_reps)
	{
		if (!philo->alive || dead_check(philo))
			return (0);
		usleep(50);
	}
	return (1);
}

int	philo_eat(t_philo *philo)
{
	time_t	eat_limit;

	if (!philo->alive)
		return (0);
	print_in_mutex(philo, "is eating");
	eat_limit = get_time_in_mili() + philo->time->to_eat;
	lengthen_life(philo);
	while (get_time_in_mili() < eat_limit)
	{
		if (!philo->alive || dead_check(philo))
			return (0);
		usleep(50);
	}
	put_porks_down(philo);
	if (philo->opt_flag)
		philo->eat_reps--;
	return (1);
}

int	philo_sleep(t_philo *philo)
{
	time_t	sleep_limit;

	if (!philo->alive)
		return (0);
	sleep_limit = get_time_in_mili() + philo->time->to_sleep;
	print_in_mutex(philo, "is sleeping");
	while (get_time_in_mili() < sleep_limit)
	{
		if (!philo->alive || dead_check(philo))
			return (0);
		usleep(50);
	}
	return (1);
}
