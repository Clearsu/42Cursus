/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex_philo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:10:49 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/30 00:21:50 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo.h"

void	free_info_and_print_error(t_info *info)
{
	free(info);
	error_msg(3, NULL);
}

int	init_mutex(t_info *info)
{
	int	i;

	info->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->n);
	if (!info->forks)
	{
		free(info);
		error_msg(2, NULL);
		return (0);
	}
	if (pthread_mutex_init(&(info->print), NULL) != 0
		|| pthread_mutex_init(&info->before_start, NULL) != 0)
	{
		free_info_and_print_error(info);
		return (0);
	}
	i = 0;
	while (i < info->n)
	{
		if (pthread_mutex_init(&(info->forks[i++]), NULL) != 0)
		{
			free_info_and_print_error(info);
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
		free(info->forks);
		free(info);
		error_msg(2, NULL);
		return (0);
	}
	return (philo);
}

int	init_philo(t_info *info)
{
	int	i;

	info->philo = malloc_philo(info);
	if (!info->philo)
		return (0);
	i = 0;
	while (i < info->n)
	{
		info->philo[i].id = i;
		info->philo[i].alive = &info->alive;
		info->philo[i].eat_left = &info->eat_left;
		info->philo[i].n = info->n;
		info->philo[i].left_idx = get_left_idx(&(info->philo[i]));
		info->philo[i].print = &(info->print);
		info->philo[i].before_start = &(info->before_start);
		info->philo[i].right_hand = &(info->forks[i]);
		if (i == 0)
			info->philo[i].left_hand = &(info->forks[info->n - 1]);
		else
			info->philo[i].left_hand = &(info->forks[i - 1]);
		i++;
	}
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
	if (info->n == 0)
	{
		free(info);
		error_msg(1, argv[1]);
		return (NULL);
	}
	info->alive = 1;
	info->eat_left = info->n;
	if (!init_mutex(info) || !init_philo(info)
		|| !set_time_in_microsec(argv, info) || !set_table(info))
		return (NULL);
	set_eat_reps(info, argv);
	return (info);
}
