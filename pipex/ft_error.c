/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:54:32 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/01 15:28:43 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(int n, char *str)
{
	if (n == 0)
		ft_printf("pipex: no such file or directory: %s\n", str);
	else if (n == 1)
		ft_printf("pipex: command not found: %s\n", str);
	else if (n == 2)
		ft_printf("pipex: memory allocation failed\n");
	exit(errno);
}
