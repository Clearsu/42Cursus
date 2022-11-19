/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:04:14 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/19 18:57:38 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

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

int	is_all_num(char *str)
{
	if (!str)
		return (-1);
	if ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (*str < '0' && *str > '9')
			return (0);
		str++;
	}
	return (1);
}

time_t	get_time_diff(time_t then, time_t now)
{
	return (now - then);
}

void	print_status(time_t timestamp, int	philo, int flag)
{
	if (flag == 0)
		printf("%ld %d has taken a fork\n", timestamp, philo);
	else if (flag == 1)
		printf("%ld %d is eating\n", timestamp, philo);
	else if (flag == 2)
		printf("%ld %d is sleeping\n", timestamp, philo);
	else if (flag == 4)
		printf("%ld %d died\n", timestamp, philo);
}
