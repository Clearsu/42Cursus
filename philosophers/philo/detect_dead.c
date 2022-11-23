/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_dead.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:17:36 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/23 16:04:13 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	give_dead_signal(t_info *info, int n)
{
	int	i;

	i = 0;
	while (i <= n)
		info->philo[i++].alive = 0;
}

void	detect_dead_and_quit(t_info *info)
{
	int	i;
	int	n;

	i = 0;
	n = info->n;
	while (1)
	{
		if (i == n)
			i = 0;
		if (info->philo[i++].alive == 0)
			break ;
	}
	give_dead_signal(info, n);
}
