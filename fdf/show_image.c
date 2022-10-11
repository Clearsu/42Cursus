/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:28:10 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/11 21:02:45 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

 void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dest;

	dest = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

static void	mlx_set_window_and_image(void **mlx, void **win, t_data *img)
{
 	
	*mlx = mlx_init();
	*win = mlx_new_window(*mlx, WIDTH, HEIGHT, "TEST");
	img->img = mlx_new_image(*mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
}

static void	mlx_put_dots_to_image(t_map_data *map_data, t_data *img)
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
			my_mlx_pixel_put(img, map_data->point[i][j].x,
					map_data->point[i][j].y, map_data->point[i][j].color);
			j++;
		}
		i++;
	}
}
void	show_image(t_map_data *map_data)
{
	void	*mlx;
	void	*win;
	t_data	img;

	mlx_set_window_and_image(&mlx, &win, &img);
	mlx_put_dots_to_image(map_data, &img);
//	put_lines(map_data, &img);
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_loop(mlx);
}
