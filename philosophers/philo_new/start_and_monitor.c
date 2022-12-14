/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_and_monitor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:17:36 by jincpark          #+#    #+#             */
/*   Updated: 2022/12/15 01:52:39 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "philo.h"

void	set_limit_and_start(t_info *info, int n)
{
	int		i;
	t_philo	*philo;
	time_t	limit;
	time_t	now;

	i = 0;
	philo = info->philo;
	now = get_time_in_mili();
	limit = now + info->to_die;
	while (i < n)
	{
		philo[i].time.start = now;
		philo[i].limit = limit;
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

int	check_if_died(t_info *info, time_t now, int i)
{
	pthread_mutex_lock(&info->mutex_philo[i]);
	if (now >= info->philo[i].limit)
	{
		pthread_mutex_lock(&info->mutex_print);
		printf("%ld %d died\n", get_timestamp(&info->philo[i]),
			info->philo[i].id);
		return (0);
	}
	pthread_mutex_unlock(&info->mutex_philo[i]);
	return (1);
}

void	monitor_without_option(t_info *info)
{
	int		i;
	int		n;
	time_t	now;

	n = info->n;
	set_limit_and_start(info, n);
	unlock_all_philos(info);
	usleep(1000);
	while (1)
	{
		i = 0;
		now = get_time_in_mili();
		while (i < n)
		{
			if (!check_if_died(info, now, i++))
				return ;
		}
	}
}

void	monitor_with_option(t_info *info)
{
	int		i;
	int		n;
	time_t	now;

	n = info->n;
	set_limit_and_start(info, info->n);
	unlock_all_philos(info);
	usleep(1000);
	while (1)
	{
		i = 0;
		now = get_time_in_mili();
		while (i < n)
		{
			if (!check_if_died(info, now, i))
				return ;
			pthread_mutex_lock(&info->mutex_eat);
			if (info->eat_left == 0)
				return ;
			pthread_mutex_unlock(&info->mutex_eat);
			i++;
		}
	}
}
