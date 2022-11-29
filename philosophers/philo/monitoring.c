/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:17:36 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/29 23:44:56 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitor_state(t_info *info)
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
			if (!info->alive || !info->eat_left)
				break ;
		}
	}
}
