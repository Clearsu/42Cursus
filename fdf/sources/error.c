/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 21:01:43 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/13 20:10:53 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

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
		ft_putstr_fd("Error : there is no file to read\n", 0);
	else if (n == 2)
		ft_putstr_fd("Error : put only one file to excute this program\n", 0);
	else if (n == 3)
		ft_putstr_fd("Error : there is a row shorter than the first row\n", 0);
	else if (n == 3)
		ft_putstr_fd("Error : data must consist of numeric data\n", 0);
	else if (n == 4)
		ft_putstr_fd("Error : memory allocation failed\n", 0);
	else if (n == 5)
		ft_putstr_fd("Error : failed to open a file\n", 0);
	exit(1);
}
