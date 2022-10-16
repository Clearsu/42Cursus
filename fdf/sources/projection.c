/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 21:02:23 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/16 15:24:39 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso_projection(t_map_data *map_data)
{
	size_t	i;
	size_t	j;
	size_t	row_len;
	size_t	col_len;

	row_len = map_data->row_len;
	col_len = map_data->col_len;
	i = 0;
	while (i < row_len)
	{
		j = 0;
		while (j < col_len)
		{
			map_data->point[i][j].u = map_data->point[i][j].x * cos(RAD)
				+ map_data->point[i][j].y * cos(RAD + 0.66666 * M_PI)
				+ map_data->point[i][j].z * cos(RAD - 0.66666 * M_PI);
			map_data->point[i][j].v = map_data->point[i][j].x * sin(RAD)
				+ map_data->point[i][j].y * sin(RAD + 0.66666 * M_PI)
				+ map_data->point[i][j].z * sin(RAD - 0.66666 * M_PI);
			j++;
		}
		i++;
	}
}
