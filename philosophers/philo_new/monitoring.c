/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:17:36 by jincpark          #+#    #+#             */
/*   Updated: 2022/12/04 21:11:28 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  <stdio.h>
#include "philo.h"

void	monitor_without_option(t_info *info)
{
	int		i;
	int		n;
	time_t	now;

	n = info->n;
	info->time.start = get_time_in_mili();
	pthread_mutex_unlock(&info->mutex_start);
	while (1)
	{
		i = 0;
		now = get_time_in_mili();
		while (i < n)
		{
			pthread_mutex_lock(&info->mutex_time);
			if (now >= info->philo[i].limit)
			{
				pthread_mutex_lock(&info->mutex_print);
				printf("%ld %d died\n", get_timestamp(&info->philo[i]), info->philo[i].id);
				return ;
			}
			pthread_mutex_unlock(&info->mutex_time);
			i++;
		}
	}
}

void	monitor_with_option(t_info *info)
{
	int		i;
	int		n;
	time_t	now;

	n = info->n;
	info->time.start = get_time_in_mili();
	pthread_mutex_unlock(&info->mutex_start);
	while (1)
	{
		i = 0;
		now = get_time_in_mili();
		while (i < n)
		{
			pthread_mutex_lock(&info->mutex_time);
			if (now >= info->philo[i].limit)
			{
				pthread_mutex_lock(&info->mutex_print);
				printf("%ld %d died\n", get_timestamp(&info->philo[i]), info->philo[i].id);
				return ;
			}
			pthread_mutex_unlock(&info->mutex_time);
			pthread_mutex_lock(&info->mutex_eat);
			if (info->eat_left == 0)
				return ;
			pthread_mutex_unlock(&info->mutex_eat);
			i++;
		}
	}
}

void	monitor_state(t_info *info)
{
	if (!info->philo[0].opt_flag)
		monitor_without_option(info);
	else
		monitor_with_option(info);
}
