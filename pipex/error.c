/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:54:32 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/27 21:01:44 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(int n, char *str)
{
	if (n == 0)
		ft_putstr_fd("Invalid argument number\n", 1);
	else if (n == 1)
		perror(str);
	exit(1);
}
