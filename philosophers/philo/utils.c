/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:04:14 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/24 15:01:56 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo.h"

int	ft_atoi(char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	return (sign * result);
}

long long	ft_atol(char *str)
{
	long long	result;
	long long	sign;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	return (sign * result);
}

int	is_all_num(char *str)
{
	if (!str)
		return (-1);
	if ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+')
		str++;
	if (*str == '-')
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	get_left_idx(t_philo *philo)
{
	int	left;

	if (philo->id == 0)
		left = philo->n - 1;
	else
		left = philo->id - 1;
	return (left);
}

void	print_in_mutex(t_philo *philo, char *str)
{
	if (philo->alive)
	{
		pthread_mutex_lock(philo->print);
		printf("%ld %d %s\n", get_timestamp(philo), philo->id, str);
		pthread_mutex_unlock(philo->print);
	}
}
