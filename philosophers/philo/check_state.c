/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:07:15 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/30 19:15:11 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo.h"

int	check_alive(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex_alive);
	if (!*philo->alive)
	{
		pthread_mutex_unlock(philo->mutex_alive);
		return (0);
	}
	pthread_mutex_unlock(philo->mutex_alive);
	return (1);
}

void	check_eat_left(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex_eat);
	if (!philo->eat_reps)
		*philo->eat_left = *philo->eat_left - 1;
	if (*philo->eat_left)
		pthread_mutex_unlock(philo->mutex_print);
	pthread_mutex_unlock(philo->mutex_eat);
}

int	check_dead(t_philo *philo)
{
	if (get_time_in_mili() >= philo->limit)
	{
		pthread_mutex_lock(philo->mutex_alive);
		*philo->alive = 0;
		pthread_mutex_unlock(philo->mutex_alive);
		pthread_mutex_lock(philo->mutex_print);
		printf("%ld %d died\n", get_timestamp(philo), philo->id);
		return (1);
	}
	return (0);
}
