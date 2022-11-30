/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:02:39 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/29 23:23:48 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	get_timestamp(t_philo *philo)
{
	return (get_time_in_mili() - philo->time->start);
}

time_t	get_time_in_mili(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	lengthen_life(t_philo *philo, time_t now)
{
	philo->limit = now + philo->time->to_die;
}
