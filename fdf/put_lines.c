/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 00:13:12 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/11 01:54:44 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	bresenham(t_data *img, int x_start, int x_fin, int y_start, int y_fin)
{
	int	x;
	int	y;
	int	w;
	int	h;
	int	slope;
	int	d_slope1;
	int	d_slope2;

	x = x_start;
	y = y_start;
	w = x_fin - x_start;
	h = y_fin - y_start;
	if (w > h)
	{
		slope = h * 2 - w;
		d_slope1 = h * 2;
		d_slope2 = (h - w) * 2;
		for (x = x_start; x < x_fin; x++)
		{
			my_mlx_pixel_put(img, x, y, 0x00FF00FF);
			if (slope < 0)
				slope += d_slope1;
			else
			{
				y++;
				slope += d_slope2;
			}
		}
	}
	else
	{

	}
}

void	put_lines(t_map_data *map_data, t_data *img)
{
	size_t	row_len;
	size_t	col_len;
	size_t	i;
	size_t	j;

	row_len = map_data->row_len - 1;
	col_len = map_data->col_len - 1;
	i = 0;
	while (i < row_len)
	{
		j = 0;
		while (j < col_len)
		{
			bresenham(img, map_data->point[i][j].x * SPACE, map_data->point[i][j + 1].x * SPACE,
					map_data->point[i][j].y * SPACE, map_data->point[i][j + 1].y * SPACE);
			j++;
		}
		i++;
	}
	j = 0;
	while (j < col_len)
	{
		i = 0;
		while (i < row_len)
		{
			bresenham(img, map_data->point[i][j].x * SPACE, map_data->point[i + 1][j].x * SPACE,
					map_data->point[i][j].y * SPACE, map_data->point[i + 1][j].y * SPACE);
			i++;
		}
		j++;
	}
}
