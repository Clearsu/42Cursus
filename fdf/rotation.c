/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 21:02:43 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/11 02:14:14 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

void	rotate_map(t_map_data *map_data, size_t row_len, size_t col_len)
{
	size_t	i;
	size_t	j;
	size_t	x;
	size_t	y;

	i = 0;
	while (i < row_len)
	{
		j = 0;
		while (j < col_len)
		{
			x = map_data->point[i][j].x;
			y = map_data->point[i][j].y;
			map_data->point[i][j].x = cos(RAD) * x - sin(RAD) * y;
			map_data->point[i][j].y = sin(RAD) * x - cos(RAD) * y;
			j++;
		}
		i++;
	}
}
