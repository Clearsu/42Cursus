/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_etc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:32:37 by jincpark          #+#    #+#             */
/*   Updated: 2022/12/07 23:47:52 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "philo.h"

void	set_time_in_microsec(char **argv, t_info *info)
{
	int		i;
	t_time	time;

	time.to_die = ft_atol(argv[2]);
	time.to_eat = ft_atol(argv[3]);
	time.to_sleep = ft_atol(argv[4]);
	info->to_die = time.to_die;
	i = 0;
	while (i < info->n)
	{
		info->philo[i].time.to_die = time.to_die;
		info->philo[i].time.to_eat = time.to_eat;
		info->philo[i].time.to_sleep = time.to_sleep;
		i++;
	}
}

void	set_eat_reps(t_info *info, char **argv)
{
	int	i;

	i = 0;
	if (argv[5])
	{
		while (i < info->n)
		{
			info->philo[i].opt_flag = 1;
			info->philo[i].eat_reps = ft_atoi(argv[5]);
			i++;
		}
		info->eat_left = info->n;
	}
	else
	{
		while (i < info->n)
			info->philo[i++].opt_flag = 0;
	}
}

void	set_left_hand_by_idx(t_info *info, int i)
{
	if (i == 0)
		info->philo[i].left_hand = &info->forks[info->n - 1];
	else
		info->philo[i].left_hand = &info->forks[i - 1];
}
