/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:24:39 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/22 22:06:53 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->curr = get_time_in_mili();
	if (philo->id == 0)
		philo->time->start = philo->curr;
	philo->limit = philo->curr + philo->time->to_die;
	while (1)
	{
		if (!philo_think(philo))
			return (NULL);
		if (!philo_eat(philo))
			return (NULL);
		if (!philo_sleep(philo))
			return (NULL);
	}
}

int	start_philo(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->n)
	{
		if (pthread_create(&(info->philo[i].thread), NULL,
				routine, &(info->philo[i])) != 0)
		{
			error_msg(5, NULL);
			return (0);
		}
		i++;
	}
	return (1);
}

int	end_philo(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->n)
	{
		if (pthread_join(info->philo[i++].thread, NULL) != 0)
		{
			error_msg(6, NULL);
			return (0);
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_info	*info;

	if (!arg_check(argc, argv))
		return (1);
	info = init_info(argv);
	if (!info)
		return (1);
	if (!start_philo(info))
		return (1);
	detect_dead_and_quit(info);
	if (!end_philo(info))
		return (1);
	return (0);
}
