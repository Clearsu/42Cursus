/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:12:19 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/07 01:29:33 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"

typedef struct s_img_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img_data;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_raw_map
{
	char	**map_str[MAX_ROW];
	size_t	row_len;
	size_t	col_len;
}	t_raw_map;

typedef struct s_map_data
{
	t_point		**point;
	size_t		row_len;
	size_t		col_len;
}	t_map_data;

#endif
