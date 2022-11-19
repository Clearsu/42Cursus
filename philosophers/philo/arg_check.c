/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:15:11 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/19 17:54:26 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_argv(char **argv)
{
	int	i;
	int	n;

	i = 1;
	n = 4
	if (argv[5])
		n = 5;
	while (i <= n)
	{
		if (!is_all_num(argv[i]))
		{
			error_msg(1, &argv[i]);
			return (0);
		}
		i++;
	}
	return (1);
}

int	arg_check(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		error(0, NULL);
		return (0);
	}
	if (!check_argv(argv))
		return (0);
	return (1);
}
