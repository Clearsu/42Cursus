/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 22:20:05 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/28 05:44:03 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	arg_check(int argc, char **argv)
{
	int	fd_test;

	if (argc < 5)
		ft_error(1, argv[argc - 1]);
	fd_test = open(argv[1], O_RDONLY);
	if (fd_test == -1)
		ft_error(0, argv[1]);
	close(fd_test);
}
