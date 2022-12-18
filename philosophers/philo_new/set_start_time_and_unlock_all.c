/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_start_time_and_unlock_all.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 04:03:00 by jincpark          #+#    #+#             */
/*   Updated: 2022/12/19 00:23:46 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "philo.h"

void	init_start_limit(t_philo *philo, int n, time_t now, time_t limit)
{
	int	i;

	i = 0;
	if (n > 3)
	{
		while (i < n)
		{
			philo[i].time.start = now;
			philo[i].limit = limit;
			philo[i + 1].time.start = now;
			philo[i + 1].limit = limit;
			philo[i + 2].time.start = now;
			philo[i + 2].limit = limit;
			philo[i + 3].time.start = now;
			philo[i + 3].limit = limit;
			i = i + 4;
		}
	}
	while (i < n)
	{
		philo[i].time.start = now;
		philo[i++].limit = limit;
	}
}

void	set_start_and_limit(t_info *info, int n)
{
	time_t	now;

	now = get_time_in_mili();
	init_start_limit(info->philo, n, now, now + info->to_die);
}

void	unlock_all_philos(t_info *info, int n)
{
	int	i;

	i = 0;
	if (n > 3)
	{
		while (i < n)
		{
			pthread_mutex_unlock(&info->mutex_philo[i]);
			pthread_mutex_unlock(&info->mutex_philo[i + 1]);
			pthread_mutex_unlock(&info->mutex_philo[i + 2]);
			pthread_mutex_unlock(&info->mutex_philo[i + 3]);
			i = i + 4;
		}
	}
	while (i < n)
		pthread_mutex_unlock(&info->mutex_philo[i++]);
}
