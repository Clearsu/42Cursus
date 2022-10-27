/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 22:20:05 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/27 23:25:39 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	arg_check(int argc, char **argv)
{
	int	fd_test;

	(void)argc;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		exit(0); // here_doc 만들 것
	fd_test = open(argv[1], O_RDONLY);
	if (fd_test == -1)
		ft_error(0, argv[1]);
	close(fd_test);
}
