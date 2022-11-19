/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:17:10 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/19 18:17:11 by jincpark         ###   ########.fr       */
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
		printf("philo : memory allocation failed\n");
	if (n == 3)
		printf("philo : mutex initiation failed\n");
	return ;
}
