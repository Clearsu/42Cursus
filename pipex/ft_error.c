/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:54:32 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/27 23:25:03 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(int n, char *str)
{
	if (n == 0)
		ft_printf("pipex: no such file or directory: %s\n", str);
	else if (n == 1)
		ft_printf("pipex: command not found: %s\n", str);
	exit(errno);
}
