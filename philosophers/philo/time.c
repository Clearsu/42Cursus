/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:02:39 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/20 18:03:21 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>

time_t	get_time_in_mili(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

time_t	get_time_diff(time_t then, time_t now)
{
	return (now - then);
}
