/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:17:10 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/20 18:29:06 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

void	error_msg(int n, char *str)
{
	if (n == 0)
		printf("philo : Invalid argument number\n");
	if (n == 1)
		printf("philo : Invalid argument : %s\n", str);
	if (n == 2)
		printf("philo : Memory allocation failed\n");
	if (n == 3)
		printf("philo : Mutex initiation failed\n");
	if (n == 4)
		printf("philo : Number out of range : %s\n", str);
	if (n == 5)
		printf("philo : Failed to create a thread\n");
	if (n == 6)
		printf("philo : Failed to join a thread\n");
	return ;
}
