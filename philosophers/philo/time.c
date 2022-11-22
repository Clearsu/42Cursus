/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:02:39 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/22 20:56:12 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "philo.h"

time_t	get_timestamp(t_philo *philo)
{
	static time_t	start;

	if (start == 0)
	{
		philo->time->start = get_time_in_mili();
		start = philo->time->start;
	}
	return (get_time_in_mili() - start);
}

time_t	get_time_in_mili(void)
{
	static struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

time_t	get_time_diff(time_t then, time_t now)
{
	return (now - then);
}
