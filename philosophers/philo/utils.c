/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:04:14 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/20 20:15:48 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/time.h>

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
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

void	print_status(time_t timestamp, int philo, int flag)
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
