/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:17:36 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/29 19:36:57 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	someone_dead_before_eat_rep(t_info *info)
{
	static int	i;

	i = 0;
	while (i < info->n)
	{
		if (!info->alive && info->philo[i++].eat_reps > 0)
			return (1);
	}
	return (0);
}

int	have_all_eaten(t_info *info)
{
	static int	i;

	i = 0;
	while (i < info->n)
	{
		if (info->philo[i++].eat_reps > 0)
			return (0);
	}
	return (1);
}

void	detect_dead_and_quit(t_info *info)
{
	if (!info->philo[0].opt_flag || !info->philo[0].eat_reps)
	{
		while (1)
		{
			if (!info->alive)
				break ;
		}
	}
	else
	{
		while (1)
		{
			if (!info->alive)
				break ;
			if (!info->eat_left)
			{
				pthread_mutex_lock(&info->print);
				break ;
			}
		}
	}
}
