/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windowtest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:30:55 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/06 10:23:54 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dest;

	dest = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

int	main(void)
{
	void	*mlx;
	void	*win;
	t_data	img;
	int		x;
	int		y;
	int		color;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "TEST");
	img.img = mlx_new_image(mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	color = 0x000000FF;
	y = 150;
	while (y < 350)
	{
		x = 150;
		while (x < 350)
		{
			if (x * (x - 500) + y * (y - 500) < -115000)
				my_mlx_pixel_put(&img, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_loop(mlx);
}
