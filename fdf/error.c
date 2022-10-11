/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 21:01:43 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/11 15:01:00 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	error(size_t n)
{
	if (n == 1)
		ft_putstr_fd("Error : there should be only/at least one argument\n", 0);
	else if (n == 2)
		ft_putstr_fd("Error : you can put only one map to excute this program\n", 0);
	else if (n == 3)
		ft_putstr_fd("Error : there is a row shorter than the first row of given map\n", 0);
	else if (n == 3)
		ft_putstr_fd("Error : coordinate data must consist of numeric data\n", 0);
	else if (n == 4)
		ft_putstr_fd("Error : memory allocation failed\n", 0);
	else if (n == 5)
		ft_putstr_fd("Error : failed to open a file\n", 0);
	exit(1);
}
