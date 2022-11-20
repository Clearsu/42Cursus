/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:15:11 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/20 18:28:16 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "philo.h"

int	range_check(char *str)
{
	long long	num;

	num = ft_atol(str);
	if (num > INT_MAX || num < INT_MIN)
	{
		error_msg(4, str);
		return (0);
	}
	return (1);
}

int	check_argv(char **argv)
{
	int			i;
	int			n;

	i = 1;
	n = 4;
	if (argv[5])
		n = 5;
	while (i <= n)
	{
		if (!is_all_num(argv[i]))
		{
			error_msg(1, argv[i]);
			return (0);
		}
		i++;
	}
	if (!range_check(argv[1]) || (argv[5] && !range_check(argv[5])))
		return (0);
	return (1);
}

int	arg_check(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		error_msg(0, NULL);
		return (0);
	}
	if (!check_argv(argv))
		return (0);
	return (1);
}
