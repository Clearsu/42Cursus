/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windowtest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:30:55 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/06 15:48:32 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	
	color = 0x00FF0000;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "TEST");
	img.img = mlx_new_image(mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	y = 150;
	while (y < 350)
	{
		x = 150;
		while (x < 350)
			my_mlx_pixel_put(&img, x++, y, color);
		y++;
	}
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_loop(mlx);
}
