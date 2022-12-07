/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:17:36 by jincpark          #+#    #+#             */
/*   Updated: 2022/12/07 19:00:58 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "philo.h"

void	set_limit_and_start(t_info *info, int n)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = info->philo;
	while (i < n)
	{
		philo[i].time.start = info->start;
		philo[i].limit = info->start + info->to_die;
		i++;
	}
}

void	unlock_all_philos(t_info *info)
{
	int	i;
	int	n;

	i = 0;
	n = info->n;
	while (i < n)
		pthread_mutex_unlock(&info->mutex_philo[i++]);
}

void	monitor_without_option(t_info *info)
{
	int		i;
	int		n;
	time_t	now;

	n = info->n;
	now = get_time_in_mili();
	info->start = now;
	set_limit_and_start(info, info->n);
	unlock_all_philos(info);
	usleep(5000);
	while (1)
	{
		i = 0;
		while (i < n)
		{
			pthread_mutex_lock(&info->mutex_philo[i]);
			if (now >= info->philo[i].limit)
			{
				pthread_mutex_lock(&info->mutex_print);
				printf("%ld %d died\n", get_timestamp(&info->philo[i]), info->philo[i].id);
				return ;
			}
			pthread_mutex_unlock(&info->mutex_philo[i]);
			i++;
		}
		now = get_time_in_mili();
	}
}

void	monitor_with_option(t_info *info)
{
	int		i;
	int		n;
	time_t	now;

	n = info->n;
	now = get_time_in_mili();
	info->start = now;
	set_limit_and_start(info, info->n);
	unlock_all_philos(info);
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
				printf("%ld %d died\n", get_timestamp(&info->philo[i]), info->philo[i].id);
				return ;
			}
			pthread_mutex_unlock(&info->mutex_philo[i]);
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
