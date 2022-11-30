/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:17:36 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/30 19:11:31 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitor_with_option(t_info *info)
{
	while (1)
	{
		pthread_mutex_lock(&info->mutex_alive);
		if (!info->alive)
		{
			pthread_mutex_unlock(&info->mutex_alive);
			break ;
		}
		pthread_mutex_unlock(&info->mutex_alive);
	}
}

void	monitor_without_option(t_info *info)
{
	while (1)
	{
		pthread_mutex_lock(&info->mutex_alive);
		if (!info->alive)
		{
			pthread_mutex_unlock(&info->mutex_alive);
			break ;
		}
		pthread_mutex_unlock(&info->mutex_alive);
		pthread_mutex_lock(&info->mutex_eat);
		if (!info->eat_left)
		{
			pthread_mutex_unlock(&info->mutex_eat);
			break ;
		}
		pthread_mutex_unlock(&info->mutex_eat);
	}
}

void	monitor_state(t_info *info)
{
	if (!info->philo[0].opt_flag || !info->philo[0].eat_reps)
		monitor_with_option(info);
	else
		monitor_without_option(info);
}
