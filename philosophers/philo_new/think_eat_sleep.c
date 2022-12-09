/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think_eat_sleep.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:39:12 by jincpark          #+#    #+#             */
/*   Updated: 2022/12/09 19:00:54 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "philo.h"

void	check_eat_left(t_philo *philo)
{
	philo->eat_reps--;
	pthread_mutex_lock(philo->mutex_eat);
	if (!philo->eat_reps)
		*philo->eat_left = *philo->eat_left - 1;
	if (*philo->eat_left)
		pthread_mutex_unlock(philo->mutex_print);
	pthread_mutex_unlock(philo->mutex_eat);
}

void	philo_think_and_get_forks(t_philo *philo)
{
	print_in_mutex(philo, "is thinking");
	pthread_mutex_lock(philo->right_hand);
	print_in_mutex(philo, "has taken a fork");
	pthread_mutex_lock(philo->left_hand);
	print_in_mutex(philo, "has taken a fork");
}

void	philo_eat(t_philo *philo)
{
	time_t	eat_limit;
	time_t	now;

	now = get_time_in_mili();
	pthread_mutex_lock(philo->mutex_philo);
	philo->limit = now + philo->time.to_die;
	pthread_mutex_unlock(philo->mutex_philo);
	pthread_mutex_lock(philo->mutex_print);
	printf("%ld %d %s\n", get_timestamp(philo), philo->id, "is eating");
	if (philo->opt_flag)
		check_eat_left(philo);
	else
		pthread_mutex_unlock(philo->mutex_print);
	eat_limit = now + philo->time.to_eat;
	while (get_time_in_mili() < eat_limit)
		usleep(200);
	pthread_mutex_unlock(philo->right_hand);
	pthread_mutex_unlock(philo->left_hand);
}

void	philo_sleep(t_philo *philo)
{
	time_t	sleep_limit;

	sleep_limit = get_time_in_mili() + philo->time.to_sleep;
	print_in_mutex(philo, "is sleeping");
	while (get_time_in_mili() < sleep_limit)
		usleep(200);
}
