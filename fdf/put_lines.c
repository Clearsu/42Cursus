/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 00:13:12 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/12 21:57:45 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	case_delta_lower_than_zero(int *delta, int *increment)
{
	*delta = -*delta;
	*increment = -1;
}

void	case_slope_lower_than_1(t_data *img, int x1, int x2, int y1, t_line_factors br_fac)
{
	int	p;
   
	p = (br_fac.dy << 1) - br_fac.dx;
	while (x1 != x2)
	{
		if (p >= 0)
		{
			y1 += br_fac.increment_y;
			p -= (br_fac.dx << 1);
		}
		x1 += br_fac.increment_x;
		p += (br_fac.dy << 1);
		my_mlx_pixel_put(img, x1, y1, 0x00FF00FF);
	}	
}

void	case_slope_higher_than_1(t_data *img, int y1, int y2, int x1, t_line_factors br_fac)
{
	int	p;
	
	p = (br_fac.dx << 1) - br_fac.dy;
	while (y1 != y2)
	{
		if (p >= 0)
		{
			x1 += br_fac.increment_x;
			p -= (br_fac.dy << 1);
		}
		y1 += br_fac.increment_y;
		p += (br_fac.dx << 1);
		my_mlx_pixel_put(img, x1, y1, 0x00660066);
	}
}

void	bresenham(t_data *img, int x1, int y1, int x2, int y2)
{
	t_line_factors	br_fac;
	
	br_fac.dx = x2 - x1;
	br_fac.dy = y2 - y1;
	br_fac.increment_x = 1;
	br_fac.increment_y = 1;
	if (br_fac.dx < 0)
		case_delta_lower_than_zero(&(br_fac.dx), &(br_fac.increment_x));
	if (br_fac.dy < 0)
		case_delta_lower_than_zero(&(br_fac.dy), &(br_fac.increment_y));
	my_mlx_pixel_put(img, x1, y1, 0x00FF00FF);
	if (br_fac.dx > br_fac.dy)
		case_slope_lower_than_1(img, x1, x2, y1, br_fac);
	else
		case_slope_higher_than_1(img, y1, y2, x1, br_fac);
}

void	put_lines(t_map_data *map_data, t_data *img)
{
	size_t	row_len;
	size_t	col_len;
	size_t	i;
	size_t	j;

	row_len = map_data->row_len;
	col_len = map_data->col_len - 1;
	i = 0;
	while (i < row_len)
	{
		j = 0;
		while (j < col_len)
		{
			bresenham(img, map_data->point[i][j].u, map_data->point[i][j].v,
					map_data->point[i][j + 1].u, map_data->point[i][j + 1].v);
			j++;
		}
		i++;
	}
	row_len--;
	col_len++;
	j = 0;
	while (j < col_len)
	{
		i = 0;
		while (i < row_len)
		{
			bresenham(img, map_data->point[i][j].u, map_data->point[i][j].v,
					map_data->point[i + 1][j].u, map_data->point[i + 1][j].v);
			i++;
		}
		j++;
	}
}
