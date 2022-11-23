/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:10:49 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/23 23:48:34 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <strings.h>
#include "philo.h"

int	init_mutex(t_info *info)
{
	int	i;

	info->pork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->n);
	if (!info->pork)
	{
		free(info);
		error_msg(2, NULL);
		return (0);
	}
	if (pthread_mutex_init(&(info->print), NULL) != 0)
	{
		free(info);
		error_msg(3, NULL);
		return (0);
	}
	i = 0;
	while (i < info->n)
	{
		if (pthread_mutex_init(&(info->pork[i++]), NULL) != 0)
		{
			free(info);
			error_msg(3, NULL);
			return (0);
		}
	}
	return (1);
}

t_philo	*malloc_philo(t_info *info)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo) * info->n);
	if (!philo)
	{
		free(info->pork);
		free(info);
		error_msg(2, NULL);
		return (0);
	}
	return (philo);
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

int	init_philo(t_info *info, char **argv)
{
	int	i;

	info->philo = malloc_philo(info);
	if (!info->philo)
		return (0);
	i = 0;
	while (i < info->n)
	{
		info->philo[i].id = i;
		info->philo[i].alive = 1;
		info->philo[i].n = info->n;
		info->philo[i].print = &(info->print);
		info->philo[i].right_hand = &(info->pork[i]);
		if (i == 0)
			info->philo[i].left_hand = &(info->pork[info->n - 1]);
		else
			info->philo[i].left_hand = &(info->pork[i - 1]);
		i++;
	}
	set_eat_reps(info, argv);
	return (1);
}

int	set_time_in_microsec(char **argv, t_info *info)
{
	t_time	*time;
	int		i;

	time = (t_time *)malloc(sizeof(t_time));
	if (!time)
	{
		error_msg(2, NULL);
		return (0);
	}
	time->start = 0;
	time->to_die = ft_atol(argv[2]);
	time->to_eat = ft_atol(argv[3]);
	time->to_sleep = ft_atol(argv[4]);
	i = 0;
	while (i < info->n)
		info->philo[i++].time = time;
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
	i = 0;
	while (i < info->n)
		info->philo[i++].table = table;
	return (1);
}

t_info	*init_info(char **argv)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
	{
		error_msg(2, NULL);
		return (NULL);
	}
	info->n = ft_atoi(argv[1]);
	if (!init_mutex(info))
		return (NULL);
	if (!init_philo(info, argv))
		return (NULL);
	if (!set_time_in_microsec(argv, info))
		return (NULL);
	if (!set_table(info))
		return (NULL);
	return (info);
}
