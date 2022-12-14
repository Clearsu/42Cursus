/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_start_time_and_unlock_all.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 04:03:00 by jincpark          #+#    #+#             */
/*   Updated: 2022/12/15 04:05:51 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_start_and_limit(t_info *info, int n)
{
	int		i;
	t_philo	*philo;
	time_t	limit;
	time_t	now;

	i = 0;
	philo = info->philo;
	now = get_time_in_mili();
	limit = now + info->to_die;
	if (n > 1)
	{
		while (i < n)
		{
			philo[i].time.start = now;
			philo[i + 1].time.start = now;
			philo[i].limit = limit;
			philo[i + 1].limit = limit;
			i = i + 2;
		}
	}
	if (i < n)
	{
		philo[i].time.start = now;
		philo[i].limit = limit;
	}
}

void	unlock_all_philos(t_info *info, int n)
{
	int	i;

	i = 0;
	if (n > 1)
	{
		while (i < n)
		{
			pthread_mutex_unlock(&info->mutex_philo[i]);
			pthread_mutex_unlock(&info->mutex_philo[i + 1]);
			i = i + 2;
		}
	}
	if (i < n)
		pthread_mutex_unlock(&info->mutex_philo[i]);
}
