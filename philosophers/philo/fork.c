/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:28:18 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/30 18:23:54 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_right_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex_table);
	if (philo->table[philo->id] == 1)
	{
		philo->table[philo->id] = 0;
		pthread_mutex_unlock(philo->mutex_table);
		pthread_mutex_lock(philo->right_hand);
		print_in_mutex(philo, "has taken a fork");
		return (1);
	}
	pthread_mutex_unlock(philo->mutex_table);
	return (0);
}

int	get_left_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex_table);
	if (philo->table[philo->left_idx] == 1)
	{
		philo->table[philo->left_idx] = 0;
		pthread_mutex_unlock(philo->mutex_table);
		pthread_mutex_lock(philo->left_hand);
		print_in_mutex(philo, "has taken a fork");
		return (1);
	}
	pthread_mutex_unlock(philo->mutex_table);
	return (0);
}

void	put_forks_down(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_hand);
	pthread_mutex_unlock(philo->left_hand);
	pthread_mutex_lock(philo->mutex_table);
	philo->table[philo->id] = 1;
	philo->table[philo->left_idx] = 1;
	pthread_mutex_unlock(philo->mutex_table);
}
