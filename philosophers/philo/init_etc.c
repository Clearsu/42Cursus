/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_etc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:32:37 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/24 20:46:00 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "philo.h"

int	set_time_in_microsec(char **argv, t_info *info)
{
	int	i;

	info->time.start = 0;
	info->time.to_die = ft_atol(argv[2]);
	info->time.to_eat = ft_atol(argv[3]);
	info->time.to_sleep = ft_atol(argv[4]);
	i = 0;
	while (i < info->n)
		info->philo[i++].time = &info->time;
	return (1);
}

int	set_table(t_info *info)
{
	char	*table;
	int		i;

	table = (char *)malloc(sizeof(char) * info->n);
	if (!table)
	{
		error_msg(2, NULL);
		return (0);
	}
	table = memset(table, 1, info->n);
	info->table = table;
	i = 0;
	while (i < info->n)
		info->philo[i++].table = table;
	return (1);
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
	}
	else
	{
		while (i < info->n)
		{
			info->philo[i].opt_flag = 0;
			info->philo[i].eat_reps = 1;
			i++;
		}
	}
}
