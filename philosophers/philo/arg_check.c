/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:15:11 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/18 19:29:35 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_argv(char **argv)
{
	int	i;
	int	n;

	i = 1;
	n = 4
	if (argv[5])
		n++;
	while (i <= n)
	{
		if (!is_all_num(argv[i]))
			error(1, &argv[i]);
		i++;
	}
}

void	arg_check(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		error(0, NULL);
	check_argv(argv);
}
