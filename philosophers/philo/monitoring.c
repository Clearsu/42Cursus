/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:17:36 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/24 02:22:43 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	give_death_signal(t_info *info, int n)
{
	int	i;

	i = 0;
	while (i < n)
		info->philo[i++].alive = 0;
}

int	have_all_eaten(t_info *info)
{
	int	i;

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
	int	i;
	int	n;

	i = 0;
	n = info->n;
	if (!info->philo[i].opt_flag)
	{
		while (1)
		{
			if (i == n)
				i = 0;
			if (info->philo[i].alive == 0)
				break ;
			i++;
		}
	}
	else
	{
		while (1)
		{
			if (have_all_eaten(info))
				break ;
		}
	}
	give_death_signal(info, n);
}