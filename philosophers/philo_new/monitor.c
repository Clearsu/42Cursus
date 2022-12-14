/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:17:36 by jincpark          #+#    #+#             */
/*   Updated: 2022/12/15 04:07:21 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo.h"

void	check_if_died(t_info *info, int n)
{
	int		i;
	time_t	now;

	while (1)
	{
		i = 0;
		now = get_time_in_mili();
		while (i < n)
		{
			pthread_mutex_lock(&info->mutex_philo[i]);
			if (now >= info->philo[i].limit)
			{
				pthread_mutex_lock(&info->mutex_print);
				printf("%ld %d died\n", get_timestamp(&info->philo[i]),
					info->philo[i].id);
				return ;
			}
			pthread_mutex_unlock(&info->mutex_philo[i++]);
		}
	}
}

void	check_if_died_or_all_eaten(t_info *info, int n)
{
	int		i;
	time_t	now;

	while (1)
	{
		i = 0;
		now = get_time_in_mili();
		while (i < n)
		{
			pthread_mutex_lock(&info->mutex_philo[i]);
			if (now >= info->philo[i].limit)
			{
				pthread_mutex_lock(&info->mutex_print);
				printf("%ld %d died\n", get_timestamp(&info->philo[i]),
					info->philo[i].id);
				return ;
			}
			pthread_mutex_unlock(&info->mutex_philo[i++]);
			pthread_mutex_lock(&info->mutex_eat);
			if (info->eat_left == 0)
				return ;
			pthread_mutex_unlock(&info->mutex_eat);
		}
	}
}

void	monitor(t_info *info)
{
	set_start_and_limit(info, info->n);
	unlock_all_philos(info, info->n);
	if (!info->philo[0].opt_flag)
		check_if_died(info, info->n);
	else
		check_if_died_or_all_eaten(info, info->n);
}
