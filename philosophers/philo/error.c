/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:17:10 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/19 17:52:24 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <errno.h>

void	error_msg(int n, char *str)
{
	if (n == 0)
		printf("philo : Invalid argument number\n");
	if (n == 1)
		printf("philo : Invalid argument : %s\n", str);
	return ;
}
