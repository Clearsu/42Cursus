/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:28:18 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/24 14:30:30 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_porks_available(t_philo *philo)
{
	return (philo->table[philo->id] && philo->table[get_left_idx(philo)]);
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
	if (philo->left_hand && philo->table[get_left_idx(philo)] == 1)
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
