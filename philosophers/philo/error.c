/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:17:10 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/24 15:04:30 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	error_msg(int n, char *str)
{
	if (n == 0)
		printf("philo : invalid argument number\n");
	if (n == 1)
		printf("philo : invalid argument : %s\n", str);
	if (n == 2)
		printf("philo : memory allocation failed\n");
	if (n == 3)
		printf("philo : mutex initiation failed\n");
	if (n == 4)
		printf("philo : number out of range : %s\n", str);
	if (n == 5)
		printf("philo : failed to create a thread\n");
	if (n == 6)
		printf("philo : failed to detach a thread\n");
	return ;
}
