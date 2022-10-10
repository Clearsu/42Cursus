/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:12:19 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/10 17:48:37 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"
# include "macro.h"
# include "libft.h"

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
	int	z;
	int	color;
}	t_point;

typedef struct s_raw_map
{
	char	***map_str;
	size_t	row_len;
	size_t	col_len;
}	t_raw_map;

typedef struct s_map_data
{
	t_point		**point;
	size_t		row_len;
	size_t		col_len;
}	t_map_data;

int		is_valid_map(t_raw_map *raw_map);
void	read_and_save(t_raw_map *raw_map, char *argv);
void	put_map_data(t_raw_map *raw_map, t_map_data *map_data);
void	error(size_t n);
int		ft_htoi(char *str);
#endif
