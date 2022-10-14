/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 21:01:43 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/14 19:32:29 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	argument_check(int argc)
{
	if (argc == 1)
		error(1);
	else if (argc > 2)
		error(2);
}

void	error(size_t n)
{
	if (n == 1)
		ft_putstr_fd("There is no file to read\n", 0);
	else if (n == 2)
		ft_putstr_fd("Put only one file to excute this program\n", 0);
	else if (n == 3)
		ft_putstr_fd("There is a row shorter than the first row\n", 0);
	else if (n == 4)
		perror("Memory allocation failed");
	else if (n == 5)
		perror("Failed to open a file");
	else if (n == 6)
		perror("Empty file or is not a file");
	exit(1);
}
